/*
 * unit:     no
 * function: ISS_SWITCH_ApplySubscreenMode
 * address:  0x0202C83C
 * packet:   pkt_0202C794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_SetSubscreenMode  0x020129A0  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   ISS_SWITCH_GetSubscreenMode  0x0202C794  thumb
 */

int ISS_SWITCH_ApplySubscreenMode(int a0, int a1){ int t0 = GAMESYSTEM_GetGameData(a0); int t1 = ISS_SWITCH_GetSubscreenMode((int)((a0 + 0) + 0), (int)((a1 + 0) + 0)); int t2 = GAME_DATA_SetSubscreenMode((int)((t0 + 0) + 0), (int)((unsigned int)(((t1 + 0) << 0x18)) >> 0x18)); return t2; }
