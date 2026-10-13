/*
 * file:     dwc_moveid.c
 * unit:     yes
 * function: func_021D3B18, func_021D3BF8, func_021D3CD0, func_021D3D44, func_021D3D8C, func_021D3DC0, func_021D40F4, DWCi_GetChildInfo, func_021D4148, func_021D41F0, func_021D4214, func_021D439C, func_021D43C8, func_021D455C, func_021D4574, func_021D45A4, func_021D45E0, func_021D4624, func_021D4770, func_021D4854
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
 *   DWCi_MOV_MBP_MemInit             0x021D1D04  arm  ov016
 *   Parent_InitDataShare             0x021D45E0  arm  ov016
 *   OS_GetTick                       0x020870D0  arm
 *   DWCi_BACKUPlRead                 0x02058770  arm
 *   DWCi_SETTINGlGetMemMap           0x021CFBD4  arm  ov016
 *   g_021DE668                       0x021DE668  data
 *   MB_EndToIdle                     0x021F5F74  arm
 *   DWCi_MOV_WH_SetGgid              0x021D3228  arm  ov016
 *   WM_GetNextTgid                   0x0208F1B4  arm
 *   MI_CpuCopy8                      0x02082D44  arm
 *   func_021D455C 0x021D455C  arm  ov016
 *   func_021D3250 0x021D3250  arm  ov016
 *   func_021D3AC8 0x021D3AC8  arm  ov016
 *   func_021D39C0 0x021D39C0  arm  ov016
 *   func_021F5F74 0x021F5F74  arm
 *   MB_CommGetChildUser          0x021F1B64  arm
 *   DWCi_MOV_WH_GetSystemState       0x021D3250  arm  ov016
 *   DWCi_MOV_WH_StartMeasureChannel  0x021D3264  arm  ov016
 *   DWCi_MOV_WH_GetMeasureChannel    0x021D34E0  arm  ov016
 *   DWCi_MOV_WH_Reset                0x021D39A4  arm  ov016
 *   OS_Terminate                     0x02088234  arm
 *   DWCi_MOV_MBP_Init                0x021D1D40  arm  ov016
 *   func_021D2780 0x021D2780 arm ov016
 *   func_021D1E54 0x021D1E54 arm ov016
 *   func_021D2794 0x021D2794 arm ov016
 *   func_021D22AC 0x021D22AC arm ov016
 *   func_021D2314 0x021D2314 arm ov016
 *   func_021D240C 0x021D240C arm ov016
 *   func_021D376C  0x021D376C  arm  ov016
 *   func_021D4854  0x021D4854  arm  ov016
 *   DWCi_MOV_MBP_GetPlayerNo         0x021D28E4  arm  ov016
 *   DWCi_MOV_MBP_GetChildInfo        0x021D28B4  arm  ov016
 *   MI_CpuFill8                      0x02082BCC  arm
 *   func_02082D44 0x02082D44 arm
 *   func_021D3904 0x021D3904 arm ov016
 *   func_021D323C 0x021D323C arm ov016
 *   func_021D38DC 0x021D38DC arm ov016
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

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

typedef struct {
    char *romFilePathp;
    u16 *gameNamep;
    u16 *gameIntroductionp;
    char *iconCharPathp;
    char *iconPalettePathp;
    u32 ggid;
    u8 language;
} MovData;

typedef struct {
    u8 sSendBuf[256];
    u8 sRecvBuf[256];
    u16 data_seq_num;
    u16 send_data_kind;
    u32 parent_step_data_share_error_cnt;
    int sRecvFlag[16];
    u8 parent_recvd_userinfo_buf[1024];
    u16 moveid_tgid;
    u16 moveid_sChannel;
    u8 dummy_userinfo[0x400];
    u8 dummy_gShareData[0x44];
    u8 mov_stt;
    u8 mov_stt_old;
    u8 language;
    u8 language_send_f;
    u32 data_send_cnt;
    u32 start_wait_child_cnt;
    u32 cnt;
    void *sChildInfo[1];
    void *p_user_info;
    void *p_mov_data;
    u8 reset_kind;
    void *sShareDataPtr;
    MBGameRegistry game_registry;
} Wk;

typedef struct MBUserInfo MBUserInfo;

typedef struct {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
} WMStartParentCallback;

typedef struct {
    u16 kind;
    u8 data[0x42];
} GShareData;

extern void DWCi_MOV_MBP_MemInit(void *mw);
extern void Parent_InitDataShare(void);
extern u32 OS_GetTick(void);
extern int DWCi_BACKUPlRead(void *mem);
extern void *DWCi_SETTINGlGetMemMap(void);
extern void MB_EndToIdle(void);
extern void DWCi_MOV_WH_SetGgid(u32 ggid);
extern u16 WM_GetNextTgid(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern int func_021D3638(void);
extern void func_021D21CC(void);
extern void func_021D455C(void);
extern unsigned int func_021D3250(void);
extern int func_021D3AC8(void);
extern void func_021D39C0(void);
extern void func_021F5F74(void);
extern MBUserInfo *MB_CommGetChildUser(unsigned short aid);
extern int DWCi_MOV_WH_GetSystemState(void);
extern int DWCi_MOV_WH_StartMeasureChannel(void);
extern u16 DWCi_MOV_WH_GetMeasureChannel(void);
extern void DWCi_MOV_WH_Reset(void);
extern void OS_Terminate(void);
extern void DWCi_MOV_MBP_Init(u32 ggid, u16 tgid);
extern u16 func_021D2780(void);
extern void func_021D1E54(void *gameInfo, u16 channel);
extern u16 func_021D2794(int bmpType);
extern int func_021D22AC(void);
extern void func_021D2314(void);
extern void func_021D240C(void);
extern void func_021D38C8(unsigned int v);
extern int func_021D376C(int mode, u16 tgid, u16 channel);
extern u16 func_021D4854(void);
extern void *DWCi_MOV_MBP_GetChildInfo(u16 child_aid);
extern u16 DWCi_MOV_MBP_GetPlayerNo(u8 *macAddress);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern int func_021D3904(void *data);
extern u16 func_021D323C(void);
extern u16 *func_021D38DC(u16 aid);
void func_021D3B18(Wk *wm, MovData *md);
int func_021D3BF8(void);
void func_021D3CD0(void);
int func_021D3D44(void);
int func_021D3D8C(void);
void func_021D3DC0(void);
void func_021D40F4(u8 *stt, u8 *change_f);
MBUserInfo *DWCi_GetChildInfo(void);
void func_021D4148(void);
void func_021D41F0(void);
void func_021D4214(void);
void func_021D439C(void);
void func_021D43C8(void);
asm void _DWCi_MOV_EraseFlashData(void);
int func_021D4574(void);
int func_021D45A4(WMStartParentCallback *cb);
void func_021D45E0(void);
void func_021D4624(u16 kind, u16 counter, u8 *data);
void func_021D4770(void);
u16 Parent_get_child_data_kind(void);
extern Wk *g_021DE668;










/*
 * sdk:      DWCi_MOVInit (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void func_021D3B18(Wk *wm, MovData *md)
{
    g_021DE668 = wm;
    DWCi_MOV_MBP_MemInit((char *)wm + 0xb00);
    g_021DE668->moveid_tgid = 0;
    g_021DE668->moveid_sChannel = 0;
    g_021DE668->mov_stt = 1;
    g_021DE668->mov_stt_old = 1;
    g_021DE668->cnt = 0;
    Parent_InitDataShare();
    g_021DE668->game_registry.romFilePathp = md->romFilePathp;
    g_021DE668->game_registry.gameNamep = md->gameNamep;
    g_021DE668->game_registry.gameIntroductionp = md->gameIntroductionp;
    g_021DE668->game_registry.iconCharPathp = md->iconCharPathp;
    g_021DE668->game_registry.iconPalettePathp = md->iconPalettePathp;
    g_021DE668->game_registry.ggid = md->ggid;
    g_021DE668->language = md->language;
    g_021DE668->game_registry.maxPlayerNum = 2;
    OS_GetTick();
    DWCi_BACKUPlRead(g_021DE668->dummy_userinfo);
    OS_GetTick();
    g_021DE668->p_user_info = DWCi_SETTINGlGetMemMap();
}










/*
 * sdk:      DWCi_MOVFinalize (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
int func_021D3BF8(void)
{
    u8 stt = g_021DE668->mov_stt;
    if (stt == 1 || stt == 20 || stt == 23 || stt == 26 || stt == 29) {
        g_021DE668->mov_stt = 34;
        g_021DE668->reset_kind = 0;
        return 1;
    }
    if (stt == 4 || stt == 5 || stt == 6 || stt == 13) {
        if (stt == 4) {
            if (g_021DE668->start_wait_child_cnt < 6)
                return 0;
        }
        MB_EndToIdle();
        g_021DE668->mov_stt = 16;
        g_021DE668->reset_kind = 2;
        return 1;
    }
    if (stt == 9 || stt == 10) {
        g_021DE668->mov_stt = 32;
        return 1;
    }
    if (stt == 12) {
        g_021DE668->mov_stt = 34;
        return 1;
    }
    return 0;
}










/*
 * sdk:      _DWCi_MOVPrepare (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void func_021D3CD0(void)
{
    DWCi_MOV_WH_SetGgid(g_021DE668->game_registry.ggid);
    g_021DE668->mov_stt = 1;
    g_021DE668->moveid_tgid = WM_GetNextTgid();
    MI_CpuCopy8(g_021DE668->p_user_info, &g_021DE668->dummy_gShareData[4], 0x40);
    g_021DE668->language_send_f = 0;
    g_021DE668->parent_step_data_share_error_cnt = 0;
    g_021DE668->moveid_tgid++;
}










/*
 * Only from the three live modes, tear the sound system down and park it at mode 2.
 * Addresses are Black-image addresses.
 */
int func_021D3D44(void)
{
    unsigned char mode = *(unsigned char *)(*(int *)0x021DE668 + 0xa90);

    if (mode != 1 && mode != 0x1a && mode != 0x1d)
        return 0;
    func_021D3CD0();
    func_021D3638();
    *(unsigned char *)(*(int *)0x021DE668 + 0xa90) = 2;
    return 1;
}










/*
 * Advance the state byte at +0xa90 from 5 to 6.
 * Addresses are Black-image addresses.
 */
int func_021D3D8C(void)
{
    char *p = *(char **)0x021DE668;

    if (*(unsigned char *)(p + 0xa90) != 5)
        return 0;
    *(unsigned char *)(p + 0xa90) = 6;
    func_021D21CC();
    return 1;
}










/*
 * State tick for the object pointed to by 0x021DE668: dispatch on its byte
 * state at +0xa90 (table 0..0x22) and advance the +0xa9c delay counter /
 * +0xa98 frame counter, calling the per-state helper.  Addresses are
 * Black-image addresses.
 */
void func_021D3DC0(void)
{
    switch (g_021DE668->mov_stt) {
    case 1:
        if (g_021DE668->reset_kind == 1) {
            g_021DE668->reset_kind = 0;
            func_021D3D44();
            return;
        }
        if (g_021DE668->reset_kind == 2) {
            g_021DE668->reset_kind = 0;
            g_021DE668->mov_stt = 0x22;
        }
        return;
    case 2:
        func_021D4148();
        return;
    case 3:
        func_021D41F0();
        g_021DE668->mov_stt = 4;
        return;
    case 4:
        g_021DE668->start_wait_child_cnt++;
        func_021D4214();
        return;
    case 5:
    case 6:
        func_021D4214();
        return;
    case 7:
        func_021D439C();
        return;
    case 8:
    case 9:
    case 10:
        func_021D43C8();
        return;
    case 11:
        func_021D455C();
        return;
    case 16:
        g_021DE668->cnt = 0;
        g_021DE668->mov_stt = 0x11;
        return;
    case 17:
        if (g_021DE668->cnt++ <= 0x1e)
            return;
        func_021D4574();
        return;
    case 18:
        func_021F5F74();
        g_021DE668->cnt = 0;
        g_021DE668->mov_stt = 0x16;
        return;
    case 19:
        if (g_021DE668->cnt++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        func_021D3AC8();
        g_021DE668->mov_stt = 0x14;
        return;
    case 21:
        func_021D39C0();
        g_021DE668->cnt = 0;
        g_021DE668->mov_stt = 0x16;
        return;
    case 22:
        if (g_021DE668->cnt++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        func_021D3AC8();
        g_021DE668->mov_stt = 0x17;
        return;
    case 24:
        func_021D39C0();
        g_021DE668->cnt = 0;
        g_021DE668->mov_stt = 0x19;
        return;
    case 25:
        if (g_021DE668->cnt++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        func_021D3AC8();
        g_021DE668->mov_stt = 0x1a;
        return;
    case 27:
        func_021D39C0();
        g_021DE668->cnt = 0;
        g_021DE668->mov_stt = 0x1c;
        return;
    case 28:
        if (g_021DE668->cnt++ <= 0x1e)
            return;
        if (func_021D3250() == 1) {
            func_021D3AC8();
            g_021DE668->mov_stt = 0x1d;
            return;
        }
        if (g_021DE668->cnt % 30 != 1)
            return;
        if (g_021DE668->cnt <= 0x37)
            return;
        func_021D39C0();
        return;
    case 32:
        func_021D39C0();
        g_021DE668->cnt = 0;
        g_021DE668->mov_stt = 0x21;
        return;
    case 33:
        if (g_021DE668->cnt++ <= 0x1e)
            return;
        if (func_021D3250() != 1)
            return;
        func_021D3AC8();
        g_021DE668->mov_stt = 0x22;
        return;
    case 30:
        func_021D39C0();
        return;
    case 0x22:
        return;
    }
    return;
}









/*
 * sdk:      DWCi_MOVGetStatus (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void func_021D40F4(u8 *stt, u8 *change_f)
{
    *stt = g_021DE668->mov_stt;
    if (g_021DE668->mov_stt != g_021DE668->mov_stt_old)
        *change_f = 1;
    else
        *change_f = 0;
    g_021DE668->mov_stt_old = g_021DE668->mov_stt;
}








MBUserInfo *DWCi_GetChildInfo(void)
{
    return MB_CommGetChildUser(1);
}







/*
 * sdk:      _DWCi_MOVSearchChannel (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void func_021D4148(void)
{
    switch (DWCi_MOV_WH_GetSystemState()) {
    case 1:
        DWCi_MOV_WH_StartMeasureChannel();
        break;
    case 7:
        g_021DE668->moveid_sChannel = DWCi_MOV_WH_GetMeasureChannel();
        g_021DE668->start_wait_child_cnt = 0;
        g_021DE668->mov_stt = 3;
        break;
    case 0:
        g_021DE668->start_wait_child_cnt = 0;
        g_021DE668->mov_stt = 3;
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
void func_021D41F0(void)
{
    DWCi_MOV_MBP_Init(g_021DE668->game_registry.ggid, g_021DE668->moveid_tgid);
}






/*
 * sdk:      _DWCi_MOV_WaitandDownloadandBoot_Child (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void func_021D4214(void)
{
    switch (func_021D2780()) {
    case 1:
        func_021D1E54((char *)g_021DE668 + 0x2b4 + 0x800, *(u16 *)((char *)g_021DE668 + 0x600 + 0x4a));
        return;
    case 2:
        if (func_021D2794(2) != 0) {
            g_021DE668->mov_stt = 5;
            return;
        }
        if (func_021D2794(3) != 0 || func_021D2794(4) != 0) {
            g_021DE668->mov_stt = 6;
            return;
        }
        if (g_021DE668->mov_stt != 5)
            return;
        if (func_021D2794(2) == 0)
            g_021DE668->mov_stt = 0xd;
        return;
    case 3:
        if (func_021D22AC() != 0) {
            func_021D2314();
            return;
        }
        if (g_021DE668->mov_stt == 6 || g_021DE668->mov_stt == 7) {
            if (func_021D2794(3) == 0)
                g_021DE668->mov_stt = 0x12;
        }
        return;
    case 5:
        g_021DE668->mov_stt = 7;
        return;
    case 7:
        func_021D240C();
        g_021DE668->mov_stt = 1;
        return;
    case 0:
        switch (func_021D3250()) {
        case 1:
            func_021D3AC8();
            break;
        case 0:
            g_021DE668->mov_stt = 0x1f;
            break;
        case 3:
            break;
        default:
            g_021DE668->mov_stt = 0x1f;
            break;
        }
        return;
    }
}






void func_021D439C(void)
{
    func_021D45E0();
    func_021D38C8((unsigned int)((void *)0x021D45A4));
    *(unsigned char *)(*(char **)0x021DE668 + 0xa90) = 8;
}







void func_021D43C8(void)
{
    switch (func_021D3250()) {
    case 1:
        func_021D376C(4, g_021DE668->moveid_tgid + 1, g_021DE668->moveid_sChannel);
        break;
    case 4:
    case 5:
    case 6:
        func_021D4624(0, g_021DE668->data_seq_num,
                      (u8 *)g_021DE668->p_user_info + (g_021DE668->data_seq_num % 16) * 64);
        func_021D4770();
        if (g_021DE668->mov_stt == 0x1b)
            break;
        if (g_021DE668->parent_step_data_share_error_cnt > 0x1e0) {
            g_021DE668->mov_stt = 0x1b;
            break;
        }
        if (func_021D4854() == 0x10 || func_021D4854() == 0x20) {
            func_021D4854();
            g_021DE668->mov_stt = 0xa;
        } else if (func_021D4854() == 0x40) {
            g_021DE668->mov_stt = 0xb;
        } else if (func_021D4854() == 0xff) {
            g_021DE668->mov_stt = 0x1b;
        } else if (func_021D4854() == 0x50) {
            g_021DE668->mov_stt = 0x15;
        } else if (func_021D4854() == 0x60) {
            g_021DE668->mov_stt = 0x18;
        } else if (func_021D4854() == 0x70) {
            g_021DE668->mov_stt = 0x1b;
        } else if (func_021D4854() == 0) {
            g_021DE668->mov_stt = 8;
        } else if (func_021D4854() == 0xbd) {
            g_021DE668->mov_stt = 9;
        } else {
            g_021DE668->mov_stt = 0x1f;
        }
        break;
    }
}






asm void _DWCi_MOV_EraseFlashData(void)
{
	ldr r0, =0x021DE668
	mov r1, #0xc
	ldr r0, [r0]
	strb r1, [r0, #0xa90]
	bx lr
}







/*
 * Enter state 1 once func_021D3250 reports ready.
 * Addresses are Black-image addresses.
 */
int func_021D4574(void)
{
    if (func_021D3250() != 1)
        return 0;
    func_021D3AC8();
    *(unsigned char *)(*(char **)0x021DE668 + 0xa90) = 1;
    return 1;
}






/*
 * sdk:      JudgeConnectableChild (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
int func_021D45A4(WMStartParentCallback *cb)
{
    u16 playerNo = DWCi_MOV_MBP_GetPlayerNo(cb->macAddress);
    if (playerNo == 0)
        return 0;
    g_021DE668->sChildInfo[playerNo - 1] = DWCi_MOV_MBP_GetChildInfo(playerNo);
    return 1;
}





/*
 * sdk:      Parent_InitDataShare (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void func_021D45E0(void)
{
    MI_CpuFill8(g_021DE668->sRecvBuf, 0, 256);
    MI_CpuFill8(g_021DE668->sSendBuf, 0, 256);
    g_021DE668->sShareDataPtr = g_021DE668;
}



/*
 * sdk:      Parent_StepDataShare (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void func_021D4624(u16 kind, u16 counter, u8 *data)
{
    u16 i;
    u16 *adr;

    if (g_021DE668->language_send_f == 1) {
        ((u16 *)g_021DE668->sShareDataPtr)[0] = kind;
        ((u16 *)g_021DE668->sShareDataPtr)[1] = counter;
        func_02082D44(data, ((u16 *)g_021DE668->sShareDataPtr) + 2, 0x40);
    } else {
        g_021DE668->parent_step_data_share_error_cnt++;
        ((u16 *)g_021DE668->sShareDataPtr)[0] = 0xbc;
        ((u8 *)((u16 *)g_021DE668->sShareDataPtr))[4] = g_021DE668->language;
    }
    if (func_021D3250() != 5)
        return;
    if (func_021D3904(g_021DE668) == 0) {
        g_021DE668->parent_step_data_share_error_cnt += 4;
        return;
    }
    if (g_021DE668->language_send_f == 0) {
        g_021DE668->parent_step_data_share_error_cnt++;
    } else {
        g_021DE668->parent_step_data_share_error_cnt = 0;
        if (func_021D323C() != 3) {
            g_021DE668->mov_stt = 0x1b;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        adr = func_021D38DC(i);
        if (adr != 0) {
            func_02082D44(adr, (g_021DE668->sRecvBuf + i * 0x44), 0x44);
            g_021DE668->sRecvFlag[i] = 1;
        } else {
            g_021DE668->sRecvFlag[i] = 0;
        }
    }
}



/*
 * sdk:      Parent_data_receive_progress (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 */
void func_021D4770(void)
{
    long i;
    GShareData *sd;
    for (i = 0; i < 16; i++) {
        if (g_021DE668->sRecvFlag[i] == 0)
            continue;
        sd = &((GShareData *)g_021DE668->sRecvBuf)[i];
        if (i != 1)
            continue;
        if (g_021DE668->language_send_f == 1) {
            if (sd->kind != 0x10)
                return;
            g_021DE668->data_send_cnt++;
            if (g_021DE668->data_send_cnt & 1)
                continue;
            g_021DE668->data_seq_num++;
            if (g_021DE668->data_seq_num >= 0x24)
                g_021DE668->data_seq_num = 0;
        } else {
            g_021DE668->send_data_kind = 0xbc;
            if (sd->kind == 0xbd) {
                g_021DE668->language_send_f = 1;
                g_021DE668->data_seq_num = 0;
                g_021DE668->data_send_cnt = 0;
            }
        }
    }
}


u16 Parent_get_child_data_kind(void)
{
    return *(u16 *)(g_021DE668->sRecvBuf + 0x44);
}
