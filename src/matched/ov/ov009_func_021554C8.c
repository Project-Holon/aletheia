/*
 * function: DWC_RAP_StepLogin
 * address:  0x021554C8
 * packet:   pkt_ov009_021554C8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * checks: 1 SDK bodies confirm arities and payloads, case6 returns observed r0=0x3EF; 2 ov009 neighbours no complete twin; 3 u16/u8 flag both unchanged DIFF10; 4 block-local u16 name[2]={0,0} fixes address lifetime, MATCH384; 5 fresh idioms/neighbours and stack-storage idiom reread.
 * EXACT after verified ov009 leaves02155C24/02155C6C attest +170/+178. TU suggest-split diagnostic completed before leaf shards: MATCH, no viable cut. Prior once300 consumed, never repeated.
 * Fresh retry: 10 one runs plus TU; assignment-return85, constant local return10, raw name/pair/union and flag widths10; initializer closes concrete bytes. No volatile or input-domain restriction.
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   d_021A8264_obj 0x021A8264  data  ov009  a4
 *   d_021A1C6C     0x021A1C6C  data  ov009  a1
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_0205C6AC  0x0205C6AC  arm
 *   func_0205C758  0x0205C758  arm
 *   func_0205C88C  0x0205C88C  arm
 *   func_0205CA20  0x0205CA20  arm
 *   func_0205C8E0  0x0205C8E0  arm
 *   DWC_InitFriendsMatch  0x0216AB20  arm
 *   func_02087C88  0x02087C88  arm
 *   DWC_LoginAsync  0x0216B0E0  arm
 *   DWC_ProcessFriendsMatch  0x0216AE88  arm
 *   DWC_UpdateServersAsync  0x0216B1E0  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   func_02168994  0x02168994  arm
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 *   DWC_RAP_HandleError  0x02155F58  thumb  ov009
 *   DWC_RAP_OnLogin  0x02155B98  thumb  ov009
 *   DWC_RAP_OnUpdateServers  0x02155C0C  thumb  ov009
 *   DWC_RAP_OnFriendStatusNop  0x02155C24  thumb  ov009
 *   DWC_RAP_OnFriendDeleted  0x02155C28  thumb  ov009
 *   DWC_RAP_OnBuddyFriendNop  0x02155C6C  thumb  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    char pad0[0x100];
    void *w100;
    char pad104[0x108 - 0x104];
    void *w108;
    char x10C[0x754 - 0x10C];
    int state;
    int w758;
    char pad75C[0x76C - 0x75C];
    int w76C;
    char pad770[0x7A9 - 0x770];
    u8 b7A9;
} G;

typedef struct {
    u16 a;
    u16 b;
    char buf[0x54];
} Req;

typedef void (*Fn)(void);
typedef struct {
    u8 language, favoriteColor, month, day;
    u16 nickName[11], nickNameLength, comment[27], commentLength;
} OSOwnerInfo;

extern G *_pRapWork;
extern char d_021A8264_obj[];
extern char d_021A1C6C[];
void *GFL_NET_GetInitParam(void);
void func_0205C6AC(void *p, u16 a, u16 b, u16 c);
void func_0205C758(void);
int func_0205C88C(void);
int func_0205CA20(void);
void func_0205C8E0(void);
void DWC_InitFriendsMatch(void *a, int b, char *c, int d, int e, void *f, int g);
typedef signed int     s32;
struct OSOwnerInfo;
void func_02087C88(struct OSOwnerInfo *info);
int DWC_LoginAsync(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param);
void DWC_ProcessFriendsMatch(void);
int DWC_UpdateServersAsync(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam);
void GFL_NET_STATE_SetError(int a, unsigned int b, unsigned int c, unsigned int d);
int func_02168994(void (*callback)(int, void *), void *param);
void DWC_RAP_SetState(int v);
int DWC_RAP_HandleError(void);
void DWC_RAP_OnLogin(int a);
void DWC_RAP_OnUpdateServers(int a);
void DWC_RAP_OnFriendStatusNop(void);
void DWC_RAP_OnFriendDeleted(s32 a, s32 b);
void DWC_RAP_OnBuddyFriendNop(void);

int DWC_RAP_StepLogin(void)
{
    OSOwnerInfo info;
    void *m;
    int flag;
    int ret;

    switch (_pRapWork->state) {
    case 0:
        GFL_NET_GetInitParam();
        func_0205C6AC(_pRapWork->x10C, 2, 1, 0x14);
        func_0205C758();
        DWC_RAP_SetState(1);
        _pRapWork->w76C = 0;
    case 1:
        if (func_0205C88C() != 0) {
            if (func_0205CA20() == 4)
                DWC_RAP_SetState(2);
            else
                DWC_RAP_SetState(14);
        } else {
            func_0205C8E0();
            break;
        }
    case 2:
        ret = DWC_RAP_HandleError();
        if (ret != 0)
            return ret;
        flag = 0;
        m = _pRapWork->w100;
        if (m != 0)
            flag = 0x20;
        DWC_InitFriendsMatch(_pRapWork->w108, 0x2FC6, d_021A1C6C, 0, 0, m, flag);
        _pRapWork->b7A9 = 1;
        { u16 name[2] = {0, 0};
        func_02087C88((struct OSOwnerInfo *)(&info));
        DWC_LoginAsync(name, 0, (void (*)(int,  int,  void *))((Fn)DWC_RAP_OnLogin), 0);
        }
        DWC_RAP_SetState(3);
    case 3:
        DWC_ProcessFriendsMatch();
        break;
    case 4:
        if (_pRapWork->w100 != 0) {
            if (DWC_UpdateServersAsync(0, DWC_RAP_OnUpdateServers, _pRapWork->w108,
                              DWC_RAP_OnFriendStatusNop, d_021A8264_obj, DWC_RAP_OnFriendDeleted,
                              d_021A8264_obj) == 0) {
                GFL_NET_STATE_SetError(0, 0, 0, 0x3EE);
            } else {
                func_02168994((void (*)(int,  void *))DWC_RAP_OnBuddyFriendNop, 0);
                DWC_ProcessFriendsMatch();
            }
        }
        DWC_RAP_SetState(5);
        break;
    case 5:
        DWC_ProcessFriendsMatch();
        if (_pRapWork->w100 == 0)
            DWC_RAP_SetState(6);
        break;
    case 6:
        DWC_ProcessFriendsMatch();
        { int code = 0x3EF; _pRapWork->w758 = code; return code; }
    }
    return DWC_RAP_HandleError();
}
