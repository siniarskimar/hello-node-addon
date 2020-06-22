#include <nan.h>

using namespace Nan;
using namespace v8;


NAN_METHOD(Hello) {
	info.GetReturnValue().Set(Nan::New<v8::String>("hello world").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
	v8::Local<v8::Context> context = exports->CreationContext();
	exports->Set(context,
		Nan::New<v8::String>("callMe").ToLocalChecked(),
		Nan::New<v8::FunctionTemplate>(Hello)
			->GetFunction(context).ToLocalChecked());
}

NODE_MODULE(hello, Init);