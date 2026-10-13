/*
 * function: IRCBATTLEMATCH_BlendBgPalette
 * address:  0x021B95F0
 * packet:   pkt_ov100_021B95F0
 * region:   ov100
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: the calls to PALANM_GetTransWork (site +0050) and PALANM_Delete
 *          (site +0084) have no witness outside this function's range.
 *          Both are unlabelled Thumb leaves in the ARM9 image, so neither
 *          `label` nor `sole-ref/code` can attest them; each call is their
 *          only referrer image-wide.  Every other byte is correct.
 * symbols:
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   PALANM_BlendChannel  0x02021FD8  thumb
 *   PALANM_GetTransWork  0x02021730  thumb
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 */
#include "../include/Obj13704.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Chan02021FD8;
struct PalAnmSlot;
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *p, int i);
extern void DWCi_ScreenDC_FlushRange(int, int);
extern void func_0207E5D0(int, int, int);
extern void func_0207E468(int, int, int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);

int IRCBATTLEMATCH_BlendBgPalette(int a, int b, int c)
{
    int r4;
    int t;
    int r7;

    r4 = (int)PALANM_Create(((struct Obj13704 *)a)->f278);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)r4, b, 0x200, ((struct Obj13704 *)a)->f278);
    t = c << 5;
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)r4, b, 0, t);
    PALANM_BlendChannel((struct Chan02021FD8 *)r4, b, 0, (u16)(c << 4), 6, 0);
    r7 = PALANM_GetTransWork((char *)r4, b);
    DWCi_ScreenDC_FlushRange(r7, t);
    if (b != 1) {
        if (b == 3)
            func_0207E5D0(r7, 0, t);
    } else {
        func_0207E468(r7, 0, t);
    }
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)r4, b);
    return PALANM_Delete((void *)r4);
}
