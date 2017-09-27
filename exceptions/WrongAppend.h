//
// Created by danonofficial on 27.09.17.
//

#ifndef UPDATED_MULTISET_WRONGAPPEND_HPP
#define UPDATED_MULTISET_WRONGAPPEND_HPP
#include <stdexcept>

namespace error {
    class WrongAppend : std::exception {
    public:

        explicit WrongAppend(std::string msg) noexcept : msg(std::move(msg)) {}

        ~WrongAppend()  noexcept override = default;

        const char *what() const noexcept override {
            return msg.c_str();
        }

    private:
        std::string msg;
    };
}
#endif //UPDATED_MULTISET_WRONGAPPEND_HPP
