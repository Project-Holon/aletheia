/*
 * function: IRCBATTLEMENU_SeqWaitTouchExit
 * address:  0x021977C0
 * packet:   pkt_ov021_021977C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_IsMessageEnd  0x021975D0  thumb  ov021
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   IRCBATTLEMENU_SetSubPaletteActive  0x02196228  thumb  ov021
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   IRCBATTLEMENU_DeleteMsgWin  0x021962F4  thumb  ov021
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqUpdateTouchTop  0x02196A4C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int IRCBATTLEMENU_IsMessageEnd(u8 *p);
extern int TOUCHPANEL_GetTrg(void);
extern void IRCBATTLEMENU_SetSubPaletteActive(u8 *p, int flag);
extern void BG_SYS_ClearSlot(u32);
extern void IRCBATTLEMENU_DeleteMsgWin(u8 *);
extern void IRCBATTLEMENU_SetSeq(u8 *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqUpdateTouchTop(u8 *a);

void IRCBATTLEMENU_SeqWaitTouchExit(u8 *a)
{
    if (IRCBATTLEMENU_IsMessageEnd(a) != 0 && TOUCHPANEL_GetTrg() != 0) {
        IRCBATTLEMENU_SetSubPaletteActive(a, 0);
        BG_SYS_ClearSlot(3);
        IRCBATTLEMENU_DeleteMsgWin(a);
        ((struct Obj00094 *)a)->f8 = 12;
        IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqUpdateTouchTop, 0x7a2);
    }
}
