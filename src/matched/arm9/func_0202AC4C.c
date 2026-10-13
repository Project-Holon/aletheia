/*
 * unit:     no
 * function: ISS_CITY_SYS_Disable
 * address:  0x0202AC4C
 * packet:   pkt_0202AC00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ISS_CITY_SYS_IsEnabled  0x0202ACC8  thumb
 */
#include "../include/Obj15814.h"

int ISS_CITY_SYS_Disable(int a0){ int t0; t0 = ISS_CITY_SYS_IsEnabled(a0); if ((unsigned int)(t0) != (unsigned int)(0)) { ((struct Obj15814 *)((char *)((a0 + 0))))->f4 = (int)0; return 0; } else { return t0; } }
