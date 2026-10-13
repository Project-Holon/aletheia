/*
 * unit:     no
 * function: FIELD_SOUND_SYSTEM_GetPlayerObjectCode
 * address:  0x02029E58
 * packet:   pkt_02029DD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 */

int FIELD_SOUND_SYSTEM_GetPlayerObjectCode(void *a0){ int t0 = GAME_DATA_GetMyPlayerWork(a0); int t1 = GAME_DATA_GetPlayerObjectCode((int)t0); return t1; }
