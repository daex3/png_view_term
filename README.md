# PNG View Term
View PNG files in a terminal with libpng+Tegrine
## Setup
```shell
git clone https://github.com/daex3/tegrine ../tegrine
sudo ln -s $(PWD)/../tegrine /usr/include/tegrine
git clone https://github.com/daex3/include ../include
make bin name=png_view_term
png_view_term x.png
```