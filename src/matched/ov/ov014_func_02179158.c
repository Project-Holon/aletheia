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
 *   gWihWork 0x021797A8 data a4
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 */

#include "../include/G_S.h"

typedef unsigned char u8;
extern struct S *gWihWork;
extern void GFL_NET_FreeAligned(void *);
void WIH_FreeWork(void) {
 if (((u8 *)gWihWork) != 0) {
 GFL_NET_FreeAligned(*(void **)(((u8 *)gWihWork) + 0x1E6C));
 GFL_NET_FreeAligned(*(void **)(((u8 *)gWihWork) + 0x1E68));
 GFL_NET_FreeAligned(((u8 *)gWihWork));
 gWihWork = 0;
 }
}
