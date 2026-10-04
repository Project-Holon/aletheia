/*
 * function: func_021BC790
 * address: 0x021BC790
 * packet: pkt_ov210_021BC790
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 */
#include "../include/Obj03370.h"
struct PalAnmSlot;
extern void *func_02021518(unsigned);
extern void func_0202155C(struct PalAnmSlot *,unsigned,unsigned,unsigned);
typedef unsigned int   u32;
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
void func_021BC790(char *p)
{
    ((struct Obj03370 *)p)->fC=func_02021518(123);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,0,512,123);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,1,512,123);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,2,512,123);
    func_0202155C(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,3,512,123);
    func_020216D4((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),0,0,512);
    func_020216D4((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),1,0,512);
    func_020216D4((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),2,0,512);
    func_020216D4((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),3,0,512);
}
