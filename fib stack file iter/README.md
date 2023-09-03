## Explanation

This code only works for GCC versions *TBD*



### Line 1: Line offset
```C
#4294967256
```
This is a [linemarker](https://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html). In this case, it defines the next line number as `4294967256` or `-40` in signed 32-bit int (size of the unsigned int used intermally by the GCC CPP). The value will overflow back to `0` 40 lines down.

### Lines 2 to 10: Line variable assignment
```C
/**
Did you know that one in every bilion comments is important to the 
compilation of a program?... 

This comment is important to the proper execution of the code. It is
in fact a variable assignment. As you may have already noticed, the
number of lines of this multi-line comment coincides with the number 
of fibonacci elements printed on the output. 
*/
```
This comment serves no purpose other than taking space vertically. Practically speaking, it is a variable assignment for the line number.

### Line 11: Initialisation condition
```C
#ifndef stdin
```
This tests if `stdio.h` has been included.

### Lines 12 and 13: `stdio.h` inclusion
```C
#0"stdio.h"3
#include __FILE__ //""
```
This is another linemarker. In this instance, it sets the next line to `0`, the file name to `stdio.h`, and the current file in the file stack as a system header, which disables a few warnings.
The next line just includes `stdio.h`. The comment is there to keep the syntax highlighter of Godbolt happy.

Note: despite the line changing through this linemarker, the iteration condition is not affaceted by this. This is because the program metaprogram is very inefficient and will most probably crash before reaching an pre-overflow corner case.

### Lines 15 to 17: Definition of macro stack primitives

### Lines 19 and 20: Definition of concatenation macros

### Lines 22 and 23: Definition of Church booleans

### Line 25: Definition of a comma encoded base-1 is-one predicate

### Lines 27 and 28: Definition of lazy and strict token dump macros

### Lines 30 to 32: Definition of pre-defined macro short-hands

### Lines 34 to 36: Definition of the `P` token factory
Defined such as `P` changes it's own state through `PP (P)`. Therefore, its first evaluation changes its state from top-state to bottom-state.


### Lines 38 to 40: Definition of the bottom state of variables `A`, `B`, and `C`

### Lines 42 and 43: Incrementation of variables `B` and `C`

### Lines 45 and 46: Definition of the top state of variables `B` and `C`

### Line 48: Incrementation of variable `B`

### Line 49: Closing of the initialisation

### Line 50: Recursion condition

### Line 51: Evaluation of token factory `P`

### Lines 53 to 55: 




## Program execution
Let's evaluate a program step by step, looking solely at macros `A`, `B`, `C`, and `P`. We will have breakpoints at lines 51, 

The previously menti




### Line 14
```C
int main () {}
```
`main` doesn't do anything in this program.

### Lines 16 to 22
```C
#define PCAT(a,b) a##b
#define CAT(x...) PCAT (x)
#define P __attribute__((constructor)) void CAT(f,CN) () {puts (&__func__[1]);} 
#define BF __BASE_FILE__
#define IL __INCLUDE_LEVEL__
#define LN __LINE__
#define CN __COUNTER__
```
`CAT` and `PCAT` are there for the concatenation of the constructor function names.
`P` is a simple constructor function factory.
The other macros are there as shorthands.

### Lines 24 to 26
```C
#define PRAGMA(p) _Pragma(#p)
#define PH(m) PRAGMA (push_macro(#m))
#define PP(m) PRAGMA (pop_macro(#m))
```
Those are the macro stack manipulation operations. `PH` for incrementation. `PP` for decrementations.

### Lines 28 and 29
```C
#define EAT(...)
#define DUMP(xs...) EAT (xs)
```
`DUMP` servers the purpose of evaluation a macro and discarding it's expansion. This is necessairy to evaluate `__COUNTER__` without using it's value.

### Lines 31 and 32
```C
#define IF_(t,f...) f
#define IF_1(t,f...) t
```
Churche booleans.

### Line 34
```C
#define ONEP(x,xs...) IF_##__VA_OPT__(1)
```
Singleton predicate.

### Lines 36 to 49
```C
#define A(...)
#define B(...)
#define C(...)

PH (B)
PH (C)

#undef B
#undef C

#define B(...) PP (B) B (.) __VA_OPT__ (PH (C) PH (A))
#define C(...) PP (C) C (.) __VA_OPT__ (PH (B))

PH (B)
```
This is the initialisation stage of the metaprogram. `A`, `B`, and `C` are variables... sort of. They take a variadic argument list. This is used as a register during the iteration.

Lines 36 to 38 present the definition of the variables when they equal zero. 
Lines 40 and 41 are an incrementation of variables `B` and `C`.
Lines 43 and 44 are the **undefinition** of the of `B` and `C`. Note: This isn't strictly necessairy, since macro redefinition is well-defined by GCC, but it is nicer to look at.
Lines 46 and 47 are the successor states of `B` and `C`.
Line 49 is the incremenation of `B`.

At the end of this section, `A` equals 0, `B` = 2, and `C` = 1.

### Line 51
```C
#if IL <= LN
```
This is the iteration test. This condition compares the current inclusion (`IL`) level with the current line (`LN`). If `IL` is smaller than `LN`, the iteration proceeds
