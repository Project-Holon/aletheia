/*
 * function: func_0216D92C
 * address:  0x0216D92C
 * packet:   pkt_ov010_0216D92C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: widens three signed bytes at p + 0x7e..0x80 to fixed
 * point (<< 12) and stores them into q[0..2].
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09334.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

void func_0216D92C(u8 *p, s32 *q)
{
    q[0] = ((struct Obj09334 *)p)->f7E << 12;
    q[1] = ((struct Obj09334 *)p)->f7F << 12;
    q[2] = ((struct Obj09334 *)p)->f80 << 12;
}
