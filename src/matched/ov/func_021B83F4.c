/*
 * function: AOSS_FD_SET
 * address:  0x021B83F4
 * packet:   pkt_021B83E8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   AOSS_FD_SET   0x021B83F4  thumb
 *
 * Store a u32 and a constant u16 into a small record, return 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_FD_SET.c \
 *       --func AOSS_FD_SET --addr 0x021B83F4 --region ov016 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj12103.h"

typedef unsigned int u32;
typedef unsigned short u16;

int AOSS_FD_SET(int v, void *rec)
{
    ((struct Obj12103 *)rec)->f0 = v;
    ((struct Obj12103 *)rec)->f4 = 1;
    return 1;
}
