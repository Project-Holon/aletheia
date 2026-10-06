/*
 * function: func_021BCA10
 * address:  0x021BCA10
 * packet:   pkt_021BCA10
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25586.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj0202EA20;
extern u32 func_0202EA20(struct Obj0202EA20 *p);

u32 func_021BCA10(u8 *p)
{
    return func_0202EA20((struct Obj0202EA20 *)(((struct Obj25586 *)p)->f2B4));
}

