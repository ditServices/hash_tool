//
// Created by howard on 19/08/2020.
//

#include "FileHandler.h"
#include "copytool_errors.h"
namespace fs = std::filesystem;

FileHandler::FileHandler() = default;

FileHandler::FileHandler(fs::path source_file) {
   if(!fs::is_directory(source_file)) {
       this->size = fs::file_size(source_file);
       this->source_path = std::move(source_file);
   } else {
       throw GeneralError("Error Directory Selected\n");
   }
}

std::filesystem::path FileHandler::get_path() {
    return this->source_path;
}

std::filesystem::path FileHandler::get_filename() {
    return this->source_path.filename();
}

int FileHandler::get_file_size() const {
    return this->size;
}
