/*
 * function: func_02179B24
 * address: 0x02179B24
 * packet: pkt_ov015_02179B24
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0217AB80 0x0217AB80 data ov015 a1
 */

#include "../include/G_State.h"

typedef unsigned char u8;
extern struct State d_0217AB80;
int func_02179B24(void) { if (((u8 *)&d_0217AB80)[0x1c] != 1) return 1; return 0; }
