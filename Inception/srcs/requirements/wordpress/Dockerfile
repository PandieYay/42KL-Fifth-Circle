FROM debian:buster

#install php and wordpress
RUN apt update && apt upgrade -y
RUN apt install -y wget
RUN apt install -y php php-fpm php-mysql php-redis
# Download wordpress and wp cli

RUN cd /tmp && wget https://wordpress.org/latest.tar.gz && tar -xvf latest.tar.gz
RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN	chmod +x wp-cli.phar
RUN	mv wp-cli.phar /usr/local/bin/wp

COPY wp-setup.sh /tmp
COPY wp-config.php /tmp
COPY www.conf /etc/php/7.3/fpm/pool.d/www.conf

CMD [ "bash", "/tmp/wp-setup.sh"]