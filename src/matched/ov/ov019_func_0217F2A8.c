/*
 * function: UNION_MSG_SetupMenu
 * address:  0x0217F2A8
 * packet:   pkt_ov019_0217F2A8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMenuItemsFromTable  0x02190A28  thumb  ov021
 *   FIELD_MSGBG_CreateMenuFuncWork  0x02190988  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09418.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Handle;
struct Pair;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 FIELD_MSGBG_CreateMenuItemsFromTable(const struct Pair *arr, int n, u32 c, u16 d);
extern struct Handle *FIELD_MSGBG_CreateMenuFuncWork(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);

void UNION_MSG_SetupMenu(char *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 h = FIELDMAP_GetMsgBg((u8 *)a1);

    if (((struct Obj09418 *)p)->f2810 == 0) {
        u32 x = FIELD_MSGBG_CreateMenuItemsFromTable((const struct Pair *)a2, a3, ((struct Obj09418 *)p)->f2808, 0x41);
        ((struct Obj09418 *)p)->f2810 = (u32)FIELD_MSGBG_CreateMenuFuncWork((u16 *)h, (const u8 *)a4, x, 0, 0, 0, 0, 1);
    }
}
