/*
 * file:     dwc_mov_mbp.c
 * unit:     yes
 * function: DWCi_MOV_MBP_MemInit, DWCi_MOV_MBP_Init, DWCi_MOV_MBP_Start, DWCi_MOV_MBP_RegistFile, DWCi_MOV_MBP_AcceptChild, DWCi_MOV_MBP_KickChild, DWCi_MOV_MBP_StartDownload, DWCi_MOV_MBP_StartDownloadAll, DWCi_MOV_MBP_IsBootableAll, DWCi_MOV_MBP_StartRebootAll, DWCi_MOV_MBP_Cancel, MBPi_CheckAllReboot, ParentStateCallback, DWCi_MOV_MBP_ChangeState, DWCi_MOV_MBP_GetState, DWCi_MOV_MBP_GetChildBmp, DWCi_MOV_MBP_GetChildState, DWCi_MOV_MBP_GetChildInfo, DWCi_MOV_MBP_GetPlayerNo
 * address:  0x021D1D04
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
 *   DWCi_MOV_WH_MemInit            0x021D298C  arm  ov016
 *   DWCi_DwcMoveidMB_EndToIdle     0x021F5F74  arm  ov016
 *   MI_CpuCopy8 0x02082D44 arm
 *   MB_Init 0x021F5904 arm
 *   OS_Terminate 0x02088234 arm
 *   MB_SetParentCommParam 0x021F5B4C arm
 *   MB_CommSetParentStateCallback 0x021F1B3C arm
 *   ParentStateCallback 0x021D2450 arm ov016
 *   gDwcMovMbpWork 0x021DE65C data
 *   MB_StartParentFromIdle  0x021f5e7c  arm  ov107
 *   FS_InitFile                      0x020788AC  arm
 *   FS_OpenFile                      0x02078C18  arm
 *   MB_GetSegmentLength              0x021F2F1C  arm
 *   MB_ReadSegment                   0x021F2FA0  arm
 *   MB_RegisterFile                  0x021F3544  arm
 *   FS_CloseFile                     0x02078A80  arm
 *   MB_CommResponseRequest  0x021F1C30  arm  ov107
 *   MB_DisconnectChild  0x021F5FB0  arm  ov107
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   DWCi_MOV_MBP_ChangeState         0x021D276C  arm  ov016
 *   DWCi_MOV_MBP_StartDownload       0x021D20E8  arm  ov016
 *   MB_CommIsBootable                0x021F1BE0  arm
 *   MB_EndToIdle                     0x021F5F74  arm
 *   DWCi_MOV_MBP_GetState          0x021D2780  arm
 *   DWCi_MOV_MBP_GetChildState     0x021D27EC  arm
 *   MBPi_CheckAllReboot            0x021D2420  arm
 *   DWCi_MOV_MBP_KickChild         0x021D200C  arm
 *   DWCi_MOV_MBP_AcceptChild       0x021D1F6C  arm
 *   MB_CommGetChildUser            0x021F1B64  arm  ov107
 *   sDwcMovMbpTable  0x021db9d4  data
 *   gMovMbpBuffers  0x021DB9D4  data
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
    u8 favoriteColor : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;

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
    u8 boot_seg_buf[0x10000];
    u8 pad1[0x10040 - 0x1002c];
    u32 work_area_for_mb[11328];
    u32 *sCWork;
    u8 *sFilebuf;
} DWCi_MOV_WPB_WORK;

typedef struct {
    char *romFilePathp;
    u16 *gameNamep;
    u16 *gameIntroductionp;
    char *iconCharPathp;
    char *iconPalettePathp;
    u32 ggid;
    u8 maxPlayerNum;
    u8 pad[3];
    u8 userParam[32];
} MBGameRegistry;

typedef struct { u8 b[0x48]; } FSFile;

typedef struct {
    u16 errCode;
    u8 pad[8];
    u8 mac[6];
} ParentCbArg;

typedef enum {
    CS_NONE,
    CS_CONNECT,
    CS_REQUEST,
    CS_ENTRY,
    CS_DOWNLOAD,
    CS_BOOTABLE,
    CS_REBOOT
} ChildState;

extern void DWCi_MOV_WH_MemInit(int);
extern int MB_Init(void *work, MBUserInfo *user, u32 ggid, u32 tgid, u32 dma);
extern int MB_SetParentCommParam(u16 sendSize, u16 maxChildren);
extern void MB_CommSetParentStateCallback(void (*cb)(u16, u32, void *));
extern int MB_StartParentFromIdle(int channel);
extern void FS_InitFile(FSFile *file);
extern int FS_OpenFile(FSFile *file, char *path);
extern u32 MB_GetSegmentLength(FSFile *file);
extern int MB_ReadSegment(FSFile *file, void *buf, u32 len);
extern int MB_RegisterFile(MBGameRegistry *game_reg, void *buf);
extern int FS_CloseFile(FSFile *file);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern int MB_CommResponseRequest(u16 child_aid, int ack);
extern void MB_DisconnectChild(u16 aid);
void DWCi_MOV_MBP_ChangeState(unsigned short v);
void DWCi_MOV_MBP_StartDownload(u16 child_aid);
extern int MB_CommIsBootable(u16 child_aid);
extern void MB_EndToIdle(void);
extern void DWCi_DwcMoveidMB_EndToIdle(void);
unsigned short DWCi_MOV_MBP_GetState(void);
ChildState DWCi_MOV_MBP_GetChildState(u16 aid);
void DWCi_MOV_MBP_KickChild(u16 child_aid);
void DWCi_MOV_MBP_AcceptChild(u16 aid);
extern void *MB_CommGetChildUser(u16 child_aid);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern void OS_Terminate(void);
void DWCi_MOV_MBP_MemInit(int x);
void DWCi_MOV_MBP_Init(u32 ggid, u16 tgid);
void DWCi_MOV_MBP_Start(MBGameRegistry *gameInfo, u16 channel);
int DWCi_MOV_MBP_RegistFile(MBGameRegistry *gameInfo);
void DWCi_MOV_MBP_StartDownloadAll(void);
int DWCi_MOV_MBP_IsBootableAll(void);
void DWCi_MOV_MBP_StartRebootAll(void);
void DWCi_MOV_MBP_Cancel(void);
u16 DWCi_MOV_MBP_GetChildBmp(int bmpType);
DWCi_MOV_MBPChildInfo *DWCi_MOV_MBP_GetChildInfo(u16 child_aid);
u16 DWCi_MOV_MBP_GetPlayerNo(u8 *macAddress);
extern DWCi_MOV_WPB_WORK *gDwcMovMbpWork;
extern u16 *sDwcMovMbpTable[6];
extern u16 *gMovMbpBuffers[6];


/*
 * Publish the object, initialise the tail region, and clear its two control words.
 * Addresses are Black-image addresses.
 */

static void MBPi_CheckAllReboot(void);
static void ParentStateCallback(u16 child_aid, u32 status, void *arg);
void DWCi_MOV_MBP_MemInit(int x)
{
    int *g = (int *)0x021DE65C;

    g[0] = x;
    DWCi_MOV_WH_MemInit(x + 0x160 + 0x1b000);
    *(int *)(g[0] + 0x1b000 + 0x140) = 0;
    *(int *)(g[0] + 0x1b000 + 0x144) = 0;
}


/*
 * sdk:      DWCi_MOV_MBP_Init (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
void DWCi_MOV_MBP_Init(u32 ggid, u16 tgid)
{
    MBUserInfo myUser;
    u8 *own = (u8 *)0x02fffc80;
    myUser.favoriteColor = 1;
    myUser.nameLength = own[0x1a];
    MI_CpuCopy8(own + 6, myUser.name, 0x14);
    myUser.playerNo = 0;
    {
        DWCi_MOV_MBPState h = {0};
        gDwcMovMbpWork->mbpState = h;
    }
    gDwcMovMbpWork->sCWork = gDwcMovMbpWork->work_area_for_mb;
    if (MB_Init(gDwcMovMbpWork->sCWork, &myUser, ggid, tgid, 2))
        OS_Terminate();
    MB_SetParentCommParam(0x100, 1);
    MB_CommSetParentStateCallback(ParentStateCallback);
    DWCi_MOV_MBP_ChangeState(1);
}


/*
 * sdk:      DWCi_MOV_MBP_Start (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
void DWCi_MOV_MBP_Start(MBGameRegistry *gameInfo, u16 channel)
{
    DWCi_MOV_MBP_ChangeState(2);
    if (MB_StartParentFromIdle(channel)) {
        DWCi_MOV_MBP_ChangeState(7);
        return;
    }
    if (DWCi_MOV_MBP_RegistFile(gameInfo))
        return;
    OS_Terminate();
}


/*
 * sdk:      DWCi_MOV_MBP_RegistFile (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
int DWCi_MOV_MBP_RegistFile(MBGameRegistry *gameInfo)
{
    FSFile file;
    FSFile *p_file;
    u32 bufferSize;
    int ret = 0;

    if (!gameInfo->romFilePathp) {
        p_file = 0;
    } else {
        p_file = &file;
        FS_InitFile(p_file);
        if (!FS_OpenFile(p_file, gameInfo->romFilePathp))
            return 0;
    }
    bufferSize = MB_GetSegmentLength(p_file);
    if (bufferSize) {
        gDwcMovMbpWork->sFilebuf = gDwcMovMbpWork->boot_seg_buf;
        if (gDwcMovMbpWork->sFilebuf) {
            if (MB_ReadSegment(p_file, gDwcMovMbpWork->sFilebuf, 0x10000)) {
                if (MB_RegisterFile(gameInfo, gDwcMovMbpWork->sFilebuf))
                    ret = 1;
            }
        }
    }
    if (p_file == &file)
        FS_CloseFile(&file);
    return ret;
}


/*
 * sdk:      DWCi_MOV_MBP_AcceptChild (libdwcutil.TWL.HYB.a dwc_mov_mbp.o)
 *
 * note:     the earlier draft read the 0x021DE65C pointer through a cast; declaring
 *           the vendor global `wb` (a pointer to a struct whose first 0xe bytes are
 *           halfwords) gives the object's registers (pool address in r1, pointee r3).
 */
void DWCi_MOV_MBP_AcceptChild(u16 aid)
{
    if (MB_CommResponseRequest(aid, 1) != 0)
        return;
    {
        u16 m = ~(1 << aid);
        unsigned long e = OS_DisableInterrupts();
        gDwcMovMbpWork->mbpState.connectChildBmp &= m;
        gDwcMovMbpWork->mbpState.requestChildBmp &= m;
        gDwcMovMbpWork->mbpState.entryChildBmp &= m;
        gDwcMovMbpWork->mbpState.downloadChildBmp &= m;
        gDwcMovMbpWork->mbpState.bootableChildBmp &= m;
        gDwcMovMbpWork->mbpState.rebootChildBmp &= m;
        OS_RestoreInterrupts(e);
    }
    MB_DisconnectChild(aid);
}


/*
 * sdk:      DWCi_MOV_MBP_KickChild (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
void DWCi_MOV_MBP_KickChild(u16 child_aid)
{
    u32 enabled;
    if (!MB_CommResponseRequest(child_aid, 0)) {
        u16 mask = ~(1 << child_aid);
        enabled = OS_DisableInterrupts();
        gDwcMovMbpWork->mbpState.connectChildBmp &= mask;
        gDwcMovMbpWork->mbpState.requestChildBmp &= mask;
        gDwcMovMbpWork->mbpState.entryChildBmp &= mask;
        gDwcMovMbpWork->mbpState.downloadChildBmp &= mask;
        gDwcMovMbpWork->mbpState.bootableChildBmp &= mask;
        gDwcMovMbpWork->mbpState.rebootChildBmp &= mask;
        OS_RestoreInterrupts(enabled);
        MB_DisconnectChild(child_aid);
        return;
    }
    enabled = OS_DisableInterrupts();
    gDwcMovMbpWork->mbpState.requestChildBmp &= (u16)~(1 << child_aid);
    gDwcMovMbpWork->mbpState.connectChildBmp &= (u16)~(1 << child_aid);
    OS_RestoreInterrupts(enabled);
}


/*
 * sdk:      DWCi_MOV_MBP_StartDownload (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
void DWCi_MOV_MBP_StartDownload(u16 child_aid)
{
    u32 enabled;
    if (!MB_CommResponseRequest(child_aid, 2)) {
        u16 mask = ~(1 << child_aid);
        enabled = OS_DisableInterrupts();
        gDwcMovMbpWork->mbpState.connectChildBmp &= mask;
        gDwcMovMbpWork->mbpState.requestChildBmp &= mask;
        gDwcMovMbpWork->mbpState.entryChildBmp &= mask;
        gDwcMovMbpWork->mbpState.downloadChildBmp &= mask;
        gDwcMovMbpWork->mbpState.bootableChildBmp &= mask;
        gDwcMovMbpWork->mbpState.rebootChildBmp &= mask;
        OS_RestoreInterrupts(enabled);
        MB_DisconnectChild(child_aid);
        return;
    }
    enabled = OS_DisableInterrupts();
    gDwcMovMbpWork->mbpState.entryChildBmp &= (u16)~(1 << child_aid);
    gDwcMovMbpWork->mbpState.downloadChildBmp |= (u16)(1 << child_aid);
    OS_RestoreInterrupts(enabled);
}


/*
 * sdk:      DWCi_MOV_MBP_StartDownloadAll (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
void DWCi_MOV_MBP_StartDownloadAll(void)
{
    u16 i;
    DWCi_MOV_MBP_ChangeState(3);
    for (i = 1; i < 16; i++) {
        if (!(gDwcMovMbpWork->mbpState.connectChildBmp & (1 << i)))
            continue;
        if (gDwcMovMbpWork->mbpState.requestChildBmp & (1 << i))
            continue;
        if (!(gDwcMovMbpWork->mbpState.entryChildBmp & (1 << i))) {
            u16 mask = ~(1 << i);
            u32 enabled = OS_DisableInterrupts();
            gDwcMovMbpWork->mbpState.connectChildBmp &= mask;
            gDwcMovMbpWork->mbpState.requestChildBmp &= mask;
            gDwcMovMbpWork->mbpState.entryChildBmp &= mask;
            gDwcMovMbpWork->mbpState.downloadChildBmp &= mask;
            gDwcMovMbpWork->mbpState.bootableChildBmp &= mask;
            gDwcMovMbpWork->mbpState.rebootChildBmp &= mask;
            OS_RestoreInterrupts(enabled);
            MB_DisconnectChild(i);
        } else {
            DWCi_MOV_MBP_StartDownload(i);
        }
    }
}


/*
 * sdk:      DWCi_MOV_MBP_IsBootableAll (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
int DWCi_MOV_MBP_IsBootableAll(void)
{
    u16 i;
    if (gDwcMovMbpWork->mbpState.connectChildBmp == 0)
        return 0;
    for (i = 1; i < 16; i++) {
        if ((gDwcMovMbpWork->mbpState.connectChildBmp & (1 << i)) && !MB_CommIsBootable(i))
            return 0;
    }
    return 1;
}


/*
 * sdk:      DWCi_MOV_MBP_StartRebootAll (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
void DWCi_MOV_MBP_StartRebootAll(void)
{
    u16 i;
    u16 sentChild = 0;
    for (i = 1; i < 16; i++) {
        if (gDwcMovMbpWork->mbpState.bootableChildBmp & (1 << i)) {
            if (MB_CommResponseRequest(i, 3)) {
                sentChild |= (u16)(1 << i);
            } else {
                u32 enabled;
                u16 mask = ~(1 << i);
                enabled = OS_DisableInterrupts();
                gDwcMovMbpWork->mbpState.connectChildBmp &= mask;
                gDwcMovMbpWork->mbpState.requestChildBmp &= mask;
                gDwcMovMbpWork->mbpState.entryChildBmp &= mask;
                gDwcMovMbpWork->mbpState.downloadChildBmp &= mask;
                gDwcMovMbpWork->mbpState.bootableChildBmp &= mask;
                gDwcMovMbpWork->mbpState.rebootChildBmp &= mask;
                OS_RestoreInterrupts(enabled);
                MB_DisconnectChild(i);
            }
        }
    }
    if (sentChild == 0)
        DWCi_MOV_MBP_ChangeState(7);
    else
        DWCi_MOV_MBP_ChangeState(4);
}


void DWCi_MOV_MBP_Cancel(void)
{
	DWCi_MOV_MBP_ChangeState(6);
	MB_EndToIdle();
}


/*
 * Guard on the kind and the paired words of the object at 0x021DE65C.
 * Addresses are Black-image addresses.
 */
static void MBPi_CheckAllReboot(void)
{
    unsigned short *p = *(unsigned short **)0x021DE65C;

    if (p[0] != 4)
        return;
    if (p[1] != p[6])
        return;
    DWCi_DwcMoveidMB_EndToIdle();
}


static void ParentStateCallback(u16 child_aid, u32 status, void *arg)
{
    ParentCbArg *userInfo = (ParentCbArg *)arg;
    void *childUser;

    switch (status) {
    case 1:
        break;
    case 2:
        if (DWCi_MOV_MBP_GetState() == 2) {
            DWCi_MOV_WPB_WORK *w = gDwcMovMbpWork;
            u32 enabled = OS_DisableInterrupts();
            u8 *mac;

            w->mbpState.connectChildBmp |= 1 << child_aid;
            OS_RestoreInterrupts(enabled);
            mac = gDwcMovMbpWork->childInfo[child_aid - 1].macAddress;
            mac[0] = userInfo->mac[0];
            mac[1] = userInfo->mac[1];
            mac[2] = userInfo->mac[2];
            mac[3] = userInfo->mac[3];
            mac[4] = userInfo->mac[4];
            mac[5] = userInfo->mac[5];
            gDwcMovMbpWork->childInfo[child_aid - 1].playerNo = child_aid;
        }
        break;
    case 3:
        if (DWCi_MOV_MBP_GetChildState(child_aid) != 6) {
            u16 mask = ~(1 << child_aid);
            u32 enabled = OS_DisableInterrupts();

            gDwcMovMbpWork->mbpState.connectChildBmp &= mask;
            gDwcMovMbpWork->mbpState.requestChildBmp &= mask;
            gDwcMovMbpWork->mbpState.entryChildBmp &= mask;
            gDwcMovMbpWork->mbpState.downloadChildBmp &= mask;
            gDwcMovMbpWork->mbpState.bootableChildBmp &= mask;
            gDwcMovMbpWork->mbpState.rebootChildBmp &= mask;
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
            gDwcMovMbpWork->mbpState.requestChildBmp |= 1 << child_aid;
            DWCi_MOV_MBP_AcceptChild(child_aid);
            childUser = MB_CommGetChildUser(child_aid);
            if (childUser)
                MI_CpuCopy8(childUser, gDwcMovMbpWork->childInfo[child_aid - 1].user, 0x16);
        }
        break;
    case 14:
        gDwcMovMbpWork->mbpState.requestChildBmp &= ~(1 << child_aid);
        gDwcMovMbpWork->mbpState.entryChildBmp |= 1 << child_aid;
        if (DWCi_MOV_MBP_GetState() == 3)
            DWCi_MOV_MBP_StartDownload(child_aid);
        break;
    case 7:
        gDwcMovMbpWork->mbpState.downloadChildBmp &= ~(1 << child_aid);
        gDwcMovMbpWork->mbpState.bootableChildBmp |= 1 << child_aid;
        break;
    case 8:
        break;
    case 9:
        gDwcMovMbpWork->mbpState.bootableChildBmp &= ~(1 << child_aid);
        gDwcMovMbpWork->mbpState.rebootChildBmp |= 1 << child_aid;
        MBPi_CheckAllReboot();
        break;
    case 11:
        break;
    case 12: {
        if (DWCi_MOV_MBP_GetState() == 4)
            DWCi_MOV_MBP_ChangeState(5);
        else
            DWCi_MOV_MBP_ChangeState(0);
        if (gDwcMovMbpWork->sFilebuf)
            gDwcMovMbpWork->sFilebuf = 0;
        if (gDwcMovMbpWork->sCWork)
            gDwcMovMbpWork->sCWork = 0;
        break;
    }
    case 13:
        switch (userInfo->errCode) {
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
 *   python tools/match.py one --src src/matched/DWCi_MOV_MBP_ChangeState.c \
 *       --func DWCi_MOV_MBP_ChangeState --addr 0x021D276C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_MOV_MBP_ChangeState(unsigned short v)
{
    gDwcMovMbpWork->mbpState.state = v;
}


/*
 * Read the halfword at the head of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_MBP_GetState.c \
 *       --func DWCi_MOV_MBP_GetState --addr 0x021D2780 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned short DWCi_MOV_MBP_GetState(void)
{
    return gDwcMovMbpWork->mbpState.state;
}


/*
 * sdk:      DWCi_MOV_MBP_GetChildBmp (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
u16 DWCi_MOV_MBP_GetChildBmp(int bmpType)
{
    sDwcMovMbpTable[0] = &gDwcMovMbpWork->mbpState.connectChildBmp;
    sDwcMovMbpTable[1] = &gDwcMovMbpWork->mbpState.requestChildBmp;
    sDwcMovMbpTable[2] = &gDwcMovMbpWork->mbpState.entryChildBmp;
    sDwcMovMbpTable[3] = &gDwcMovMbpWork->mbpState.downloadChildBmp;
    sDwcMovMbpTable[4] = &gDwcMovMbpWork->mbpState.bootableChildBmp;
    sDwcMovMbpTable[5] = &gDwcMovMbpWork->mbpState.rebootChildBmp;
    return *gMovMbpBuffers[bmpType];
}


/*
 * sdk:      DWCi_MOV_MBP_GetChildState (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
ChildState DWCi_MOV_MBP_GetChildState(u16 aid)
{
    DWCi_MOV_MBPState tmpState;
    u32 enabled;
    enabled = OS_DisableInterrupts();
    if (!(gDwcMovMbpWork->mbpState.connectChildBmp & (u16)(1 << aid))) {
        OS_RestoreInterrupts(enabled);
        return CS_NONE;
    }
    MI_CpuCopy8(&gDwcMovMbpWork->mbpState, &tmpState, sizeof(DWCi_MOV_MBPState));
    OS_RestoreInterrupts(enabled);
    if (tmpState.requestChildBmp & (u16)(1 << aid))
        return CS_REQUEST;
    if (tmpState.entryChildBmp & (u16)(1 << aid))
        return CS_ENTRY;
    if (tmpState.downloadChildBmp & (u16)(1 << aid))
        return CS_DOWNLOAD;
    if (tmpState.bootableChildBmp & (u16)(1 << aid))
        return CS_BOOTABLE;
    if (tmpState.rebootChildBmp & (u16)(1 << aid))
        return CS_REBOOT;
    return CS_CONNECT;
}


/*
 * sdk:      DWCi_MOV_MBP_GetChildInfo (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
DWCi_MOV_MBPChildInfo *DWCi_MOV_MBP_GetChildInfo(u16 child_aid)
{
    if (gDwcMovMbpWork->mbpState.connectChildBmp & (1 << child_aid))
        return &gDwcMovMbpWork->childInfo[child_aid - 1];
    return 0;
}


static inline int cmpmac(u8 *a, u8 *b)
{
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]
        && a[4] == b[4] && a[5] == b[5];
}


/*
 * sdk:      DWCi_MOV_MBP_GetPlayerNo (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
u16 DWCi_MOV_MBP_GetPlayerNo(u8 *macAddress)
{
    u16 i;
    for (i = 1; i < 2; i++) {
        if ((gDwcMovMbpWork->mbpState.connectChildBmp & (1 << i)) && cmpmac(macAddress, gDwcMovMbpWork->childInfo[i - 1].macAddress))
            return gDwcMovMbpWork->childInfo[i - 1].playerNo;
    }
    return 0;
}
