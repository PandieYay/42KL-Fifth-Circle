cd tmp
mv wordpress /var/www/html/
mv index.html /var/www/html/
mv wp-config.php /var/www/html/wordpress
chown -R www-data:www-data /var/www/html/wordpress/
chmod -R 755 /var/www/html/wordpress/
mkdir /var/www/html/wordpress/wp-content/uploads
chown -R www-data:www-data /var/www/html/wordpress/wp-content/uploads/
echo "<?php echo phpinfo();?>" > /var/www/html/info.php
echo "Wordpress sh script done"
mkdir -p /run/php
/usr/sbin/php-fpm7.3 -F -R