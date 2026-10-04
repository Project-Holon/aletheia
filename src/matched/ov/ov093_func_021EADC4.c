/*
 * function: func_021EADC4
 * address: 0x021EADC4
 * packet: pkt_ov093_021EADC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE2F8 0x021EE2F8 thumb ov093
 */
#include "../include/Obj21573.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct O;
extern void func_021EE2F8(struct O *);
void func_021EADC4(u8 *p)
{
    func_021EE2F8(*(struct O * *)&((struct Obj21573 *)p)->f17C);
}
