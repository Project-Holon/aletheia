/*
 * function: ParentStateCallback
 * address:  0x021D2450
 * packet:   pkt_ov016_021D2450
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  near miss (792 vs 796 compiled). Residue is codegen, not source
 *           shape: (1) the object allocates child_aid to r8 and the case-2
 *           wb temp to r6 (push {r4,r5,r6,r7,r8,lr}); dsi/1.1p1 allocates the
 *           same values one register lower (push {r3,r4,r5,r6,r7,lr}, r7/r6/r3)
 *           although every instruction body matches. (2) MSG-case 0xd switch
 *           on arg->f0 lowers to a range tree in the object (cmp #8/bgt, then
 *           ==2, ==1, ==9) but to a linear chain under 1.1p1. dwc_mov_mbp.o
 *           carries its own .comment 4.0.0.1025, between 1.1p1 (1024) and
 *           1.2 (1026); its smaller functions reproduce exactly, this largest
 *           one does not. No source spelling of the two forms above flipped
 *           either residue (12+ variants tried).
 *
 * sdk:      ParentStateCallback (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
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

extern DWCi_MOV_WPB_WORK *g_021DE65C;
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

static void ParentStateCallback(u16 child_aid, u32 status, void *arg)
{
    MBUserInfo *userInfo = (MBUserInfo *)arg;
    void *childUser;

    switch (status) {
    case 1:
        break;
    case 2:
        if (DWCi_MOV_MBP_GetState() == 2) {
            u32 enabled = OS_DisableInterrupts();
            u8 *mac;

            g_021DE65C->mbpState.connectChildBmp |= 1 << child_aid;
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
        if (DWCi_MOV_MBP_GetState() == 2) {
            g_021DE65C->mbpState.requestChildBmp |= 1 << child_aid;
            DWCi_MOV_MBP_AcceptChild(child_aid);
            childUser = MB_CommGetChildUser(child_aid);
            if (childUser)
                MI_CpuCopy8(childUser, g_021DE65C->childInfo[child_aid - 1].user, 0x16);
        } else {
            DWCi_MOV_MBP_KickChild(child_aid);
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
        if (*(u32 *)((char *)g_021DE65C + 0x1b144))
            *(u32 *)((char *)g_021DE65C + 0x1b144) = 0;
        if (*(u32 *)((char *)g_021DE65C + 0x1b140))
            *(u32 *)((char *)g_021DE65C + 0x1b140) = 0;
        break;
    }
    case 13:
        switch (userInfo->f0) {
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
        OS_Terminate();
        break;
    default:
        OS_Terminate();
        break;
    }
}

