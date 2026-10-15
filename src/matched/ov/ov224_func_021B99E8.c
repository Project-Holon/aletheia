/*
 * function: SUBWAY_MAP_GRAPHIC_DeleteScreen
 * address: 0x021B99E8
 * packet: pkt_ov224_021B99E8
 * region: ov224
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
 *   SUBWAY_MAP_GRAPHIC_DeleteCamera 0x021B9BE8 thumb ov224
 *   SUBWAY_MAP_GRAPHIC_DeleteClactUnit 0x021B9B50 thumb ov224
 *   SUBWAY_MAP_GRAPHIC_DeleteBg 0x021B9ACC thumb ov224
 */
#include "../include/Obj26110.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);
extern void MI_CpuFill8(void *, u32, u32);
extern void GF_FONT_SetDefaultTextColor(void);
extern void SUBWAY_MAP_GRAPHIC_DeleteCamera(u32 *p);
extern void SUBWAY_MAP_GRAPHIC_DeleteClactUnit(char *p);
extern void SUBWAY_MAP_GRAPHIC_DeleteBg(void *);
static inline void G2_BlendNone(void) { *(volatile u16 *)0x04000050 = 0; }
static inline void G2S_BlendNone(void) { *(volatile u16 *)0x04001050 = 0; }
static inline void GX_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0xE000) | (window << 13));
}
static inline void GXS_SetVisibleWnd(int window) {
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0xE000) | (window << 13));
}
void SUBWAY_MAP_GRAPHIC_DeleteScreen(char *p)
{
    func_02030EAC(((struct Obj26110 *)p)->fC);
    SUBWAY_MAP_GRAPHIC_DeleteCamera((u32 *)(p + 8));
    SUBWAY_MAP_GRAPHIC_DeleteClactUnit(p + 4);
    SUBWAY_MAP_GRAPHIC_DeleteBg(p);
    GF_FONT_SetDefaultTextColor();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    MI_CpuFill8(p, 0, 16);
    func_020307B0(p);
}
