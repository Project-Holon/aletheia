/*
 * function: func_021F4614
 * address:  0x021F4614
 * packet:   pkt_021F4614
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14507.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef void (*fn_021F4614_t)(u8 *, u8 *, u32);

void func_021F4614(u8 *p)
{
    if (((struct Obj14507 *)p)->f4 == 0) {
        ((fn_021F4614_t)*(void **)p)(p, p + 8, ((struct Obj14507 *)p)->fC);
    }
}

