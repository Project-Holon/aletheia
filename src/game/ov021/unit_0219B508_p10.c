/*
 * file:     unit_0219B508_p10.c
 * unit:     yes
 * function: func_0219BFDC, func_0219C000
 * address:  0x0219BFDC
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
 *   d_021D53A0  0x021D53A0  data  a4
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0216DA7C  0x0216DA7C  thumb
 */
#include "../../matched/include/Obj17962.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int (*Step)(u32, u8 *);

extern void *func_0216D69C(void *p);
extern void func_0216D438(char *a0, int a1);
extern u16 func_0216D5F8(void *p);
extern u32 func_0216DA50(u32);
extern u32 func_0216DA7C(u32);
extern int func_02197E7C(int a, int b);
void func_0219BFDC(u32 a);
int func_0219C000(char *a, u32 b, u32 c, u32 d);
extern Step d_021D53A0[];


void func_0219BFDC(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    while (d_021D53A0[p[0]](a, p) == 1) {
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219C000(char *a, u32 b, u32 c, u32 d)
{
func_0216D438(a, (((u32)func_02197E7C((u32)(((u32)func_0216D5F8((void *)a) << 16) >> 16), (u32)0) << 16) >> 16));
func_0216DA50((u32)a);
func_0216DA7C((u32)a);
((struct Obj17962 *)((u8 *)(b)))->f0 = 1;
return 1;
}
