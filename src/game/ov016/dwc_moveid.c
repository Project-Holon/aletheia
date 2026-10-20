/*
 * file:     dwc_moveid.c
 * unit:     yes
 * function: DWCi_MOVInit, DWCi_MOVFinalize, _DWCi_MOVPrepare, DWCi_MOVStartAdmitChild, DWCi_MOVStartDownloadandBootChild, DWCi_MOVFramework, DWCi_MOVGetStatus, DWCi_GetChildInfo, _DWCi_MOVSearchChannel, _DWCi_MOVStartWaitChild, _DWCi_MOV_WaitandDownloadandBoot_Child, _DWCi_MOV_ReadyMovUserID, _DWCi_MOV_MovUserID, _DWCi_MOV_EraseFlashData, _DWCi_MOVEnd, JudgeConnectableChild, Parent_InitDataShare, Parent_StepDataShare, Parent_data_receive_progress, Parent_get_child_data_kind
 * address:  0x021D3B18
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
 *   DWCi_MOV_MBP_StartDownloadAll  0x021D21CC  arm  ov016
 *   DWCi_MOV_WH_Initialize         0x021D3638  arm  ov016
 *   DWCi_MOV_WH_SetJudgeAcceptFunc 0x021D38C8  arm  ov016
 *   DWCi_MOV_MBP_MemInit             0x021D1D04  arm  ov016
 *   Parent_InitDataShare             0x021D45E0  arm  ov016
 *   OS_GetTick                       0x020870D0  arm
 *   DWCi_BACKUPlRead                 0x02058770  arm
 *   DWCi_SETTINGlGetMemMap           0x021CFBD4  arm  ov016
 *   gDwcMoveidWork                       0x021DE668  data
 *   MB_EndToIdle                     0x021F5F74  arm
 *   DWCi_MOV_WH_SetGgid              0x021D3228  arm  ov016
 *   WM_GetNextTgid                   0x0208F1B4  arm
 *   MI_CpuCopy8                      0x02082D44  arm
 *   _DWCi_MOV_EraseFlashData 0x021D455C  arm  ov016
 *   DWCi_MOV_WH_GetSystemState 0x021D3250  arm  ov016
 *   DWCi_MOV_WH_End 0x021D3AC8  arm  ov016
 *   DWCi_MOV_WH_Finalize 0x021D39C0  arm  ov016
 *   DWCi_DwcMoveidMB_EndToIdle 0x021F5F74  arm
 *   MB_CommGetChildUser          0x021F1B64  arm
 *   DWCi_MOV_WH_StartMeasureChannel  0x021D3264  arm  ov016
 *   DWCi_MOV_WH_GetMeasureChannel    0x021D34E0  arm  ov016
 *   DWCi_MOV_WH_Reset                0x021D39A4  arm  ov016
 *   OS_Terminate                     0x02088234  arm
 *   DWCi_MOV_MBP_Init                0x021D1D40  arm  ov016
 *   DWCi_MOV_MBP_GetState 0x021D2780 arm ov016
 *   DWCi_MOV_MBP_Start 0x021D1E54 arm ov016
 *   DWCi_MOV_MBP_GetChildBmp 0x021D2794 arm ov016
 *   DWCi_MOV_MBP_IsBootableAll 0x021D22AC arm ov016
 *   DWCi_MOV_MBP_StartRebootAll 0x021D2314 arm ov016
 *   DWCi_MOV_MBP_Cancel 0x021D240C arm ov016
 *   DWCi_MOV_WH_ParentConnect  0x021D376C  arm  ov016
 *   Parent_get_child_data_kind  0x021D4854  arm  ov016
 *   DWCi_MOV_MBP_GetPlayerNo         0x021D28E4  arm  ov016
 *   DWCi_MOV_MBP_GetChildInfo        0x021D28B4  arm  ov016
 *   MI_CpuFill8                      0x02082BCC  arm
 *   DWCi_MOV_WH_StepDS 0x021D3904 arm ov016
 *   DWCi_MOV_WH_GetBitmap 0x021D323C arm ov016
 *   DWCi_MOV_WH_GetSharedDataAdr 0x021D38DC arm ov016
 */
#include "../types.h"

#include "../sdk_mb.h"

#include "dwc_moveid_types.h"

#include "../sdk_wm.h"

typedef struct {
    u16 kind;
    u8 data[0x42];
} GShareData;

typedef int ChildState;
#include "dwc_mov_mbp.h"
typedef unsigned long long OSTick;
#include "../arm9/os_tick.h"
#include "../arm9/dwc_backup.h"
#include "setting.h"
#include "../ov107/mb_wm_base.h"
#include "dwc_mov_wh.h"
#include "../arm9/wm_sync.h"
#include "../arm9/mi_memory.h"
extern void DWCi_DwcMoveidMB_EndToIdle(void);
#include "../ov107/mb_parent.h"
#include "../arm9/os_terminate_processor.h"
struct DWCi_MOV_MBPChildInfo;
void DWCi_MOVInit(Wk *wm, MovData *md);
int DWCi_MOVFinalize(void);
int DWCi_MOVStartAdmitChild(void);
int DWCi_MOVStartDownloadandBootChild(void);
void DWCi_MOVFramework(void);
void DWCi_MOVGetStatus(u8 *stt, u8 *change_f);
MBUserInfo *DWCi_GetChildInfo(void);
void _DWCi_MOV_EraseFlashData(void);
u16 Parent_get_child_data_kind(void);
extern Wk *gDwcMoveidWork;

/*
 * sdk:      DWCi_MOVInit (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */

static void _DWCi_MOVPrepare(void);
static void _DWCi_MOVSearchChannel(void);
static void _DWCi_MOVStartWaitChild(void);
static void _DWCi_MOV_WaitandDownloadandBoot_Child(void);
static void _DWCi_MOV_ReadyMovUserID(void);
static void _DWCi_MOV_MovUserID(void);
static int _DWCi_MOVEnd(void);
static int JudgeConnectableChild(WMStartParentCallback *cb);
static void Parent_InitDataShare(void);
static void Parent_StepDataShare(u16 kind, u16 counter, u8 *data);
static void Parent_data_receive_progress(void);
void DWCi_MOVInit(Wk *wm, MovData *md)
{
    gDwcMoveidWork = wm;
    DWCi_MOV_MBP_MemInit((sptr)wm + 0xb00);
    gDwcMoveidWork->moveid_tgid = 0;
    gDwcMoveidWork->moveid_sChannel = 0;
    gDwcMoveidWork->mov_stt = 1;
    gDwcMoveidWork->mov_stt_old = 1;
    gDwcMoveidWork->cnt = 0;
    Parent_InitDataShare();
    gDwcMoveidWork->game_registry.romFilePathp = md->romFilePathp;
    gDwcMoveidWork->game_registry.gameNamep = md->gameNamep;
    gDwcMoveidWork->game_registry.gameIntroductionp = md->gameIntroductionp;
    gDwcMoveidWork->game_registry.iconCharPathp = md->iconCharPathp;
    gDwcMoveidWork->game_registry.iconPalettePathp = md->iconPalettePathp;
    gDwcMoveidWork->game_registry.ggid = md->ggid;
    gDwcMoveidWork->language = md->language;
    gDwcMoveidWork->game_registry.maxPlayerNum = 2;
    OS_GetTick();
    DWCi_BACKUPlRead(gDwcMoveidWork->dummy_userinfo);
    OS_GetTick();
    gDwcMoveidWork->p_user_info = DWCi_SETTINGlGetMemMap();
}

/*
 * sdk:      DWCi_MOVFinalize (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
int DWCi_MOVFinalize(void)
{
    u8 stt = gDwcMoveidWork->mov_stt;
    if (stt == 1 || stt == 20 || stt == 23 || stt == 26 || stt == 29) {
        gDwcMoveidWork->mov_stt = 34;
        gDwcMoveidWork->reset_kind = 0;
        return 1;
    }
    if (stt == 4 || stt == 5 || stt == 6 || stt == 13) {
        if (stt == 4) {
            if (gDwcMoveidWork->start_wait_child_cnt < 6)
                return 0;
        }
        MB_EndToIdle();
        gDwcMoveidWork->mov_stt = 16;
        gDwcMoveidWork->reset_kind = 2;
        return 1;
    }
    if (stt == 9 || stt == 10) {
        gDwcMoveidWork->mov_stt = 32;
        return 1;
    }
    if (stt == 12) {
        gDwcMoveidWork->mov_stt = 34;
        return 1;
    }
    return 0;
}

/*
 * sdk:      _DWCi_MOVPrepare (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
static void _DWCi_MOVPrepare(void)
{
    DWCi_MOV_WH_SetGgid(gDwcMoveidWork->game_registry.ggid);
    gDwcMoveidWork->mov_stt = 1;
    gDwcMoveidWork->moveid_tgid = WM_GetNextTgid();
    MI_CpuCopy8(gDwcMoveidWork->p_user_info, &gDwcMoveidWork->dummy_gShareData[4], 0x40);
    gDwcMoveidWork->language_send_f = 0;
    gDwcMoveidWork->parent_step_data_share_error_cnt = 0;
    gDwcMoveidWork->moveid_tgid++;
}

/*
 * Only from the three live modes, tear the sound system down and park it at mode 2.
 * Addresses are Black-image addresses.
 */
int DWCi_MOVStartAdmitChild(void)
{
    unsigned char mode = *(unsigned char *)(*(int *)0x021DE668 + 0xa90);

    if (mode != 1 && mode != 0x1a && mode != 0x1d)
        return 0;
    _DWCi_MOVPrepare();
    DWCi_MOV_WH_Initialize();
    *(unsigned char *)(*(int *)0x021DE668 + 0xa90) = 2;
    return 1;
}

/*
 * Advance the state byte at +0xa90 from 5 to 6.
 * Addresses are Black-image addresses.
 */
int DWCi_MOVStartDownloadandBootChild(void)
{
    char *p = *(char **)0x021DE668;

    if (*(unsigned char *)(p + 0xa90) != 5)
        return 0;
    *(unsigned char *)(p + 0xa90) = 6;
    DWCi_MOV_MBP_StartDownloadAll();
    return 1;
}

/*
 * State tick for the object pointed to by 0x021DE668: dispatch on its byte
 * state at +0xa90 (table 0..0x22) and advance the +0xa9c delay counter /
 * +0xa98 frame counter, calling the per-state helper.  Addresses are
 * Black-image addresses.
 */
void DWCi_MOVFramework(void)
{
    switch (gDwcMoveidWork->mov_stt) {
    case 1:
        if (gDwcMoveidWork->reset_kind == 1) {
            gDwcMoveidWork->reset_kind = 0;
            DWCi_MOVStartAdmitChild();
            return;
        }
        if (gDwcMoveidWork->reset_kind == 2) {
            gDwcMoveidWork->reset_kind = 0;
            gDwcMoveidWork->mov_stt = 0x22;
        }
        return;
    case 2:
        _DWCi_MOVSearchChannel();
        return;
    case 3:
        _DWCi_MOVStartWaitChild();
        gDwcMoveidWork->mov_stt = 4;
        return;
    case 4:
        gDwcMoveidWork->start_wait_child_cnt++;
        _DWCi_MOV_WaitandDownloadandBoot_Child();
        return;
    case 5:
    case 6:
        _DWCi_MOV_WaitandDownloadandBoot_Child();
        return;
    case 7:
        _DWCi_MOV_ReadyMovUserID();
        return;
    case 8:
    case 9:
    case 10:
        _DWCi_MOV_MovUserID();
        return;
    case 11:
        _DWCi_MOV_EraseFlashData();
        return;
    case 16:
        gDwcMoveidWork->cnt = 0;
        gDwcMoveidWork->mov_stt = 0x11;
        return;
    case 17:
        if (gDwcMoveidWork->cnt++ <= 0x1e)
            return;
        _DWCi_MOVEnd();
        return;
    case 18:
        DWCi_DwcMoveidMB_EndToIdle();
        gDwcMoveidWork->cnt = 0;
        gDwcMoveidWork->mov_stt = 0x16;
        return;
    case 19:
        if (gDwcMoveidWork->cnt++ <= 0x1e)
            return;
        if (DWCi_MOV_WH_GetSystemState() != 1)
            return;
        DWCi_MOV_WH_End();
        gDwcMoveidWork->mov_stt = 0x14;
        return;
    case 21:
        DWCi_MOV_WH_Finalize();
        gDwcMoveidWork->cnt = 0;
        gDwcMoveidWork->mov_stt = 0x16;
        return;
    case 22:
        if (gDwcMoveidWork->cnt++ <= 0x1e)
            return;
        if (DWCi_MOV_WH_GetSystemState() != 1)
            return;
        DWCi_MOV_WH_End();
        gDwcMoveidWork->mov_stt = 0x17;
        return;
    case 24:
        DWCi_MOV_WH_Finalize();
        gDwcMoveidWork->cnt = 0;
        gDwcMoveidWork->mov_stt = 0x19;
        return;
    case 25:
        if (gDwcMoveidWork->cnt++ <= 0x1e)
            return;
        if (DWCi_MOV_WH_GetSystemState() != 1)
            return;
        DWCi_MOV_WH_End();
        gDwcMoveidWork->mov_stt = 0x1a;
        return;
    case 27:
        DWCi_MOV_WH_Finalize();
        gDwcMoveidWork->cnt = 0;
        gDwcMoveidWork->mov_stt = 0x1c;
        return;
    case 28:
        if (gDwcMoveidWork->cnt++ <= 0x1e)
            return;
        if (DWCi_MOV_WH_GetSystemState() == 1) {
            DWCi_MOV_WH_End();
            gDwcMoveidWork->mov_stt = 0x1d;
            return;
        }
        if (gDwcMoveidWork->cnt % 30 != 1)
            return;
        if (gDwcMoveidWork->cnt <= 0x37)
            return;
        DWCi_MOV_WH_Finalize();
        return;
    case 32:
        DWCi_MOV_WH_Finalize();
        gDwcMoveidWork->cnt = 0;
        gDwcMoveidWork->mov_stt = 0x21;
        return;
    case 33:
        if (gDwcMoveidWork->cnt++ <= 0x1e)
            return;
        if (DWCi_MOV_WH_GetSystemState() != 1)
            return;
        DWCi_MOV_WH_End();
        gDwcMoveidWork->mov_stt = 0x22;
        return;
    case 30:
        DWCi_MOV_WH_Finalize();
        return;
    case 0x22:
        return;
    }
    return;
}

/*
 * sdk:      DWCi_MOVGetStatus (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void DWCi_MOVGetStatus(u8 *stt, u8 *change_f)
{
    *stt = gDwcMoveidWork->mov_stt;
    if (gDwcMoveidWork->mov_stt != gDwcMoveidWork->mov_stt_old)
        *change_f = 1;
    else
        *change_f = 0;
    gDwcMoveidWork->mov_stt_old = gDwcMoveidWork->mov_stt;
}

MBUserInfo *DWCi_GetChildInfo(void)
{
    return MB_CommGetChildUser(1);
}

/*
 * sdk:      _DWCi_MOVSearchChannel (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
static void _DWCi_MOVSearchChannel(void)
{
    switch (DWCi_MOV_WH_GetSystemState()) {
    case 1:
        DWCi_MOV_WH_StartMeasureChannel();
        break;
    case 7:
        gDwcMoveidWork->moveid_sChannel = DWCi_MOV_WH_GetMeasureChannel();
        gDwcMoveidWork->start_wait_child_cnt = 0;
        gDwcMoveidWork->mov_stt = 3;
        break;
    case 0:
        gDwcMoveidWork->start_wait_child_cnt = 0;
        gDwcMoveidWork->mov_stt = 3;
        break;
    case 9:
        DWCi_MOV_WH_Reset();
        break;
    case 3:
        break;
    default:
        OS_Terminate();
        break;
    }
}

/*
 * sdk:      _DWCi_MOVStartWaitChild (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
static void _DWCi_MOVStartWaitChild(void)
{
    DWCi_MOV_MBP_Init(gDwcMoveidWork->game_registry.ggid, gDwcMoveidWork->moveid_tgid);
}

/*
 * sdk:      _DWCi_MOV_WaitandDownloadandBoot_Child (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
static void _DWCi_MOV_WaitandDownloadandBoot_Child(void)
{
    switch (DWCi_MOV_MBP_GetState()) {
    case 1:
        DWCi_MOV_MBP_Start((MBGameRegistry *)((char *)gDwcMoveidWork + 0x2b4 + 0x800), *(u16 *)((char *)gDwcMoveidWork + 0x600 + 0x4a));
        return;
    case 2:
        if (DWCi_MOV_MBP_GetChildBmp(2) != 0) {
            gDwcMoveidWork->mov_stt = 5;
            return;
        }
        if (DWCi_MOV_MBP_GetChildBmp(3) != 0 || DWCi_MOV_MBP_GetChildBmp(4) != 0) {
            gDwcMoveidWork->mov_stt = 6;
            return;
        }
        if (gDwcMoveidWork->mov_stt != 5)
            return;
        if (DWCi_MOV_MBP_GetChildBmp(2) == 0)
            gDwcMoveidWork->mov_stt = 0xd;
        return;
    case 3:
        if (DWCi_MOV_MBP_IsBootableAll() != 0) {
            DWCi_MOV_MBP_StartRebootAll();
            return;
        }
        if (gDwcMoveidWork->mov_stt == 6 || gDwcMoveidWork->mov_stt == 7) {
            if (DWCi_MOV_MBP_GetChildBmp(3) == 0)
                gDwcMoveidWork->mov_stt = 0x12;
        }
        return;
    case 5:
        gDwcMoveidWork->mov_stt = 7;
        return;
    case 7:
        DWCi_MOV_MBP_Cancel();
        gDwcMoveidWork->mov_stt = 1;
        return;
    case 0:
        switch (DWCi_MOV_WH_GetSystemState()) {
        case 1:
            DWCi_MOV_WH_End();
            break;
        case 0:
            gDwcMoveidWork->mov_stt = 0x1f;
            break;
        case 3:
            break;
        default:
            gDwcMoveidWork->mov_stt = 0x1f;
            break;
        }
        return;
    }
}

static void _DWCi_MOV_ReadyMovUserID(void)
{
    Parent_InitDataShare();
    DWCi_MOV_WH_SetJudgeAcceptFunc((uptr)((void *)0x021D45A4));
    *(unsigned char *)(*(char **)0x021DE668 + 0xa90) = 8;
}

static void _DWCi_MOV_MovUserID(void)
{
    switch (DWCi_MOV_WH_GetSystemState()) {
    case 1:
        DWCi_MOV_WH_ParentConnect(4, gDwcMoveidWork->moveid_tgid + 1, gDwcMoveidWork->moveid_sChannel);
        break;
    case 4:
    case 5:
    case 6:
        Parent_StepDataShare(0, gDwcMoveidWork->data_seq_num,
                      (u8 *)gDwcMoveidWork->p_user_info + (gDwcMoveidWork->data_seq_num % 16) * 64);
        Parent_data_receive_progress();
        if (gDwcMoveidWork->mov_stt == 0x1b)
            break;
        if (gDwcMoveidWork->parent_step_data_share_error_cnt > 0x1e0) {
            gDwcMoveidWork->mov_stt = 0x1b;
            break;
        }
        if (Parent_get_child_data_kind() == 0x10 || Parent_get_child_data_kind() == 0x20) {
            Parent_get_child_data_kind();
            gDwcMoveidWork->mov_stt = 0xa;
        } else if (Parent_get_child_data_kind() == 0x40) {
            gDwcMoveidWork->mov_stt = 0xb;
        } else if (Parent_get_child_data_kind() == 0xff) {
            gDwcMoveidWork->mov_stt = 0x1b;
        } else if (Parent_get_child_data_kind() == 0x50) {
            gDwcMoveidWork->mov_stt = 0x15;
        } else if (Parent_get_child_data_kind() == 0x60) {
            gDwcMoveidWork->mov_stt = 0x18;
        } else if (Parent_get_child_data_kind() == 0x70) {
            gDwcMoveidWork->mov_stt = 0x1b;
        } else if (Parent_get_child_data_kind() == 0) {
            gDwcMoveidWork->mov_stt = 8;
        } else if (Parent_get_child_data_kind() == 0xbd) {
            gDwcMoveidWork->mov_stt = 9;
        } else {
            gDwcMoveidWork->mov_stt = 0x1f;
        }
        break;
    }
}

void _DWCi_MOV_EraseFlashData(void)
{
    gDwcMoveidWork->mov_stt = 12;
}

/*
 * Enter state 1 once DWCi_MOV_WH_GetSystemState reports ready.
 * Addresses are Black-image addresses.
 */
static int _DWCi_MOVEnd(void)
{
    if (DWCi_MOV_WH_GetSystemState() != 1)
        return 0;
    DWCi_MOV_WH_End();
    *(unsigned char *)(*(char **)0x021DE668 + 0xa90) = 1;
    return 1;
}

/*
 * sdk:      JudgeConnectableChild (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
static int JudgeConnectableChild(WMStartParentCallback *cb)
{
    u16 playerNo = DWCi_MOV_MBP_GetPlayerNo(cb->macAddress);
    if (playerNo == 0)
        return 0;
    gDwcMoveidWork->sChildInfo[playerNo - 1] = DWCi_MOV_MBP_GetChildInfo(playerNo);
    return 1;
}

/*
 * sdk:      Parent_InitDataShare (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
static void Parent_InitDataShare(void)
{
    MI_CpuFill8(gDwcMoveidWork->sRecvBuf, 0, 256);
    MI_CpuFill8(gDwcMoveidWork->sSendBuf, 0, 256);
    gDwcMoveidWork->sShareDataPtr = gDwcMoveidWork;
}

/*
 * sdk:      Parent_StepDataShare (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
static void Parent_StepDataShare(u16 kind, u16 counter, u8 *data)
{
    u16 i;
    u16 *adr;

    if (gDwcMoveidWork->language_send_f == 1) {
        ((u16 *)gDwcMoveidWork->sShareDataPtr)[0] = kind;
        ((u16 *)gDwcMoveidWork->sShareDataPtr)[1] = counter;
        MI_CpuCopy8(data, ((u16 *)gDwcMoveidWork->sShareDataPtr) + 2, 0x40);
    } else {
        gDwcMoveidWork->parent_step_data_share_error_cnt++;
        ((u16 *)gDwcMoveidWork->sShareDataPtr)[0] = 0xbc;
        ((u8 *)((u16 *)gDwcMoveidWork->sShareDataPtr))[4] = gDwcMoveidWork->language;
    }
    if (DWCi_MOV_WH_GetSystemState() != 5)
        return;
    if (DWCi_MOV_WH_StepDS(gDwcMoveidWork) == 0) {
        gDwcMoveidWork->parent_step_data_share_error_cnt += 4;
        return;
    }
    if (gDwcMoveidWork->language_send_f == 0) {
        gDwcMoveidWork->parent_step_data_share_error_cnt++;
    } else {
        gDwcMoveidWork->parent_step_data_share_error_cnt = 0;
        if (DWCi_MOV_WH_GetBitmap() != 3) {
            gDwcMoveidWork->mov_stt = 0x1b;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        adr = DWCi_MOV_WH_GetSharedDataAdr(i);
        if (adr != 0) {
            MI_CpuCopy8(adr, (gDwcMoveidWork->sRecvBuf + i * 0x44), 0x44);
            gDwcMoveidWork->sRecvFlag[i] = 1;
        } else {
            gDwcMoveidWork->sRecvFlag[i] = 0;
        }
    }
}

/*
 * sdk:      Parent_data_receive_progress (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
static void Parent_data_receive_progress(void)
{
    long i;
    GShareData *sd;
    for (i = 0; i < 16; i++) {
        if (gDwcMoveidWork->sRecvFlag[i] == 0)
            continue;
        sd = &((GShareData *)gDwcMoveidWork->sRecvBuf)[i];
        if (i != 1)
            continue;
        if (gDwcMoveidWork->language_send_f == 1) {
            if (sd->kind != 0x10)
                return;
            gDwcMoveidWork->data_send_cnt++;
            if (gDwcMoveidWork->data_send_cnt & 1)
                continue;
            gDwcMoveidWork->data_seq_num++;
            if (gDwcMoveidWork->data_seq_num >= 0x24)
                gDwcMoveidWork->data_seq_num = 0;
        } else {
            gDwcMoveidWork->send_data_kind = 0xbc;
            if (sd->kind == 0xbd) {
                gDwcMoveidWork->language_send_f = 1;
                gDwcMoveidWork->data_seq_num = 0;
                gDwcMoveidWork->data_send_cnt = 0;
            }
        }
    }
}

u16 Parent_get_child_data_kind(void)
{
    return *(u16 *)(gDwcMoveidWork->sRecvBuf + 0x44);
}
