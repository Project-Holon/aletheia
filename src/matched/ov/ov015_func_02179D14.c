/*
 * function: func_02179D14
 * address: 0x02179D14
 * packet: pkt_ov015_02179D14
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
extern struct s_aba0 d_0217ABA0;
extern struct State d_0217AB80;
extern unsigned int func_0217A014(void);
extern unsigned int func_0217A5A4(void);
void func_02179D14(void) { ((u8 *)&d_0217AB80)[0x1c] = func_0217A014(); ((u8 *)&d_0217ABA0)[7] = func_0217A5A4(); }
