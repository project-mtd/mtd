#include "mtd.h"

int receiver_move(const char *src, const char *dest, mtd_options *opts) {
    if (rename(src, dest) == 0) {
        return 0;
    } else {
        perror("Move failed");
        return -1;
    }
}
