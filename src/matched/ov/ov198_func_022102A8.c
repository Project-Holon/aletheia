/*
 * function: func_022102A8
 * address:  0x022102A8
 * packet:   pkt_022102A8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25235.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0201F7A8(void *desc, u32 kind);

u32 func_022102A8(u8 *p)
{
    func_0201F7A8((void *)(((struct Obj25235 *)p)->f1F68), 0);
    return 4;
}

