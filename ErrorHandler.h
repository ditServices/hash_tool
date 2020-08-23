//
// Created by howard on 19/08/2020.
//

#ifndef ERR_EXAMPLE_ERRORHANDLER_H
#define ERR_EXAMPLE_ERRORHANDLER_H


#include <string>
#include <exception>

class ErrorHandler : public std::exception {
public:
    explicit ErrorHandler(const char * e);
    ErrorHandler();
    [[nodiscard]] const char * what() const noexcept override;
private:
   const char * error;
};


#endif //ERR_EXAMPLE_ERRORHANDLER_H
