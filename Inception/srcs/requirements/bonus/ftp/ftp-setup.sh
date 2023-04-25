useradd -m $FTP_USER
echo -e "$FTP_PWD\n$FTP_PWD" | passwd $FTP_USER

mkdir -p /var/run/vsftpd/empty

chown -R $FTP_USR:$FTP_USR /var/www/html

echo $FTP_USER | tee -a /etc/vsftpd.userlist

echo "||Starting FTP||"
/usr/sbin/vsftpd