#include "mtd.h"

int main(int argc, char *argv[]) {
    mtd_options opts = {false, false, NULL};
    
    if (argc < 3) {
        fprintf(stderr, "Usage: mtd [options] <source> <destination>\n");
        return 1;
    }

    // In future, options.c will handle flags, for now we skip them
    char *dest = argv[argc - 1];

    for (int i = 1; i < argc - 1; i++) {
        mtd_process(argv[i], dest, &opts);
    }

    return 0;
}
