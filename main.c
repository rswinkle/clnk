
#define CLNK_IMPLEMENTATION
#include "clnk.h"


int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Usage: %s some_shortcut.lnk\n", argv[0]);
        return 0;
    }

    char path[1024] = {0};
    if (clnk_get_path_buf(argv[1], path, sizeof(path))) {
        printf("Path: %s\n", path);
    } else {
        printf("Error: %s\n", clnk_failure_reason());
    }

    char* path2 = clnk_get_path(argv[1]);
    if (path2) {
        printf("Path: %s\n", path2);
        free(path2);
    } else {
        printf("Error: %s\n", clnk_failure_reason());
    }

    return 0;
}
