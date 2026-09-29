/*
 * function: func_021D4148
 * address:  0x021D4148
 * packet:   pkt_ov016_021D4148
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      _DWCi_MOVSearchChannel (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   DWCi_MOV_WH_GetSystemState       0x021D3250  arm  ov016
 *   DWCi_MOV_WH_StartMeasureChannel  0x021D3264  arm  ov016
 *   DWCi_MOV_WH_GetMeasureChannel    0x021D34E0  arm  ov016
 *   DWCi_MOV_WH_Reset                0x021D39A4  arm  ov016
 *   OS_Terminate                     0x02088234  arm
 *   g_021DE668                       0x021DE668  data
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

extern Wk *g_021DE668;
extern int DWCi_MOV_WH_GetSystemState(void);
extern int DWCi_MOV_WH_StartMeasureChannel(void);
extern u16 DWCi_MOV_WH_GetMeasureChannel(void);
extern void DWCi_MOV_WH_Reset(void);
extern void OS_Terminate(void);

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
