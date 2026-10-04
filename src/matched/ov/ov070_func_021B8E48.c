/*
 * function: func_021B8E48
 * address: 0x021B8E48
 * packet: pkt_ov070_021B8E48
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 */
#include "../include/Obj04331.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
void func_021B8E48(char *p)
{
    *(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854 = func_02021518(((struct Obj04331 *)p)->f544);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 2, 0x200, ((struct Obj04331 *)p)->f544);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 0, 0x20, ((struct Obj04331 *)p)->f544);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 0, 0, 0x20);
}
