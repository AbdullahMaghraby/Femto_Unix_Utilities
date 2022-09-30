#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{

    if (argc > 3) {
	printf("Just use 2 Arguements");
	return -1;
    }
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1)
	printf("Error while openning src file");

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT,0644);
    if (dest_fd == -1)
	printf("Error while openning dest file");

    char *buf[100];		/*creatring buffer for read sys call */
    volatile int read_cntr = read(src_fd, buf, 100);

    if (read_cntr == -1)
	printf("Error while reading from src file");

    while ((read(src_fd, buf, 100)) > 0){
	write(dest_fd, buf, read_cntr);
    }

    if (write(dest_fd, buf, read_cntr) == -1)
	printf("Error while writting on dest file");

    /*Program closes file while checking :) */

   /* close(src_fd);*/
    if (close(src_fd) == -1)
	printf("Error while closing src file");

   /* close(dest_fd);*/
    if (close(dest_fd) == -1)
	printf("Error while closing dest file");



    return 0;
}
