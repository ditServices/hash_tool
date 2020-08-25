//
// Created by howard on 19/08/2020.
//

#ifndef COPY_TOOL_COPYTOOL_ERRORS_H
#define COPY_TOOL_COPYTOOL_ERRORS_H

#include "ErrorHandler.h"

class GeneralError : public ErrorHandler {
    using ErrorHandler::ErrorHandler;
};

class md5Error : public ErrorHandler {
    using  ErrorHandler::ErrorHandler;
};

class xxhError : public ErrorHandler {
    using ErrorHandler::ErrorHandler;
};

class FileError : public ErrorHandler {
    using ErrorHandler::ErrorHandler;
};
#endif //COPY_TOOL_COPYTOOL_ERRORS_H
