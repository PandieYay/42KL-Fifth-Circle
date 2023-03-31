cd tmp
mv wordpress /var/www/html/
mv index.html /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress/
chmod -R 755 /var/www/html/wordpress/
mkdir /var/www/html/wordpress/wp-content/uploads
chown -R www-data:www-data /var/www/html/wordpress/wp-content/uploads/
echo "Wordpress sh script done"
sleep 5