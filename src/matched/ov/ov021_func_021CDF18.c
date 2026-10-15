/*
 * function: COMM_ENTRY_MENU_MainMode3
 * address:  0x021CDF18
 * packet:   pkt_ov021_021CDF18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case 2's r == 2 arm really calls COMM_ENTRY_ResetLeaveConfirm twice: the original's
 * branch lands on case 4's second-call tail after its own call.
 *
 * symbols:
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 *   COMM_ENTRY_SendJoinRequest  0x021CF1AC  thumb  ov021
 *   COMM_ENTRY_MENU_OpenWindows  0x021CE7AC  thumb  ov021
 *   COMM_ENTRY_RunLeaveConfirm  0x021CF068  thumb  ov021
 *   COMM_ENTRY_MENU_CloseWindows  0x021CE81C  thumb  ov021
 *   COMM_ENTRY_ResetLeaveConfirm  0x021CF0F4  thumb  ov021
 *   COMM_ENTRY_SendReady  0x021CF32C  thumb  ov021
 *   COMM_ENTRY_MENU_RefreshNames  0x021CE9A0  thumb  ov021
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   gCommEntryMsgTable  0x021DB498  data   ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void COMM_ENTRY_MENU_PrintMessage(u8 *p, int n);
extern u32 COMM_ENTRY_SendJoinRequest(u32 a, u32 b, u32 c);
extern void COMM_ENTRY_MENU_OpenWindows(u32 *p);
extern int COMM_ENTRY_RunLeaveConfirm(u8 *p);
extern void COMM_ENTRY_MENU_CloseWindows(u32 *p);
extern void COMM_ENTRY_ResetLeaveConfirm(u8 *p);
extern u32 COMM_ENTRY_SendReady(u32 flag);
extern void COMM_ENTRY_MENU_RefreshNames(u8 *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, u32 a, u32 b);
struct WordSet;
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern u32 func_0200FB24(void);
extern u8 gCommEntryMsgTable[];

#define U32(o) (*(u32 *)(p + (o)))

int COMM_ENTRY_MENU_MainMode3(u8 *p)
{
    switch (p[0x51E]) {
    case 0:
        COMM_ENTRY_MENU_PrintMessage(p, 0x15);
        p[0x51E]++;
        break;
    case 1:
        U32(0x52C) = 0;
        if (COMM_ENTRY_SendJoinRequest((u32)(p + 0x30), 0, p[0x51B]) == 1) {
            p[0x51E] = 2;
        }
        break;
    case 2:
        if (COMM_ENTRY_RunLeaveConfirm(p) == 2) {
            COMM_ENTRY_MENU_CloseWindows((u32 *)p);
            COMM_ENTRY_ResetLeaveConfirm(p);
            COMM_ENTRY_ResetLeaveConfirm(p);
            p[0x51E] = 0xb;
            break;
        }
        if (U32(0x52C) == 1) {
            p[0x51E] = 3;
            COMM_ENTRY_ResetLeaveConfirm(p);
        } else if (U32(0x52C) == 2) {
            p[0x51E] = 9;
            COMM_ENTRY_ResetLeaveConfirm(p);
        } else if (p[0x519] == 1) {
            p[0x51E] = 5;
            COMM_ENTRY_ResetLeaveConfirm(p);
        } else if (p[0x51A] == 1) {
            p[0x51E] = 0xb;
            COMM_ENTRY_ResetLeaveConfirm(p);
        }
        break;
    case 3:
        COMM_ENTRY_MENU_OpenWindows((u32 *)p);
        p[0x51E]++;
        break;
    case 4:
        if (COMM_ENTRY_RunLeaveConfirm(p) == 2) {
            COMM_ENTRY_MENU_CloseWindows((u32 *)p);
            COMM_ENTRY_ResetLeaveConfirm(p);
            p[0x51E] = 0xb;
            break;
        }
        if (p[0x577] == 1) {
            if (COMM_ENTRY_SendReady(p[0x51B]) == 1) {
                p[0x577] = 0;
            }
        }
        COMM_ENTRY_MENU_RefreshNames(p);
        if (p[0x519] == 1) {
            COMM_ENTRY_MENU_CloseWindows((u32 *)p);
            COMM_ENTRY_ResetLeaveConfirm(p);
            p[0x51E] = 5;
        } else if (p[0x51A] == 1) {
            COMM_ENTRY_MENU_CloseWindows((u32 *)p);
            COMM_ENTRY_ResetLeaveConfirm(p);
            p[0x51E] = 7;
        }
        break;
    case 5:
        if (p[0x520] == 0) {
            COMM_ENTRY_MENU_PrintMessage(p, 0x1e);
        }
        p[0x51E] = 6;
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27);
        break;
    case 6:
        if (p[0x520] != 0 || FIELD_MSGBG_SysWinMain((u32 *)U32(0x14)) == 1) {
            if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27) == 1) {
                U32(0x2c) = 1;
                p[0x51E] = 0xc;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 7;
            }
        }
        break;
    case 7:
        COMM_ENTRY_MENU_PrintMessage(p, *(u16 *)(gCommEntryMsgTable + p[0x520] * 12 + 8));
        p[0x51E] = 8;
        break;
    case 8:
        if (FIELD_MSGBG_SysWinMain((u32 *)U32(0x14)) == 1) {
            U32(0x2c) = 2;
            p[0x51E] = 0xc;
        }
        break;
    case 9:
        GFL_NET_Exit(0);
        WORDSET_SetSlotMyStatus((struct WordSet *)U32(4), 0, (void *)((int)(p + 0x530)));
        COMM_ENTRY_MENU_PrintMessage(p, 0x1f);
        p[0x51E] = 10;
        break;
    case 10:
        if (GFL_NET_IsSessionNull() == 1 && FIELD_MSGBG_SysWinMain((u32 *)U32(0x14)) == 1) {
            U32(0x2c) = 3;
            p[0x51E] = 0xc;
        }
        break;
    case 11:
        U32(0x2c) = 2;
        p[0x51E] = 0xc;
        break;
    case 12:
        COMM_ENTRY_MENU_CloseWindows((u32 *)p);
        return 1;
    }
    if (func_0200FB24() != 0) {
        COMM_ENTRY_ResetLeaveConfirm(p);
        U32(0x2c) = 4;
        return 1;
    }
    return 0;
}
