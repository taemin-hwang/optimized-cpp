#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include "LogPrefix.h"

using namespace std;

LOGLEVEL loglevel = LOGLEVEL::DEBUG;

class Logger {
  public:
    Logger(LOGLEVEL level) {
        _logprefix = LogPrefix(level);
        _buffer << _logprefix.GetMessage() << " ";
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
    LogPrefix _logprefix;
};

#define log(level) \
if(level > loglevel) ; \
else Logger(level)

#define logFatal \
if(LOGLEVEL::FATAL > loglevel) ; \
else Logger(LOGLEVEL::FATAL)

#define logError \
if(LOGLEVEL::ERROR > loglevel) ; \
else Logger(LOGLEVEL::ERROR)

#define logWarn \
if(LOGLEVEL::WARN > loglevel) ; \
else Logger(LOGLEVEL::WARN)

#define logInfo \
if(LOGLEVEL::INFO > loglevel) ; \
else Logger(LOGLEVEL::INFO)

#define logDebug \
if(LOGLEVEL::DEBUG > loglevel) ; \
else Logger(LOGLEVEL::DEBUG)

#endif
