/*
 * function: func_0219027C
 * address:  0x0219027C
 * packet:   pkt_ov021_0219027C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02192CF0  0x02192CF0  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02192EB8  0x02192EB8  thumb
 */
#include "../include/Obj12600.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02192CF0(void *a, int b);
extern void *func_020056A0(void (*fn)(void *, void *), void *arg, u32 pri);
extern void func_02192EB8(u32 a, u8 *b);

void func_0219027C(u8 *a)
{
    func_02192CF0(a, 0);
    if (((struct Obj12600 *)a)->f16C == 0)
        ((struct Obj12600 *)a)->f16C = func_020056A0((void (*)(void *, void *))func_02192EB8, a, 0);
}
