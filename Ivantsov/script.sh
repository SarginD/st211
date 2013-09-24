mkdir test1
cd test1
touch word.txt
touch file.xls
mkdir test2
cp file.xls test2/tst.xls
cd test2
mv tst.xls abrak.xls
cd ..
echo Helloworld > word.txt
grep world *.txt
cat word.txt
cd ..
rm -r test1
whoami
pwd
ls

