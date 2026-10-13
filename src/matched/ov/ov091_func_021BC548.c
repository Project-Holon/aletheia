/*
 * function: PLIST_MENU_ShowHpRestored
 * address:  0x021BC548
 * packet:   pkt_ov091_021BC548
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLIST_PLATE_GetHp  0x021BB464  thumb  ov091
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb  ov091
 *   PLIST_MESSAGE_SetWordSetPokemon  0x021BB99C  thumb  ov091
 *   PLIST_MESSAGE_SetWordSetNumber  0x021BB9EC  thumb  ov091
 *   POKELIST_ShowMessage  0x021B9788  thumb  ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb  ov091
 *   POKELIST_CheckItemUsable  0x021B9E44  thumb  ov091
 */
#include "../include/Obj03682.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern unsigned short PLIST_PLATE_GetHp(int unused, unsigned short *p);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetPokemon(int, int, int, int);
extern void PLIST_MESSAGE_SetWordSetNumber(int a, int b, int c, int d, unsigned char e);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void POKELIST_CheckItemUsable(u8 *p);

void PLIST_MENU_ShowHpRestored(int p)
{
    u16 h;
    u16 v;
    h = PLIST_PLATE_GetHp(p, (short unsigned int *)(*(int *)(p + ((struct Obj03682 *)p)->f2C * 4 + 0x160)));
    *(int *)(((struct Obj03682 *)p)->f280 + 0x40) = 10;
    PLIST_MESSAGE_CreateWordSet((u16 *)p, ((struct Obj03682 *)p)->f150);
    PLIST_MESSAGE_SetWordSetPokemon(p, ((struct Obj03682 *)p)->f150, 0, ((struct Obj03682 *)p)->f38);
    v = ((struct Obj03682 *)p)->f11C;
    if (v != 0) {
        PLIST_MESSAGE_SetWordSetNumber(p, ((struct Obj03682 *)p)->f150, 1, (u16)(h - v), (int)3);
        POKELIST_ShowMessage((u8 *)p, 0x2c, 1, (int)POKELIST_CheckItemUsable);
    } else {
        POKELIST_ShowMessage((u8 *)p, 0x32, 1, (int)POKELIST_CheckItemUsable);
    }
    PLIST_MESSAGE_DestroyWordSet((void *)p, ((struct Obj03682 *)p)->f150);
}
