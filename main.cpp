#include <iostream>
#include "circlelist.h"
using namespace std;

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
    printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
    printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
    passedAssertions++; \
    }
#define assertionReport() { \
    printf("==========================================\n"); \
    printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
    printf("\n"); \
    }
//*******************************************************

int main()
{
    CircleList C;
    C.add("A"); //C.advance();
    C.add("B"); C.advance();
    C.add("C");C.advance();
    C.add("D"); C.advance();
    C.advance();

    expect(C.toString() == "A B C D ");
    return 0;
}
