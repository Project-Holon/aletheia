/*
 * function: ITEMMENU_AllocPalAnmSlots
 * address: 0x021B8E48
 * packet: pkt_ov070_021B8E48
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 */
#include "../include/Obj04331.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
void ITEMMENU_AllocPalAnmSlots(char *p)
{
    *(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854 = PALANM_Create(((struct Obj04331 *)p)->f544);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 2, 0x200, ((struct Obj04331 *)p)->f544);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 0, 0x20, ((struct Obj04331 *)p)->f544);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj04331 *)p)->f854, 0, 0, 0x20);
}
