/*
 * function: DWCi_MOV_WH_ParentConnect
 * address:  0x021D376C
 * packet:   pkt_ov016_021D39C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_Terminate                     0x02088234  arm
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *   WM_GetDispersionBeaconPeriod     0x0208EF30  arm
 *   DWCi_MOV_WH_StateInSetParentParam 0x021D2A64  arm
 *   dwc_mov_wh_bss                   0x021DE660  data
 *   dwc_mov_wh_str_13820             0x021DBE90  data
 *   dwc_mov_wh_str_13821             0x021DBEA8  data
 *   dwc_mov_wh_str_14263             0x021DBEF0  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(dwc_mov_wh.o), symbol DWCi_MOV_WH_ParentConnect (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021D376C.c \n *       --func DWCi_MOV_WH_ParentConnect --addr 0x021D376C --region ov016 --cc 1.1p1 --arm
 */
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

extern DWC_MOV_WH_BSS dwc_mov_wh_bss;

typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

extern void OS_Terminate(void);
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern unsigned short WM_GetDispersionBeaconPeriod(void);
extern int DWCi_MOV_WH_StateInSetParentParam(void);
extern const char dwc_mov_wh_str_13820[];
extern const char dwc_mov_wh_str_13821[];
extern const char dwc_mov_wh_str_14263[];

int DWCi_MOV_WH_ParentConnect(int mode, unsigned short tgid, unsigned short channel)
{
    if (dwc_mov_wh_bss.wh->sysState != 1)
        OS_Terminate();
    dwc_mov_wh_bss.wh->recvBufSize = 0x180;
    dwc_mov_wh_bss.wh->sendBufSize = 0xE0;
    if (dwc_mov_wh_bss.wh_trace)
        dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13820, dwc_mov_wh_bss.wh->recvBufSize);
    if (dwc_mov_wh_bss.wh_trace)
        dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13821, dwc_mov_wh_bss.wh->sendBufSize);
    dwc_mov_wh_bss.wh->connectMode = mode;
    DWCi_MOV_WH_ChangeSysState(3);
    dwc_mov_wh_bss.wh->tgid = tgid;
    dwc_mov_wh_bss.wh->pchannel = channel;
    dwc_mov_wh_bss.wh->f_18 = WM_GetDispersionBeaconPeriod();
    dwc_mov_wh_bss.wh->f_34 = 0xD0;
    dwc_mov_wh_bss.wh->f_36 = 0x44;
    dwc_mov_wh_bss.wh->f_10 = 2;
    dwc_mov_wh_bss.wh->f_16 = 0;
    dwc_mov_wh_bss.wh->f_12 = 0;
    dwc_mov_wh_bss.wh->f_0E = 1;
    dwc_mov_wh_bss.wh->f_14 = (mode == 2) ? 1 : 0;
    switch (mode) {
    case 0:
    case 2:
    case 4:
        return DWCi_MOV_WH_StateInSetParentParam();
    default:
        if (dwc_mov_wh_bss.wh_trace)
            dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_14263, mode);
        return 0;
    }
}
