/*
 * function: IRCBATTLEMENU_FadePaletteBank
 * address:  0x021961A4
 * packet:   pkt_ov021_021961A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   PALANM_BlendChannel  0x02021FD8  thumb
 *   PALANM_GetTransWork  0x02021730  thumb
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 */
#include "../include/Obj12628.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Chan02021FD8;
struct PalAnmSlot;
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *p, int i);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207E5D0(void *p, u32 a, u32 size);
extern void func_0207E468(void *p, u32 a, u32 size);

void IRCBATTLEMENU_FadePaletteBank(u8 *p, u32 a, u32 b)
{
    u32 h;
    u32 n;
    void *d;

    h = (u32)PALANM_Create(((struct Obj12628 *)p)->f10);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)h, a, 0x200, ((struct Obj12628 *)p)->f10);
    n = b << 5;
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)h, a, 0, n);
    PALANM_BlendChannel((struct Chan02021FD8 *)h, a, 0, (b << 20) >> 16, 6, 0);
    d = (void *)PALANM_GetTransWork((char *)h, a);
    DC_FlushRange(d, n);
    if (a != 1) {
        if (a == 3)
            func_0207E5D0(d, 0, n);
    } else {
        func_0207E468(d, 0, n);
    }
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)h, a);
    PALANM_Delete((void *)h);
}
