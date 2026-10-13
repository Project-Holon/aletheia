/*
 * function: WIH_GetBitmap
 * address: 0x02178E38
 * packet: pkt_ov014_02178E38
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data a4
 */

#include "../include/G_S.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern struct S *gWihWork;
u16 WIH_GetBitmap(void) { return *(u16 *)(((u8 *)gWihWork) + 0x1EAA); }
