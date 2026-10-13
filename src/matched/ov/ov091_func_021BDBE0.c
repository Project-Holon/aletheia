/*
 * function: func_021BDBE0
 * address: 0x021BDBE0
 * packet: pkt_ov091_021BDBE0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02050DB8 0x02050DB8 arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 */
#include "../include/Obj09935.h"
typedef unsigned char u8;
extern void func_02050DB8(u8 *);
extern void GFL_NET_FreeAligned(void *);
void func_021BDBE0(unsigned int p)
{
    func_02050DB8(*(u8 * *)&((struct Obj09935 *)p)->f260);
    GFL_NET_FreeAligned(((struct Obj09935 *)p)->f25C);
}
