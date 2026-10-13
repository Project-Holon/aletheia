/*
 * unit:     no
 * function: GAME_DATA_GetPlayTime
 * address:  0x02012FCC
 * packet:   pkt_02012F08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int GAME_DATA_GetPlayTime(int p0){ return *(int *)((p0 + (0x6AC << 0))); }
