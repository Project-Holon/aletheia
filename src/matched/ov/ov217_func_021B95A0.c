/*
 * function: RESEARCH_TOP_InitProc
 * address:  0x021B95A0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_TOP_ResetProc  0x021B985C  thumb  ov217
 *   RESEARCH_TOP_CreateCommon  0x021B9874  thumb  ov217
 *   RESEARCH_TOP_CreateListView  0x021B9894  thumb  ov217
 *   RESEARCH_TOP_InitBackgrounds  0x021B98B8  thumb  ov217
 *   RESEARCH_TOP_LoadSubAssets  0x021B9920  thumb  ov217
 *   RESEARCH_TOP_LoadTopAssets  0x021B9A24  thumb  ov217
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BG_SYS_SetLcdSwap  0x0204363C  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01438.h"
#include "../include/Obj10952.h"
#include "../include/Obj25801.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct DispVram;
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void RESEARCH_TOP_ResetProc(void *p, u32 value);
extern void RESEARCH_TOP_CreateCommon(u32 a0);
extern void RESEARCH_TOP_CreateListView(u32 a0);
extern void RESEARCH_TOP_InitBackgrounds(unsigned short heapId);
extern void RESEARCH_TOP_LoadSubAssets(u32 heap);
extern void RESEARCH_TOP_LoadTopAssets(u32 heap);
u32 RESEARCH_TOP_InitProc(u32 a0, u32 a1, u8 *a2, u32 a3)
{
    switch (((struct Obj10952 *)((u8*)a1))->f0) {
    case 0:
    PROCSYS_AllocProcWork((struct Proc *)a0, 32, 1);
    ((struct Obj10952 *)((u8*)a1))->f0 = (u32)(((struct Obj10952 *)((u8*)a1))->f0 + 1);
    break;
    case 1:
    RESEARCH_TOP_ResetProc((void *)a3, ((struct Obj25801 *)((u8*)a2))->f0);
    BG_SYS_SetVramBanks((const struct DispVram *)0x21C2EA0);
    BG_SYS_SetLcdSwap(0);
    RESEARCH_TOP_InitBackgrounds(((struct Obj01438 *)((u8*)a3))->f0);
    RESEARCH_TOP_LoadTopAssets(((struct Obj01438 *)((u8*)a3))->f0);
    RESEARCH_TOP_LoadSubAssets(((struct Obj01438 *)((u8*)a3))->f0);
    RESEARCH_TOP_CreateCommon(a3);
    RESEARCH_TOP_CreateListView(a3);
    return 1;
    }
    return 0;
}

