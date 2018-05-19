#pragma once

#include <cassert>
#include <exception>
#include <iostream>

#ifndef __cpp_lib_uncaught_exceptions
#if __cplusplus >= 201703L
#define __cpp_lib_uncaught_exceptions
#endif
#endif

namespace sqlite {
	namespace utility {
#ifdef __cpp_lib_uncaught_exceptions
		class UncaughtExceptionDetector {
		public:
			operator bool() {
				return count != std::uncaught_exceptions();
			}
		private:
			int count = std::uncaught_exceptions();
		};
#else
		class UncaughtExceptionDetector {
		public:
			operator bool() {
				return std::uncaught_exception();
			}
		};
#endif
	}
}
