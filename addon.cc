// hello.cc
#include <node.h>
#include <memory>
#include <dlfcn.h>
#include <iostream>
#include <unistd.h>
#include "test_project/src/Wrapper.h"
#include "renderer/src/Renderer.h"

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

std::unique_ptr<Wrapper> wrapper;

std::string globalTest;

void hello(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void print(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    std::cout << *v8::String::Utf8Value(args[0]) << globalTest << std::endl;
    globalTest = *v8::String::Utf8Value(args[0]);
}

typedef Wrapper* (*InitProjectFunc)();

void init(Local<Object> exports) {
    initSDLRenderer();

    void* handle = dlopen("test_project/generated/cmake/build/libTestProject.dylib", RTLD_LAZY);
    if (!handle) {
        std::cout << "Could not open the library" << std::endl;
        return;
    }

    InitProjectFunc initProject = reinterpret_cast<InitProjectFunc>(dlsym(handle, "initProject"));
    if (!initProject) {
        std::cout << "Could not find symbol SayHello" << std::endl;
        dlclose(handle);
        return;
    }

    wrapper = std::unique_ptr<Wrapper>(initProject());
    std::cout << wrapper->sum(10,20) << std::endl;

    NODE_SET_METHOD(exports, "hello", hello);
    NODE_SET_METHOD(exports, "print", print);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo
