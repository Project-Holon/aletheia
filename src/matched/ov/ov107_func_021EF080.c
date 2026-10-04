/*
 * function: func_021EF080
 * address: 0x021EF080
 * packet: pkt_ov107_021EF080
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
#include "../include/Obj00979.h"
struct Bank;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020403F4(unsigned);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
void func_021EF080(char *p) {
 func_0204B3B4(((struct Obj00979 *)p)->f7C);
 func_0204B1CC(((struct Obj00979 *)p)->f6C);
 func_0204A5AC();
 func_020403F4(0);func_020403F4(1);func_020403F4(2);func_020403F4(3);
 func_020403F4(7);func_020403F4(6);func_020403F4(5);func_020403F4(4);
 func_020450C8();func_0203F9B4();
}
