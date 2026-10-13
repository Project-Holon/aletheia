/*
 * function: WIH_GetSysState
 * address: 0x02178E4C
 * packet: pkt_ov014_02178E4C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data a4
 */

#include "../include/G_S.h"

typedef unsigned char u8;
extern struct S *g_021797A8;
int WIH_GetSysState(void) { if (((u8 *)g_021797A8) == 0) return 0; return *(int *)(((u8 *)g_021797A8) + 0x1E70); }
