/*
 * function: func_021BCC1C
 * address:  0x021BCC1C
 * packet:   pkt_021BCC1C
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
#include "../include/Obj25587.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);

u32 func_021BCC1C(u8 *p)
{
    return func_020307B0((void *)(((struct Obj25587 *)p)->f2BC));
}

