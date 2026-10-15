/*
 * function: WORLDTRADE_BOX_Init
 * address: 0x021F5154
 * packet: pkt_ov135_021F5154
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword 04000304 read at 021F5162 before masked write.
 * symbols:
 *   WORLDTRADE_BOX_CreateStrings 0x021F5980 thumb ov135
 *   WORLDTRADE_BOX_SetupBgPlanes 0x021F5250 thumb ov135
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   WORLDTRADE_BOX_LoadBgGraphics 0x021F5374 thumb ov135
 *   WORLDTRADE_BOX_CreateWindows 0x021F57EC thumb ov135
 *   WORLDTRADE_BOX_CreateActors 0x021F5420 thumb ov135
 *   WORLDTRADE_SUBLCD_SetSlotActorPositions 0x021FFD44 thumb ov135
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   WORLDTRADE_BOX_LoadBoxIcons 0x021F68A4 thumb ov135
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj10575.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORLDTRADE_BOX_CreateStrings(u8 *);
extern void WORLDTRADE_BOX_SetupBgPlanes(void);
extern void WORLDTRADE_TITLE_ScrollBg(u8 *, u32, u32);
extern void WORLDTRADE_BOX_LoadBgGraphics(u8 *);
extern void WORLDTRADE_BOX_CreateWindows(u8 *);
extern void WORLDTRADE_BOX_CreateActors(u8 *);
extern void WORLDTRADE_SUBLCD_SetSlotActorPositions(char *p);
extern int GXx_GetMasterBrightness_(volatile u16 *reg);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern void WORLDTRADE_BOX_LoadBoxIcons(u8 *, int);
extern void WORLDTRADE_ENTER_RestartNetTimeout(u8 *);
int WORLDTRADE_BOX_Init(u8 *p)
{
    WORLDTRADE_BOX_CreateStrings(p);
    *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
    WORLDTRADE_BOX_SetupBgPlanes();
    WORLDTRADE_TITLE_ScrollBg(p, 0, 0);
    WORLDTRADE_BOX_LoadBgGraphics(p);
    WORLDTRADE_BOX_CreateWindows(p);
    WORLDTRADE_BOX_CreateActors(p);
    WORLDTRADE_SUBLCD_SetSlotActorPositions((char *)p);
    if (GXx_GetMasterBrightness_((u16 *)0x0400106c) == 0) {
        WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
    } else {
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x48);
    }
    WORLDTRADE_BOX_LoadBoxIcons(p, ((struct Obj10575 *)p)->fC4);
    WORLDTRADE_ENTER_RestartNetTimeout(p);
    ((struct Obj10575 *)p)->f28 = 0;
    ((struct Obj10575 *)p)->f12E4 = 0;
    return 1;
}
