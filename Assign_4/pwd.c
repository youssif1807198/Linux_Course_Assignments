#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    char buffer[PATH_MAX];
    if (getcwd(buffer, sizeof(buffer)) != NULL) {
	printf("Current working dir: %s\n", buffer);
    } else {
	perror("getcwd() error");
	return 1;
    }
    return 0;
}
