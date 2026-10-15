/*
 * function: MANUAL_GRAPHIC_DeleteScreen
 * address: 0x021B99A0
 * packet: pkt_ov225_021B99A0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 0x04000050 0x04001050 0x04000000 0x04001000
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   MANUAL_GRAPHIC_DeleteClactUnit 0x021B9B0C thumb ov225
 *   MANUAL_GRAPHIC_DeleteBg 0x021B9A88 thumb ov225
 */
#include "../include/Obj26130.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);
extern void MI_CpuFill8(void *, u32, u32);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MANUAL_GRAPHIC_DeleteClactUnit(char *p);
extern void MANUAL_GRAPHIC_DeleteBg(void *);
static inline void G2_BlendNone(void) { *(volatile u16 *)0x04000050 = 0; }
static inline void G2S_BlendNone(void) { *(volatile u16 *)0x04001050 = 0; }
static inline void GX_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0xE000) | (window << 13));
}
static inline void GXS_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0xE000) | (window << 13));
}
void MANUAL_GRAPHIC_DeleteScreen(char *p)
{
    func_02030EAC(((struct Obj26130 *)p)->fC);
    MANUAL_GRAPHIC_DeleteClactUnit(p + 4);
    MANUAL_GRAPHIC_DeleteBg(p);
    GF_FONT_SetDefaultTextColor();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    MI_CpuFill8(p, 0, 16);
    func_020307B0(p);
}
