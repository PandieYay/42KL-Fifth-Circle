all:
	docker-compose -f srcs/docker-compose.yml build
	docker-compose -f srcs/docker-compose.yml up

clean:
	docker-compose -f srcs/docker-compose.yml down

fclean: clean
	docker volume prune -f
	docker system prune -f
	rm -rf /Users/edlim/data/db/*
	rm -rf /Users/edlim/data/wordpress/*

re: fclean all

.PHONY: all clean fclean re