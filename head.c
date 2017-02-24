#include "types.h"
#include "user.h"

char buf[1024];
char buf2[1024];

void head(int fd, int lineNumber)
{
    int i, n;
    int lineCount=0;
    while((n = read(fd, buf, sizeof(buf))) > 0)
	{
		for(i=0;i < n;i++) 
		{
			if(buf[i] == '\n') //reached end of line
       			{
				lineCount = lineCount + 1;  	
       			}
			buf2[i] = buf[i];
			if (lineCount > lineNumber)
			{
				printf(1,"%s\n",buf2);
				exit();
			}
		}
	} 
    printf(1,"%s\n",buf2);
}

int main(int argc, char *argv[])
{
    int fd,lineNumber=9;
    char *fileName = argv[1];
    if (argc > 2)
    {    
	lineNumber = (int) (argv[1][1] - '0'); 
	fileName = argv[2];
    }
    if(argc < 2)
    {
        head(0,lineNumber);
        exit();
    }
    fd = open(fileName, 0);
    if(fd < 0)
    {
        printf(1,"Unable to open the file\n");
        exit();
    }
    head(fd,lineNumber);
    close(fd);
    exit();
}
