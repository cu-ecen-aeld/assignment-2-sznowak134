#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

void initSyslog()
{
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
    setlogmask(LOG_UPTO(LOG_INFO));
}

int main(int argc, char *argv[])
{
    int userArgCount = argc - 1;

    initSyslog();
    syslog(LOG_DEBUG, "Number of arguments provided by user: %d\n", userArgCount);
    if (userArgCount < 2)
    {
        printf("Usage: %s <filename> <content>\n", argv[0]);
        syslog(LOG_ERR, "Insufficient arguments provided. Expected 2, got %d", userArgCount);
        return 1;
    }

    const char *filename = argv[1];
    const char *content = argv[2];

    FILE * file = fopen(filename, "w");
    if(!file)
    {
        syslog(LOG_ERR, "Failed to open file '%s' for writing", filename);
        return 1;
    }

    int result = fprintf(file, "%s\n", content);
    if(result < 0)
    {
        syslog(LOG_ERR, "Failed to write to file '%s'", filename);
        fclose(file);
        return 1;
    }
    else
    {
        syslog(LOG_DEBUG, "Writing %s to file %s", content, filename);
    }

    fclose(file);

    return 0;
}