FROM debian:buster

#install php and wordpress
RUN apt update && apt upgrade -y
RUN apt install -y vsftpd

COPY ftp-setup.sh /tmp
COPY vsftpd.conf /etc/vsftpd.conf

CMD ["bash", "/tmp/ftp-setup.sh"]