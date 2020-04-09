#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

enum LOGLEVEL { FATAL, ERROR, WARN, INFO, DEBUG };

class Logger {
  public:
    Logger(LOGLEVEL loglevel_ = ERROR) {
        _buffer << loglevel_ << " : " << std::string (loglevel_ > DEBUG ? (loglevel_ - DEBUG) * 4 : 1, ' ');
    }

    template <typename T>
    Logger & operator << (T const& value) {
        _buffer << value;
        return *this;
    }

    ~Logger() {
        _buffer << std::endl;
        std::cerr << _buffer.str();
    }

  private:
    std::ostringstream _buffer;
};

extern LOGLEVEL loglevel;

#define log(level) \
if(level > loglevel) ; \
else Logger(level)

#endif
