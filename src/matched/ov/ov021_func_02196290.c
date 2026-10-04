/*
 * function: func_02196290
 * address:  0x02196290
 * packet:   pkt_ov021_02196290
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202F038  0x0202F038  thumb
 *   func_0202EE8C  0x0202EE8C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void func_0202F038(u8 *p);
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);

void func_02196290(u8 *a)
{
    if (((struct Obj00094 *)a)->f2E8 != 0) {
        func_0202F038((u8 *)(((struct Obj00094 *)a)->f2E8));
        ((struct Obj00094 *)a)->f2E8 = 0;
    }
    ((struct Obj00094 *)a)->f2E8 = (u32)func_0202EE8C(((struct Obj00094 *)a)->f2B8, (void *)(*(u32 *)&((struct Obj00094 *)a)->f2B0), 15, 16, ((struct Obj00094 *)a)->f10);
}
