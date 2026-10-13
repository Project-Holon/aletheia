/*
 * unit:     yes
 * function: POKELIST_OnTakeMailChoice, POKELIST_OpenMailItemMenu
 * address:  0x021BA3A4
 * packet:   pkt_ov091_021BA3A4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb ov091
 *   MAIL_FindEmptySlot  0x02009020  thumb
 *   MAIL_Create  0x02008F08  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_020307B0  0x020307B0  arm
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   PLIST_PLATE_Redraw  0x021BB2C0  thumb ov091
 *   POKELIST_ShowMessage  0x021B9788  thumb ov091
 *   POKELIST_EndMessageToList  0x021B9E20  thumb ov091
 *   POKELIST_OpenChoiceMenu  0x021B9804  thumb ov091
 *   POKELIST_OnMailItemChoice  0x021BA454  thumb ov091
 */
#include "../include/Obj13245.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern int   MAIL_FindEmptySlot(void *obj, int v);
struct Sub02008F80Obj;
extern void *MAIL_Create(int a0);
extern u32   POKE_TOOL_GetPartyValue(void *obj, u32 key, u32 off);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern u32 func_020307B0(void *p);
extern void  POKE_TOOL_SetPartyValue(void *obj, u32 key, u32 v);
extern void PLIST_PLATE_Redraw(u8 *a, u8 *s);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void POKELIST_EndMessageToList(u8 *p);
extern void POKELIST_OpenChoiceMenu(u8 *p, int a1);
extern void POKELIST_OnMailItemChoice(u8 *a, int k);
extern void  POKELIST_OpenMailItemMenu();

void POKELIST_OnTakeMailChoice(u8 *p, u32 state)
{
    int r;
    void *buf;

    PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
    if (state == 14) {
        r = MAIL_FindEmptySlot((void *)((u32 *)W(0x280))[2], 0);
        if (r >= 0) {
            buf = MAIL_Create(((struct Obj13245 *)p)->f0);
            POKE_TOOL_GetPartyValue((void *)W(0x38), 0xa7, (u32)buf);
            func_0200903C((void *)((u32 *)W(0x280))[2], 0, r, buf);
            func_020307B0(buf);
            POKE_TOOL_SetPartyValue((void *)W(0x38), 6, 0);
            PLIST_PLATE_Redraw(p, (u8 *)(((u32 *)(p + 0x160))[W(0x2c)]));
            POKELIST_ShowMessage(p, 0x1a, 1, (int)POKELIST_EndMessageToList);
        } else {
            POKELIST_ShowMessage(p, 0x1e, 1, (int)POKELIST_EndMessageToList);
        }
        return;
    }
    POKELIST_ShowMessage(p, 0x1b, 0, (int)POKELIST_OpenMailItemMenu);
}

void POKELIST_OpenMailItemMenu(u8 *p)
{
    POKELIST_OpenChoiceMenu(p, (int)POKELIST_OnMailItemChoice);
}
