/*
 * function: NAMEIN_GRAPHIC_CreateDisplay
 * address: 0x021F4AE4
 * packet: pkt_ov194_021F4AE4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 0x04000050, 0x04001050, 0x04000000, 0x04001000.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   NAMEIN_GRAPHIC_InitBg 0x021F4C0C thumb ov194
 *   NAMEIN_GRAPHIC_InitClact 0x021F4CB0 thumb ov194
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   d_021F5784 0x021F5784 data a1
 *   d_021F55D0 0x021F55D0 data a4
 *   NAMEIN_GRAPHIC_DisplayMainTask 0x021F4BF8 thumb ov194
 */
#include "../include/Obj24926.h"
struct DispVram;
extern const char d_021F5784[];
extern const struct DispVram d_021F55D0;
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BMP_SetDisplaySwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void NAMEIN_GRAPHIC_InitBg(void *, unsigned short);
extern void NAMEIN_GRAPHIC_InitClact(unsigned char *, int, int);
extern void *GFL_USE_AddMainTask(unsigned, unsigned, unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void NAMEIN_GRAPHIC_DisplayMainTask(u32 a, u8 *b);
static inline void G2_BlendNone(void) { *(volatile unsigned short *)0x04000050 = 0; }
static inline void G2S_BlendNone(void) { *(volatile unsigned short *)0x04001050 = 0; }
static inline void GX_SetVisibleWnd(int window) { *(volatile unsigned *)0x04000000 = (*(volatile unsigned *)0x04000000 & ~0xE000) | (window << 13); }
static inline void GXS_SetVisibleWnd(int window) { *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xE000) | (window << 13); }
unsigned char *NAMEIN_GRAPHIC_CreateDisplay(unsigned swap, unsigned short heap)
{
    unsigned char *p;
    p = func_02030734(heap, 0x10, 0, d_021F5784, 0x1BB);
    MI_CpuFill8(p, 0, 0x10);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021F55D0);
    BMP_SetDisplaySwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    NAMEIN_GRAPHIC_InitBg(p, heap);
    NAMEIN_GRAPHIC_InitClact(p + 4, (int)&d_021F55D0, heap);
    ((struct Obj24926 *)p)->fC = GFL_USE_AddMainTask((unsigned)NAMEIN_GRAPHIC_DisplayMainTask, (unsigned)p, 0);
    return p;
}
