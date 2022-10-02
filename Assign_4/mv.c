#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
int main(int argc, char *argv[])
{

    int dest_fd = open(argv[2], O_CREAT | O_WRONLY, 0644);

    if (dest_fd == -1) {

	printf("ERROR OPENING THE FILE \n");


    }

    int src_fd = open(argv[1],O_RDWR);


    if (src_fd == -1) {

	printf("ERROR OPENING FILE\n ");

    }


    char buffer[100];

    int read_count = 1;
    int write_count = 0;

    while ((read_count = read(src_fd, buffer, 100)) != 0) {

	write_count = write(dest_fd, buffer, read_count);

	if ((write_count != read_count) | (write_count == -1)) {

	    printf("ERROR IN COPY PASTE PROCESS\n");
	    break;

	}





    }


    if (remove(argv[1]) == -1) {

	printf("ERROR IN REMOVING SOURCE DIRECTORY");
	    close(src_fd);
	close(dest_fd);


    }


    else {
	close(dest_fd);
    }




}
