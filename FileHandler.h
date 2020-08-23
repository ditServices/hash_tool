//
// Created by howard on 19/08/2020.
//

#ifndef COPY_TOOL_FILEHANDLER_H
#define COPY_TOOL_FILEHANDLER_H

#include <filesystem>

class FileHandler {
public:
    FileHandler();
    FileHandler(std::filesystem::path source_file);
    std::filesystem::path get_path();
    std::filesystem::path get_filename();
    [[nodiscard]] int get_file_size() const;
protected:
    std::filesystem::path source_path;
    int size = 0;
};




#endif //COPY_TOOL_FILEHANDLER_H
