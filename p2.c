//1. create pipe
//2. read using file descriptor
//3. print the string and length values
//4. close the filedescriptor

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include <string.h>

#define SIZE 64

int main(int argc, char const *argv[])
{
    int fd;
    unsigned char buff[SIZE];

    char * myfifo = "/usr/share/dictionary/myfifo";
    mkfifo("myfifo", S_IRUSR | S_IWUSR);

    fd = open("myfifo", O_RDONLY);
    read(fd, buff, SIZE);
    printf("P2:%s\n", buff);
    printf("length of the string is %d\n",strlen(buff));
    close(fd);
    return 0;
}