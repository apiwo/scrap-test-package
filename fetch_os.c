#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "system_info.h"

void get_os(char *buf) {
    FILE *f = fopen("/etc/os-release", "r");
    strcpy(buf, "Linux");
    if (f) {
        char line[256];
        while (fgets(line, sizeof(line), f)) {
            if (strncmp(line, "PRETTY_NAME=", 12) == 0) {
                sscanf(line, "PRETTY_NAME=\"%[^\"]\"", buf);
                break;
            }
        }
        fclose(f);
    }
}
