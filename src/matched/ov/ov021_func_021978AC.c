/*
 * function: IRCBATTLEMENU_SeqSaveQuestionWait
 * address:  0x021978AC
 * packet:   pkt_ov021_021978AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_IsMessageEnd  0x021975D0  thumb  ov021
 *   IRCBATTLEMENU_OpenYesNoMenu  0x02197534  thumb  ov021
 *   IRCBATTLEMENU_SetSeq  0x02196034  thumb  ov021
 *   IRCBATTLEMENU_SeqSaveYesNo  0x02197800  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int IRCBATTLEMENU_IsMessageEnd(u8 *p);
struct Obj;
extern void IRCBATTLEMENU_OpenYesNoMenu(struct Obj *a);
extern void IRCBATTLEMENU_SetSeq(u8 *, void (*)(), u32);
extern void IRCBATTLEMENU_SeqSaveYesNo(u8 *a);

void IRCBATTLEMENU_SeqSaveQuestionWait(u8 *a)
{
    if (IRCBATTLEMENU_IsMessageEnd(a) != 0) {
        IRCBATTLEMENU_OpenYesNoMenu((struct Obj *)a);
        IRCBATTLEMENU_SetSeq(a, IRCBATTLEMENU_SeqSaveYesNo, 0x7DC);
    }
}
