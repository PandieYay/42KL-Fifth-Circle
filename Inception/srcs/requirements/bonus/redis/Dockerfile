FROM debian:buster

#install php and wordpress
RUN apt update && apt upgrade -y
RUN apt install -y redis-server

COPY redis-setup.sh /tmp

CMD [ "bash", "/tmp/redis-setup.sh"]