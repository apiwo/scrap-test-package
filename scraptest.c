#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>
#include "ascii.h"
#include "system_info.h"

int main() {
    struct sysinfo si;
    struct statvfs vfs;
    char os[128], cpu[128], gpu[128];

    sysinfo(&si);
    statvfs("/", &vfs);
    get_os(os);
    get_cpu(cpu);
    get_gpu(gpu);

    double total_mem = si.totalram / 1024.0 / 1024.0 / 1024.0;
    double total_disk = (vfs.f_blocks * vfs.f_frsize) / 1024.0 / 1024.0 / 1024.0;

    printf("%s\n", tux_ascii);
    printf("\033[1;36mOS:\033[0m      %s\n", os);
    printf("\033[1;36mGPU:\033[0m     %s\n", gpu);
    printf("\033[1;36mCPU:\033[0m     %s\n", cpu);
    printf("\033[1;36mSTORAGE:\033[0m %.2f GB\n", total_disk);
    printf("\033[1;36mMEMORY:\033[0m  %.2f GB\n", total_mem);
    printf("\033[1;36mWM:\033[0m      %s\n", getenv("XDG_CURRENT_DESKTOP") ? getenv("XDG_CURRENT_DESKTOP") : "N/A");

    return 0;
}
