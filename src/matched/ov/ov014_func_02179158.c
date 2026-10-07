/*
 * function: func_02179158
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
 *   func_0203D7FC 0x0203D7FC arm
 */

#include "../include/G_S.h"

typedef unsigned char u8;
extern struct S *g_021797A8;
extern void func_0203D7FC(void *);
void func_02179158(void) {
 if (((u8 *)g_021797A8) != 0) {
 func_0203D7FC(*(void **)(((u8 *)g_021797A8) + 0x1E6C));
 func_0203D7FC(*(void **)(((u8 *)g_021797A8) + 0x1E68));
 func_0203D7FC(((u8 *)g_021797A8));
 g_021797A8 = 0;
 }
}
