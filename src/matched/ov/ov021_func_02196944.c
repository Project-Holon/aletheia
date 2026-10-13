/*
 * function: IRCBATTLEMENU_SeqWaitNotEnoughMsg
 * address:  0x02196944
 * packet:   pkt_ov021_02196944
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
 *   IRCBATTLEMENU_DeleteMsgWin  0x021962F4  thumb  ov021
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqUpdateTouchTop  0x02196A4C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int IRCBATTLEMENU_IsMessageEnd(u8 *p);
extern int TOUCHPANEL_GetTrg(void);
extern void IRCBATTLEMENU_DeleteMsgWin(u8 *);
extern void IRCBATTLEMENU_SetSeq(u8 *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqUpdateTouchTop(u8 *a);

void IRCBATTLEMENU_SeqWaitNotEnoughMsg(u8 *a)
{
    if (IRCBATTLEMENU_IsMessageEnd(a) != 0 && TOUCHPANEL_GetTrg() != 0) {
        IRCBATTLEMENU_DeleteMsgWin(a);
        IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqUpdateTouchTop, 0x3CB);
    }
}
