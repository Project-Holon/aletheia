/*
 * unit:     no
 * function: WEATHER_StoreZoneWeatherId
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
 *   GAME_DATA_SetWeatherId  0x020129A0  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   WEATHER_GetZoneWeatherId  0x0202C794  thumb
 */

int WEATHER_StoreZoneWeatherId(int a0, int a1){ int t0 = GAMESYSTEM_GetGameData(a0); int t1 = WEATHER_GetZoneWeatherId((int)((a0 + 0) + 0), (int)((a1 + 0) + 0)); int t2 = GAME_DATA_SetWeatherId((int)((t0 + 0) + 0), (int)((unsigned int)(((t1 + 0) << 0x18)) >> 0x18)); return t2; }
