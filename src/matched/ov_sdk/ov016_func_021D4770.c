/*
 * function: func_021D4770
 * address:  0x021D4770
 * packet:   pkt_ov016_021D4770
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      Parent_data_receive_progress (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   gDwcMoveidWork                       0x021DE668  data
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

extern Wk *gDwcMoveidWork;
typedef struct {
    u16 kind;
    u8 data[0x42];
} GShareData;

void func_021D4770(void)
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
