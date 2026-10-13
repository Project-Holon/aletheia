/*
 * function: DOWSING_InitFade
 * address:  0x021F0B74
 * packet:   pkt_ov033_021F0B74
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     func_02030CBC takes (n, mem) (GFL_USE_InitSystem): the 0xB8 result
 *           left in r1 before `blx func_02030CBC` is its second argument.
 *
 * symbols:
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   sDowsingFileName 0x021F0E60 data ov033 a1
 */
#include "../include/Obj01512.h"

extern unsigned func_02030CB0(unsigned);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
struct Obj02021EE4;
struct PalAnmSlot;
extern void *PALANM_Create(u32 heap);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern const char sDowsingFileName[];

void DOWSING_InitFade(char *p)
{
    ((struct Obj01512 *)p)->fB8 = func_02030734(((struct Obj01512 *)p)->f0, func_02030CB0(2), 1, sDowsingFileName, 0x6DF);
    ((struct Obj01512 *)p)->fB4 = func_02030CBC(2, ((struct Obj01512 *)p)->fB8);
    ((struct Obj01512 *)p)->fBC = (unsigned int)PALANM_Create(((struct Obj01512 *)p)->f0);
    PALANM_SetAutoTransfer((struct Obj02021EE4 *)(((struct Obj01512 *)p)->fBC), 1);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 1, 0x60, ((struct Obj01512 *)p)->f0);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 3, 0x80, ((struct Obj01512 *)p)->f0);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 1, 0, 0x60);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 3, 0, 0x80);
    ((struct Obj01512 *)p)->fC0 = 0;
    ((struct Obj01512 *)p)->fC4 = 0;
}
