/*
 * unit:     no
 * function: FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent
 * address:  0x02014554
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
#include "../include/Obj06862.h"

int FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(int a0, int a1){ int t0, t1, t2; t0 = func_020122C0((int)a0, (int)0, (int)0x201450D, (int)0x10); t1 = func_020124E8((int)t0); ((struct Obj06862 *)((char *)((t1 + 0))))->f0 = (int)(a0 + 0); ((struct Obj06862 *)((char *)((t1 + 0))))->f4 = (int)(a1 + 0); t2 = GAMESYSTEM_GetGameData((int)((a0 + 0) + 0)); ((struct Obj06862 *)((char *)((t1 + 0))))->f8 = (int)t2; ((struct Obj06862 *)((char *)((t1 + 0))))->fC = (int)0; return ((t0 + 0) + 0); }
