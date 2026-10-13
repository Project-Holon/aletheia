/*
 * unit:     no
 * function: BTL_SETUP_SetPlayerParty
 * address:  0x0201333C
 * packet:   pkt_02013284
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 */
#include "../include/Obj00155.h"

int BTL_SETUP_SetPlayerParty(int a0, int a1, int a2){ int t0, t1, t2, t3; t0 = GAME_DATA_GetMyPlayerWork((int)((a1 + 0) + 0)); t1 = func_0201A920((int)((a2 + 0) + 0)); *(int *)&((struct Obj00155 *)((char *)((a0 + 0))))->f24 = (int)t1; t2 = GAME_DATA_GetMyParty((int)((a1 + 0) + 0)); t3 = func_0201AC2C((int)t2, (int)*(int *)&((struct Obj00155 *)((char *)((a0 + 0))))->f24); return t3; }
