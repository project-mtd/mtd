#include <stdio.h>
#include <stdbool.h>
#include "mvtd.h"

int main(int argc, char *argv[]) {
    // Inisialisasi opsi (Default: verbose=false, recursive=false)
    // Pastikan struct mtd_options di mtd.h memiliki member: verbose dan recursive
    mtd_options opts = {false, false, NULL};

    // Validasi jumlah argumen minimal
    if (argc < 3) {
        fprintf(stderr, "Usage: mvtd [options] <source1> <source2> ... <destination>\n");
        return 1;
    }

    // Paksa verbose aktif untuk keperluan debugging/demo saat ini
    // Nanti ini akan diatur secara dinamis oleh options.c
    opts.verbose = true;

    // Argumen paling akhir dipastikan sebagai DESTINATION
    char *dest = argv[argc - 1];

    // Iterasi semua argumen di antara perintah 'mtd' dan 'destination'
    for (int i = 1; i < argc - 1; i++) {
        // Abaikan jika argumen berupa flag (dimulai dengan '-')
        if (argv[i][0] == '-') {
            // Di sini nantinya options.c akan memproses flag seperti -v atau -r
            continue;
        }

        // Panggil mtd_process untuk memindahkan file/folder i ke tujuan
        mtd_process(argv[i], dest, &opts);
    }

    return 0;
}
