/*
 * file:     unit_021D3B18_p01.c
 * unit:     yes
 * function: func_021D3B18, func_021D3BF8, func_021D3CD0, func_021D3D44, func_021D3D8C
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
} MBGameRegistry_021D3B18;

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
    MBGameRegistry_021D3B18 game_registry;
} Wk;

typedef struct {
    u8 pad[0x14];
    u32 ggid;
    u8 pad2[0x3c - 0x18];
} MBGameRegistry_021D3BF8;

typedef struct {
    u8 pad[0x14];
    u32 ggid;
    u8 pad2[0x3c - 0x18];
} MBGameRegistry_021D3CD0;

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
void func_021D3B18(Wk *wm, MovData *md);
int func_021D3BF8(void);
void func_021D3CD0(void);
int func_021D3D44(void);
int func_021D3D8C(void);
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
