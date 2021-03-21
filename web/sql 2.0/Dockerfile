FROM python:3.8-slim-buster

WORKDIR .

COPY requirements.txt requirements.txt

RUN pip3 install -r requirements.txt

COPY . .

CMD [ "gunicorn", "--bind 0.0.0.0 5000", "--workers=3", "app.py" ]

EXPOSE 5000
