/*
 * function: func_02179024
 * address: 0x02179024
 * packet: pkt_ov014_02179024
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data a4
 *   func_02178138 0x02178138 thumb ov014
 *   WIH_PickRandomChannel 0x02179050 thumb ov014
 */

#include "../include/G_S.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern struct S *g_021797A8;
extern void func_02178138(int);
extern int WIH_PickRandomChannel(u16);
u16 func_02179024(void) {
 func_02178138(1);
 *(u16 *)(((u8 *)g_021797A8) + 0x1EAC) = WIH_PickRandomChannel(*(u16 *)(((u8 *)g_021797A8) + 0x1EB0));
 return *(u16 *)(((u8 *)g_021797A8) + 0x1EAC);
}
