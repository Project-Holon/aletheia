/*
 * function: ZKNSEARCH_MAIN_InitPaletteAnim
 * address: 0x021BC790
 * packet: pkt_ov210_021BC790
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 */
#include "../include/Obj03370.h"
struct PalAnmSlot;
extern void *PALANM_Create(unsigned);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *,unsigned,unsigned,unsigned);
typedef unsigned int   u32;
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
void ZKNSEARCH_MAIN_InitPaletteAnim(char *p)
{
    ((struct Obj03370 *)p)->fC=PALANM_Create(123);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,0,512,123);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,1,512,123);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,2,512,123);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj03370 *)p)->fC,3,512,123);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),0,0,512);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),1,0,512);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),2,0,512);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(*(unsigned *)&((struct Obj03370 *)p)->fC),3,0,512);
}
