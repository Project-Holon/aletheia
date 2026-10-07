/*
 * file:     unit_021D298C_p05.c
 * unit:     yes
 * function: func_021D2FEC, func_021D3040
 * address:  0x021D2FEC
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
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *   DWCi_MOV_WH_Reset                0x021D39A4  arm
 *   dwc_mov_wh_bss                   0x021DE660  data
 *   dwc_mov_wh_str_13805             0x021DBE68  data
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *   WM_EndParent                     0x0208F654  arm
 *   DWCi_MOV_WH_StateOutEndParent    0x021D3068  arm
 */
#include "../../matched/include/G_DWC_MOV_WH_BSS.h"

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

typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_Reset(void);
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern int WM_EndParent(void (*callback)(void *));
extern void DWCi_MOV_WH_StateOutEndParent(void *arg);
extern struct DWC_MOV_WH_BSS dwc_mov_wh_bss;
extern const char dwc_mov_wh_str_13805[];


static void DWCi_MOV_WH_StateOutEndParentMP(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_Reset();
        return;
    }
    if (DWCi_MOV_WH_StateInEndParent())
        return;
    if (dwc_mov_wh_bss.wh_trace)
        dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13805);
    DWCi_MOV_WH_Reset();
}


static int DWCi_MOV_WH_StateInEndParent(void)
{
    int result;

    result = WM_EndParent(DWCi_MOV_WH_StateOutEndParent);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    return 0;
}
