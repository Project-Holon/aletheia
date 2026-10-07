/*
 * function: func_021D7C48
 * address: 0x021D7C48
 * packet: pkt_ov125_021D7C48
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7BCC 0x021D7BCC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   d_021D9E40 0x021D9E40 data a4
 */

#include "../include/G_Clear.h"

extern void func_021D7CAC(void);
extern unsigned func_021D7BCC(void);
extern void func_021D7CC0(void);
extern struct Clear d_021D9E40;
int func_021D7C48(void){func_021D7CAC();if(func_021D7BCC()!=9){func_021D7CC0();return 0;}else{func_021D7CC0();return *(int*)(((char *)&d_021D9E40)+0x250);}}
