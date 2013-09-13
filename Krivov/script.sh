mkdir -p temporary/another_temporary
cd temporary
whoami > i_am.txt
umask > my_umask.txt
pwd > where_am_i.txt
history | grep cd
cp where_am_i.txt another_temporary/here.txt
mv another_temporary/here.txt another_temporary/there.txt
ls -la >> where_am_i.txt
rm -r another_temporary
cd ../ && echo "Done"

