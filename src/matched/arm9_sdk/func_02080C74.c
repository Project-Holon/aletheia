/*
 * function: GX_GetBankForSubOBJExtPltt
 * address:  0x02080C74
 * packet:   pkt_02080C74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     gx_vramcnt.o GX_GetBankForSubOBJExtPltt.
 *
 * symbols:
 *   gGXState  0x02150E4C  data  a4
 */

#include "../include/G_GX_State.h"

typedef unsigned short u16;

extern struct GX_State gGXState;

u16 GX_GetBankForSubOBJExtPltt(void)
{
    return gGXState.vramCnt_sub_objExtPltt;
}
