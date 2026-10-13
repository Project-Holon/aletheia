/*
 * function: func_0203D650
 * address:  0x0203D650
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the word at +0x34c of the net context, or 0 when there is none.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D650.c \
 *       --func func_0203D650 --addr 0x0203D650 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 */
#include "../include/Obj15989.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);

u32 func_0203D650(void)
{
    u8 *p = GFL_NET_GetSession();

    return p != 0 ? ((struct Obj15989 *)p)->f34C : 0;
}
