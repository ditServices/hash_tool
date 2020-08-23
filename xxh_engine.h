//
// Created by howard on 23/08/2020.
//

#ifndef COPY_TOOL_XXH_ENGINE_H
#define COPY_TOOL_XXH_ENGINE_H

#include <xxhash.h>
#include "FileHandler.h"

class xxh_engine {
public:
    int calculate_xxh(FileHandler e);
    XXH64_hash_t digest;
};


#endif //COPY_TOOL_XXH_ENGINE_H
