/*
 * function: POKELIST_SetupModeScreen
 * address:  0x021B7B98
 * packet:   pkt_ov091_021B7B98
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the listing extent's last two bytes (0x021B7CC2) are alignment
 * padding before the next function, not a follower.
 *
 * symbols:
 *   func_020409B4  0x020409B4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   PLIST_MESSAGE_OpenWindow  0x021BB714  thumb  ov091
 *   PLIST_MESSAGE_PrintText  0x021BB7E8  thumb  ov091
 *   PLIST_BATTLE_RefreshOpponentMessage  0x021BD4EC  thumb  ov091
 *   POKELIST_RefreshCursor  0x021B8418  thumb  ov091
 */
#include "../include/Obj00009.h"
#include "../include/Obj20857.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020409B4(u32 index);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void PLIST_MESSAGE_OpenWindow(void *a, u32 *s, u32 k);
extern void PLIST_MESSAGE_PrintText(u8 *a, u32 *s, u32 x);
extern void PLIST_BATTLE_RefreshOpponentMessage(char *p);
extern void POKELIST_RefreshCursor(u8 *p);

void POKELIST_SetupModeScreen(u8 *p)
{
    func_020409B4(0);
    switch (((struct Obj20857 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f34) {
    case 0:
        PLIST_MESSAGE_OpenWindow(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        PLIST_MESSAGE_PrintText(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 9);
        ((struct Obj00009 *)p)->f14 = 1;
        break;
    case 1:
        PLIST_BATTLE_RefreshOpponentMessage((char *)p);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00009 *)p)->f1E0, 0);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 22:
    case 23:
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 5:
    case 16:
        PLIST_MESSAGE_OpenWindow(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        PLIST_MESSAGE_PrintText(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xd);
        ((struct Obj00009 *)p)->f14 = 0;
        ((struct Obj00009 *)p)->f28 = 0;
        break;
    case 9:
    case 14:
        PLIST_MESSAGE_OpenWindow(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        PLIST_MESSAGE_PrintText(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xc);
        ((struct Obj00009 *)p)->f14 = 0;
        ((struct Obj00009 *)p)->f28 = 0;
        break;
    case 6:
        PLIST_MESSAGE_OpenWindow(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        PLIST_MESSAGE_PrintText(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xe);
        ((struct Obj00009 *)p)->f14 = 0;
        ((struct Obj00009 *)p)->f28 = 0;
        break;
    case 18:
        PLIST_MESSAGE_OpenWindow(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        PLIST_MESSAGE_PrintText(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0x10);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 3:
    case 25:
        PLIST_MESSAGE_OpenWindow(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        PLIST_MESSAGE_PrintText(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 9);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 21:
        PLIST_MESSAGE_OpenWindow(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        PLIST_MESSAGE_PrintText(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xa3);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00009 *)p)->f1E0, 0);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    }
    POKELIST_RefreshCursor(p);
}
