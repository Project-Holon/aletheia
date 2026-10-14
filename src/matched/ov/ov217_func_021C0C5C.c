/*
 * function: RESEARCH_COMMON_AllocSlotBuffers
 * address: 0x021C0C5C
 * packet: pkt_ov217_021C0C5C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 */
#include "../include/Obj00791.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *, u32, u32, u32);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, u32, u32, u32);
void RESEARCH_COMMON_AllocSlotBuffers(u8 *p)
{
    struct PalAnmSlot *slots = *(struct PalAnmSlot * *)&((struct Obj00791 *)p)->f28;
    PALANM_AllocSlotBuffers(slots, 0, 512, ((struct Obj00791 *)p)->f0);
    PALANM_AllocSlotBuffers(slots, 2, 512, ((struct Obj00791 *)p)->f0);
    PALANM_AllocSlotBuffers(slots, 1, 512, ((struct Obj00791 *)p)->f0);
    PALANM_AllocSlotBuffers(slots, 3, 512, ((struct Obj00791 *)p)->f0);
    PALANM_CopyHwPaletteToSlot(slots, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(slots, 2, 0, 512);
    PALANM_CopyHwPaletteToSlot(slots, 1, 0, 512);
    PALANM_CopyHwPaletteToSlot(slots, 3, 0, 512);
}
