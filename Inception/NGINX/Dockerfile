FROM debian:buster

#install nginx
RUN apt update
RUN apt install -y nginx

COPY nginx.conf /etc/nginx
COPY default /etc/nginx/sites-available/default

CMD [ "nginx", "-g", "daemon off;"]