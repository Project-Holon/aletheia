/*
 * function: func_021BE110
 * address:  0x021BE110
 * packet:   pkt_021BE110
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE8B8  0x021BE8B8  thumb  ov210
 *   func_021BF85C  0x021BF85C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00222.h"
#include "../include/Obj25605.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BE8B8(u8 *);
extern void func_021BF85C(char *p, int i, int flag);

void func_021BE110(u8 *p)
{
    u32 t = *(u32 *)&((struct Obj00222 *)p)->f0;
    *(u8 *)(((struct Obj25605 *)t)->f8 + 1) = 0;
    func_021BE8B8(p);
    func_021BF85C((char *)p, 0, 1);
}

