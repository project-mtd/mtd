#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include "mvtd.h"

/**
 * Fungsi: receiver_move
 * Deskripsi: Eksekutor pemindahan file/direktori tunggal yang mendukung 
 *            logika non-overwrite, verbose mode, dan penanganan cross-device.
 */
int receiver_move(const char *src, const char *dest, mvtd_options *opts) {
    struct stat st;

    // 1. Pastikan source ada
    if (stat(src, &st) == -1) {
        return -1;
    }

    // 2. Eksekusi pemindahan menggunakan rename()
    if (rename(src, dest) == 0) {
        // Berikan feedback jika mode verbose aktif
        if (opts && opts->verbose) {
            printf("[SUCCESS] Moved: %s -> %s\n", src, dest);
        }
        return 0;
    } else {
        // 3. Penanganan Error & Logika Non-Overwrite
        if (errno == EEXIST || errno == ENOTEMPTY) {
            // Inti dari mtd: Jangan timpa jika tujuan sudah ada
            if (opts && opts->verbose) {
                printf("[SKIPPED] Already exists: %s\n", src);
            }
        } else if (errno == EXDEV) {
            // Error jika mencoba memindah antar filesystem yang berbeda
            fprintf(stderr, "[ERROR] Cross-device link failed: Cannot move %s to a different filesystem.\n", src);
        } else {
            // Error sistem lainnya
            fprintf(stderr, "[ERROR] Failed to move %s: %s\n", src, strerror(errno));
        }
        return -1;
    }
}
