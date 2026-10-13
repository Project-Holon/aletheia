/*
 * unit:     no
 * function: GFL_NET_StartChangeoverParent
 * address:  0x0203D10C
 * packet:   pkt_0203D0DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_STATE_StartChangeover  0x0203BA98  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 */
#include "../include/Obj15980.h"

int GFL_NET_StartChangeoverParent(int a0){ int t0 = GFL_NET_GetSession(); int t1 = GFL_NET_STATE_StartChangeover((int)((struct Obj15980 *)((char *)(t0)))->f56, (int)a0, (int)0); return t1; }
