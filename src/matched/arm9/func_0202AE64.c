/*
 * function: func_0202AE64
 * address:  0x0202AE64
 * packet:   pkt_0202AE68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_02020F0C.c is now a manifest entry (matched class)
 *
 * Plain field read: the word at 0xc.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202AE64.c \
 *       --func func_0202AE64 --addr 0x0202AE64 --thumb --cc 1.1p1
 */
#include "../include/Obj11306.h"

typedef unsigned char u8;
typedef unsigned int  u32;

u32 func_0202AE64(u8 *p)
{
    return ((struct Obj11306 *)p)->fC;
}
