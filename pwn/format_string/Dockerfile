FROM ubuntu:18.04

RUN apt-get update
RUN apt-get install -y \
	apt-utils \ 
	build-essential \
	socat \
    gcc-multilib

RUN useradd -ms /bin/sh anubhav
WORKDIR /home/anubhav

COPY ./flag.txt ./
COPY ./format ./
COPY ./run.sh ./

RUN chown -R root:anubhav /home/anubhav && \
    chmod 750 /home/anubhav && \
    chown root:anubhav /home/anubhav/flag.txt && \
    chmod 440 /home/anubhav/flag.txt && \
    chmod 550 /home/anubhav/format && \
    chmod 550 /home/anubhav/run.sh

EXPOSE 8743

CMD ["socat", "-T60", "TCP-LISTEN:8743,reuseaddr,fork,su=anubhav", "EXEC:/home/anubhav/run.sh,pty,rawer"]