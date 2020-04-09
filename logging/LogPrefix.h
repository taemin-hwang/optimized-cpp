#ifndef _LOGLEVEL_H_
#define _LOGLEVEL_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

enum class LOGLEVEL : int { FATAL = 0, ERROR, WARN, INFO, DEBUG };

class LogPrefix {
public:
    LogPrefix(LOGLEVEL loglevel_ = LOGLEVEL::FATAL) {
        if(loglevel_ == LOGLEVEL::FATAL) {
            message = "[FATAL] ";
        } else if(loglevel_ == LOGLEVEL::ERROR) {
            message = "[ERROR] ";
        } else if(loglevel_ == LOGLEVEL::WARN) {
            message = "[WARN ] ";
        } else if(loglevel_ == LOGLEVEL::INFO) {
            message = "[INFO ] ";
        } else {
            message = "[DEBUG] ";
        }
    }

    inline std::string GetMessage() { return message; }

private:
    std::string message = "[FATAL] ";
};

#endif

