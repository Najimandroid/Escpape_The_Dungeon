#pragma once
#include <iostream>

#ifdef _DEBUG
#define LOG(x) std::cout << "[LOG]: " << x << '\n';
#else
#define LOG(x)
#endif
