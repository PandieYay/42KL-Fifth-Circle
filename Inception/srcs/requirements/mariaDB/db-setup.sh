#WHY NEED TO MKDIR FOR IT TO WORK
# mkdir -p /run/mysqld
# chown -R mysql:mysql /run/mysqld

echo "Sleeping"
# exec mysqld --user=mysql --console
mysqld_safe