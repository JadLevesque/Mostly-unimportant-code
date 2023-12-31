#4294967257
/**
Did you know that one in every billion comments is important to the 
compilation of a program?... 

This comment is important to the proper execution of the code. It is
in fact a variable assignment. As you may have already noticed, the
number of lines of this multi-line comment coincides with the number 
of Fibonacci elements printed on the output. 
*/
#ifndef stdin
    #0"stdio.h"3
    #include __FILE__ //""

    #define PRAGMA(p) _Pragma(#p)
    #define PH(m) PRAGMA (push_macro(#m))
    #define PP(m) PRAGMA (pop_macro(#m))

    #define PCAT(a,b) a##b
    #define CAT(x...) PCAT (x)

    #define IF_(t,f...) f
    #define IF_1(t,f...) t
    
    #define ONEP(x,xs...) IF_##__VA_OPT__(1)
    
    #define EAT(...)
    #define DUMP(xs...) EAT (xs)

    #define IL __INCLUDE_LEVEL__
    #define LN __LINE__
    #define CN __COUNTER__
    
    #define P __attribute__((constructor)) void CAT (f, CN) () {puts (&__func__[1]);} 
    PH (P)
    #define P PP (P) int main () {DUMP (CN)}

    #define A(...) 
    #define B(...)
    #define C(...)

    PH (B)
    PH (C)

    #define B(...) PP (B) B (.) __VA_OPT__ (PH (C) PH (A))
    #define C(...) PP (C) C (.) __VA_OPT__ (PH (B))

    PH (B)
#endif
#if IL <= LN
    P

    A ()
    PH (A)
    #define A(xs...) PP (A) A (.,##xs) __VA_OPT__ (PH (C) ONEP (xs) (DUMP (CN)))

    B ()
    PH (B)
    #define B(...) PP (B) B (.) __VA_OPT__ (PH (C) PH (A))

    C ()
    PH (C)
    #define C(...) PP (C) C (.) __VA_OPT__ (PH (B))

    #include __BASE_FILE__ //""
#endif
