/*
 * function: POKELIST_OnMailItemChoice
 * address:  0x021BA454
 * packet:   pkt_ov091_021BA454
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb  ov091
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKELIST_CheckBagItem  0x021BA65C  thumb  ov091
 *   POKELIST_ReturnBagItem  0x021BA688  thumb  ov091
 *   POKELIST_ShowMessage  0x021B9788  thumb  ov091
 *   PLIST_PLATE_Redraw  0x021BB2C0  thumb  ov091
 *   POKELIST_SetupModeScreen  0x021B7B98  thumb  ov091
 *   POKELIST_EndMessageToList  0x021B9E20  thumb  ov091
 */
#include "../include/Obj00009.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern u32 POKE_TOOL_GetPartyValue(void *obj, u32 key, u32 off);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKELIST_CheckBagItem(u8 *p, u16 id);
extern u32 POKELIST_ReturnBagItem(u8 *p, u16 id);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
extern void PLIST_PLATE_Redraw(u8 *a, u8 *s);
extern void POKELIST_SetupModeScreen(u8 *a);
extern void POKELIST_EndMessageToList(u8 *p);

void POKELIST_OnMailItemChoice(u8 *a, int k)
{
    PLIST_MESSAGE_CloseWindow(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150));
    if (k == 0xe) {
        int v = POKE_TOOL_GetPartyValue((void *)*(int *)&((struct Obj00009 *)a)->f38, 6, 0);

        if (POKELIST_CheckBagItem(a, v) == 0x3e7) {
            POKELIST_ShowMessage(a, 0x3f, 1, (int)POKELIST_EndMessageToList);
            return;
        }
        POKELIST_ReturnBagItem(a, v);
        POKE_TOOL_SetPartyValue((void *)(*(int *)&((struct Obj00009 *)a)->f38), 6, 0);
        PLIST_PLATE_Redraw(a, (u8 *)(*(int *)(a + ((struct Obj00009 *)a)->f2C * 4 + 0x160)));
        POKELIST_ShowMessage(a, 0x1f, 1, (int)POKELIST_EndMessageToList);
    } else {
        PLIST_MESSAGE_CloseWindow(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150));
        a[0xc] = 2;
        POKELIST_SetupModeScreen(a);
    }
}
