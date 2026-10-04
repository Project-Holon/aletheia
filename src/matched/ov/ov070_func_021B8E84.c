/*
 * function: func_021B8E84
 * address: 0x021B8E84
 * packet: pkt_ov070_021B8E84
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 02021540 forwards r0 to the allocator's free; name the pointer here
 * despite its legacy ARM9 thunk definition omitting that argument.
 * symbols:
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 */
#include "../include/Obj09878.h"
typedef unsigned int u32;
struct PalAnmSlot;
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern void func_02021540(void *slots);
void func_021B8E84(char *p)
{
    func_020215A0(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854, 0);
    func_020215A0(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854, 2);
    func_02021540(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854);
}
