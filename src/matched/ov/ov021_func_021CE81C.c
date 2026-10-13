/*
 * function: COMM_ENTRY_MENU_CloseWindows
 * address:  0x021CE81C
 * packet:   pkt_ov021_021CE81C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_ClearPrintQue  0x02190490  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern int FIELD_MSGBG_DeleteMsgWin(void *a);
extern void FIELD_MSGBG_ClearPrintQue(u8 *p);

void COMM_ENTRY_MENU_CloseWindows(u32 *p)
{
    u32 h = FIELDMAP_GetMsgBg((u8 *)p[0]);

    if (p[4] != 0) {
        FIELD_MSGBG_DeleteMsgWin((void *)p[4]);
        p[4] = 0;
    }
    if (p[3] != 0) {
        FIELD_MSGBG_DeleteMsgWin((void *)p[3]);
        p[3] = 0;
    }
    FIELD_MSGBG_ClearPrintQue((u8 *)h);
}
