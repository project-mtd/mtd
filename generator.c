#include "mtd.h"

bool generator_should_move(const char *src, const char *dest) {
    // Check if destination already exists
    if (access(dest, F_OK) == 0) {
        // Logically skip if exists to prevent overwrite
        return false;
    }
    return true;
}
