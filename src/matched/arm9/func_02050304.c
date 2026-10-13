/*
 * unit:     no
 * function: BILLBOARD_ACT_DeleteSlot
 * address:  0x02050304
 * packet:   pkt_02050304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   AREAMAN_Free  0x0203422C  arm
 *   BILLBOARD_ACT_InitSlot  0x02050088  arm
 */
#include "../include/Obj08868.h"

int BILLBOARD_ACT_DeleteSlot(int a0, int a1){ int t0 = BILLBOARD_ACT_InitSlot((int)(*(int *)&((struct Obj08868 *)((char *)(a0)))->fC + (a1 << 3))); int t1 = AREAMAN_Free((int)((struct Obj08868 *)((char *)(a0)))->f14, (int)a1, (int)1); return t1; }
