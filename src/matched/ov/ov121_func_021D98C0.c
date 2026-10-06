/*
 * function: func_021D98C0
 * address: 0x021D98C0
 * packet: pkt_ov121_021D98C0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj13946.h"
typedef unsigned char u8;
struct Bank;
extern void func_0204B084(void *);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *,int,unsigned);
void func_021D98C0(u8 *p) {
    func_0204B084(((struct Obj13946 *)p)->f4);
    func_0204B1CC(((struct Obj13946 *)p)->f0);
    func_0204A5AC();
    func_02082BCC(p,0,8);
}
