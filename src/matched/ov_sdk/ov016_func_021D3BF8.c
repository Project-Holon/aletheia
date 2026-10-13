/*
 * function: DWCi_MOVFinalize
 * address:  0x021D3BF8
 * packet:   pkt_ov016_021D3BF8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOVFinalize (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   MB_EndToIdle                     0x021F5F74  arm
 *   gDwcMoveidWork                       0x021DE668  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 pad[0x14];
    u32 ggid;
    u8 pad2[0x3c - 0x18];
} MBGameRegistry;

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
extern void MB_EndToIdle(void);

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
