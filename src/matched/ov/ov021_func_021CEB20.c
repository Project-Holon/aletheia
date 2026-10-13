/*
 * function: COMM_ENTRY_MENU_StartYesNo
 * address:  0x021CEB20
 * packet:   pkt_ov021_021CEB20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMenuItems  0x02190A20  thumb  ov021
 *   COMM_ENTRY_BuildParentItems  0x021CEF1C  thumb  ov021
 *   FIELD_MSGBG_CreateMenuFunc  0x0219097C  thumb  ov021
 *   gCommEntryParentListHeader  0x021DB478  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00659.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 FIELD_MSGBG_CreateMenuItems(u32, u32);
extern void COMM_ENTRY_BuildParentItems(u8 *p);
extern u32 FIELD_MSGBG_CreateMenuFunc(u32, const void *, u32);
extern const u8 gCommEntryParentListHeader[];

void COMM_ENTRY_MENU_StartYesNo(u8 *p)
{
    u32 h;

    h = FIELDMAP_GetMsgBg((u8 *)(((struct Obj00659 *)p)->f0));
    ((struct Obj00659 *)p)->f13C = FIELD_MSGBG_CreateMenuItems(0x10, ((struct Obj00659 *)p)->f528);
    COMM_ENTRY_BuildParentItems(p);
    ((struct Obj00659 *)p)->f140 = FIELD_MSGBG_CreateMenuFunc(h, gCommEntryParentListHeader, ((struct Obj00659 *)p)->f13C);
    p[0x40c] = 0;
}
