/*
 * function: KEY_SetRepeatSpeed
 * address:  0x02036270
 * packet:   pkt_02036270
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   KEY_SetRepeatSpeedSys  0x02036254  arm
 */

int KEY_SetRepeatSpeed(int a0, int a1){ int t0, t1; t0 = func_02035224(); t1 = KEY_SetRepeatSpeedSys((int)t0, (int)a0, (int)a1); return t1; }
