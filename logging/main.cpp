#include <iostream>
#include "Logger.h"

using namespace std;

class Foo {
 public:
    Foo() { logInfo << __func__; }
};

int main() {
    logInfo << "Info message : " << 1;

    int count = 3;
    logDebug << "A loop with " << count << " iterations";

    for(int i = 0; i < count; ++i) {
        logError << "the counter i = " << i;
    }

    Foo f;
}
