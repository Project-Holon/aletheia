/*
 * function: DWCi_MOV_WH_StateInStartParentMP
 * address:  0x021D2D6C
 * packet:   pkt_ov016_021D39C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *   WM_StartMP                       0x0208FC4C  arm
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *   dwc_mov_wh_bss                   0x021DE660  data
 *   DWCi_MOV_WH_StateOutStartParentMP 0x021D2E00  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_StateInStartParentMP (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D2D6C.c \n *       --func DWCi_MOV_WH_StateInStartParentMP --addr 0x021D2D6C --region ov016 --cc 1.1p1 --arm
 */

#include "../../../matched/include/G_DWC_MOV_WH_BSS.h"

/*
 * dwc_mov_wh.o's .bss (wh_trace, wh) at 0x021DE660, one object in the vendor order.
 * The work area wh points at has no DWARF layout in the object; members are named by offset.
 */
typedef struct WHWork {
    int             f_00;              /* 0x00 */
    unsigned short  f_04;              /* 0x04 */
    char            pad_06[0x0C - 0x06];
    unsigned short  tgid;              /* 0x0C */
    unsigned short  f_0E;              /* 0x0E */
    unsigned short  f_10;              /* 0x10 */
    unsigned short  f_12;              /* 0x12 */
    unsigned short  f_14;              /* 0x14 */
    unsigned short  f_16;              /* 0x16 */
    unsigned short  f_18;              /* 0x18 */
    char            pad_1A[0x32 - 0x1A];
    unsigned short  pchannel;          /* 0x32 */
    unsigned short  f_34;              /* 0x34 */
    unsigned short  f_36;              /* 0x36 */
    char            pad_38[0x40 - 0x38];
    int             sysState;          /* 0x40 */
    int             connectMode;       /* 0x44 */
    int             f_48;              /* 0x48 */
    int           (*judgeAcceptFunc)(void *cb);  /* 0x4C */
    unsigned short  f_50;              /* 0x50 */
    unsigned short  bitmap;            /* 0x52 */
    int             f_54;              /* 0x54 */
    unsigned long   randSeed;          /* 0x58 */
    unsigned short  channel;           /* 0x5C */
    unsigned short  minBusyRatio;      /* 0x5E */
    unsigned short  busyChannelBitmap; /* 0x60 */
    char            pad_62[0xF80 - 0x62];
    unsigned short  sendBuf[0x70];     /* 0xF80 */
    unsigned short  recvBuf[0x120];    /* 0x1060 */
    int             sendBufSize;       /* 0x12A0 */
    int             recvBufSize;       /* 0x12A4 */
    char            pad_12A8[0x13A8 - 0x12A8];
    int             f_13A8;            /* 0x13A8 */
    unsigned short (*parentWEPKeyGenerator)(unsigned short *wepkey, void *param);  /* 0x13AC */
    int             f_13B0;            /* 0x13B0 */
    char            pad_13B4[0x0C];
    unsigned short  wepkey[0x10];      /* 0x13C0 */
    char            dsInfo[0x1C00 - 0x13E0];  /* 0x13E0, struct WMDataSharingInfo */
    char            receiveData[1];    /* 0x1C00, struct WMDataSet */
} WHWork;

typedef struct {
    void  (*wh_trace)(int level, const char *fmt, ...);
    WHWork *wh;
} DWC_MOV_WH_BSS;

extern struct DWC_MOV_WH_BSS dwc_mov_wh_bss;

typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

extern void DWCi_MOV_WH_ChangeSysState(int state);
extern int WM_StartMP(void (*callback)(void *), unsigned short *recvBuf, unsigned short recvBufSize,
                      unsigned short *sendBuf, unsigned short sendBufSize, unsigned short mpFreq);
extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_StateOutStartParentMP(void *arg);

static int DWCi_MOV_WH_StateInStartParentMP(void)
{
    int result;

    if (((WHWork *)dwc_mov_wh_bss.wh)->sysState == 6 || ((WHWork *)dwc_mov_wh_bss.wh)->sysState == 5 || ((WHWork *)dwc_mov_wh_bss.wh)->sysState == 4)
        return 1;
    DWCi_MOV_WH_ChangeSysState(4);
    result = WM_StartMP(DWCi_MOV_WH_StateOutStartParentMP,
                        ((WHWork *)dwc_mov_wh_bss.wh)->recvBuf, (unsigned short)((WHWork *)dwc_mov_wh_bss.wh)->recvBufSize,
                        ((WHWork *)dwc_mov_wh_bss.wh)->sendBuf, (unsigned short)((WHWork *)dwc_mov_wh_bss.wh)->sendBufSize, 1);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    return 0;
}
