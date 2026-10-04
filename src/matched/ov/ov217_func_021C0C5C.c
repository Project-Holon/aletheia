/*
 * function: func_021C0C5C
 * address: 0x021C0C5C
 * packet: pkt_ov217_021C0C5C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 */
#include "../include/Obj00791.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void func_0202155C(struct PalAnmSlot *, u32, u32, u32);
extern void func_020216D4(struct PalAnmSlot *, u32, u32, u32);
void func_021C0C5C(u8 *p)
{
    struct PalAnmSlot *slots = *(struct PalAnmSlot * *)&((struct Obj00791 *)p)->f28;
    func_0202155C(slots, 0, 512, ((struct Obj00791 *)p)->f0);
    func_0202155C(slots, 2, 512, ((struct Obj00791 *)p)->f0);
    func_0202155C(slots, 1, 512, ((struct Obj00791 *)p)->f0);
    func_0202155C(slots, 3, 512, ((struct Obj00791 *)p)->f0);
    func_020216D4(slots, 0, 0, 512);
    func_020216D4(slots, 2, 0, 512);
    func_020216D4(slots, 1, 0, 512);
    func_020216D4(slots, 3, 0, 512);
}
