/*
 * function: THE_END_GRAPHIC_Create
 * address: 0x021B98E4
 * packet: pkt_ov182_021B98E4
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 04000050/04001050 writes and 04000000/04001000 read/write 021B990C-021B9922.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   THE_END_GRAPHIC_InitWindows 0x021B9A10 thumb ov182
 *   THE_END_GRAPHIC_InitActors 0x021B9AB4 thumb ov182
 *   THE_END_GRAPHIC_InitCamera 0x021B9B20 thumb ov182
 *   func_020056A0 0x020056A0 thumb
 *   THE_END_GRAPHIC_VBlankTask 0x021B99FC thumb ov182
 *   d_021B9CE0 0x021B9CE0 data a1
 *   d_021B9C48 0x021B9C48 data a4
 */
#include "../include/Obj24514.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021B9CE0[];
extern const u32 d_021B9C48[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void THE_END_GRAPHIC_InitWindows(void *, int);
extern void THE_END_GRAPHIC_InitActors(int *, int, int);
extern void THE_END_GRAPHIC_InitCamera(int *p, u16 heap);
extern void THE_END_GRAPHIC_VBlankTask(int, char *);
extern void *func_020056A0(void (*)(int, char *), void *, int);
char *THE_END_GRAPHIC_Create(int a, u16 heap)
{
    char *p;
    p = func_02030734(heap, 0x10, 0, d_021B9CE0, 0x1cc);
    MI_CpuFill8(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= ~0xe000;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B9C48);
    BG_SYS_SetLcdSwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    THE_END_GRAPHIC_InitWindows(p, heap);
    THE_END_GRAPHIC_InitActors((int *)(p + 4), (int)d_021B9C48, heap);
    THE_END_GRAPHIC_InitCamera((int *)(p + 8), heap);
    ((struct Obj24514 *)p)->fC = func_020056A0(THE_END_GRAPHIC_VBlankTask, p, 0);
    return p;
}
