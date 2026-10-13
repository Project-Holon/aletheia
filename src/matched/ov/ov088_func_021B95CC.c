/*
 * function: STARTMENU_TitleDemoUpdateTimer
 * address:  0x021B95CC
 * packet:   pkt_ov088_021B95CC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   ICA_ANIME_GetFrame  0x0201160C  thumb
 *   STARTMENU_Demo3dSetFrame  0x021B9E7C  thumb  ov088
 */
#include "../include/Obj00462.h"

typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
struct Obj11245;
extern u32 ICA_ANIME_GetFrame(struct Obj11245 *p);
extern void STARTMENU_Demo3dSetFrame(int *p, int x);

void STARTMENU_TitleDemoUpdateTimer(char *p)
{
    if (((struct Obj00462 *)p)->f8C == 0x29A) {
        FADE_Start(12, 16, 0, 3);
        BG_SYS_SetLcdSwap(1);
        func_02040588(6, 0);
        BG_SYS_SetSubPlaneVisible(16, 0);
        BG_SYS_SetMainPlaneVisible(8, 0);
        ((struct Obj00462 *)p)->f94 = 1;
    }
    if (((struct Obj00462 *)p)->f94 == 2 && ICA_ANIME_GetFrame((struct Obj11245 *)(((struct Obj00462 *)p)->f4C)) == 0x015F3000)
        STARTMENU_Demo3dSetFrame((int *)(p + 0x40), 0x14B5);
    ((struct Obj00462 *)p)->f8C += 1;
    if (((struct Obj00462 *)p)->f8C > 0x1248) {
        ((struct Obj00462 *)p)->f4 = 1;
        ((struct Obj00462 *)p)->f0 = 5;
    }
}
