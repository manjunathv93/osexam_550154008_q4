//Open the file /usr/share/dictionary in process P1 and send the strings 
//starting with letter 'm' to process P2 using pipes. In process P2 find and print the length of string.
//manjunathv_210550154008
//Algorithm
//1. create pipe with the given path 
//2. use makefifo create the fifo with permissions
//3. open the pipe
//4. write the string
//5.close the filedescriptor


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/stat.h>


int main(int argc, char const *argv[])
{
    int fd;
    char * myfifo = "/usr/share/dictionary/myfifo";
    
    mkfifo("myfifo", S_IRUSR | S_IWUSR);

    fd = open("myfifo", O_WRONLY);
    write(fd, "message\n", 8);
    close(fd);
    

    return 0;
}
