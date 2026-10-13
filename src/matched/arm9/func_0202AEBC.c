/*
 * function: ISS_CITY_SYS_ApplyVolume
 * address:  0x0202AEBC
 * packet:   pkt_0202AEBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   ISS_CITY_SYS_CalcOutputVolume  0x0202AED0  thumb
 */

int ISS_CITY_SYS_ApplyVolume(int a0){ int t0, t1; t0 = ISS_CITY_SYS_CalcOutputVolume(a0); t1 = GFL_USE_SetBgmTrackVolume((int)(3 << 8), (int)(t0 + 0)); return t1; }
