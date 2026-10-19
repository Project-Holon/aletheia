/*
 * function: SHINKA_DEMO_GRAPHIC_Create
 * address:  0x022058F8
 * packet:   pkt_022058F8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208F50 0x02208F50 data a4
 *   d_02208CEC 0x02208CEC data a4
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   SHINKA_DEMO_GRAPHIC_SetupMainBg 0x02205AC0 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_InitClact 0x02205B6C thumb ov195
 *   SHINKA_DEMO_GRAPHIC_Init3d 0x02205BDC thumb ov195
 *   SHINKA_DEMO_GRAPHIC_VBlank 0x02205AAC thumb ov195
 *   func_020056A0 0x020056A0 thumb
 */
#include "../include/Obj24951.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 d_02208F50[];
extern u32 d_02208CEC[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void MI_CpuFill8(void *, int, int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void SHINKA_DEMO_GRAPHIC_SetupMainBg(void *a, void *b);
extern void SHINKA_DEMO_GRAPHIC_InitClact(unsigned char *p, int a, u32 b);
extern void SHINKA_DEMO_GRAPHIC_Init3d(u32 *a, void *b);
extern void SHINKA_DEMO_GRAPHIC_VBlank(int a, char *b);
extern u32 func_020056A0(void *, void *, int);

char *SHINKA_DEMO_GRAPHIC_Create(u32 a, u32 b)
{
    char *p = func_02030734(b, 0x10, 0, (const char *)d_02208F50, 0x1df);

    MI_CpuFill8(p, 0, 0x10);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_02208CEC);
    BG_SYS_SetLcdSwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    SHINKA_DEMO_GRAPHIC_SetupMainBg(p, (void *)b);
    SHINKA_DEMO_GRAPHIC_InitClact((unsigned char *)(p + 4), (int)d_02208CEC, b);
    SHINKA_DEMO_GRAPHIC_Init3d((u32 *)(p + 8), (void *)b);
    ((struct Obj24951 *)p)->fC = func_020056A0(SHINKA_DEMO_GRAPHIC_VBlank, p, 0);
    return p;
}
