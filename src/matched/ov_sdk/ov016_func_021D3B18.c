/*
 * function: func_021D3B18
 * address:  0x021D3B18
 * packet:   pkt_ov016_021D3B18
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOVInit (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   DWCi_MOV_MBP_MemInit             0x021D1D04  arm  ov016
 *   Parent_InitDataShare             0x021D45E0  arm  ov016
 *   OS_GetTick                       0x020870D0  arm
 *   DWCi_BACKUPlRead                 0x02058770  arm
 *   DWCi_SETTINGlGetMemMap           0x021CFBD4  arm  ov016
 *   g_021DE668                       0x021DE668  data
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

extern Wk *g_021DE668;
extern void DWCi_MOV_MBP_MemInit(void *mw);
extern void Parent_InitDataShare(void);
extern u32 OS_GetTick(void);
extern int DWCi_BACKUPlRead(void *mem);
extern void *DWCi_SETTINGlGetMemMap(void);

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
