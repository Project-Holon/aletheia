/*
 * function: GAME_DATA_CheckSaveFlag
 * address:  0x02012BF8
 * packet:   pkt_02012BF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSaveControlWork  0x02012EC0  thumb
 */

int GAME_DATA_CheckSaveFlag(int a0, int a1){ int t0, t1, t2; t0 = GAME_DATA_GetSaveControlWork(a0); t1 = func_0200C404((int)t0); t2 = func_0200C44C((int)t1, (int)((a1 + 0) + 0)); return t2; }
