/*
 * unit:     no
 * function: ISS_CITY_SYS_UpdateSteady
 * address:  0x0202ACFC
 * packet:   pkt_0202ACCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_CITY_SYS_RefreshVolume  0x0202AE68  thumb
 *   ISS_CITY_SYS_ApplyVolume  0x0202AEBC  thumb
 */

int ISS_CITY_SYS_UpdateSteady(int a0){ int t0, t1; t0 = ISS_CITY_SYS_RefreshVolume(a0); if ((unsigned int)(t0) != (unsigned int)(0)) { t1 = ISS_CITY_SYS_ApplyVolume((int)((a0 + 0) + 0)); } else {  return t0; } }
