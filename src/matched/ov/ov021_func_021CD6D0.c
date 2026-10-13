/*
 * function: COMM_ENTRY_MENU_MainRecruit
 * address:  0x021CD6D0
 * packet:   pkt_ov021_021CD6D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gCommEntryMsgTable  0x021DB498  data
 *   COMM_ENTRY_MENU_CheckDisconnects  0x021CE24C  thumb  ov021
 *   COMM_ENTRY_MENU_UpdateMemberList  0x021CE2BC  thumb  ov021
 *   COMM_ENTRY_MENU_ProcessMemberQueues  0x021CE12C  thumb  ov021
 *   COMM_ENTRY_MENU_OpenWindows  0x021CE7AC  thumb  ov021
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 *   COMM_ENTRY_SendJoinRequest  0x021CF1AC  thumb  ov021
 *   COMM_ENTRY_MENU_AdvanceMemberStates  0x021CE36C  thumb  ov021
 *   COMM_ENTRY_MENU_ProcessRequest  0x021CE41C  thumb  ov021
 *   COMM_ENTRY_MENU_IsIdle  0x021CE78C  thumb  ov021
 *   COMM_ENTRY_MENU_CountAcceptedMembers  0x021CE73C  thumb  ov021
 *   COMM_ENTRY_MENU_SnapshotStates  0x021CEA28  thumb  ov021
 *   COMM_ENTRY_MENU_ProcessCancel  0x021CE52C  thumb  ov021
 *   COMM_ENTRY_MENU_ProcessStartConfirm  0x021CE5AC  thumb  ov021
 *   COMM_ENTRY_SendSessionLock  0x021CF2F0  thumb  ov021
 *   COMM_ENTRY_MENU_MarkMemberReady  0x021CE6F0  thumb  ov021
 *   COMM_ENTRY_SendCancel  0x021CF3B0  thumb  ov021
 *   COMM_ENTRY_SendAccept  0x021CF378  thumb  ov021
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   COMM_ENTRY_IsOtherMemberConnected  0x021CF12C  thumb  ov021
 *   COMM_ENTRY_MENU_CloseWindows  0x021CE81C  thumb  ov021
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_StartByNetType  0x0203D01C  arm
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   func_020362DC  0x020362DC  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_NotifyUserEvent  0x0203D1E8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   func_02080D24  0x02080D24  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *
 * Per-frame state machine (state byte at 0x51E, 20 cases). Closed:
 * case 8 placed after case 12 (image layout), case 1 written with the
 * `== 0` arm first, case 14 through an Entry pointer local (keeps the +8
 * out of the pool word), loop condition `(i < 4) ? 1 : 0` (branch to the
 * bottom test), `1u << i` in the x526 test only (an identical `1 << i`
 * there is CSEd across the call and spills the mask), and `1 << (u32)i` in
 * the x578 test: with the plain int promotion of i the shift is evaluated
 * before the x578 load, so `movs r0,#1` is live across the reload of the
 * spilled 0x578 offset and the reload lands in r1; the u32 count orders the
 * load first and the reload takes r0 (2026-10-02).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0x14];
    u32 h;              /* 0x014 */
    u8  pad18[0x14];
    u32 x2C;            /* 0x02C */
    u8  sub[0x4E4];     /* 0x030 */
    u8  x514;           /* 0x514 */
    u8  pad515[6];
    u8  x51B;           /* 0x51B */
    u8  x51C;           /* 0x51C */
    u8  x51D;           /* 0x51D */
    u8  state;          /* 0x51E */
    u8  pad51F;
    u8  x520;           /* 0x520 */
    u8  pad521[5];
    u8  x526;           /* 0x526 */
    u8  pad527[0x4C];
    u8  x573;           /* 0x573 */
    u16 x574;           /* 0x574 */
    u8  pad576[2];
    u8  x578;           /* 0x578 */
} Work;

typedef struct {
    u8  pad0[8];
    u16 f8;
    u8  padA[2];
} Entry;

typedef struct {
    u8  pad0[0x26];
    u16 f26;
} Obj;

typedef struct {
    u8  pad0[0x18];
    Obj *(*get)(u32);
} Vtbl;

extern Entry gCommEntryMsgTable[];

extern void COMM_ENTRY_MENU_CheckDisconnects(u8 *p);
extern void COMM_ENTRY_MENU_UpdateMemberList(u8 *p);
extern void COMM_ENTRY_MENU_ProcessMemberQueues(u8 *p);
extern void COMM_ENTRY_MENU_OpenWindows(u32 *p);
extern void COMM_ENTRY_MENU_PrintMessage(Work *p, int n);
extern void GFL_NET_StartByNetType(void);
extern int GFL_NET_SYSTEM_GetConnectNum(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern u32 func_020362DC(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);
extern u32 COMM_ENTRY_SendJoinRequest(u32 a, u32 b, u32 c);
extern void COMM_ENTRY_MENU_AdvanceMemberStates(u8 *p);
extern void COMM_ENTRY_MENU_ProcessRequest(u32 *p);
extern int COMM_ENTRY_MENU_IsIdle(u32 a);
extern int COMM_ENTRY_MENU_CountAcceptedMembers(Work *p);
extern void COMM_ENTRY_MENU_SnapshotStates(Work *p);
extern int GFL_NET_GetNegotiationNum(void);
extern int COMM_ENTRY_MENU_ProcessCancel(u32 *p);
extern void GFL_NET_NotifyUserEvent(u32 unused, void *arg);
extern u32 COMM_ENTRY_MENU_ProcessStartConfirm(u32 *p);
extern int COMM_ENTRY_SendSessionLock(int a);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void COMM_ENTRY_MENU_MarkMemberReady(Work *p, int a);
extern void GFL_NET_SetLoginOption(u8 a0);
extern u32 GFL_NET_IsConnectMember(u32 index);
extern u32 func_02080D24(int a);
extern int COMM_ENTRY_SendCancel(int a);
extern int COMM_ENTRY_SendAccept(int a);
struct Link;
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern unsigned int func_02039CB4(struct Link *a, unsigned int b, unsigned int c);
extern void *GFL_NET_GetInitParam(void);
extern u32 GFL_NET_GetUserArg(void);
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);
extern int COMM_ENTRY_IsOtherMemberConnected(int a);
extern void COMM_ENTRY_MENU_CloseWindows(u32 *p);
extern u32 func_0200FB24(void);

int COMM_ENTRY_MENU_MainRecruit(Work *p)
{
    int n;
    u16 saved;
    u8 mask;
    u8 i;

    if (p->state != 0) {
        COMM_ENTRY_MENU_CheckDisconnects((u8 *)p);
        COMM_ENTRY_MENU_UpdateMemberList((u8 *)p);
        COMM_ENTRY_MENU_ProcessMemberQueues((u8 *)p);
    }

    switch (p->state) {
    case 0:
        COMM_ENTRY_MENU_OpenWindows((u32 *)p);
        COMM_ENTRY_MENU_PrintMessage(p, 8);
        p->state++;
        break;
    case 1:
        if (p->x520 == 0) {
            p->state = 4;
        } else {
            GFL_NET_StartByNetType();
            p->state++;
        }
        break;
    case 2:
        if (GFL_NET_SYSTEM_GetConnectNum() > 1) {
            if (GFL_NET_HANDLE_CheckNegotiation() == 1) {
                p->state++;
            }
        } else if (func_020362DC() & 2) {
            p->state = 7;
            p->x2C = 2;
            p->state = 0x13;
        }
        break;
    case 3:
        if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)((u32)GFL_NET_HANDLE_GetCurrentHandle())) == 1) {
            p->state = 4;
        }
        break;
    case 4:
        if (COMM_ENTRY_SendJoinRequest((u32)p->sub, 1, p->x51B) == 1) {
            p->state++;
        }
        break;
    case 5:
        COMM_ENTRY_MENU_AdvanceMemberStates((u8 *)p);
        COMM_ENTRY_MENU_ProcessRequest((u32 *)p);
        if (COMM_ENTRY_MENU_IsIdle((u32)p) == 1) {
            n = COMM_ENTRY_MENU_CountAcceptedMembers(p);
            saved = p->x574;
            p->x574 = 0xFFFF;
            if (n >= p->x51D || (n >= p->x51C && (func_020362DC() & 1))) {
                COMM_ENTRY_MENU_SnapshotStates(p);
                p->state = 6;
            } else if (func_020362DC() & 2) {
                p->state = 7;
            } else if (p->x520 == 0 && GFL_NET_GetNegotiationNum() <= 1) {
                p->state = 0x11;
            } else if (saved != 0xFFFF) {
                COMM_ENTRY_MENU_PrintMessage(p, saved);
            }
        }
        break;
    case 6:
        n = COMM_ENTRY_MENU_ProcessCancel((u32 *)p);
        if (n == 1) {
            GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
            p->state = 9;
        } else if (n == 2) {
            if (COMM_ENTRY_MENU_CountAcceptedMembers(p) >= p->x51D) {
                p->state = 7;
            } else {
                p->state = 5;
                if (COMM_ENTRY_MENU_CountAcceptedMembers(p) > 1 && p->x520 == 1) {
                    p->x574 = 9;
                } else {
                    p->x574 = 8;
                }
            }
        }
        break;
    case 7:
        n = COMM_ENTRY_MENU_ProcessStartConfirm((u32 *)p);
        if (n == 1) {
            GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
            p->state = 0xD;
        } else if (n == 2) {
            p->state = 5;
        }
        break;
    case 9:
        if (COMM_ENTRY_SendSessionLock(p->x51B) == 1) {
            COMM_ENTRY_MENU_MarkMemberReady(p, GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())));
            p->x526 = p->x514;
            GFL_NET_SetLoginOption(1);
            p->state = 10;
        }
        break;
    case 10:
        mask = 1 << GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
        for (i = 0; (i < 4) ? 1 : 0; i++) {
            if (i != GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())) && (p->x526 & (1u << i))) {
                if (GFL_NET_IsConnectMember(i) == 1) {
                    if (p->x578 & (1 << (u32)i)) {
                        mask |= (u8)(1 << i);
                    }
                } else {
                    p->state = 0xB;
                    break;
                }
            }
        }
        if (p->x526 == mask) {
            if (func_02080D24(p->x578) < p->x51C) {
                p->state = 0xB;
            } else {
                p->state = 0xC;
            }
        }
        break;
    case 11:
        if (COMM_ENTRY_SendCancel(p->x51B) == 1) {
            p->x526 = p->x514;
            p->x2C = 2;
            p->state = 0xE;
        }
        break;
    case 12:
        if (COMM_ENTRY_SendAccept(p->x51B) == 1) {
            p->x2C = 1;
            p->state = 8;
            p->x573 = func_02080D24(p->x578);
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27);
        }
        break;
    case 8:
        if (p->x573 != GFL_NET_SYSTEM_GetConnectNum() || p->x51C > GFL_NET_SYSTEM_GetConnectNum()) {
            if (COMM_ENTRY_SendCancel(p->x51B) == 1) {
                p->x526 = p->x514;
                p->x2C = 2;
                p->state = 0xE;
            }
        } else if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27) == 1) {
            Vtbl *v;

            p->x2C = 1;
            p->state = 0x13;
            v = GFL_NET_GetInitParam();
            v->get(GFL_NET_GetUserArg())->f26 = 0;
        }
        break;
    case 13:
        if (COMM_ENTRY_SendCancel(p->x51B) == 1) {
            p->x526 = p->x514;
            p->x2C = 2;
            p->state = 0x10;
        }
        break;
    case 14:
        {
            Entry *e = &gCommEntryMsgTable[p->x520];

            COMM_ENTRY_MENU_PrintMessage(p, e->f8);
        }
        p->state = 0xF;
        break;
    case 15:
        if (FIELD_MSGBG_SysWinMain((u32 *)p->h) == 1) {
            p->state = 0x10;
        }
        break;
    case 16:
        if (COMM_ENTRY_IsOtherMemberConnected(p->x526) == 0) {
            p->state = 0x13;
        }
        break;
    case 17:
        COMM_ENTRY_MENU_PrintMessage(p, 0x14);
        p->state = 0x12;
        break;
    case 18:
        if (FIELD_MSGBG_SysWinMain((u32 *)p->h) == 1) {
            p->x2C = 2;
            p->state = 0x13;
        }
        break;
    case 19:
        COMM_ENTRY_MENU_CloseWindows((u32 *)p);
        return 1;
    }

    if (func_0200FB24() != 0) {
        p->x2C = 4;
        return 1;
    }
    return 0;
}
