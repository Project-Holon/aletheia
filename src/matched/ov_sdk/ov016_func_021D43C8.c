/*
 * function: _DWCi_MOV_MovUserID
 * address:  0x021D43C8
 * packet:   pkt_ov016_021D43C8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _DWCi_MOV_MovUserID (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   func_021D3250  0x021D3250  arm  ov016
 *   DWCi_MOV_WH_ParentConnect  0x021D376C  arm  ov016
 *   func_021D4624  0x021D4624  arm  ov016
 *   func_021D4770  0x021D4770  arm  ov016
 *   func_021D4854  0x021D4854  arm  ov016
 *   gDwcMoveidWork     0x021DE668  data
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

extern unsigned int func_021D3250(void);
extern int DWCi_MOV_WH_ParentConnect(int mode, u16 tgid, u16 channel);
extern void func_021D4624(u16 kind, u16 counter, u8 *data);
extern void func_021D4770(void);
extern u16 func_021D4854(void);
extern Wk *gDwcMoveidWork;

void _DWCi_MOV_MovUserID(void)
{
    switch (func_021D3250()) {
    case 1:
        DWCi_MOV_WH_ParentConnect(4, gDwcMoveidWork->moveid_tgid + 1, gDwcMoveidWork->moveid_sChannel);
        break;
    case 4:
    case 5:
    case 6:
        func_021D4624(0, gDwcMoveidWork->data_seq_num,
                      (u8 *)gDwcMoveidWork->p_user_info + (gDwcMoveidWork->data_seq_num % 16) * 64);
        func_021D4770();
        if (gDwcMoveidWork->mov_stt == 0x1b)
            break;
        if (gDwcMoveidWork->parent_step_data_share_error_cnt > 0x1e0) {
            gDwcMoveidWork->mov_stt = 0x1b;
            break;
        }
        if (func_021D4854() == 0x10 || func_021D4854() == 0x20) {
            func_021D4854();
            gDwcMoveidWork->mov_stt = 0xa;
        } else if (func_021D4854() == 0x40) {
            gDwcMoveidWork->mov_stt = 0xb;
        } else if (func_021D4854() == 0xff) {
            gDwcMoveidWork->mov_stt = 0x1b;
        } else if (func_021D4854() == 0x50) {
            gDwcMoveidWork->mov_stt = 0x15;
        } else if (func_021D4854() == 0x60) {
            gDwcMoveidWork->mov_stt = 0x18;
        } else if (func_021D4854() == 0x70) {
            gDwcMoveidWork->mov_stt = 0x1b;
        } else if (func_021D4854() == 0) {
            gDwcMoveidWork->mov_stt = 8;
        } else if (func_021D4854() == 0xbd) {
            gDwcMoveidWork->mov_stt = 9;
        } else {
            gDwcMoveidWork->mov_stt = 0x1f;
        }
        break;
    }
}
