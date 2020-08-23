//
// Created by howard on 22/08/2020.
//
#include <openssl/md5.h>
#include <cstring>
#include "md5_engine.h"
#include "copytool_errors.h"

int md5_engine::calculate_md5(FileHandler e) {
    FILE *src;
    char buf[512];
    ssize_t bytes = 0;

    src = fopen(e.get_path().c_str(), "rb");
    if(!src) return -1;

    MD5_CTX c;
    MD5_Init(&c);

    while ((bytes = fread(buf, 1, 512, src)) != 0) {
        MD5_Update(&c, buf, bytes);
    }

    MD5_Final(this->final, &c);
    fclose(src);
    return 0;
}
