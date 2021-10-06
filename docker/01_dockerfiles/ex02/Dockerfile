FROM ruby

MAINTAINER lechapus <lechapus@student.42.fr>

RUN apt-get update -y && apt-get install -y build-essential libpq-dev nodejs sqlite3

ONBUILD COPY rails_helloworld/ /opt/app

ONBUILD WORKDIR /opt/app

ONBUILD EXPOSE 3000

ONBUILD RUN gem install bundler:1.17.2

ONBUILD RUN bundle install

ONBUILD RUN bundle update rak

ONBUILD RUN rake db:migrate

ONBUILD RUN rake db:seed
