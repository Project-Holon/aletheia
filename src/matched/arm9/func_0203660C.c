/*
 * unit:     no
 * function: GFL_NET_RING_BUFF_GetFreeSize
 * address:  0x0203660C
 * packet:   pkt_020363B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_RING_BUFF_GetDataSize  0x020365E8  arm
 */
#include "../include/Obj01465.h"

int GFL_NET_RING_BUFF_GetFreeSize(int a0, int a1, int a2, int a3){ int t0 = GFL_NET_RING_BUFF_GetDataSize((int)a0); return (*(int *)&((struct Obj01465 *)((char *)(a0)))->f4 - t0); }
