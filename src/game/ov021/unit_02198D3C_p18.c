/*
 * file:     unit_02198D3C_p18.c
 * unit:     yes
 * function: func_0219A75C, func_0219A780
 * address:  0x0219A75C
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
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   d_021D4DB8  0x021D4DB8  data  a4
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 */
#include "../../matched/include/Obj17955.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int (*Step)(u32, u8 *);

extern void *func_0216D69C(void *p);
extern void func_0216D438(char *a0, int a1);
extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
void func_0219A75C(u32 a);
int func_0219A780(char *a, u32 b, u32 c, u32 d);
extern Step d_021D4DB8[];


void func_0219A75C(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D4DB8[(s8)p[2]](a, p) == 1) {
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219A780(char *a, u32 b, u32 c, u32 d)
{
func_0216D438(a, (((u32)func_02197E7C((u32)(((u32)func_0216D5F8((void *)a) << 16) >> 16), (u32)0) << 16) >> 16));
((struct Obj17955 *)((u8 *)(b)))->f2 = 1;
return 1;
}
