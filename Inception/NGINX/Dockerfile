FROM debian:buster

#install nginx
RUN apt update
RUN apt install -y nginx

COPY nginx.conf /etc/nginx

CMD [ "nginx", "-g", "daemon off;"]