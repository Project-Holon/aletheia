/*
 * function: func_021D2794
 * address:  0x021D2794
 * packet:   pkt_ov016_021D2794
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_GetChildBmp (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   g_021DE65C  0x021de65c  data
 *   g_021DB9D4  0x021db9d4  data
 *   g_021DB9D4_b  0x021DB9D4  data
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
    u16 connectedBmp;
    u16 entryBmp;
    u16 requestBmp;
    u16 downloadBmp;
    u16 bootBmp;
    u16 endBmp;
} DWCi_MOV_MBPState;

typedef struct {
    DWCi_MOV_MBPState mbpState;
    DWCi_MOV_MBPChildInfo childInfo[1];
} DWCi_MOV_WPB_WORK;

extern DWCi_MOV_WPB_WORK *g_021DE65C;

extern u16 *g_021DB9D4[6];
extern u16 *g_021DB9D4_b[6];

u16 func_021D2794(int bmpType)
{
    g_021DB9D4[0] = &g_021DE65C->mbpState.connectedBmp;
    g_021DB9D4[1] = &g_021DE65C->mbpState.entryBmp;
    g_021DB9D4[2] = &g_021DE65C->mbpState.requestBmp;
    g_021DB9D4[3] = &g_021DE65C->mbpState.downloadBmp;
    g_021DB9D4[4] = &g_021DE65C->mbpState.bootBmp;
    g_021DB9D4[5] = &g_021DE65C->mbpState.endBmp;
    return *g_021DB9D4_b[bmpType];
}
