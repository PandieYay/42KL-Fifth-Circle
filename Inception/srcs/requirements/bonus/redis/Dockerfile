FROM debian:buster

#install php and wordpress
RUN apt update && apt upgrade -y
RUN apt install -y redis-server

COPY redis.conf /etc/redis/redis.conf

CMD [ "redis-server", "--protected-mode no"]