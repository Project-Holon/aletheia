/*
 * function: func_0218F0E8
 * address:  0x0218F0E8
 * packet:   pkt_ov021_0218F0E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj01653.h"
#include "../include/Obj19569.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

u32 func_0218F0E8(u8 *a)
{
    u8 *p = *(u8 * *)&((struct Obj01653 *)a)->fEC;
    if (p == 0)
        return 0;
    return ((struct Obj19569 *)p)->f28;
}
