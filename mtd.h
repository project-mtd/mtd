#ifndef MTD_H
#define MTD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>

// Structure for CLI options
typedef struct {
    bool verbose;
    bool dry_run;
    char *exclude_pattern;
} mtd_options;

// Module Prototypes
void parse_options(int argc, char *argv[], mtd_options *opts);
bool should_exclude(const char *path, mtd_options *opts);
bool generator_should_move(const char *src, const char *dest);
int receiver_move(const char *src, const char *dest, mtd_options *opts);
void mtd_process(const char *src, const char *dest, mtd_options *opts);

#endif
