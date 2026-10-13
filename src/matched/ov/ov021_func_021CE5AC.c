/*
 * function: COMM_ENTRY_MENU_ProcessStartConfirm
 * address:  0x021CE5AC
 * packet:   pkt_ov021_021CE5AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The extent runs long into the unlabelled leaf COMM_ENTRY_MENU_MarkMemberReady (filed on its
 * own). Cases 1 and 3 are identical bodies the compiler tail-merged.
 *
 * symbols:
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   COMM_ENTRY_MENU_CountAcceptedMembers  0x021CE73C  thumb  ov021
 *   gCommEntryMsgTable  0x021DB498  data   ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00011.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 h;
    u32 result;
    u8  state;
} Sub;

struct Handle;
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);
extern void COMM_ENTRY_MENU_PrintMessage(u32 *p, int n);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
extern int COMM_ENTRY_MENU_CountAcceptedMembers(u32 *p);
extern u8 gCommEntryMsgTable[];

u32 COMM_ENTRY_MENU_ProcessStartConfirm(u32 *p)
{
    Sub *q;
    u32 r;

    q = (Sub *)((u8 *)p + 0x130);
    if (!FIELD_MSGBG_SysWinMain((u32 *)p[5])) {
        return 0;
    }
    switch (q->state) {
    case 0:
        COMM_ENTRY_MENU_PrintMessage(p, *(u16 *)(gCommEntryMsgTable + ((u8 *)p)[0x520] * 12 + 2));
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
        FIELD_MSGBG_DeleteMenuFunc((void *)q->h);
        q->h = 0;
        if (r == 1) {
            q->result = 2;
            q->state = 100;
        } else if (COMM_ENTRY_MENU_CountAcceptedMembers(p) <= 1) {
            COMM_ENTRY_MENU_PrintMessage(p, *(u16 *)(gCommEntryMsgTable + ((u8 *)p)[0x520] * 12 + 4));
            q->state = 5;
        } else {
            COMM_ENTRY_MENU_PrintMessage(p, 0xf);
            q->state++;
        }
        break;
    case 3:
        q->h = (u32)FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg((u8 *)p[0]), 0);
        q->state++;
        break;
    case 4:
        r = FIELD_MSGBG_YesNoMenuMain((struct Handle *)q->h);
        if (r == 2) {
            break;
        }
        FIELD_MSGBG_DeleteMenuFunc((void *)q->h);
        q->h = 0;
        if (r == 0) {
            COMM_ENTRY_MENU_PrintMessage(p, *(u16 *)(gCommEntryMsgTable + ((u8 *)p)[0x520] * 12 + 4));
            q->state++;
        } else {
            q->result = 2;
            q->state = 100;
        }
        break;
    case 5:
        q->state = 0xff;
        q->result = 1;
        break;
    case 100:
        if (COMM_ENTRY_MENU_CountAcceptedMembers(p) > 1 && ((u8 *)p)[0x520] == 1) {
            ((struct Obj00011 *)p)->f574 = 9;
        } else {
            ((struct Obj00011 *)p)->f574 = 8;
        }
        q->state = 0xff;
        break;
    case 0xff:
        if (q->h) {
            FIELD_MSGBG_DeleteMenuFunc((void *)q->h);
            q->h = 0;
        }
        q->state = 0;
        return q->result;
    }
    return 0;
}
