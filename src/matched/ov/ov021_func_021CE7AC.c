/*
 * function: COMM_ENTRY_MENU_OpenWindows
 * address:  0x021CE7AC
 * packet:   pkt_ov021_021CE7AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   gCommEntryMsgTable  0x021DB498  data   ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03619.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Fx;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern void *FIELD_MSGBG_CreateMsgWin(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern int FIELD_MSGBG_MsgWinPrintMsg(u32 a, u32 b, u32 c, u32 d);
extern u8 gCommEntryMsgTable[];

void COMM_ENTRY_MENU_OpenWindows(u32 *p)
{
    u32 h;
    int k;

    h = FIELDMAP_GetMsgBg((u8 *)p[0]);
    k = 0x10;
    if (((struct Obj03619 *)p)->f51F) {
        k = 0xe;
    }
    p[3] = (u32)FIELD_MSGBG_CreateMsgWin((struct Fx *)h, p[2], 2, 6, 0x12, k - 6);
    p[4] = (u32)FIELD_MSGBG_CreateMsgWin((struct Fx *)h, p[2], 2, 1, 0x1c, 2);
    FIELD_MSGBG_MsgWinPrintMsg(p[4], 0, 0, *(u16 *)(gCommEntryMsgTable + ((struct Obj03619 *)p)->f520 * 12));
}
