/*
 * function: PLIST_MENU_InitTimer
 * address:  0x021BCCCC
 * packet:   pkt_ov091_021BCCCC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLIST_MENU_CreateBank  0x021BCE84  thumb  ov091
 *   PLIST_MENU_LoadResources  0x021BCEAC  thumb  ov091
 *   PLIST_BATTLE_CreateTeamPanel  0x021BD05C  thumb  ov091
 *   PLIST_BATTLE_CreateTimerWindows  0x021BD59C  thumb  ov091
 */
#include "../include/Obj00047.h"
#include "../include/Obj07737.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern void PLIST_MENU_CreateBank(char *p);
extern void PLIST_MENU_LoadResources(u8 *p);
typedef unsigned int   u32;
extern u32 *PLIST_BATTLE_CreateTeamPanel(u8 *p, u32 *list, u8 x, u8 y, u8 w);
extern void PLIST_BATTLE_CreateTimerWindows(char *p);

void PLIST_MENU_InitTimer(int p)
{
    int r;
    PLIST_MENU_CreateBank((char *)p);
    PLIST_MENU_LoadResources((u8 *)p);
    r = ((struct Obj00047 *)p)->f280;
    if (((struct Obj07737 *)r)->f8C == 1) {
        switch (((struct Obj07737 *)r)->f64) {
        case 1:
            ((struct Obj00047 *)p)->f1F4 = (int)PLIST_BATTLE_CreateTeamPanel((u8 *)p, (u32 *)(r + 0x74), 10, 0, 2);
            break;
        case 2:
            ((struct Obj00047 *)p)->f1F0 = (int)PLIST_BATTLE_CreateTeamPanel((u8 *)p, (u32 *)(r + 0x68), 0, 0, 0);
            ((struct Obj00047 *)p)->f1F4 = (int)PLIST_BATTLE_CreateTeamPanel((u8 *)p, (u32 *)(((struct Obj00047 *)p)->f280 + 0x74), 0xb, 0, 0);
            ((struct Obj00047 *)p)->f1F8 = (int)PLIST_BATTLE_CreateTeamPanel((u8 *)p, (u32 *)(((struct Obj00047 *)p)->f280 + 0x80), 0x16, 0, 0);
            break;
        }
    }
    r = ((struct Obj00047 *)p)->f280;
    ((struct Obj00047 *)p)->f20C = ((struct Obj07737 *)r)->f94;
    ((struct Obj00047 *)p)->f20D = 0;
    if (((struct Obj07737 *)r)->f90 == 1) {
        PLIST_BATTLE_CreateTimerWindows((char *)p);
    }
    ((struct Obj00047 *)p)->f24E = 0;
}
