/*
 * function: func_021BB8DC
 * address: 0x021BB8DC
 * packet: pkt_ov093_021BB8DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_02017E1C 0x02017E1C thumb
 *   func_020271DC 0x020271DC thumb
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 * evidence: caller narrows func_02017E1C result to u16 before 020271DC.
 */
#include "../include/Obj13295.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D5844(void *);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_020271DC(u16);
extern void func_021BA1B4(u8 *, int);
void func_021BB8DC(u8 *p, u32 *q) {
    func_020271DC(func_02017E1C(func_021D5844(q),5,0));
    func_021BA1B4(*(u8 * *)&((struct Obj13295 *)p)->fC,7);
    func_021BA1B4(*(u8 * *)&((struct Obj13295 *)p)->fC,0x54);
}
