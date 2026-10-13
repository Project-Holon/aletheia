/*
 * unit:     no
 * function: RINGTONE_SYS_StopRing
 * address:  0x0202A01C
 * packet:   pkt_02029F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 */
#include "../include/Obj15806.h"

int RINGTONE_SYS_StopRing(int a0){ int t0; t0 = GFL_USE_StopSeSlot((int)4); ((struct Obj15806 *)((char *)((a0 + 0))))->f4 = (unsigned short)0; return 0; }
