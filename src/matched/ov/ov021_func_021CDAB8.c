/*
 * function: COMM_ENTRY_MENU_MainMode1
 * address:  0x021CDAB8
 * packet:   pkt_ov021_021CDAB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   COMM_ENTRY_MENU_EndYesNo  0x021CEB64  thumb  ov021
 *   COMM_ENTRY_MENU_CloseWindows  0x021CE81C  thumb  ov021
 *   COMM_ENTRY_MENU_StartYesNo  0x021CEB20  thumb  ov021
 *   GFL_NET_BeaconScanStart  0x0203D010  arm
 *   COMM_ENTRY_MENU_MainYesNo  0x021CEB84  thumb  ov021
 *   func_0201F02C  0x0201F02C  thumb
 *   COMM_ENTRY_MENU_OpenWindows  0x021CE7AC  thumb  ov021
 *   COMM_ENTRY_RunLeaveConfirm  0x021CF068  thumb  ov021
 *   COMM_ENTRY_ResetLeaveConfirm  0x021CF0F4  thumb  ov021
 *   COMM_ENTRY_SendReady  0x021CF32C  thumb  ov021
 *   COMM_ENTRY_MENU_RefreshNames  0x021CE9A0  thumb  ov021
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_02082D44  0x02082D44  arm
 *   COMM_ENTRY_EndNetCommands  0x021CF17C  thumb  ov021
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   COMM_ENTRY_StartNetCommands  0x021CF164  thumb  ov021
 *   func_0200FB24  0x0200FB24  thumb
 *   gCommEntryMsgTable  0x021DB498  data   ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void COMM_ENTRY_MENU_PrintMessage(u8 *p, int n);
struct Req;
struct WordSet;
extern u32 FIELD_MSGBG_SysWinMain(u32 *p);
extern void COMM_ENTRY_MENU_EndYesNo(u8 *p);
extern void COMM_ENTRY_MENU_CloseWindows(u32 *p);
extern void COMM_ENTRY_MENU_StartYesNo(u8 *p);
extern void GFL_NET_BeaconScanStart(void);
extern u32 COMM_ENTRY_MENU_MainYesNo(u8 *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void COMM_ENTRY_MENU_OpenWindows(u32 *p);
extern int COMM_ENTRY_RunLeaveConfirm(u8 *p);
extern void COMM_ENTRY_ResetLeaveConfirm(u8 *p);
extern u32 COMM_ENTRY_SendReady(u32 flag);
extern void COMM_ENTRY_MENU_RefreshNames(u8 *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern u32 GFL_NET_GetUserArg(void);
extern void *GFL_NET_GetInitParam(void);
extern void func_02082D44(void *src, void *dst, int n);
extern void COMM_ENTRY_EndNetCommands(void);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern int GFL_NET_GetRunState(void);
extern void COMM_ENTRY_StartNetCommands(u32 a);
extern u32 func_0200FB24(void);
extern u8 gCommEntryMsgTable[];

#define U32(o) (*(u32 *)(p + (o)))

int COMM_ENTRY_MENU_MainMode1(u8 *p)
{
    switch (p[0x51E]) {
    case 0:
        COMM_ENTRY_MENU_PrintMessage(p, *(u16 *)(gCommEntryMsgTable + p[0x520] * 12 + 10));
        p[0x51E]++;
        break;
    case 1:
        if (FIELD_MSGBG_SysWinMain((u32 *)U32(0x14)) == 1) {
            p[0x51E]++;
        }
        break;
    case 2:
        COMM_ENTRY_MENU_EndYesNo(p);
        COMM_ENTRY_MENU_CloseWindows((u32 *)p);
        U32(0x404) = 0;
        COMM_ENTRY_MENU_StartYesNo(p);
        GFL_NET_BeaconScanStart();
        p[0x51E]++;
        break;
    case 3:
        switch (COMM_ENTRY_MENU_MainYesNo(p)) {
        case 1:
            COMM_ENTRY_MENU_EndYesNo(p);
            if (p[0x519] == 1) {
                p[0x51E] = 6;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 8;
            } else {
                func_0201F02C((struct WordSet *)U32(4), 0, (void *)U32(0x404));
                COMM_ENTRY_MENU_PrintMessage(p, 0x21);
                p[0x51E] = 4;
            }
            break;
        case 2:
            COMM_ENTRY_MENU_EndYesNo(p);
            p[0x51E] = 10;
            break;
        case 3:
            COMM_ENTRY_MENU_EndYesNo(p);
            p[0x51E] = 0xe;
            break;
        }
        break;
    case 4:
        if (FIELD_MSGBG_SysWinMain((u32 *)U32(0x14)) == 1) {
            COMM_ENTRY_MENU_PrintMessage(p, 0x22);
            COMM_ENTRY_MENU_OpenWindows((u32 *)p);
            p[0x51E]++;
        }
        break;
    case 5:
        if (COMM_ENTRY_RunLeaveConfirm(p) == 2) {
            COMM_ENTRY_MENU_CloseWindows((u32 *)p);
            COMM_ENTRY_ResetLeaveConfirm(p);
            p[0x51E] = 0xe;
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
            p[0x51E] = 6;
        } else if (p[0x51A] == 1) {
            COMM_ENTRY_MENU_CloseWindows((u32 *)p);
            COMM_ENTRY_ResetLeaveConfirm(p);
            p[0x51E] = 8;
        }
        break;
    case 6:
        if (p[0x520] == 0) {
            COMM_ENTRY_MENU_PrintMessage(p, 0x1e);
        }
        p[0x51E] = 7;
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27);
        break;
    case 7:
        if (p[0x520] != 0 || FIELD_MSGBG_SysWinMain((u32 *)U32(0x14)) == 1) {
            if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27) == 1) {
                U32(0x2c) = 1;
                p[0x51E] = 0xf;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 8;
            }
        }
        break;
    case 8:
        COMM_ENTRY_MENU_PrintMessage(p, *(u16 *)(gCommEntryMsgTable + p[0x520] * 12 + 8));
        p[0x51E] = 9;
        break;
    case 9:
        if (FIELD_MSGBG_SysWinMain((u32 *)U32(0x14)) == 1) {
            p[0x51E] = 0xe;
        }
        break;
    case 10:
        U32(0x484) = GFL_NET_GetUserArg();
        func_02082D44(GFL_NET_GetInitParam(), p + 0x414, 0x70);
        COMM_ENTRY_EndNetCommands();
        GFL_NET_Exit(0);
        func_0201F02C((struct WordSet *)U32(4), 0, (void *)((int)(p + 0x530)));
        COMM_ENTRY_MENU_PrintMessage(p, 0x1f);
        p[0x51E] = 0xb;
        break;
    case 11:
        if (GFL_NET_IsSessionNull() == 1 && FIELD_MSGBG_SysWinMain((u32 *)U32(0x14)) == 1) {
            p[0x51E] = 0xc;
        }
        break;
    case 12:
        GFL_NET_StartSession((struct Req *)(p + 0x414), 0, (u32)((void *)U32(0x484)));
        p[0x51E] = 0xd;
        break;
    case 13:
        if (GFL_NET_GetRunState() == 1) {
            COMM_ENTRY_StartNetCommands((u32)p);
            p[0x51E] = 0;
        }
        break;
    case 14:
        U32(0x2c) = 2;
        p[0x51E] = 0xf;
        break;
    case 15:
        COMM_ENTRY_MENU_EndYesNo(p);
        COMM_ENTRY_MENU_CloseWindows((u32 *)p);
        return 1;
    }
    if (func_0200FB24() != 0) {
        COMM_ENTRY_ResetLeaveConfirm(p);
        COMM_ENTRY_MENU_EndYesNo(p);
        U32(0x2c) = 4;
        return 1;
    }
    return 0;
}
