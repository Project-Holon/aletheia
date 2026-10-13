/*
 * function: func_021C07BC
 * address: 0x021C07BC
 * packet: pkt_ov217_021C07BC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 */
#include "../include/Obj03953.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *PALANM_Create(u32);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *, u32, u32, u32);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, u32, u32, u32);
void func_021C07BC(u8 *p)
{
    ((struct Obj03953 *)p)->f3B8 = PALANM_Create(((struct Obj03953 *)p)->f4);
    PALANM_AllocSlotBuffers(((struct Obj03953 *)p)->f3B8, 0, 512, ((struct Obj03953 *)p)->f4);
    PALANM_AllocSlotBuffers(((struct Obj03953 *)p)->f3B8, 2, 512, ((struct Obj03953 *)p)->f4);
    PALANM_CopyHwPaletteToSlot(((struct Obj03953 *)p)->f3B8, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(((struct Obj03953 *)p)->f3B8, 2, 0, 512);
}
