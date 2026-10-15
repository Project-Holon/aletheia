/*
 * function: RESEARCH_LIST_CreatePalAnm
 * address: 0x021BD47C
 * packet: pkt_ov217_021BD47C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing: two alignment bytes at 021BD4CA.
 *
 * symbols:
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb  arm9
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *PALANM_Create(u32);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *, u32, u32, u32);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, u32, u32, u32);
void RESEARCH_LIST_CreatePalAnm(u8 *p)
{
    *(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98 = PALANM_Create(((struct Obj00025 *)p)->f8);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 0, 512, ((struct Obj00025 *)p)->f8);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 2, 512, ((struct Obj00025 *)p)->f8);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00025 *)p)->f98, 2, 0, 512);
}
