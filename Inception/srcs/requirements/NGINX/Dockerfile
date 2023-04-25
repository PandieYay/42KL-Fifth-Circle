FROM debian:buster

#install nginx
RUN apt update
RUN apt install -y nginx
RUN apt install -y openssl

RUN openssl req -batch -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
RUN openssl dhparam -out /etc/nginx/dhparam.pem 4096

COPY self-signed.conf /etc/nginx/snippets/
COPY ssl-params.conf /etc/nginx/snippets/
COPY nginx.conf /etc/nginx
COPY default /etc/nginx/sites-available/default

CMD ["nginx", "-g", "daemon off;"]