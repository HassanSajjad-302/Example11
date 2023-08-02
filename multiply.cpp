module;
export module division;
import <iostream>;

#ifdef MULTIPLY
export void printMultiply(unsigned int a, unsigned int b)
{
    std::cout << a * b << std::endl;
}

#endif