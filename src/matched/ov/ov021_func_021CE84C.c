/*
 * function: COMM_ENTRY_MENU_PrintRemaining
 * address:  0x021CE84C
 * packet:   pkt_ov021_021CE84C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   FIELD_MSGBG_FillMsgWin  0x02190794  thumb  ov021
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02736.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int FIELD_MSGBG_IsMsgWinTransDone(u8 *p);
struct Slot;
struct WordSet;
extern void FIELD_MSGBG_FillMsgWin(struct Slot **p, int x, int y, int w, int h);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern int FIELD_MSGBG_MsgWinPrintStr(u32 a, u32 b, u32 c, u32 d);

int COMM_ENTRY_MENU_PrintRemaining(u32 *p, int n)
{
    if (p[3] && FIELD_MSGBG_IsMsgWinTransDone((u8 *)p[3]) == 1) {
        FIELD_MSGBG_FillMsgWin((struct Slot **)p[3], 0, 0x40, 0x90, 0x50);
        WORDSET_SetSlotNumber((struct WordSet *)p[1], 0, ((struct Obj02736 *)p)->f51D - n, 1, 0, 1);
        WORDSET_CopyTaggedText((struct WordSet *)p[1], (void *)p[10], (void *)p[9]);
        FIELD_MSGBG_MsgWinPrintStr(p[3], 0, 0x40, p[10]);
        return 1;
    }
    return 0;
}
