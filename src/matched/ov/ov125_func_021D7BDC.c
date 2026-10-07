/*
 * function: func_021D7BDC
 * address: 0x021D7BDC
 * packet: pkt_ov125_021D7BDC
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7BCC 0x021D7BCC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   d_021D9E40 0x021D9E40 data a4
 */

#include "../include/G_Clear.h"

extern void func_021D7CAC(void); extern unsigned int func_021D7BCC(void); extern void func_021D7CC0(void); extern struct Clear d_021D9E40;
char *func_021D7BDC(void) {func_021D7CAC(); if(func_021D7BCC()!=8){func_021D7CC0();return 0;} func_021D7CC0();return *(char **)(((char *)&d_021D9E40)+0x260)+4;}
