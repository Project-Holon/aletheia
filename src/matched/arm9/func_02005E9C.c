/*
 * function: GFL_USE_PopBgm
 * address:  0x02005E9C
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_StopBgm  0x02005D14  thumb
 *   GFL_USE_FlushBgmChange  0x02005FBC  thumb
 */

int GFL_USE_PopBgm(void){ int t0, t1, t2, t3; t0 = GFL_USE_FlushBgmChange(); t1 = func_02005900((int)t0); if ((unsigned int)(t1) != (unsigned int)(0)) { t2 = GFL_USE_StopBgm((int)t1); t3 = func_02005A4C((int)t2); return t3; } else { return t1; } }
