#include "mtd.h"

void mtd_process(const char *src, const char *dest, mtd_options *opts) {
    struct stat st;
    if (stat(src, &st) != 0) return;

    if (S_ISDIR(st.st_mode)) {
        mkdir(dest, 0755);
        DIR *dir = opendir(src);
        struct dirent *entry;

        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;

            char new_src[1024], new_dest[1024];
            snprintf(new_src, sizeof(new_src), "%s/%s", src, entry->d_name);
            snprintf(new_dest, sizeof(new_dest), "%s/%s", dest, entry->d_name);

            if (!should_exclude(new_src, opts)) {
                mtd_process(new_src, new_dest, opts);
            }
        }
        closedir(dir);
        rmdir(src); // Cleanup empty dir
    } else {
        if (generator_should_move(src, dest)) {
            receiver_move(src, dest, opts);
        }
    }
}
