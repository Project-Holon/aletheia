/*
 * function: PLIST_MENU_ShowItemUsedThenContinue
 * address:  0x021BC30C
 * packet:   pkt_ov091_021BC30C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb  ov091
 *   PLIST_MESSAGE_SetWordSetItem  0x021BB9AC  thumb  ov091
 *   POKELIST_ShowMessage  0x021B9788  thumb  ov091
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb  ov091
 *   POKELIST_EndMessageToList  0x021B9E20  thumb  ov091
 */
#include "../include/Obj00009.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetItem(int, int, int, int);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void POKELIST_EndMessageToList(u8 *p);

void PLIST_MENU_ShowItemUsedThenContinue(int p)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    PLIST_MESSAGE_CreateWordSet((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    PLIST_MESSAGE_SetWordSetItem(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x44));
    POKELIST_ShowMessage((u8 *)p, 0x51, 1, (int)POKELIST_EndMessageToList);
    PLIST_MESSAGE_DestroyWordSet((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}
