FROM debian:buster

#install nginx
RUN apt update && apt upgrade -y
RUN apt install -y wget
RUN apt install -y php-fpm
RUN cd /tmp && wget https://wordpress.org/latest.tar.gz && tar -xvf latest.tar.gz

COPY wp-setup.sh /tmp
COPY index.html /tmp
COPY www.conf /etc/php/7.3/fpm/pool.d/www.conf

CMD [ "bash", "/tmp/wp-setup.sh"]