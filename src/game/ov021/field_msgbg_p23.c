/*
 * file:     field_msgbg_p23.c
 * unit:     yes
 * function: func_0218C530, func_0218C54C, func_0218C574
 * address:  0x0218C530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218BBD0  0x0218BBD0  thumb  ov021
 */
#include "../../matched/include/Obj09173.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int f0;
    int f4;
    short f8;
    short fA;
    int *fC;
} S_0218C54C;

typedef struct {
    int a, b, c;
    int *d;
} S_0218C574;

int func_0218BBD0(int a, int b);
u8 func_0218C530(int a);
void func_0218C54C(S_0218C54C *p, int save);
void func_0218C574(int a, S_0218C574 *s, int b);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u8 func_0218C530(int a)
{
if (*(u32 *)((u8 *)(((struct Obj09173 *)((u8 *)(a)))->fC)) == (~0)) {
    return ((((struct Obj09173 *)((u8 *)(a)))->f4 << 24) >> 24);
}
return ((*(u32 *)((u8 *)(((struct Obj09173 *)((u8 *)(a)))->fC)) << 24) >> 24);
}


void func_0218C54C(S_0218C54C *p, int save)
{
    if (save) {
        *p->fC = p->f4;
        p->f4 = -1;
        p->fA = 1;
    } else {
        p->f4 = *p->fC;
        *p->fC = -1;
        p->fA = 0;
    }
}


void func_0218C574(int a, S_0218C574 *s, int b)
{
    *s->d = func_0218BBD0(a, b);
}
