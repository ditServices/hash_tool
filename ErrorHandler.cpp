//
// Created by howard on 19/08/2020.
//

#include "ErrorHandler.h"

#include <utility>

ErrorHandler::ErrorHandler(const char * e) {
    this->error = e;
}

const char *ErrorHandler::what() const noexcept {
    return this->error;
}

ErrorHandler::ErrorHandler() {
    this->error = "ERROR: Unhandled Exception";
}

