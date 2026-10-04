/*
 * function: func_021EADE4
 * address: 0x021EADE4
 * packet: pkt_ov093_021EADE4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE370 0x021EE370 thumb ov093
 */
#include "../include/Obj21575.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct O;
extern void func_021EE370(struct O *);
void func_021EADE4(u8 *p)
{
    func_021EE370(*(struct O * *)&((struct Obj21575 *)p)->f17C);
}
