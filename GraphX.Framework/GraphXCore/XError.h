#ifndef XERROR_H
#define XERROR_H

#include <string>

namespace GraphX {
	namespace Error {
		class XError {
		public:
			XError(std::string name, std::string message, bool out = false);

			virtual std::string getMessage() const;
		protected:
			std::string mName;
			std::string mMessage;
		};

		class NullPointerError : public XError {
		public:
			NullPointerError(std::string whatIsNull, std::string functionName);
		};

		class InitError : public XError {
		public:
			InitError(std::string reason)
				: XError("GraphXInit", reason, true) {};
		};
	}
}
#endif