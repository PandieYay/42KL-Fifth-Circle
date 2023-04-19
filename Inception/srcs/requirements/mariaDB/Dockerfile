FROM debian:buster

#install mariadb
RUN apt update && apt upgrade -y
RUN apt install -y mariadb-server

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY db-setup.sh /tmp

CMD ["bash", "/tmp/db-setup.sh"]