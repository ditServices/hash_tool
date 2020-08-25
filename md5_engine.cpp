//
// Created by howard on 22/08/2020.
//
#include <openssl/md5.h>
#include <cstring>
#include "md5_engine.h"
#include "copytool_errors.h"

int md5_engine::calculate_md5(FileHandler e) {
    FILE *src;
    ssize_t BUFFERSIZE = 512;
    char buf[BUFFERSIZE];
    ssize_t bytes = 0;

    src = fopen(e.get_path().c_str(), "rb");
    if (!src) throw (FileError("File Error\n"));

    MD5_CTX c;
    MD5_Init(&c);

    while ((bytes = fread(buf, 1, BUFFERSIZE, src)) != 0) {
        if (bytes == 0) throw (md5Error("MD5 Error\n"));
        MD5_Update(&c, buf, bytes);
    }

    MD5_Final(this->final, &c);
    fclose(src);

    return 0;
}
