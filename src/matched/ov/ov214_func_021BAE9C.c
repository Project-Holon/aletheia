/*
 * function: func_021BAE9C
 * address: 0x021BAE9C
 * packet: pkt_ov214_021BAE9C
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   site 0x021BB658 data ov214
 */
#include "../include/Obj00182.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
struct Ctx;
struct Obj02021EE4;
struct PalAnmSlot;
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *PALANM_Create(u32);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern const char site[];
void func_021BAE9C(int unused,char *p)
{
    ((struct Obj00182 *)p)->f2DC=func_02030734(((struct Obj00182 *)p)->f0,func_02030CB0(2),1,site,2403);
    ((struct Obj00182 *)p)->f2D8=func_02030CBC(2,((struct Obj00182 *)p)->f2DC);
    ((struct Obj00182 *)p)->f2E0=PALANM_Create(((struct Obj00182 *)p)->f0);
    PALANM_SetAutoTransfer(((struct Obj00182 *)p)->f2E0,1);
    PALANM_AllocSlotBuffers(((struct Obj00182 *)p)->f2E0,0,448,((struct Obj00182 *)p)->f0);
    PALANM_AllocSlotBuffers(((struct Obj00182 *)p)->f2E0,2,448,((struct Obj00182 *)p)->f0);
    PALANM_CopyHwPaletteToSlot(((struct Obj00182 *)p)->f2E0,0,0,448);
    PALANM_CopyHwPaletteToSlot(((struct Obj00182 *)p)->f2E0,2,0,448);
    ((struct Obj00182 *)p)->f2E8=2;
    ((struct Obj00182 *)p)->f2E4=0;
}
