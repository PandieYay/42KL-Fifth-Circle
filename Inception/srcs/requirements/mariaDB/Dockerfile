FROM debian:buster

#install mariadb
RUN apt update && apt upgrade -y
RUN apt install -y mariadb-server

COPY db-setup.sh /tmp

CMD ["bash", "/tmp/db-setup.sh"]