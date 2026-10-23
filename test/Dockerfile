FROM php:8.4-apache

# Add vim
RUN apt-get update && apt-get install vim -y

# Install MySQL extensions for PHP
RUN docker-php-ext-install mysqli pdo pdo_mysql

# Enable Apache rewrite module
RUN a2enmod rewrite

# Set working directory
WORKDIR /var/www/html


