FROM php:7.1-apache

# Add vim
RUN apt-get update && apt-get install vim -y

# PHP extensions
RUN docker-php-ext-install pdo pdo_mysql 

# Add rewrite module in Apache for htaccess
RUN ["cp", "/etc/apache2/mods-available/rewrite.load","/etc/apache2/mods-enabled"]
