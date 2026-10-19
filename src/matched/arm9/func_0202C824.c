/*
 * unit:     no
 * function: WEATHER_IsSeasonSynced
 * address:  0x0202C824
 * packet:   pkt_0202C794
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   COMM_PLAYER_SUPPORT_GetSeasonFromClock  0x0202E888  thumb
 */

int WEATHER_IsSeasonSynced(int a0){ int t0, t1; t0 = GAME_DATA_GetSeason(a0); t1 = COMM_PLAYER_SUPPORT_GetSeasonFromClock((int)t0); if ((unsigned int)((t0 + 0)) == (unsigned int)(t1)) {  return 1; } else {  return 0; } }
