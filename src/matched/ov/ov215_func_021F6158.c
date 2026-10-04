/*
 * function: func_021F6158
 * address: 0x021F6158
 * packet: pkt_ov215_021F6158
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020310C4 0x020310C4 arm
 */
#include "../include/Obj25747.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
void func_021F6158(void *unused, char *p)
{
    func_020310C4(((struct Obj25747 *)p)->f54);
}
