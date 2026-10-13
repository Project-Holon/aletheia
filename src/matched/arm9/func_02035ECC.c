/*
 * unit:     no
 * function: TOUCHPANEL_SetCont
 * address:  0x02035ECC
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
#include "../include/Obj11339.h"

int TOUCHPANEL_SetCont(int a0, int a1, int a2){ int t0; t0 = TOUCHPANEL_GetWork(); ((struct Obj11339 *)((char *)(t0)))->f6A = (unsigned short)a2; ((struct Obj11339 *)((char *)(t0)))->f62 = (unsigned short)a1; return t0; }
