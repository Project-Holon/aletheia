/*
 * function: EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut
 * address:  0x021BEF08
 * packet:   pkt_ov021_021BEF08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FADE_Start  0x0204E720  arm
 *   func_0208068C  0x0208068C  arm
 *   OS_WaitVBlankIntr  0x02087AE4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   SYMBOL_MAP_StartBg2Scale  0x02166B0C  thumb  ov010
 *   sCaptureDispConfig     0x021D9F50  data  ov021  a4
 */
#include "../include/Obj20152.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[4]; } S16;

typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void func_0208068C(u32 a);
extern void OS_WaitVBlankIntr(void);
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void func_0207FDCC(u32 a);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void SYMBOL_MAP_StartBg2Scale(void);
extern S16 sCaptureDispConfig;

int EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut(u32 p0, int *st, u8 *q)
{
    S16 loc;

    if (*st == 0) {
        FADE_Start(((struct Obj20152 *)q)->fC, 0, 0x10, 0x10 - 0x11);
        func_0208068C(8);
        *(volatile u32 *)0x04000064 = 0x80330010;
        OS_WaitVBlankIntr();
        OS_WaitVBlankIntr();
        loc = sCaptureDispConfig;
        BG_SYS_SetGraphicsMode((struct DispConfig *)(&loc));
        *(volatile u16 *)0x0400000C = 0x4084 | (*(volatile u16 *)0x0400000C & 0x43);
        func_0207FDCC(8);
        BG_SYS_SetVisibleLayer(2, 0);
        func_02040588(2, 1);
        SYMBOL_MAP_StartBg2Scale();
        return 1;
    }
    return 0;
}
