/*
 * file:     unit_0219B508_p12.c
 * unit:     yes
 * function: func_0219C080, func_0219C0AC, func_0219C0D4
 * address:  0x0219C080
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0216DA7C  0x0216DA7C  thumb
 *   func_0216D684  0x0216D684  thumb  ov010
 */
#include "../../matched/include/Obj17964.h"
#include "../../matched/include/Obj17965.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_0216D438(char *a0, int a1);
extern u16 func_0216D608(void *p);
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern int func_02197E7C(int a, int b);
extern u32 func_0216DA50(u32);
extern u32 func_0216DA7C(u32);
extern u32 func_02197EDC(u8 *p);
extern void *func_0216D684(int a0, int a1, u32 a2, u32 a3);
int func_0219C080(char *a, u32 b, u32 c, u32 d);
int func_0219C0AC(u32 a, u32 b, u32 c, u32 d);
void func_0219C0D4(u32 a, u32 b, u32 c, u32 a3);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219C080(char *a, u32 b, u32 c, u32 d)
{
func_0216D438(a, (((u32)func_02197E7C((u32)func_0216D608(func_0216DEE0((void *)func_0216D67C((void *)a))), (u32)0) << 16) >> 16));
((struct Obj17964 *)((u8 *)(b)))->f0 = 4;
return 1;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219C0AC(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 0) {
    return 0;
}
func_0216DA50(a);
func_0216DA7C(a);
((struct Obj17965 *)((u8 *)(b)))->f0 = 2;
return 0;
}


void func_0219C0D4(u32 a, u32 b, u32 c, u32 a3)
{
    u32 *p = func_0216D684(a, 12, c, a3);
    p[1] = b;
    p[2] = c;
}
