/*
 * unit:     no
 * function: ISS_CITY_SYS_SelectUnitForZone
 * address:  0x0202ADB4
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
 *   ISS_CITY_SYS_FindUnitIndex  0x0202ADD8  thumb
 */
#include "../include/Obj15817.h"

int ISS_CITY_SYS_SelectUnitForZone(int a0, int a1){ int t0, t1; t0 = ISS_CITY_SYS_GetCurrentUnitIndex(a0); t1 = ISS_CITY_SYS_FindUnitIndex((int)((a0 + 0) + 0), (int)((a1 + 0) + 0)); if ((unsigned int)((t0 + 0)) == (unsigned int)(t1)) {  return 0; } else { ((struct Obj15817 *)((char *)((a0 + 0))))->f19 = (unsigned char)t1; return 1; } }
