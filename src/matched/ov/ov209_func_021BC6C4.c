/*
 * function: ZUKAN_LIST_InitPaletteAnim
 * address: 0x021BC6C4
 * packet: pkt_ov209_021BC6C4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 */
#include "../include/Obj00123.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *PALANM_Create(u32);
struct PalAnmSlot;
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
void ZUKAN_LIST_InitPaletteAnim(char *p)
{
    ((struct Obj00123 *)p)->fC = PALANM_Create(0x6B);
    PALANM_AllocSlotBuffers(((struct Obj00123 *)p)->fC, 0, 0x200, 0x6B);
    PALANM_AllocSlotBuffers(((struct Obj00123 *)p)->fC, 1, 0x200, 0x6B);
    PALANM_AllocSlotBuffers(((struct Obj00123 *)p)->fC, 2, 0x200, 0x6B);
    PALANM_AllocSlotBuffers(((struct Obj00123 *)p)->fC, 3, 0x200, 0x6B);
}
