/*
 * unit:     no
 * function: ISS_CITY_SYS_GetCurrentUnit
 * address:  0x0202AD78
 * packet:   pkt_0202ACCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_CITY_SYS_GetCurrentUnitIndex  0x0202AD88  thumb
 */
#include "../include/Obj15816.h"

int ISS_CITY_SYS_GetCurrentUnit(int a0){ int t0 = ISS_CITY_SYS_GetCurrentUnitIndex(a0); return *(int *)(((char *)(((struct Obj15816 *)((char *)((a0 + 0))))->f14) + ((int)((t0 << 2)) << 0))); }
