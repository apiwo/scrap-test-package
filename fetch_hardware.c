#include <stdio.h>
#include <string.h>
#include "system_info.h"

void get_cpu(char *buf) {
    FILE *f = fopen("/proc/cpuinfo", "r");
    if (f) {
        char line[256];
        while (fgets(line, sizeof(line), f)) {
            if (strncmp(line, "model name", 10) == 0) {
                char *colon = strchr(line, ':');
                if (colon) {
                    strcpy(buf, colon + 2);
                    buf[strlen(buf)-1] = '\0';
                }
                break;
            }
        }
        fclose(f);
    }
}

void get_gpu(char *buf) {
    // Basic GPU detection via lspci pipe
    FILE *f = popen("lspci | grep -i vga | cut -d ':' -f3", "r");
    if (f) {
        fgets(buf, 128, f);
        buf[strlen(buf)-1] = '\0';
        pclose(f);
    } else {
        strcpy(buf, "Unknown");
    }
}
