//
// Created by howard on 23/08/2020.
//

#include "xxh_engine.h"
#include "copytool_errors.h"

int xxh_engine::calculate_xxh(FileHandler e) {
    size_t const bufferSize = 512;
    void * const buffer = malloc(bufferSize);
    if(buffer == nullptr) throw(GeneralError());

    XXH64_state_t* const state = XXH64_createState();
    XXH64_hash_t const seed = 0;
    if(XXH64_reset(state, seed)) throw(xxhError());

    FILE *src = fopen(e.get_path().c_str(), "rb");
    if(!src) throw(FileError());

    ssize_t bytes;
    while((bytes = fread(buffer, 1, bufferSize, src)) != 0) {
        if(bytes == 0) throw(xxhError());
        if(XXH64_update(state, buffer, bytes) == XXH_ERROR) return -1;
    }

    this->digest = XXH64_digest(state);
    fclose(src);
    free(buffer);
    return 0;
}
