#include "csapp.h"


int main (int argc, char **argv)
{
struct stat stat;
char *type, *readok;
fstat(atoi(argv[1]), &stat); 
if (S_ISREG(stat.st_mode)) /* Determine file type */
    type = "regular";
else if (S_ISDIR(stat.st_mode))
    type = "directory";
else
    type = "other";
if ((stat.st_mode & S_IRUSR)) /* Check read access */
        readok = "yes";
    else
        readok = "no";
printf("type: %s, read: %s\n", type, readok);
exit(0); 
}