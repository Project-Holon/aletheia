/*
 * unit:     yes
 * function: POKELIST_ShowHealResult, POKELIST_OpenTakeMailMenu
 * address:  0x021BA318
 * packet:   pkt_ov091_021BA318
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_PLATE_GetHp  0x021BB464  thumb ov091
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb ov091
 *   PLIST_MESSAGE_SetWordSetPokemon  0x021BB99C  thumb ov091
 *   PLIST_MESSAGE_SetWordSetNumber  0x021BB9EC  thumb ov091
 *   POKELIST_ShowMessage  0x021B9788  thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb ov091
 *   POKELIST_EndMessageToList  0x021B9E20  thumb ov091
 *   POKELIST_OpenChoiceMenu  0x021B9804  thumb ov091
 *   POKELIST_OnTakeMailChoice  0x021BA3A4  thumb ov091
 */
#include "../include/Obj13244.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern u16  PLIST_PLATE_GetHp(int unused, u16 *q);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetPokemon(int a, int b, int c, int d);
extern void PLIST_MESSAGE_SetWordSetNumber(int a, int b, int c, int d, unsigned char e);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void POKELIST_EndMessageToList(u8 *p);
extern void POKELIST_OpenChoiceMenu(u8 *p, int a1);
extern void POKELIST_OnTakeMailChoice(u8 *p, u32 state);

void POKELIST_ShowHealResult(u8 *p)
{
    u16 r;
    u16 t;

    r = PLIST_PLATE_GetHp((int)p, (u16 *)((u32 *)(p + 0x160))[((u32 *)W(0x280))[0x3c / 4]]);
    W(0x2c) = ((u32 *)W(0x280))[0x3c / 4];
    PLIST_MESSAGE_CreateWordSet((u16 *)p, W(0x150));
    PLIST_MESSAGE_SetWordSetPokemon((int)p, W(0x150), 0, W(0x38));
    t = ((struct Obj13244 *)p)->f11C;
    if (t) {
        PLIST_MESSAGE_SetWordSetNumber((int)p, (u32)W(0x150), (u32)1, (u16)(r - t), 3);
        POKELIST_ShowMessage(p, 0x2c, 1, (int)POKELIST_EndMessageToList);
    }
    PLIST_MESSAGE_DestroyWordSet(p, W(0x150));
}

void POKELIST_OpenTakeMailMenu(u8 *p)
{
    POKELIST_OpenChoiceMenu(p, (int)POKELIST_OnTakeMailChoice);
}
