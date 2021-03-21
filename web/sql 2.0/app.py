import os
from uuid import uuid4

from flask import Flask, send_from_directory, render_template, make_response, request, abort
from flaskext.mysql import MySQL

from flask_limiter import Limiter
from flask_limiter.util import get_remote_address

app = Flask(__name__)
app.config.update(
    MYSQL_DATABASE_HOST='db',
    MYSQL_DATABASE_DB='web_chall',
    MYSQL_DATABASE_USER='web_sql',
    MYSQL_DATABASE_PASSWORD='codefest_web',
)
mysql = MySQL(autocommit=True)
mysql.init_app(app)

limiter = Limiter(app=app, key_func=get_remote_address, default_limits=['8/minute'])

@app.route('/')
def index():
    res = make_response(render_template('index.html'))
    cursor = mysql.connect().cursor()

    if request.cookies.get('session_id'):
        sid = request.cookies.get('session_id')
        cursor.execute(f"SELECT * FROM sessions WHERE session_id='{sid}'")
        if len(cursor.fetchone()) > 0:
            res.set_cookie('session_id', sid)
            return res

    sid = str(uuid4())
    cursor.execute(f"INSERT INTO sessions (session_id) VALUES ('{sid}')")
    res.set_cookie('session_id', sid)

    return res

@app.route('/<path:path>')
def website(path):
    if path.endswith('.html'):
        return send_from_directory('templates', path)
    return abort(404)

if __name__ == '__main__':
    app.run()
