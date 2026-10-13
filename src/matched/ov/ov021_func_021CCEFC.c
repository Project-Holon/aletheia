/*
 * function: PARTY_SELECT_LIST_CreateMenu
 * address:  0x021CCEFC
 * packet:   pkt_ov021_021CCEFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_CreateMenuItemsFromTable  0x02190A28  thumb  ov021
 *   FIELD_MSGBG_CreateMenuFuncCallback  0x02190938  thumb  ov021
 *   PARTY_SELECT_LIST_MenuMoveCallback  0x021CCF60  thumb  ov021
 *   PARTY_SELECT_LIST_MenuSelectCallback  0x021CCF7C  thumb  ov021
 *   d_021DB414     0x021DB414  data  a4
 *   d_021DB42C     0x021DB42C  data  ov021  a4
 */
#include "../include/Obj07588.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_021DB414[];
extern u8 d_021DB42C[];
struct Handle;
struct Pair;
extern u32 FIELD_MSGBG_CreateMenuItemsFromTable(const struct Pair *arr, int n, u32 c, u16 d);
extern struct Handle *FIELD_MSGBG_CreateMenuFuncCallback(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u32 g, u32 h, u32 i);
extern void PARTY_SELECT_LIST_MenuMoveCallback(void *a, u32 sel);
extern void PARTY_SELECT_LIST_MenuSelectCallback(void *p, int k);

void PARTY_SELECT_LIST_CreateMenu(u8 *p)
{
    void *r;

    r = (void *)FIELD_MSGBG_CreateMenuItemsFromTable((const struct Pair *)d_021DB414, 3, ((struct Obj07588 *)p)->fA8, ((struct Obj07588 *)p)->fC);
    ((struct Obj07588 *)p)->fAC = FIELD_MSGBG_CreateMenuFuncCallback((u16 *)(((struct Obj07588 *)p)->fA4), d_021DB42C, (u32)r, 0, 0,
        (u32)PARTY_SELECT_LIST_MenuMoveCallback, (u32)PARTY_SELECT_LIST_MenuSelectCallback, (u32)p);
}
