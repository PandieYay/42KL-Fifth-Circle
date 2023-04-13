all:
	cd srcs && docker-compose build
	cd srcs && docker-compose up

clean:
	cd srcs && docker-compose down
	docker volume prune -f
	docker image prune -f
	docker container prune -f

fclean: clean

re: fclean all

.PHONY: all clean fclean re