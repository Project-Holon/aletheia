/*
 * function: func_021BB8BC
 * address: 0x021BB8BC
 * packet: pkt_ov093_021BB8BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_02017E1C 0x02017E1C thumb
 *   func_02027268 0x02027268 thumb
 */
#include "../include/Obj13294.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_021D5844(void *);
extern u32 func_02017E1C(void *, u32, u32);
extern void func_02027268(u32);
void func_021BB8BC(u8 *p, u32 *q) {
    func_02017E1C(func_021D5844(q),0x73,((struct Obj13294 *)p)->fAC);
    func_02027268(((struct Obj13294 *)p)->fAC);
}
