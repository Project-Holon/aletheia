/*
 * function: func_021BE314
 * address:  0x021BE314
 * packet:   pkt_ov210_021BE314
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:

 * Unlabelled leaf, filed as the witness for func_021BD19C.
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00085.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
u32 func_021BE314(u8 *p, u32 a)
{
    p[0x2ba] = 0;
    ((struct Obj00085 *)p)->f18 = a;
    return 5;
}
