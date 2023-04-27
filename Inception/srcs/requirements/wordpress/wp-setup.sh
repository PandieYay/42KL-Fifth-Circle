cd tmp
mv wordpress/* /var/www/html/
mv wp-config.php /var/www/html
chown -R www-data:www-data /var/www/html/
chmod -R 755 /var/www/html/
mkdir /var/www/html/wp-content/uploads
chown -R www-data:www-data /var/www/html/wp-content/uploads/
echo "<?php echo phpinfo();?>" > /var/www/html/info.php

cd /var/www/html

# Admin user
wp core install --url=$DOMAIN_NAME --title=Inception --admin_name=$MYSQL_ADMIN --admin_password=$MYSQL_ADMIN_PASSWORD --admin_email=$MYSQL_ADMIN@gmail.com --allow-root
wp user create $WP_USER $WP_USER@gmail.com --user_pass=$WP_USER_PASSWORD --role=author --allow-root

# Installing redis plugin
wp config set WP_REDIS_HOST redis --allow-root
wp config set WP_REDIS_PORT 6379 --raw --allow-root
wp config set WP_REDIS_DATABASE 0 --raw --allow-root
wp config set WP_REDIS_PREFIX $DOMAIN_NAME --allow-root
wp config set WP_REDIS_TIMEOUT 1 --raw --allow-root
wp config set WP_REDIS_READ_TIMEOUT 1 --raw --allow-root
wp plugin install redis-cache --allow-root
wp plugin update --all --allow-root
wp plugin activate redis-cache --allow-root
wp redis enable --allow-root

echo "Wordpress sh script done"
mkdir -p /run/php
/usr/sbin/php-fpm7.3 -F -R