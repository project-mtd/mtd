#include "mvtd.h"

bool should_exclude(const char *path, mtd_options *opts) {
    if (opts->exclude_pattern && strstr(path, opts->exclude_pattern)) {
        return true;
    }
    return false;
}
