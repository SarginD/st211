ls
mkdir www
cd www
echo "Создадим файл index.php и запишем туда функцию phpinfo()"
touch index.php
echo "<? phpinfo(); ?>" >> index.php
echo "Создадим файл си"
touch test.cpp
chmod 0777 test.cpp
echo "Напшием приветствие"
echo "#include <stdio.h>" >> test.cpp
echo "int main() {" >> test.cpp
echo "printf(\"Hello MIPT!!!\n\");" >> test.cpp
echo "return 0; }" >> test.cpp
g++ test.cpp
rm test.cpp
chmod 0777 a.out
cd ..
echo "Зачем нам два разных файла в одной папке"
mkdir temp
cp www/a.out temp
cd www
rm a.out
cd ..
pwd
tree
temp/a.out
