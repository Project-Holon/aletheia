/*
 * function: func_021D7808
 * address: 0x021D7808
 * packet: pkt_ov125_021D7808
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   func_021D7F60 0x021D7F60 arm ov125
 *   func_021D7C90 0x021D7C90 arm ov125
 *   func_021D858C 0x021D858C arm ov125
 */

#include "../include/G_Clear.h"

extern struct Clear d_021D9E40;
extern void func_021D7F60(void);
extern void func_021D7C90(int);
extern void func_021D858C(void);
void func_021D7808(void) {
 func_021D7F60();
 if(((int *)&d_021D9E40)[0x258/4]) {
  func_021D7C90(((int *)&d_021D9E40)[0x258/4]);
  ((int *)&d_021D9E40)[0x258/4]=0;
 }
 ((int *)&d_021D9E40)[0x244/4]=15;
 ((int *)&d_021D9E40)[0x248/4]=30;
 ((int *)&d_021D9E40)[0x24c/4]=30;
 ((int *)&d_021D9E40)[0x254/4]=0;
 ((int *)&d_021D9E40)[0x25c/4]=0;
 ((int *)&d_021D9E40)[0x260/4]=0;
 ((int *)&d_021D9E40)[0x264/4]=0;
 ((int *)&d_021D9E40)[0x268/4]=0;
 ((int *)&d_021D9E40)[0x13c/4]=1;
 ((int *)&d_021D9E40)[0x250/4]=0;
 func_021D858C();
}
