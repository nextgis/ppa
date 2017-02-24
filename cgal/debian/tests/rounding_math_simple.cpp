#include <fenv.h>
#include <stdio.h>

double stop_constant_propagation(double x)
{
    // asm volatile ("" : "+mx"(x)); return x;
    asm volatile ("" : "=m"(x) : "m"(x)); return x;
    // volatile double y = x; return y;   
}

double force_to_double(double x)
{
#if defined __i386__ || defined __ia64__
    // asm volatile ("" : "+mx"(x)); return x;
    asm volatile ("" : "=m"(x) : "m"(x)); return x;
    // volatile double y = x; return y;   
#else
    return x;
#endif       
}

int main()
{
    fesetround(FE_UPWARD);
    double lhs = -force_to_double((-1.1) * stop_constant_propagation(10.1));
    double rhs =  force_to_double(( 1.1) * stop_constant_propagation(10.1));
    printf( "%s\n", lhs != rhs ? "lhs != rhs (correct)" : "lhs == rhs (error)");
    return lhs != rhs ? 0 : 1;
}
