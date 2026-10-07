/*
 * function: func_02080C34
 * address:  0x02080C34
 * packet:   pkt_02080C34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     gx_vramcnt.o GX_GetBankForOBJExtPltt.
 *
 * symbols:
 *   gGXState  0x02150E4C  data  a4
 */

#include "../include/G_GX_State.h"

typedef unsigned short u16;

extern struct GX_State gGXState;

u16 func_02080C34(void)
{
    return gGXState.vramCnt_objExtPltt;
}
