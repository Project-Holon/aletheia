/*
 * function: WORLDTRADE_TITLE_Init
 * address: 0x021FFDA8
 * packet: pkt_ov135_021FFDA8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware display control 0x04000304 read and written at 0x021FFDB6..0x021FFDBA.
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WORLDTRADE_TITLE_CreateStrings 0x0220040C thumb ov135
 *   WORLDTRADE_TITLE_SetupBgPlanes 0x021FFF10 thumb ov135
 *   WORLDTRADE_TITLE_LoadBgGraphics 0x0220015C thumb ov135
 *   WORLDTRADE_TITLE_CreateWindows 0x022002A0 thumb ov135
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   WORLDTRADE_TITLE_LoadMainBgSwap 0x02200AB4 thumb ov135
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 *   WORLDTRADE_TITLE_CreateMenuWindow 0x02200BAC thumb ov135
 *   WORLDTRADE_TITLE_CreateActors 0x022001F4 thumb ov135
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 *   WORLDTRADE_TITLE_DrawMenuLabels 0x0220093C thumb ov135
 *   WORLDTRADE_TITLE_SetBgVisible 0x02200130 thumb ov135
 *   WORLDTRADE_SUBLCD_StartAnimTaskA 0x021FF8B0 thumb ov135
 *   WORLDTRADE_SUBLCD_SetSlotActorPositions 0x021FFD44 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotAnims 0x021FFBC8 thumb ov135
 *   func_02040588 0x02040588 arm
 *   func_0207D55C 0x0207D55C arm
 */
#include "../include/Obj00137.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORLDTRADE_TITLE_CreateStrings(u8 *);
extern void WORLDTRADE_TITLE_SetupBgPlanes(void);
extern void WORLDTRADE_TITLE_LoadBgGraphics(u8 *);
extern void WORLDTRADE_TITLE_CreateWindows(u8 *);
extern void WORLDTRADE_TITLE_ScrollBg(u8 *,u32,u32);
extern void WORLDTRADE_TITLE_LoadMainBgSwap(u8 *);
extern void WORLDTRADE_TITLE_LoadSubBgSwap(u8 *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void WORLDTRADE_TITLE_CreateMenuWindow(u8 *,u32);
extern void WORLDTRADE_TITLE_CreateActors(u8 *);
extern void WORLDTRADE_ENTER_RestartNetTimeout(u8 *);
extern void WORLDTRADE_TITLE_DrawMenuLabels(u8 *);
extern void WORLDTRADE_TITLE_SetBgVisible(char *p);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void WORLDTRADE_SUBLCD_StartAnimTaskA(u8 *);
extern int func_0207D55C(volatile u16 *reg);
extern void WORLDTRADE_SUBLCD_SetSlotActorPositions(char *p);
extern void WORLDTRADE_SUBLCD_UpdateSlotAnims(u8 *);
int WORLDTRADE_TITLE_Init(u8 *p)
{
    u32 control;
    WORLDTRADE_TITLE_CreateStrings(p);
    control=*(volatile u16 *)0x04000304;
    control &= ~0x8000;
    *(volatile u16 *)0x04000304=control;
    WORLDTRADE_TITLE_SetupBgPlanes();
    WORLDTRADE_TITLE_LoadBgGraphics(p);
    WORLDTRADE_TITLE_CreateWindows(p);
    WORLDTRADE_TITLE_ScrollBg(p,0,0);
    WORLDTRADE_TITLE_LoadMainBgSwap(p);
    if(((struct Obj00137 *)p)->f30==0) func_02040588(4,0);
    else {WORLDTRADE_TITLE_LoadSubBgSwap(p);func_02040588(4,1);}
    WORLDTRADE_TITLE_CreateMenuWindow(p,0);
    ((struct Obj00137 *)p)->f12E4=0;
    WORLDTRADE_TITLE_CreateActors(p);
    WORLDTRADE_ENTER_RestartNetTimeout(p);
    WORLDTRADE_TITLE_DrawMenuLabels(p);
    if(((struct Obj00137 *)p)->f30==0) {
        WORLDTRADE_TITLE_SetBgVisible((char *)p);
        WIPE_SYS_Start(0,1,1,0,6,1,0x48);
        ((struct Obj00137 *)p)->f28=0;
        ((struct Obj00137 *)p)->f30=1;
        WORLDTRADE_SUBLCD_StartAnimTaskA(p);
    } else {
        if(((struct Obj00137 *)p)->fEB4==1 && func_0207D55C((u16 *)0x0400106C)!=0) {
            WORLDTRADE_SUBLCD_SetSlotActorPositions((char *)p);
            WIPE_SYS_Start(0,1,1,0,6,1,0x48);
        } else WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
        ((struct Obj00137 *)p)->f28=5;
    }
    ((struct Obj00137 *)p)->fEB4=0;
    WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
    return 1;
}
