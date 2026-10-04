/*
 * function: func_021BD47C
 * address: 0x021BD47C
 * packet: pkt_ov217_021BD47C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing: two alignment bytes at 021BD4CA.
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *func_02021518(u32);
extern void func_0202155C(struct PalAnmSlot *, u32, u32, u32);
extern void func_020216D4(struct PalAnmSlot *, u32, u32, u32);
void func_021BD47C(u8 *p)
{
    *(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98 = func_02021518(((struct Obj00025 *)p)->f8);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 0, 512, ((struct Obj00025 *)p)->f8);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 2, 512, ((struct Obj00025 *)p)->f8);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 0, 0, 512);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 2, 0, 512);
}
