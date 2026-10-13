/*
 * function: func_021D9890
 * address: 0x021D9890
 * packet: pkt_ov129_021D9890
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 */
#include "../include/Obj02483.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
typedef signed int     s32;
struct PalAnmSlot;
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
void func_021D9890(char *p)
{
    void *pal=((struct Obj02483 *)p)->f290;
    void *arc=((struct Obj02483 *)p)->f258;
    func_02049658(arc,6,1,0,0,0,50);
    func_020498F4(arc,10,1,0,0,0,50);
    PALANM_LoadArcPaletteToSlot(pal,59,1,50,0,64,0);
    func_02049658(arc,7,5,0,0,0,50);
    func_020498F4(arc,11,5,0,0,0,50);
    func_02049B68(arc,2,4,0,0,50);
    ((struct Obj02483 *)p)->f260=func_0204ABF0(arc,0,0,0,50);
    ((struct Obj02483 *)p)->f26C=func_0204A6C8(arc,5,0,0,50);
    ((struct Obj02483 *)p)->f284=func_0204AF28(arc,12,15,50);
    ((struct Obj02483 *)p)->f268=func_0204ABF0(arc,4,0,32,50);
    ((struct Obj02483 *)p)->f274=func_0204A6C8(arc,9,0,0,50);
    ((struct Obj02483 *)p)->f28C=func_0204AF28(arc,14,17,50);
    ((struct Obj02483 *)p)->f264=func_0204ABF0(arc,3,0,64,50);
    ((struct Obj02483 *)p)->f270=func_0204A6C8(arc,8,0,0,50);
    ((struct Obj02483 *)p)->f288=func_0204AF28(arc,13,16,50);
    func_0201F5BC(4,1,11,0,50);
    func_02049B40(23,5,4,384,32,50);
}
