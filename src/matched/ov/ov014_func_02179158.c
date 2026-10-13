/*
 * function: WIH_FreeWork
 * address: 0x02179158
 * packet: pkt_ov014_02179158
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data a4
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 */

#include "../include/G_S.h"

typedef unsigned char u8;
extern struct S *g_021797A8;
extern void GFL_NET_FreeAligned(void *);
void WIH_FreeWork(void) {
 if (((u8 *)g_021797A8) != 0) {
 GFL_NET_FreeAligned(*(void **)(((u8 *)g_021797A8) + 0x1E6C));
 GFL_NET_FreeAligned(*(void **)(((u8 *)g_021797A8) + 0x1E68));
 GFL_NET_FreeAligned(((u8 *)g_021797A8));
 g_021797A8 = 0;
 }
}
