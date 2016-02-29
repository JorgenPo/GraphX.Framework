#include "XError.h"
#include <iostream>

namespace GraphX {
	namespace Error {
		using namespace std;

		XError::XError(std::string name, std::string message, bool out)
			:mName(name), mMessage(message)
		{
			if (out) {
				std::cerr << getMessage().c_str() << std::endl;
			}
		}

		string XError::getMessage() const
		{
			return mName + ": " + mMessage;
		}

		NullPointerError::NullPointerError(std::string whatIsNull, std::string functionName)
			: XError("NullPointerError", "trying to work with nullpt", true)
		{
			std::string message = whatIsNull 
				+ " was null in function \"" + functionName + "\"";
			mMessage = message;
		}
	}
}
