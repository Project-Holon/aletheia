/*
 * function: AOSS_FD_ZERO
 * address:  0x021B83E8
 * packet:   pkt_021B83E8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   AOSS_FD_ZERO   0x021B83E8  thumb
 *
 * Clear a u32 and two u16 fields of a small record.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_FD_ZERO.c \
 *       --func AOSS_FD_ZERO --addr 0x021B83E8 --region ov016 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj09184.h"

typedef unsigned int u32;
typedef unsigned short u16;

void AOSS_FD_ZERO(void *rec)
{
    ((struct Obj09184 *)rec)->f0 = 0;
    ((struct Obj09184 *)rec)->f4 = 0;
    ((struct Obj09184 *)rec)->f6 = 0;
}
