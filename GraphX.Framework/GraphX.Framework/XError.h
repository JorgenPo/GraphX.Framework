#ifndef XERROR_H
#define XERROR_H

#include <string>

namespace GraphX {
	namespace Error {
		class IError {
		public:
			IError(string name, string message, bool out = false);

			virtual std::string getMessage() const;
		protected:
			std::string mName;
			std::string mMessage;
		};

		class NullPointerError : public IError {
			NullPointerError() 
				: IError("NullPointerError", "trying to work with nullptr") {};
		};

		class InitError : public IError {
			InitError(string reason)
				: IError("GraphXInit", reason) {};
		};
	}
}
#endif