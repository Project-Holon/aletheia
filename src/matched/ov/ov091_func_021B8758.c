/*
 * function: POKELIST_UpdateHealShareCommand
 * address:  0x021B8758
 * packet:   pkt_ov091_021B8758
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb  ov091
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKELIST_ShowMessage  0x021B9788  thumb  ov091
 *   POKELIST_EndMessageToList  0x021B9E20  thumb  ov091
 *   POKELIST_MoveCursorToPlate  0x021B8F68  thumb  ov091
 *   PLIST_PLATE_SetSelected  0x021BAFA0  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   PLIST_PLATE_Redraw  0x021BB2C0  thumb  ov091
 *   PLIST_PLATE_GetHp  0x021BB464  thumb  ov091
 *   POKELIST_StartHpTransfer  0x021BA288  thumb  ov091
 *   _u32_div_f     0x0209C2B0  arm
 *   func_020061E4  0x020061E4  thumb
 *   POKELIST_SetupModeScreen  0x021B7B98  thumb  ov091
 */
#include "../include/Obj00009.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void *func_0201AB28(void *p, u32 idx);
extern u32   POKE_TOOL_GetPartyValue(void *obj, u32 key, u32 off);
extern void  POKE_TOOL_SetPartyValue(void *obj, u32 key, u32 v);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void POKELIST_EndMessageToList(u8 *p);
extern void  POKELIST_MoveCursorToPlate(u8 *p, int v);
extern void PLIST_PLATE_SetSelected(u8 *a, u8 *s, int k);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void PLIST_PLATE_Redraw(u8 *a, u8 *s);
extern unsigned short PLIST_PLATE_GetHp(int unused, unsigned short *p);
extern void POKELIST_StartHpTransfer(u8 *p);
extern void  func_020061E4(u32 id);
extern void  POKELIST_SetupModeScreen(u8 *p);

void POKELIST_UpdateHealShareCommand(u8 *p)
{
    u32 a, b;
    void *o;
    u32 c, d, e;

    PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
    if (p[0xf] == 3) {
        W(0x38) = (u32)func_0201AB28((void *)*(u32 *)W(0x280), W(0x2c));
        a = POKE_TOOL_GetPartyValue((void *)W(0x38), 0xa0, 0);
        b = POKE_TOOL_GetPartyValue((void *)W(0x38), 0xa1, 0);
        if (W(0x2c) == W(0x34) || a == 0 || b == a) {
            POKELIST_ShowMessage(p, 0x64, 1, (int)POKELIST_EndMessageToList);
            POKELIST_MoveCursorToPlate(p, W(0x2c));
            PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
            PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1dc), 0);
            ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
            return;
        }
        PLIST_PLATE_Redraw(p, (u8 *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        W(0x38) = (u32)func_0201AB28((void *)*(u32 *)W(0x280), W(0x2c));
        p[0xc] = 10;
        ((struct Obj00009 *)p)->f11C = PLIST_PLATE_GetHp((int)p, (short unsigned int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        W(0x120) = (u32)POKELIST_StartHpTransfer;
        POKELIST_MoveCursorToPlate(p, W(0x2c));
        PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
        func_0204B3DC((struct Obj *)W(0x1dc), 0);
        o = func_0201AB28((void *)*(u32 *)W(0x280), W(0x34));
        c = POKE_TOOL_GetPartyValue(o, 0xa1, 0);
        d = POKE_TOOL_GetPartyValue(o, 0xa0, 0);
        e = c / 5;
        if (a + e > b) {
            POKE_TOOL_SetPartyValue(o, 0xa0, d - (b - a));
        } else {
            POKE_TOOL_SetPartyValue(o, 0xa0, d - e);
        }
        ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
        W(0x2c) = W(0x34);
        PLIST_PLATE_Redraw(p, (u8 *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        func_020061E4(0x56f);
        return;
    }
    W(0x38) = 0;
    p[0xc] = 2;
    POKELIST_MoveCursorToPlate(p, W(0x2c));
    PLIST_PLATE_SetSelected(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 0);
    W(0x34) = 9;
    ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
    POKELIST_SetupModeScreen(p);
    func_020061E4(0x551);
}
