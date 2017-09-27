//
// Created by danonofficial on 10.09.17.
//

#ifndef UPDATED_MULTISET_NOFILEERROR_H
#define UPDATED_MULTISET_NOFILEERROR_H

#include <stdexcept>

namespace error {
    class NoFileError : std::exception {
    public:

        explicit NoFileError(std::string msg) noexcept : msg(std::move(msg)) {}

        ~NoFileError()  noexcept override = default;

        const char *what() const noexcept override {
            return msg.c_str();
        }

    private:
        std::string msg;
    };
}
#endif //UPDATED_MULTISET_NOFILEERROR_H
