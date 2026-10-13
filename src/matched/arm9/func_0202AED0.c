/*
 * unit:     no
 * function: ISS_CITY_SYS_CalcOutputVolume
 * address:  0x0202AED0
 * packet:   pkt_0202AEBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ISS_CITY_SYS_GetFadeLevel  0x0202AE04  thumb
 *   ISS_CITY_SYS_GetVolume  0x0202AE64  thumb
 */

int ISS_CITY_SYS_CalcOutputVolume(int a0, int a1, int a2, int a3){ int t0 = ISS_CITY_SYS_GetVolume(a0); int t1 = ISS_CITY_SYS_GetFadeLevel((int)((a0 + 0) + 0)); int t2 = func_0209C0A4((int)((t0 + 0) * t1), (int)0x7f); return t2; }
