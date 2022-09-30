#include<stdio.h>
#include <unistd.h>



int main()
{

    char *buf[100];
    char *mypwd = getwd(buf);
    if (mypwd != "NULL") {	/*check on return value */
	printf("%s\n", mypwd);
    } else {
	printf("Error...\n");
    }

    return 0;
}
