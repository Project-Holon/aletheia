/*
 * unit: yes
 * function: func_021EAE24, func_021EAE34
 * address: 0x021EAE24
 * packet: pkt_ov093_021EAE24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE23C 0x021EE23C thumb ov093
 *   func_021EE25C 0x021EE25C thumb ov093
 */
#include "../../../matched/include/Obj21577.h"
#include "../../../matched/include/Obj21578.h"
typedef unsigned char u8;
struct Q;
extern void func_021EE23C(struct Q *q);
extern int func_021EE25C(void *);
void func_021EAE24(u8 *p)
{
    func_021EE23C(((struct Obj21577 *)p)->f17C);
}
int func_021EAE34(u8 *p)
{
    return func_021EE25C(((struct Obj21578 *)p)->f17C);
}
