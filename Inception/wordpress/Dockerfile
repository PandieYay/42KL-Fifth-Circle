FROM debian:buster

#install nginx
RUN apt update && apt upgrade
RUN apt install wget

CMD [ "nginx", "-g", "daemon off;"]