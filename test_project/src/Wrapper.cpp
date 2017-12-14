#include "Wrapper.h"

int Wrapper::sum(int a, int b) {
    return a * b;
}

Wrapper* initProject() {
    return new Wrapper();
}
