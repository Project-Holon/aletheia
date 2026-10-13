/*
 * unit:     no
 * function: TOUCHPANEL_SetTrg
 * address:  0x02035EB0
 * packet:   pkt_02035E84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetWork  0x02035750  arm
 */
#include "../include/Obj11338.h"

int TOUCHPANEL_SetTrg(int a0, int a1, int a2){ int t0; t0 = TOUCHPANEL_GetWork(); ((struct Obj11338 *)((char *)(t0)))->f68 = (unsigned short)a2; ((struct Obj11338 *)((char *)(t0)))->f60 = (unsigned short)a1; return t0; }
