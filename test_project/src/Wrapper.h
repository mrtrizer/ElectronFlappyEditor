#pragma once

class Wrapper
{
public:
    Wrapper() = default;
    virtual ~Wrapper() = default;

    virtual int sum(int a, int b);
};

extern "C"
{
    Wrapper* initProject();
}
