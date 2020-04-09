#include <iostream>
#include "Logger.h"

using namespace std;

LOGLEVEL loglevel = ERROR;

int main() {
    LOGLEVEL loglevel_ = loglevel;
    loglevel = DEBUG;

    log(INFO) << "Info message : " << 1;

    int count = 3;
    log(DEBUG) << "A loop with " << count << " iterations";

    for(int i = 0; i < count; ++i) {
        log(DEBUG) << "the counter i = " << i;
        log(FATAL) << "the counter i = " << i;
    }

    loglevel = loglevel_;
}
