/*
 * function: func_0202846C
 * address:  0x0202846C
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202846C.c \\
 *       --func func_0202846C --addr 0x0202846C --thumb --cc 1.1p1
 */
#include "../include/Obj15793.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;



u32 func_0202846C(u8 *p)
{
    return ((struct Obj15793 *)p)->fC;
}
