/*
 * file:     unit_021D1D04_p03.c
 * unit:     yes
 * function: func_021D2420, func_021D2450, func_021D276C
 * address:  0x021D2420
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021DE65C                     0x021DE65C  data
 *   DWCi_MOV_MBP_GetState          0x021D2780  arm
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   DWCi_MOV_MBP_GetChildState     0x021D27EC  arm
 *   MBPi_CheckAllReboot            0x021D2420  arm
 *   DWCi_MOV_MBP_KickChild         0x021D200C  arm
 *   DWCi_MOV_MBP_AcceptChild       0x021D1F6C  arm
 *   MB_CommGetChildUser            0x021F1B64  arm  ov107
 *   MI_CpuCopy8                    0x02082D44  arm
 *   DWCi_MOV_MBP_StartDownload     0x021D20E8  arm
 *   DWCi_MOV_MBP_ChangeState       0x021D276C  arm
 *   OS_Terminate                   0x02088234  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
    u8 user[0x16];
    u8 macAddress[6];
    u16 playerNo;
} DWCi_MOV_MBPChildInfo;

typedef struct {
    u16 state;
    u16 connectChildBmp;
    u16 requestChildBmp;
    u16 entryChildBmp;
    u16 downloadChildBmp;
    u16 bootableChildBmp;
    u16 rebootChildBmp;
} DWCi_MOV_MBPState;

typedef struct {
    DWCi_MOV_MBPState mbpState;
    DWCi_MOV_MBPChildInfo childInfo[1];
} DWCi_MOV_WPB_WORK;

typedef struct {
    u16 f0;
    u8 pad[8];
    u8 mac[6];
} MBUserInfo;

extern void func_021F5F74(void);
extern u16 DWCi_MOV_MBP_GetState(void);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern int DWCi_MOV_MBP_GetChildState(u16 aid);
extern void MBPi_CheckAllReboot(void);
extern void DWCi_MOV_MBP_KickChild(u16 child_aid);
extern void DWCi_MOV_MBP_AcceptChild(u16 child_aid);
extern void *MB_CommGetChildUser(u16 child_aid);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern void DWCi_MOV_MBP_StartDownload(u16 child_aid);
extern void DWCi_MOV_MBP_ChangeState(u16 state);
extern void OS_Terminate(void);
void func_021D2420(void);
void func_021D276C(unsigned short v);
extern DWCi_MOV_WPB_WORK *g_021DE65C;


/*
 * Guard on the kind and the paired words of the object at 0x021DE65C.
 * Addresses are Black-image addresses.
 */
void func_021D2420(void)
{
    unsigned short *p = *(unsigned short **)0x021DE65C;

    if (p[0] != 4)
        return;
    if (p[1] != p[6])
        return;
    func_021F5F74();
}


static void ParentStateCallback(u16 child_aid, u32 status, void *arg)
{
    MBUserInfo *userInfo = (MBUserInfo *)arg;
    void *childUser;

    switch (status) {
    case 1:
        break;
    case 2:
        if (DWCi_MOV_MBP_GetState() == 2) {
            DWCi_MOV_WPB_WORK *w = g_021DE65C;
            u32 enabled = OS_DisableInterrupts();
            u8 *mac;

            w->mbpState.connectChildBmp |= 1 << child_aid;
            OS_RestoreInterrupts(enabled);
            mac = g_021DE65C->childInfo[child_aid - 1].macAddress;
            mac[0] = userInfo->mac[0];
            mac[1] = userInfo->mac[1];
            mac[2] = userInfo->mac[2];
            mac[3] = userInfo->mac[3];
            mac[4] = userInfo->mac[4];
            mac[5] = userInfo->mac[5];
            g_021DE65C->childInfo[child_aid - 1].playerNo = child_aid;
        }
        break;
    case 3:
        if (DWCi_MOV_MBP_GetChildState(child_aid) != 6) {
            u16 mask = ~(1 << child_aid);
            u32 enabled = OS_DisableInterrupts();

            g_021DE65C->mbpState.connectChildBmp &= mask;
            g_021DE65C->mbpState.requestChildBmp &= mask;
            g_021DE65C->mbpState.entryChildBmp &= mask;
            g_021DE65C->mbpState.downloadChildBmp &= mask;
            g_021DE65C->mbpState.bootableChildBmp &= mask;
            g_021DE65C->mbpState.rebootChildBmp &= mask;
            OS_RestoreInterrupts(enabled);
            MBPi_CheckAllReboot();
        }
        break;
    case 4:
    case 5:
    case 6:
        break;
    case 10:
        if (DWCi_MOV_MBP_GetState() != 2) {
            DWCi_MOV_MBP_KickChild(child_aid);
        } else {
            g_021DE65C->mbpState.requestChildBmp |= 1 << child_aid;
            DWCi_MOV_MBP_AcceptChild(child_aid);
            childUser = MB_CommGetChildUser(child_aid);
            if (childUser)
                MI_CpuCopy8(childUser, g_021DE65C->childInfo[child_aid - 1].user, 0x16);
        }
        break;
    case 14:
        g_021DE65C->mbpState.requestChildBmp &= ~(1 << child_aid);
        g_021DE65C->mbpState.entryChildBmp |= 1 << child_aid;
        if (DWCi_MOV_MBP_GetState() == 3)
            DWCi_MOV_MBP_StartDownload(child_aid);
        break;
    case 7:
        g_021DE65C->mbpState.downloadChildBmp &= ~(1 << child_aid);
        g_021DE65C->mbpState.bootableChildBmp |= 1 << child_aid;
        break;
    case 8:
        break;
    case 9:
        g_021DE65C->mbpState.bootableChildBmp &= ~(1 << child_aid);
        g_021DE65C->mbpState.rebootChildBmp |= 1 << child_aid;
        MBPi_CheckAllReboot();
        break;
    case 11:
        break;
    case 12: {
        if (DWCi_MOV_MBP_GetState() == 4)
            DWCi_MOV_MBP_ChangeState(5);
        else
            DWCi_MOV_MBP_ChangeState(0);
        {
            char *p = (char *)g_021DE65C;
            p += 0x1b000;
            if (*(int *)(p + 0x144))
                *(int *)(p + 0x144) = 0;
        }
        {
            char *p = (char *)g_021DE65C;
            p += 0x1b000;
            if (*(int *)(p + 0x140))
                *(int *)(p + 0x140) = 0;
        }
        break;
    }
    case 13:
        switch (userInfo->f0) {
        case 8:
            break;
        case 9:
        case 1:
        case 2:
            DWCi_MOV_MBP_ChangeState(7);
            break;
        default:
            break;
        }
        break;
    case 0:
    default:
        OS_Terminate();
        break;
    }
}

/*
 * Store a halfword at the head of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D276C.c \
 *       --func func_021D276C --addr 0x021D276C --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021D276C(unsigned short v)
{
    *(unsigned short *)(*(char **)0x021DE65C) = v;
}
