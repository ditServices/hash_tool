//
// Created by howard on 22/08/2020.
//

#ifndef COPY_TOOL_MD5_ENGINE_H
#define COPY_TOOL_MD5_ENGINE_H

#include "FileHandler.h"
#include <openssl/md5.h>

class md5_engine {
public:
   int calculate_md5(FileHandler e);
   unsigned char final[MD5_DIGEST_LENGTH];
};


#endif //COPY_TOOL_MD5_ENGINE_H
