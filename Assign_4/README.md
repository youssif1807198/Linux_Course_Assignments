#copy paste utility
gcc -o copy_paste copy_paste.c
./copy_paste src_file.txt dst_file.txt

#echo utilty

gcc -o print_user_input print_user_input.c
./print_user_input hello world

#pwd utilty
vim pwd.c
indent -kr pwd.c
gcc -o pwd pwd.c
./pwd

#mv utility
indent -kr mv.c
gcc -o mv mv.c
mv 1.txt ../2.txt



