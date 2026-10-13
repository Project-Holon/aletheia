/*
 * unit:     yes
 * function: PLIST_MENU_SwitchToNextTarget, PLIST_MENU_OnLevelUpMessageDone, PLIST_MENU_SkipToMoveLearn
 * address:  0x021BC628
 * packet:   pkt_ov091_021BC628
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLIST_MENU_FindItemTarget  0x021BC1D0  thumb  ov091
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb  ov091
 *   PLIST_PLATE_SetPalette  0x021BB050  thumb  ov091
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   PLIST_MENU_StartItemUse  0x021BC350  thumb  ov091
 *   PLIST_DEMO_UseItemOnMon  0x021BE2B4  thumb  ov091
 *   PLIST_PLATE_Redraw  0x021BB2C0  thumb  ov091
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PLIST_MESSAGE_DrawKeyCursorMark  0x021BBA70  thumb  ov091
 */
#include "../include/Obj00009.h"
#include "../include/Obj07736.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int PLIST_MENU_FindItemTarget(int);
extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void PLIST_PLATE_SetPalette(int unused, u8 *s, int k);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern int PLIST_MENU_StartItemUse(u8 *p, int v);
extern int PLIST_DEMO_UseItemOnMon(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern void PLIST_PLATE_Redraw(u8 *a, u8 *s);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void PLIST_MESSAGE_DrawKeyCursorMark(int, int);

void PLIST_MENU_SwitchToNextTarget(int p)
{
    int n = PLIST_MENU_FindItemTarget(p);
    PLIST_MESSAGE_CloseWindow((void *)p, (u32 *)(*(int *)&((struct Obj00009 *)p)->f150));
    PLIST_PLATE_SetPalette(p, (u8 *)(*(int *)(p + ((struct Obj00009 *)p)->f2C * 4 + 0x160)), 3);
    ((struct Obj00009 *)p)->f2C = n;
    *(int *)&((struct Obj00009 *)p)->f38 = (int)POKEPARTY_GetMember(**(void ** *)&((struct Obj00009 *)p)->f280, n);
    PLIST_MENU_StartItemUse((u8 *)p, 0);
    PLIST_DEMO_UseItemOnMon((void *)(*(int *)&((struct Obj00009 *)p)->f38),
                  *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x44), 0,
                  *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x30), ((struct Obj00009 *)p)->f0);
    PLIST_PLATE_Redraw((u8 *)p, (u8 *)(*(int *)(p + ((struct Obj00009 *)p)->f2C * 4 + 0x160)));
    GFL_USE_PlaySeDefaultVolume(0x56f);
}

void PLIST_MENU_OnLevelUpMessageDone(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 0;
    *(int *)(((struct Obj07736 *)p)->f280 + 0x50) = 0;
    PLIST_MESSAGE_DrawKeyCursorMark((int)p, ((struct Obj07736 *)p)->f150);
}

void PLIST_MENU_SkipToMoveLearn(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 6;
}
