/*
 * unit:     no
 * function: ISS_CITY_SYS_HasUnitForZone
 * address:  0x0202ADA0
 * packet:   pkt_0202AD8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ISS_CITY_SYS_FindUnitIndex  0x0202ADD8  thumb
 */

int ISS_CITY_SYS_HasUnitForZone(int a0, int a1){ int t0; t0 = ISS_CITY_SYS_FindUnitIndex(a0, a1); if ((unsigned int)(t0) != (unsigned int)(0xff)) {  return 1; } else {  return 0; } }
