all:
	cd srcs && docker-compose build
	cd srcs && docker-compose up

clean:
	cd srcs && docker-compose down

fclean: clean
	docker system prune -f
	rm -rf /Users/edlim/data/db/*
	rm -rf /Users/edlim/data/wordpress/*

re: fclean all

.PHONY: all clean fclean re