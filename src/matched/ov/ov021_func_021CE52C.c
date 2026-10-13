/*
 * function: COMM_ENTRY_MENU_ProcessCancel
 * address:  0x021CE52C
 * packet:   pkt_ov021_021CE52C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   COMM_ENTRY_MENU_StatesUnchanged  0x021CEA50  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 h;
    u32 pad4;
    u8  state;
} Sub;

typedef unsigned short u16;
struct Handle;
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);
extern void COMM_ENTRY_MENU_PrintMessage(u32 *p, int n);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern int COMM_ENTRY_MENU_StatesUnchanged(u8 *p);
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);

int COMM_ENTRY_MENU_ProcessCancel(u32 *p)
{
    Sub *q;
    u32 r;

    q = (Sub *)((u8 *)p + 0x130);
    if (!FIELD_MSGBG_SysWinMain((u32 *)p[5])) {
        return 0;
    }
    switch (q->state) {
    case 0:
        COMM_ENTRY_MENU_PrintMessage(p, 0xb);
        q->state++;
        break;
    case 1:
        q->h = (u32)FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg((u8 *)p[0]), 0);
        q->state++;
        break;
    case 2:
        if (!COMM_ENTRY_MENU_StatesUnchanged((u8 *)p)) {
            r = 1;
        } else {
            r = FIELD_MSGBG_YesNoMenuMain((struct Handle *)q->h);
            if (r == 2) {
                break;
            }
        }
        FIELD_MSGBG_DeleteMenuFunc((void *)q->h);
        q->h = 0;
        q->state = 0;
        if (r == 0) {
            return 1;
        }
        return 2;
    }
    return 0;
}
