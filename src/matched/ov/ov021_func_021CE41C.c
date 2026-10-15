/*
 * function: COMM_ENTRY_MENU_ProcessRequest
 * address:  0x021CE41C
 * packet:   pkt_ov021_021CE41C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x104 base kept in r6 comes from w being assigned first; the slot
 * store is spelled through the row pointer ((u8 *)p + i * 0x2c)[0x70] while
 * the test indexes p directly.
 *
 * symbols:
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   COMM_ENTRY_MENU_AdvanceMemberStates  0x021CE36C  thumb  ov021
 *   COMM_ENTRY_MENU_CountAcceptedMembers  0x021CE73C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 h;
    u32 pad4;
    u8  state;
} Sub;

struct Handle;
struct WordSet;
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void COMM_ENTRY_MENU_PrintMessage(u32 *p, int n);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
extern void COMM_ENTRY_MENU_AdvanceMemberStates(u8 *p);
extern int COMM_ENTRY_MENU_CountAcceptedMembers(u32 *p);

void COMM_ENTRY_MENU_ProcessRequest(u32 *p)
{
    Sub *q;
    u8 *w;
    u32 r;
    u8 i;
    u8 v;

    w = (u8 *)p + 0x104;
    q = (Sub *)((u8 *)p + 0x130);
    if (p[0x40] == 0) {
        return;
    }
    if (!FIELD_MSGBG_SysWinMain((u32 *)p[5])) {
        return;
    }
    switch (q->state) {
    case 0:
        WORDSET_SetSlotMyStatus((struct WordSet *)p[1], 0, (void *)((int)w));
        COMM_ENTRY_MENU_PrintMessage(p, 10);
        q->state++;
        break;
    case 1:
        q->h = (u32)FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg((u8 *)p[0]), 0);
        q->state++;
        break;
    case 2:
        r = FIELD_MSGBG_YesNoMenuMain((struct Handle *)q->h);
        if (r == 2) {
            break;
        }
        v = 4;
        if (r != 0) {
            v = 5;
        }
        for (i = 0; i < 4; i++) {
            if (((u8 *)p)[0x70 + i * 0x2c] == 3) {
                ((u8 *)p + i * 0x2c)[0x70] = v;
                if (v == 4) {
                    ((u8 *)p)[0x521] |= 1 << i;
                } else {
                    ((u8 *)p)[0x522] |= 1 << i;
                }
                break;
            }
        }
        FIELD_MSGBG_DeleteMenuFunc((void *)q->h);
        q->h = 0;
        q->state++;
        break;
    case 3:
        p[0x40] = 0;
        q->state = 0;
        COMM_ENTRY_MENU_AdvanceMemberStates((u8 *)p);
        if (p[0x40] == 0) {
            if (COMM_ENTRY_MENU_CountAcceptedMembers(p) > 1 && ((u8 *)p)[0x520] == 1) {
                ((struct Obj00011 *)p)->f574 = 9;
            } else {
                ((struct Obj00011 *)p)->f574 = 8;
            }
        }
        break;
    }
}
