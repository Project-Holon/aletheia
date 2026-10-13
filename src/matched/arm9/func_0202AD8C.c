/*
 * unit:     no
 * function: ISS_CITY_SYS_HasCurrentUnit
 * address:  0x0202AD8C
 * packet:   pkt_0202AD8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ISS_CITY_SYS_GetCurrentUnitIndex  0x0202AD88  thumb
 */

int ISS_CITY_SYS_HasCurrentUnit(int a0){ int t0; t0 = ISS_CITY_SYS_GetCurrentUnitIndex(a0); if ((unsigned int)(t0) != (unsigned int)(0xff)) {  return 1; } else {  return 0; } }
