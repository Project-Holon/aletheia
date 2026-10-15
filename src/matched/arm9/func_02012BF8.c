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
 *   RECENT_ID_LIST_SAVEDATA_GetBlockFromSys  0x0200C404  thumb
 *   RECENT_ID_LIST_SAVEDATA_ContainsId  0x0200C44C  thumb
 */

int GAME_DATA_CheckSaveFlag(int a0, int a1){ int t0, t1, t2; t0 = GAME_DATA_GetSaveControlWork(a0); t1 = RECENT_ID_LIST_SAVEDATA_GetBlockFromSys((int)t0); t2 = RECENT_ID_LIST_SAVEDATA_ContainsId((int)t1, (int)((a1 + 0) + 0)); return t2; }
