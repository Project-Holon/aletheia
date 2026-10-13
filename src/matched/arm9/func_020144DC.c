/*
 * unit:     no
 * function: FIELD_STATUS_CreateFieldCloseEvent
 * address:  0x020144DC
 * packet:   pkt_02014488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 */
#include "../include/Obj06860.h"

int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1){ int t0, t1, t2; t0 = func_020122C0((int)a0, (int)0, (int)0x2014489, (int)0x10); t1 = func_020124E8((int)t0); ((struct Obj06860 *)((char *)((t1 + 0))))->f0 = (int)(a0 + 0); ((struct Obj06860 *)((char *)((t1 + 0))))->f4 = (int)(a1 + 0); t2 = GAMESYSTEM_GetGameData((int)((a0 + 0) + 0)); ((struct Obj06860 *)((char *)((t1 + 0))))->f8 = (int)t2; ((struct Obj06860 *)((char *)((t1 + 0))))->fC = (int)1; return ((t0 + 0) + 0); }
