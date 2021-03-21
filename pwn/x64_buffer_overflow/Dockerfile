FROM ubuntu:20.04

RUN apt-get update
RUN apt-get install -y \
	apt-utils \ 
	build-essential \
	socat

RUN useradd -ms /bin/sh anubhav
WORKDIR /home/anubhav

COPY ./flag.txt ./
COPY ./source ./
COPY ./run.sh ./

RUN chown -R root:anubhav /home/anubhav && \
    chmod 750 /home/anubhav && \
    chown root:anubhav /home/anubhav/flag.txt && \
    chmod 440 /home/anubhav/flag.txt && \
    chmod 550 /home/anubhav/source && \
    chmod 550 /home/anubhav/run.sh

EXPOSE 8778

CMD ["socat", "-T60", "TCP-LISTEN:8778,reuseaddr,fork,su=anubhav", "EXEC:/home/anubhav/run.sh,pty,rawer"]