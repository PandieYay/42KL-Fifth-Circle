FROM debian:buster

#install php and wordpress
RUN apt update && apt upgrade -y
RUN apt install -y wget

COPY adminer-setup.sh /tmp

CMD ["bash", "/tmp/adminer-setup.sh"]