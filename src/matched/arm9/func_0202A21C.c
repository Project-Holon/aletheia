/*
 * unit:     no
 * function: TPOKE_DATA_GetRecordPtr
 * address:  0x0202A21C
 * packet:   pkt_0202A19C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj15812.h"

int TPOKE_DATA_GetRecordPtr(int a0, int a1){ int t0 = func_0200F128((int)(a1 + 0)); return (((struct Obj15812 *)((char *)((a0 + 0))))->f8 + (t0 * 0x1c)); }
