/*
 * file:     weather_task_p58.c
 * unit:     yes
 * function: func_021A53BC, func_021A53D0
 * address:  0x021A53BC
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
 *   func_021A5318  0x021A5318  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 */
#include "../../matched/include/Obj09569.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_021A5318(u32 *p, u32 m);
void *func_021A3960(unsigned char *p);
u16 func_0216D5F8(void *p);
void *func_0216D4B4(char *p);
void func_0216D5E0(int a0, int a1);
void func_0216D674(void *p, u16 v);
void func_021A3964(u8 *p, u32 v);
int func_021A53BC(u32 a);
void func_021A53D0(u32 *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A53BC(u32 a)
{
if (func_021A5318((u32 *)a, 16) != 0) {
    return 1;
}
return 0;
}


void func_021A53D0(u32 *p)
{
    void *h;
    int v;

    if (p[0] == 3) {
        h = func_021A3960(*(unsigned char * *)&((struct Obj09569 *)p)->fC);
        v = func_0216D5F8(h);
        func_0216D4B4(h);
        func_0216D5E0((int)h, v);
        func_0216D674(h, 0);
        func_021A3964((u8 *)p[3], 0);
    }
}
