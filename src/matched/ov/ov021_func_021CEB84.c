/*
 * function: COMM_ENTRY_MENU_MainYesNo
 * address:  0x021CEB84
 * packet:   pkt_ov021_021CEB84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_ENTRY_TickParentTimeouts  0x021CEE00  thumb  ov021
 *   COMM_ENTRY_ScanParents  0x021CEE48  thumb  ov021
 *   COMM_ENTRY_PollParentList  0x021CEDA0  thumb  ov021
 *   COMM_ENTRY_BuildParentItems  0x021CEF1C  thumb  ov021
 *   FIELD_MSGBG_RewriteMenuFunc  0x02190A14  thumb  ov021
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   func_020362DC  0x020362DC  arm
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *   COMM_ENTRY_SendJoinRequest  0x021CF1AC  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_IsPrintQueFinished  0x0219049C  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   FIELD_MSGBG_DrawMenuFuncFrame  0x02190B1C  thumb  ov021
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 */
#include "../include/Obj00011.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void COMM_ENTRY_TickParentTimeouts(u8 *p);
extern void COMM_ENTRY_ScanParents(u8 *p);
extern int COMM_ENTRY_PollParentList(u8 *p);
extern void COMM_ENTRY_BuildParentItems(u8 *p);
struct Handle;
extern void FIELD_MSGBG_RewriteMenuFunc(u8 *p);
extern int GFL_NET_SYSTEM_GetConnectNum(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern u32 func_020362DC(void);
extern void COMM_ENTRY_MENU_PrintMessage(u8 *p, int n);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);
extern u32 COMM_ENTRY_SendJoinRequest(u32 a, u32 b, u32 c);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
extern int FIELD_MSGBG_IsPrintQueFinished(u8 *p);
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
extern int FIELD_MSGBG_DrawMenuFuncFrame(u32 a);
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);

typedef struct {
    u8 pad0[0x2c8];
    u32 busy;
    u32 result;
    u8 state;
    u8 pad2d1[2];
    u8 prev;
    u16 timer;
} Sub;

u32 COMM_ENTRY_MENU_MainYesNo(u8 *p)
{
    u32 *w = (u32 *)(p + 0x130);
    Sub *s = (Sub *)(p + 0x13c);
    u32 r;

    switch (s->state) {
    case 0:
        if (s->busy == 0) {
            COMM_ENTRY_TickParentTimeouts(p);
            COMM_ENTRY_ScanParents(p);
            if (COMM_ENTRY_PollParentList(p) == 0) {
                s->result = 3;
                s->state = 3;
            } else if (p[0x40d] == 1) {
                COMM_ENTRY_BuildParentItems(p);
                FIELD_MSGBG_RewriteMenuFunc((u8 *)(((struct Obj00011 *)p)->f140));
                p[0x40d] = 0;
            }
        } else if (GFL_NET_SYSTEM_GetConnectNum() > 1) {
            if (GFL_NET_HANDLE_CheckNegotiation() == 1) {
                s->state++;
            }
        } else {
            if (func_020362DC() & 2) {
                s->prev = s->state;
                s->state = 4;
            }
            (s->timer)++;
            if (s->timer >= 300) {
                s->state = 6;
                COMM_ENTRY_MENU_PrintMessage(p, 0x24);
            }
        }
        break;
    case 1:
        if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)GFL_NET_HANDLE_GetCurrentHandle()) == 1) {
            ((struct Obj00011 *)p)->f52C = 0;
            if (COMM_ENTRY_SendJoinRequest((u32)(p + 0x30), 0, p[0x51b]) == 1) {
                s->state = 2;
            }
        } else if (func_020362DC() & 2) {
            s->prev = s->state;
            s->state = 4;
        }
        if (p[0x51a] == 1) {
            s->result = 1;
            s->state = 3;
        }
        break;
    case 2:
        if (((struct Obj00011 *)p)->f52C == 1) {
            s->result = 1;
            s->state = 3;
        } else if (((struct Obj00011 *)p)->f52C == 2) {
            s->result = 2;
            s->state = 3;
        } else if (func_020362DC() & 2) {
            s->prev = s->state;
            s->state = 4;
        }
        if (p[0x51a] == 1) {
            s->result = 1;
            s->state = 3;
        }
        break;
    case 3:
        return s->result;
    case 4:
        COMM_ENTRY_MENU_PrintMessage(p, 0x23);
        *w = (u32)FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg((u8 *)(((struct Obj00011 *)p)->f0)), 0);
        s->state = 5;
        break;
    case 5:
        r = FIELD_MSGBG_YesNoMenuMain((struct Handle *)(*w));
        if (FIELD_MSGBG_IsPrintQueFinished((u8 *)FIELDMAP_GetMsgBg((u8 *)(((struct Obj00011 *)p)->f0))) == 1 && p[0x576] == 1) {
            r = 1;
        }
        if (r == 2 && FIELD_MSGBG_IsPrintQueFinished((u8 *)FIELDMAP_GetMsgBg((u8 *)(((struct Obj00011 *)p)->f0))) == 1) {
            if (p[0x519] == 1 || p[0x51a] == 1) {
                FIELD_MSGBG_DeleteMenuFunc((void *)(*w));
                *w = 0;
                s->result = 1;
                s->state = 3;
            }
        } else {
            FIELD_MSGBG_DeleteMenuFunc((void *)(*w));
            *w = 0;
            if (r == 1) {
                s->state = s->prev;
                COMM_ENTRY_MENU_PrintMessage(p, 0x20);
                if (((struct Obj00011 *)p)->f140 != 0) {
                    FIELD_MSGBG_DrawMenuFuncFrame(((struct Obj00011 *)p)->f140);
                }
            } else {
                s->result = 3;
                s->state = 3;
            }
        }
        break;
    case 6:
        if (FIELD_MSGBG_SysWinMain((u32 *)(((struct Obj00011 *)p)->f14)) == 1) {
            s->result = 3;
            s->state = 3;
        }
        break;
    }
    return 0;
}
