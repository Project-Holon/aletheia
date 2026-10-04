/*
 * function: func_021EADF4
 * address: 0x021EADF4
 * packet: pkt_ov093_021EADF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE390 0x021EE390 thumb ov093
 */
#include "../include/Obj21576.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct O;
extern int func_021EE390(struct O *);
int func_021EADF4(u8 *p)
{
    return func_021EE390(*(struct O * *)&((struct Obj21576 *)p)->f17C);
}
