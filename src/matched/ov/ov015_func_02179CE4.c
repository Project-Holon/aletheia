/*
 * function: func_02179CE4
 * address: 0x02179CE4
 * packet: pkt_ov015_02179CE4
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0217AB80 0x0217AB80 data ov015 a1
 *   d_0217ABA0 0x0217ABA0 data ov015 a1
 *   func_0217A014 0x0217A014 arm ov015
 *   func_0217A5A4 0x0217A5A4 arm ov015
 */

#include "../include/G_s_aba0.h"
#include "../include/G_State.h"

typedef unsigned char u8;
extern struct State d_0217AB80;
extern struct s_aba0 d_0217ABA0;
extern unsigned int func_0217A014(void);
extern unsigned int func_0217A5A4(void);
void func_02179CE4(void) { d_0217AB80.f28 = func_0217A014(); ((u8 *)&d_0217ABA0)[7] = func_0217A5A4(); d_0217AB80.f29 = 1; ((u8 *)&d_0217ABA0)[2] = 0; ((u8 *)&d_0217ABA0)[3] = 14; if (d_0217AB80.f28 != 1) d_0217AB80.f14 = 1; }
