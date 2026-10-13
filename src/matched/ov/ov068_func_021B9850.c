/*
 * function: OPTION_MENU_InitScreen
 * address:  0x021B9850
 * packet:   pkt_ov068_021B9850
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   func_0204363C  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   OPTION_MENU_InitGfx  0x021B9980  thumb
 *   OPTION_MENU_InitSprites  0x021B9E28  thumb
 *   OPTION_MENU_ScreenTaskMain  0x021B996C  thumb
 *   func_020056A0  0x020056A0  thumb
 *   gOptionMenuDispVram     0x021BB598  data  a4
 */
#include "../include/Obj20634.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02082BCC(void *p, u32 a, u32 b);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32 v);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void OPTION_MENU_InitGfx(void *p, u32 a);
extern void OPTION_MENU_InitSprites(int *p, void *res, u32 heap);
extern void OPTION_MENU_ScreenTaskMain(void *task, char *p);
extern u32 func_020056A0(void (*fn)(void), void *arg, u32 z);
extern int gOptionMenuDispVram[];

void OPTION_MENU_InitScreen(u8 *p, u32 a)
{
    func_02082BCC(p, 0, 0xd4);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)gOptionMenuDispVram);
    func_0204363C(0);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    GF_FONT_SetTextColor(0xf, 0xe, 0);
    OPTION_MENU_InitGfx(p, a);
    OPTION_MENU_InitSprites((int *)(p + 0x7c), gOptionMenuDispVram, a);
    ((struct Obj20634 *)p)->fD0 = func_020056A0((void (*)(void))OPTION_MENU_ScreenTaskMain, p, 0);
}
