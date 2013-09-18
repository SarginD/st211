mkdir Lord_Of_The_Ring
cd Lord_Of_The_Ring
mkdir Shire
cd Shire
echo "Жили были Фродо и Сэм"
mkdir Frodo Sam
touch Frodo/Ring.txt
echo "Было у Фродо колечко (очень плохое колечко)"
tree
cd ..
echo "One ring to rule them all, one ring to find them, One ring to bring them all and in the darkness bind them." > Shire/Frodo/Ring.txt
mkdir Rivendell Moria Mordor
echo "На колечке было написано:"
cat Shire/Frodo/Ring.txt
tree
echo "Отправились хоббиты в Ривенделл"
mv Shire/Frodo Rivendell
mv Shire/Sam Rivendell
pwd
tree
echo "Начинается самое интересное)"
cd Rivendell
cp Frodo/Ring.txt Sam
echo "Сэм сделал копию кольца для себя"
tree
cd ..
echo "В Морию не пойдем!"
mv Rivendell/Frodo Mordor
mv Rivendell/Sam Mordor
tree
echo "Фродо уничтожил свое кольцо (вместе с пальцем)"
rm Mordor/Frodo/Ring.txt
echo "А свое кольцо Сэм оставил себе"
tree


