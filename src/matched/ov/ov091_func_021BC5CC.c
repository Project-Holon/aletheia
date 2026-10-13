/*
 * function: PLIST_MENU_ShowItemResult
 * address:  0x021BC5CC
 * packet:   pkt_ov091_021BC5CC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb  ov091
 *   PLIST_MESSAGE_SetWordSetPokemon  0x021BB99C  thumb  ov091
 *   PLIST_MENU_FindItemTarget  0x021BC1D0  thumb  ov091
 *   POKELIST_ShowMessage  0x021B9788  thumb  ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb  ov091
 *   PLIST_MENU_SwitchToNextTarget  0x021BC628  thumb  ov091
 *   POKELIST_EndMessageToExit  0x021B9E3C  thumb  ov091
 */
#include "../include/Obj00009.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetPokemon(int, int, int, int);
extern int PLIST_MENU_FindItemTarget(int);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void PLIST_MENU_SwitchToNextTarget(int);
extern void POKELIST_EndMessageToExit(char *p);

void PLIST_MENU_ShowItemResult(int p)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    PLIST_MESSAGE_CreateWordSet((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    PLIST_MESSAGE_SetWordSetPokemon(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(int *)&((struct Obj00009 *)p)->f38);
    if (PLIST_MENU_FindItemTarget(p) != -1) {
        POKELIST_ShowMessage((u8 *)p, 0x32, 1, (int)PLIST_MENU_SwitchToNextTarget);
    } else {
        POKELIST_ShowMessage((u8 *)p, 0x32, 1, (int)POKELIST_EndMessageToExit);
    }
    PLIST_MESSAGE_DestroyWordSet((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}
