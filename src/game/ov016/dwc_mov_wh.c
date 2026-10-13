/*
 * file:     dwc_mov_wh.c
 * unit:     yes
 * function: DWCi_MOV_WH_MemInit, DWCi_MOV_WH_ChangeSysState, DWCi_MOV_WH_SetError, DWCi_MOV_WH_StateInSetParentParam, DWCi_MOV_WH_StateOutSetParentParam, DWCi_MOV_WH_StateInSetParentWEPKey, DWCi_MOV_WH_StateOutSetParentWEPKey, DWCi_MOV_WH_StateInStartParent, DWCi_MOV_WH_StateOutStartParent, DWCi_MOV_WH_StateInStartParentMP, DWCi_MOV_WH_StateOutStartParentMP, DWCi_MOV_WH_StateInStartParentKeyShare, DWCi_MOV_WH_StateInEndParentKeyShare, DWCi_MOV_WH_StateInEndParentMP, DWCi_MOV_WH_StateOutEndParentMP, DWCi_MOV_WH_StateInEndParent, DWCi_MOV_WH_StateOutEndParent, DWCi_MOV_WH_StateInEndChildKeyShare, DWCi_MOV_WH_StateInEndChildMP, DWCi_MOV_WH_StateOutEndChildMP, DWCi_MOV_WH_StateInEndChild, DWCi_MOV_WH_StateOutEndChild, DWCi_MOV_WH_StateInReset, DWCi_MOV_WH_StateOutReset, DWCi_MOV_WH_StateOutEnd, DWCi_MOV_WH_SetGgid, DWCi_MOV_WH_GetBitmap, DWCi_MOV_WH_GetSystemState, DWCi_MOV_WH_StartMeasureChannel, DWCi_MOV_WH_StateInMeasureChannel, DWCi_MOV_WH_StateOutMeasureChannel, DWCi_DwcMovWhWHi_MeasureChannel, DWCi_MOV_WH_GetMeasureChannel, DWCi_DwcMovWhSelectChannel, DWCi_MOV_WH_Initialize, DWCi_MOV_WH_IndicateHandler, DWCi_MOV_WH_StateInInitialize, DWCi_MOV_WH_StateOutInitialize, DWCi_MOV_WH_ParentConnect, DWCi_MOV_WH_SetJudgeAcceptFunc, DWCi_MOV_WH_GetSharedDataAdr, DWCi_MOV_WH_StepDS, DWCi_MOV_WH_Reset, DWCi_MOV_WH_Finalize, DWCi_MOV_WH_End
 * address:  0x021D298C
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
 *   WM_StartKeySharing             0x02090B9C  arm  arm9
 *   dwc_mov_wh_bss                   0x021DE660  data
 *   wh_statenames                    0x021DBD8C  data
 *   dwc_mov_wh_str_13637             0x021DBDB4  data
 *   dwc_mov_wh_str_13638             0x021DBDBC  data
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *   WM_SetWEPKey                     0x02090BC4  arm
 *   WM_StartParent                   0x0208F644  arm
 *   WM_Disconnect                    0x0208F938  arm
 *   dwc_mov_wh_str_13726             0x021DBDC0  data
 *   dwc_mov_wh_str_13728             0x021DBDEC  data
 *   dwc_mov_wh_str_13730             0x021DBE18  data
 *   WM_StartMP                       0x0208FC4C  arm
 *   DWCi_MOV_WH_StateInStartParentKeyShare 0x021D2F50  arm
 *   WM_StartDataSharing              0x0209004C  arm
 *   dwc_mov_wh_str_13783             0x021DBE38  data
 *   WM_EndMP                         0x0208FDEC  arm
 *   dwc_mov_wh_str_13805             0x021DBE68  data
 *   WM_EndParent                     0x0208F654  arm
 *   WM_Reset                         0x0208F400  arm
 *   OS_GetMacAddress                 0x02087C6C  arm
 *   WM_GetAllowedChannel             0x0208EE60  arm
 *   dwc_mov_wh_str_14186             0x021DBEC0  data
 *   WM_MeasureChannel                0x02090E50  arm
 *   OS_Terminate                     0x02088234  arm
 *   dwc_mov_wh_str_14204             0x021DBED8  data
 *   DWCi_MOV_WH_StateInInitialize    0x021D36D0  arm  ov016
 *   wh_trace                         0x021DE660  data
 *   WM_SetIndCallback                0x0208EAC8  arm
 *   WM_GetDispersionBeaconPeriod     0x0208EF30  arm
 *   DWCi_MOV_WH_StateInSetParentParam 0x021D2A64  arm
 *   dwc_mov_wh_str_13820             0x021DBE90  data
 *   dwc_mov_wh_str_13821             0x021DBEA8  data
 *   dwc_mov_wh_str_14263             0x021DBEF0  data
 *   WM_StepDataSharing               0x020902D8  arm
 *   dwc_mov_wh_str_14361             0x021DBF0C  data
 *   dwc_mov_wh_str_14362             0x021DBF3C  data
 *   DWCi_MOV_WH_StateInEndChildKeyShare 0x021D308C  arm
 *   DWCi_MOV_WH_StateInEndParentKeyShare 0x021D2F8C  arm
 *   dwc_mov_wh_str_14400             0x021DBF70  data
 *   dwc_mov_wh_str_14401             0x021DBF94  data
 *   WM_Initialize  0x0208F370  arm  arm9
 *   WM_End  0x0208F43C  arm  arm9
 *   WM_SetParentParameter  0x0208F480  arm  arm9
 *   WM_GetSharedDataAddress  0x02090B18  arm  arm9
 *   WM_EndKeySharing  0x02090BB8  arm  arm9
 */
#include "../../matched/include/G_DWC_MOV_WH_BSS.h"
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

typedef struct {
    unsigned short apiid;
    unsigned short errcode;
    char           pad_04[4];
    unsigned short state;      /* 0x08 */
    char           pad_0A[6];
    unsigned short aid;        /* 0x10 */
} WMStartParentCallback;

typedef struct {
    unsigned short apiid;
    unsigned short errcode;
    unsigned short state;      /* 0x04 */
} WMStartMPCallback;

typedef struct {
    unsigned short apiid;
    unsigned short errcode;
    char           pad_04[4];
    unsigned short channel;        /* 0x08 */
    unsigned short ccaBusyRatio;   /* 0x0A */
} WMMeasureChannelCallback;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
    u32 f0;
    u16 f4;
    u8 pad0[0x48 - 6];
    u32 f48;
    u32 f4c;
    u16 f50;
    u16 f52;
    u32 f54;
    u8 pad1[0x12a0 - 0x58];
    u32 f12a0;
    u32 f12a4;
} Wh;

typedef struct { unsigned short apiid; unsigned short errcode; unsigned short state; } WMIndCallback;

extern int WM_SetParentParameter(int, int);
void DWCi_MOV_WH_SetError(unsigned int v);
extern int WM_SetWEPKey(void (*callback)(void *), unsigned short wepmode, unsigned short *wepkey);
extern int WM_StartParent(void (*callback)(void *));
extern int WM_Disconnect(void (*callback)(void *), unsigned short aid);
extern int WM_StartMP(void (*callback)(void *), unsigned short *recvBuf, unsigned short recvBufSize,
                      unsigned short *sendBuf, unsigned short sendBufSize, unsigned short mpFreq);
int DWCi_MOV_WH_StateInStartParentKeyShare(void);
extern int WM_StartDataSharing(void *dsInfo, unsigned short port, unsigned short aidBitmap,
                               unsigned short dataLength, int doubleMode);
extern int WM_StartKeySharing(int, int);
extern int WM_EndKeySharing(int);
extern int WM_EndMP(void (*callback)(void *));
extern int WM_EndParent(void (*callback)(void *));
extern int WM_Reset(void (*callback)(void *));
extern void OS_GetMacAddress(unsigned char *macAddress);
extern unsigned short WM_GetAllowedChannel(void);
extern int WM_MeasureChannel(void (*callback)(void *), unsigned short ccaMode, unsigned short edThreshold,
                             unsigned short channel, unsigned short measureTime);
extern void OS_Terminate(void);
int DWCi_MOV_WH_StateInInitialize(void);
extern int WM_Initialize(int, int, int);
extern int WM_SetIndCallback(void (*callback)(void *));
extern unsigned short WM_GetDispersionBeaconPeriod(void);
int DWCi_MOV_WH_StateInSetParentParam(void);
extern void WM_GetSharedDataAddress(void *, void *, int);
extern int WM_StepDataSharing(void *dsInfo, unsigned short *sendData, void *receiveData);
int DWCi_MOV_WH_StateInEndChildKeyShare(void);
int DWCi_MOV_WH_StateInEndParentKeyShare(void);
extern int WM_End(int);
void DWCi_MOV_WH_MemInit(void *mw);
void DWCi_MOV_WH_SetGgid(unsigned int v);
unsigned short DWCi_MOV_WH_GetBitmap(void);
unsigned int DWCi_MOV_WH_GetSystemState(void);
int DWCi_MOV_WH_StartMeasureChannel(void);
unsigned short DWCi_MOV_WH_GetMeasureChannel(void);
int DWCi_MOV_WH_Initialize(void);
int DWCi_MOV_WH_ParentConnect(int mode, unsigned short tgid, unsigned short channel);
void DWCi_MOV_WH_SetJudgeAcceptFunc(unsigned int v);
void DWCi_MOV_WH_GetSharedDataAdr(int a);
int DWCi_MOV_WH_StepDS(void *data);
void DWCi_MOV_WH_Reset(void);
void DWCi_MOV_WH_Finalize(void);
int DWCi_MOV_WH_End(void);
extern struct DWC_MOV_WH_BSS dwc_mov_wh_bss;
extern const char *const wh_statenames[];
extern const char dwc_mov_wh_str_13637[];
extern const char dwc_mov_wh_str_13638[];
extern const char dwc_mov_wh_str_13726[];
extern const char dwc_mov_wh_str_13728[];
extern const char dwc_mov_wh_str_13730[];
extern const char dwc_mov_wh_str_13783[];
extern const char dwc_mov_wh_str_13805[];
extern const char dwc_mov_wh_str_14186[];
extern const char dwc_mov_wh_str_14204[];
extern const char dwc_mov_wh_str_13820[];
extern const char dwc_mov_wh_str_13821[];
extern const char dwc_mov_wh_str_14263[];
extern const char dwc_mov_wh_str_14361[];
extern const char dwc_mov_wh_str_14362[];
extern const char dwc_mov_wh_str_14400[];
extern const char dwc_mov_wh_str_14401[];

static void DWCi_MOV_WH_ChangeSysState(int state);
static void DWCi_MOV_WH_StateOutSetParentParam(void *arg);
static int DWCi_MOV_WH_StateInSetParentWEPKey(void);
static void DWCi_MOV_WH_StateOutSetParentWEPKey(void *arg);
static int DWCi_MOV_WH_StateInStartParent(void);
static void DWCi_MOV_WH_StateOutStartParent(void *arg);
static int DWCi_MOV_WH_StateInStartParentMP(void);
static void DWCi_MOV_WH_StateOutStartParentMP(void *arg);
static int DWCi_MOV_WH_StateInEndParentMP(void);
static void DWCi_MOV_WH_StateOutEndParentMP(void *arg);
static int DWCi_MOV_WH_StateInEndParent(void);
static void DWCi_MOV_WH_StateOutEndParent(void *arg);
static int DWCi_MOV_WH_StateInEndChildMP(void);
static void DWCi_MOV_WH_StateOutEndChildMP(void *arg);
static int DWCi_MOV_WH_StateInEndChild(void);
static void DWCi_MOV_WH_StateOutEndChild(void *arg);
static int DWCi_MOV_WH_StateInReset(void);
static void DWCi_MOV_WH_StateOutReset(void *arg);
static void DWCi_MOV_WH_StateOutEnd(void *arg);
static unsigned short DWCi_MOV_WH_StateInMeasureChannel(unsigned short channel);
static void DWCi_MOV_WH_StateOutMeasureChannel(void *arg);
static int WHi_MeasureChannel(void (*func)(void *), unsigned short channel);
static short SelectChannel(unsigned short bitmap);
static void DWCi_MOV_WH_IndicateHandler(void *arg);
static void DWCi_MOV_WH_StateOutInitialize(void *arg);


void DWCi_MOV_WH_MemInit(void *mw)
{
    dwc_mov_wh_bss.wh = (WHWork *)mw;
    ((WHWork *)dwc_mov_wh_bss.wh)->sysState = 0;
    ((WHWork *)dwc_mov_wh_bss.wh)->f_13A8 = 0;
    ((WHWork *)dwc_mov_wh_bss.wh)->parentWEPKeyGenerator = 0;
    ((WHWork *)dwc_mov_wh_bss.wh)->f_13B0 = 0;
}


static void DWCi_MOV_WH_ChangeSysState(int state)
{
    if (dwc_mov_wh_bss.wh_trace)
        dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13637, wh_statenames[((WHWork *)dwc_mov_wh_bss.wh)->sysState]);
    ((WHWork *)dwc_mov_wh_bss.wh)->sysState = state;
    if (dwc_mov_wh_bss.wh_trace)
        dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13638, wh_statenames[((WHWork *)dwc_mov_wh_bss.wh)->sysState]);
}


/*
 * Store v unless the state word at +0x40 is 9 or 10.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_WH_SetError.c \
 *       --func DWCi_MOV_WH_SetError --addr 0x021D2A44 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_MOV_WH_SetError(unsigned int v)
{
    char **p = (char **)0x021DE660;
    char *q = p[1];
    if (*(unsigned int *)(q + 0x40) - 9 > 1)
        *(unsigned int *)(q + 0x54) = v;
}


/*
 * Select port 3, poll the global tail against the table at 0x021D2AA8, then fall back.
 * Addresses are Black-image addresses.
 */
int DWCi_MOV_WH_StateInSetParentParam(void)
{
    int *g = (int *)0x021DE660;
    int rs;

    DWCi_MOV_WH_ChangeSysState(3);
    rs = WM_SetParentParameter((int)0x021D2AA8, g[1]);
    if (rs == 2)
        return 1;
    DWCi_MOV_WH_SetError(rs);
    DWCi_MOV_WH_ChangeSysState(9);
    return 0;
}


static void DWCi_MOV_WH_StateOutSetParentParam(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_ChangeSysState(9);
        return;
    }
    if (((WHWork *)dwc_mov_wh_bss.wh)->parentWEPKeyGenerator != 0) {
        if (!DWCi_MOV_WH_StateInSetParentWEPKey())
            DWCi_MOV_WH_ChangeSysState(9);
    } else {
        if (!DWCi_MOV_WH_StateInStartParent())
            DWCi_MOV_WH_ChangeSysState(9);
    }
}


static int DWCi_MOV_WH_StateInSetParentWEPKey(void)
{
    unsigned short wepmode;
    int result;

    DWCi_MOV_WH_ChangeSysState(3);
    wepmode = ((WHWork *)dwc_mov_wh_bss.wh)->parentWEPKeyGenerator(((WHWork *)dwc_mov_wh_bss.wh)->wepkey, dwc_mov_wh_bss.wh);
    result = WM_SetWEPKey(DWCi_MOV_WH_StateOutSetParentWEPKey, wepmode, ((WHWork *)dwc_mov_wh_bss.wh)->wepkey);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    DWCi_MOV_WH_ChangeSysState(9);
    return 0;
}


static void DWCi_MOV_WH_StateOutSetParentWEPKey(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_ChangeSysState(9);
        return;
    }
    if (!DWCi_MOV_WH_StateInStartParent())
        DWCi_MOV_WH_ChangeSysState(9);
}


static int DWCi_MOV_WH_StateInStartParent(void)
{
    int result;

    if (((WHWork *)dwc_mov_wh_bss.wh)->sysState == 6 || ((WHWork *)dwc_mov_wh_bss.wh)->sysState == 5 || ((WHWork *)dwc_mov_wh_bss.wh)->sysState == 4)
        return 1;
    result = WM_StartParent(DWCi_MOV_WH_StateOutStartParent);
    if (result != 2) {
        DWCi_MOV_WH_SetError(result);
        return 0;
    }
    ((WHWork *)dwc_mov_wh_bss.wh)->f_50 = 0;
    ((WHWork *)dwc_mov_wh_bss.wh)->bitmap = 1;
    return 1;
}


static void DWCi_MOV_WH_StateOutStartParent(void *arg)
{
    WMStartParentCallback *cb = (WMStartParentCallback *)arg;
    unsigned short target_bitmap = (unsigned short)(1 << cb->aid);
    int result;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_ChangeSysState(9);
        return;
    }
    switch (cb->state) {
    case 7:
        if (dwc_mov_wh_bss.wh_trace)
            dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13726, cb->aid);
        if (((WHWork *)dwc_mov_wh_bss.wh)->judgeAcceptFunc != 0 && !((WHWork *)dwc_mov_wh_bss.wh)->judgeAcceptFunc(cb)) {
            result = WM_Disconnect(0, cb->aid);
            if (result == 2)
                return;
            DWCi_MOV_WH_SetError(result);
            DWCi_MOV_WH_ChangeSysState(9);
            return;
        }
        ((WHWork *)dwc_mov_wh_bss.wh)->bitmap |= target_bitmap;
        break;
    case 9:
        if (dwc_mov_wh_bss.wh_trace)
            dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13728, cb->aid);
        ((WHWork *)dwc_mov_wh_bss.wh)->bitmap &= ~target_bitmap;
        break;
    case 0:
        if (!DWCi_MOV_WH_StateInStartParentMP())
            DWCi_MOV_WH_ChangeSysState(9);
        break;
    case 2:
        break;
    default:
        if (dwc_mov_wh_bss.wh_trace)
            dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13730, cb->state);
        break;
    }
}


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


static void DWCi_MOV_WH_StateOutStartParentMP(void *arg)
{
    WMStartMPCallback *cb = (WMStartMPCallback *)arg;
    int result;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_ChangeSysState(9);
        return;
    }
    switch (cb->state) {
    case 10:
        if (((WHWork *)dwc_mov_wh_bss.wh)->connectMode == 2) {
            if (((WHWork *)dwc_mov_wh_bss.wh)->sysState == 4) {
                if (DWCi_MOV_WH_StateInStartParentKeyShare())
                    return;
                if (dwc_mov_wh_bss.wh_trace)
                    dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13783);
                DWCi_MOV_WH_ChangeSysState(9);
                return;
            } else if (((WHWork *)dwc_mov_wh_bss.wh)->sysState == 6) {
                return;
            }
        } else if (((WHWork *)dwc_mov_wh_bss.wh)->connectMode == 4) {
            result = WM_StartDataSharing(((WHWork *)dwc_mov_wh_bss.wh)->dsInfo, 13, 7, 0x44, 1);
            if (result != 0) {
                DWCi_MOV_WH_SetError(result);
                DWCi_MOV_WH_ChangeSysState(9);
                return;
            }
            DWCi_MOV_WH_ChangeSysState(5);
            return;
        }
        DWCi_MOV_WH_ChangeSysState(4);
        break;
    case 11:
        break;
    case 12:
    case 13:
    default:
        if (dwc_mov_wh_bss.wh_trace)
            dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13730, cb->state);
        break;
    }
}


/*
 * Select port 6, start key sharing on the global object's tail, then reset on mismatch.
 * Addresses are Black-image addresses.
 */
int DWCi_MOV_WH_StateInStartParentKeyShare(void)
{
    int *g = (int *)0x021DE660;
    int rs;

    DWCi_MOV_WH_ChangeSysState(6);
    rs = WM_StartKeySharing(g[1] + 0x1e00, 0xd);
    if (rs == 2)
        return 1;
    DWCi_MOV_WH_SetError(rs);
    return 0;
}


/*
 * Query the global object's tail, then reset on anything but the ready answer.
 * Addresses are Black-image addresses.
 */
int DWCi_MOV_WH_StateInEndParentKeyShare(void)
{
    int *g = (int *)0x021DE660;
    int rs;

    rs = WM_EndKeySharing(g[1] + 0x1e00);
    if (rs == 2)
        return 1;
    DWCi_MOV_WH_SetError(rs);
    return 0;
}


static int DWCi_MOV_WH_StateInEndParentMP(void)
{
    int result;

    DWCi_MOV_WH_ChangeSysState(3);
    result = WM_EndMP(DWCi_MOV_WH_StateOutEndParentMP);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    return 0;
}


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


static void DWCi_MOV_WH_StateOutEndParent(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(1);
}


/*
 * Only in state 6, select port 3 and query the global tail for the ready answer.
 * Addresses are Black-image addresses.
 */
int DWCi_MOV_WH_StateInEndChildKeyShare(void)
{
    int *g = (int *)0x021DE660;
    int rs;

    if (*(int *)(g[1] + 0x40) != 6)
        return 0;
    DWCi_MOV_WH_ChangeSysState(3);
    rs = WM_EndKeySharing(g[1] + 0x1e00);
    if (rs == 2)
        return 1;
    DWCi_MOV_WH_SetError(rs);
    return 0;
}


static int DWCi_MOV_WH_StateInEndChildMP(void)
{
    int result;

    DWCi_MOV_WH_ChangeSysState(3);
    result = WM_EndMP(DWCi_MOV_WH_StateOutEndChildMP);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    return 0;
}


static void DWCi_MOV_WH_StateOutEndChildMP(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_Finalize();
        return;
    }
    if (DWCi_MOV_WH_StateInEndChild())
        return;
    DWCi_MOV_WH_ChangeSysState(9);
}


static int DWCi_MOV_WH_StateInEndChild(void)
{
    int result;

    DWCi_MOV_WH_ChangeSysState(3);
    result = WM_Disconnect(DWCi_MOV_WH_StateOutEndChild, 0);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    DWCi_MOV_WH_Reset();
    return 0;
}


static void DWCi_MOV_WH_StateOutEndChild(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(1);
}


static int DWCi_MOV_WH_StateInReset(void)
{
    int result;

    DWCi_MOV_WH_ChangeSysState(3);
    result = WM_Reset(DWCi_MOV_WH_StateOutReset);
    if (result == 2)
        return 1;
    DWCi_MOV_WH_SetError(result);
    return 0;
}


static void DWCi_MOV_WH_StateOutReset(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_ChangeSysState(9);
        DWCi_MOV_WH_SetError(cb->errcode);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(1);
}


static void DWCi_MOV_WH_StateOutEnd(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_ChangeSysState(10);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(0);
}


/*
 * Store a word at +0x08 of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_WH_SetGgid.c \
 *       --func DWCi_MOV_WH_SetGgid --addr 0x021D3228 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_MOV_WH_SetGgid(unsigned int v)
{
    char **p = (char **)0x021DE660;
    unsigned int *q = (unsigned int *)(p[1] + 4);
    q[1] = v;
}


/*
 * Halfword at +0x52 of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_WH_GetBitmap.c \
 *       --func DWCi_MOV_WH_GetBitmap --addr 0x021D323C --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned short DWCi_MOV_WH_GetBitmap(void)
{
    char **p = (char **)0x021DE660;
    unsigned short *q = (unsigned short *)(p[1] + 0x52);
    return *q;
}


/*
 * Word at +0x40 of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_WH_GetSystemState.c \
 *       --func DWCi_MOV_WH_GetSystemState --addr 0x021D3250 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned int DWCi_MOV_WH_GetSystemState(void)
{
    char **p = (char **)0x021DE660;
    unsigned int *q = (unsigned int *)(p[1] + 0x40);
    return *q;
}


static inline unsigned long OS_GetVBlankCount(void)
{
    return *(volatile unsigned long *)0x02FFFC3C;
}


int DWCi_MOV_WH_StartMeasureChannel(void)
{
    unsigned char macAddr[6];
    unsigned short result;

    OS_GetMacAddress(macAddr);
    ((WHWork *)dwc_mov_wh_bss.wh)->randSeed = (unsigned long)(OS_GetVBlankCount() + *(unsigned short *)&macAddr[0] + *(unsigned short *)&macAddr[2] + *(unsigned short *)&macAddr[4]);
    ((WHWork *)dwc_mov_wh_bss.wh)->randSeed = ((WHWork *)dwc_mov_wh_bss.wh)->randSeed * 69069 + 12345;
    ((WHWork *)dwc_mov_wh_bss.wh)->channel = 0;
    ((WHWork *)dwc_mov_wh_bss.wh)->minBusyRatio = 101;
    DWCi_MOV_WH_ChangeSysState(3);
    result = DWCi_MOV_WH_StateInMeasureChannel(1);
    if (result == 24) {
        DWCi_MOV_WH_SetError(24);
        DWCi_MOV_WH_ChangeSysState(9);
        return 0;
    }
    if (result != 2) {
        DWCi_MOV_WH_SetError(result);
        DWCi_MOV_WH_ChangeSysState(9);
        return 0;
    }
    return 1;
}


static unsigned short DWCi_MOV_WH_StateInMeasureChannel(unsigned short channel)
{
    unsigned short allowedChannel;

    allowedChannel = WM_GetAllowedChannel();
    if (allowedChannel == 0x8000) {
        DWCi_MOV_WH_SetError(3);
        DWCi_MOV_WH_ChangeSysState(9);
        return 3;
    }
    if (allowedChannel == 0) {
        DWCi_MOV_WH_SetError(22);
        DWCi_MOV_WH_ChangeSysState(9);
        return 24;
    }
    while ((allowedChannel & (1 << (channel - 1))) == 0) {
        channel++;
        if (channel > 16)
            return 24;
    }
    return WHi_MeasureChannel(DWCi_MOV_WH_StateOutMeasureChannel, channel);
}


static void DWCi_MOV_WH_StateOutMeasureChannel(void *arg)
{
    WMMeasureChannelCallback *cb = (WMMeasureChannelCallback *)arg;
    unsigned short channel;
    unsigned short result;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_ChangeSysState(9);
        return;
    }
    if (dwc_mov_wh_bss.wh_trace)
        dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_14186, cb->channel, cb->ccaBusyRatio);
    channel = cb->channel;
    if (((WHWork *)dwc_mov_wh_bss.wh)->minBusyRatio > cb->ccaBusyRatio) {
        ((WHWork *)dwc_mov_wh_bss.wh)->minBusyRatio = cb->ccaBusyRatio;
        ((WHWork *)dwc_mov_wh_bss.wh)->busyChannelBitmap = 1 << (channel - 1);
    } else if (((WHWork *)dwc_mov_wh_bss.wh)->minBusyRatio == cb->ccaBusyRatio) {
        ((WHWork *)dwc_mov_wh_bss.wh)->busyChannelBitmap |= 1 << (channel - 1);
    }
    result = DWCi_MOV_WH_StateInMeasureChannel(++channel);
    if (result == 24) {
        DWCi_MOV_WH_ChangeSysState(7);
        return;
    }
    if (result != 2)
        DWCi_MOV_WH_ChangeSysState(9);
}


static int WHi_MeasureChannel(void (*func)(void *), unsigned short channel)
{
    return WM_MeasureChannel(func, 3, 17, channel, 30);
}


unsigned short DWCi_MOV_WH_GetMeasureChannel(void)
{
    if (((WHWork *)dwc_mov_wh_bss.wh)->sysState != 7)
        OS_Terminate();
    DWCi_MOV_WH_ChangeSysState(1);
    ((WHWork *)dwc_mov_wh_bss.wh)->channel = SelectChannel(((WHWork *)dwc_mov_wh_bss.wh)->busyChannelBitmap);
    if (dwc_mov_wh_bss.wh_trace)
        dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_14204, ((WHWork *)dwc_mov_wh_bss.wh)->channel);
    return ((WHWork *)dwc_mov_wh_bss.wh)->channel;
}


static short SelectChannel(unsigned short bitmap)
{
    short i;
    short channel = 0;
    unsigned short num = 0;
    unsigned short select;

    for (i = 0; i < 16; i++) {
        if (bitmap & (1 << i)) {
            channel = (short)(i + 1);
            num++;
        }
    }
    if (num <= 1)
        return channel;
    ((WHWork *)dwc_mov_wh_bss.wh)->randSeed = ((WHWork *)dwc_mov_wh_bss.wh)->randSeed * 69069 + 12345;
    select = (unsigned short)((num * (((WHWork *)dwc_mov_wh_bss.wh)->randSeed & 0xFF)) >> 8);
    for (i = 0; i < 16; i++) {
        if (bitmap & 1) {
            if (select == 0)
                return (short)(i + 1);
            select--;
        }
        bitmap >>= 1;
    }
    return 0;
}


static void *wh_trace = 0;


static Wh *wh = 0;


/*
 * closed 2026-10-01 (ov SDK wave 4): the tail is `switch (call) { case 0:
 *   return 0; default: return 1; }`. Vendor .debug_line puts moveq on its own
 *   line (2567) and movne on 2570, i.e. two return statements; a two-return
 *   switch is the only 1.1p1 shape whose if-converted select writes r0 in both
 *   arms (if/else, ternary, goto, local forms all coalesce the result onto a
 *   constant register). The history below is superseded.
 *
 *           vendor object dwc_mov_wh.o is .comment 4.0.0.1025, for which no
 *           tools/mwccarm build maps (1.1p1 is 1024); every emitted instruction
 *           matches except the if-converted boolean select at +0068, where the
 *           object writes the result into r0 (`moveq r0,r5; movne r0,r4`) and
 *           1.1p1 coalesces it into the r5 zero constant (`movne r5,r4; mov
 *           r0,r5`).  Both orderings are reachable only by flipping the 0/1
 *           constant registers.  The function has no local in the vendor DWARF,
 *           so it is a direct return; ~30 spellings re-tried this pass, and a
 *           400-candidate permuter run found no single mutation that improves it.
 *
 * w9_nm: still 5 B. Also tried: the ternary with no local, one/zero locals selected by a ternary, result from a local then a ternary, early return of r or 1.
 *
 * sdk:      DWCi_MOV_WH_Initialize (libdwcutil.TWL.HYB.a(dwc_mov_wh.o))
 *
 * w6_nm tried: goto-spelled exits with a shared return label (both senses),
 * a result local via goto, unsigned char return/callee types: register roles unchanged.
 *
 * w8_nm: `int r = 0; ... if (call) r = 1; return r;` puts 0 in r5 and 1 in r4 as
 * in the object (15 B -> 5 B). Left: the object returns with `moveq r0,r5;
 * movne r0,r4`, this compile with `movne r5,r4; mov r0,r5`. The result local is
 * not in the DWARF. Tried: `? 1 : 0`, `!!`, `!= 0`, if/else returns in both
 * senses, r = 1 then clear, if/else assignment, the call result in a local,
 * cc 1.1, 1.2, 1.2p1, 1.3.
 *
 * T6: still 5 B - the select's destination register. Object `moveq r0,r5 /
 * movne r0,r4`; this build `movne r5,r4 / mov r0,r5` (the result coalesces
 * into the r5 zero constant). 14 spellings re-run: if/return without else in
 * both senses, if/else returns, `r = c ? 1 : 0;` at declaration and after the
 * stores, `(c != 0)`, one/zero locals, `if (c) r = 1; else r = 0;` - every one
 * either flips the constant assignment to r4=0/r5=1 or keeps the result in
 * r5. Only `int r = 0; if (c) r = 1; return r;` keeps the object's r5=0/r4=1
 * ordering, and that is the shape whose result coalesces. A sweep over all
 * nine pins x seven flag sets x inline/ipa variants is D5 in every cell.
 * U26: 8 further tail spellings (bare ternary, assignment-ternary, `!= 0`, `!!`, if/else in both
 * senses, braced single-arm if, do/while(0), temp local, `return c ? 1 : r` with r == 0) - every
 * one either flips the constants (0 to r4, 1 to r5, 15 B out) or keeps the result coalesced into
 * r5 with the copy to r0 (5 B out).  The 2-instruction residue is the if-converted select's
 * destination register, not a statement shape.
 *
 * wave8: confirmed the residue is the if-converted select's DESTINATION
 * register, not a statement shape.  This pass (20+ spellings: direct `? 1 : 0`
 * and `? B_TRUE : B_FALSE` returns, if/else returns and assignments in both arm
 * orders and both senses, enum-constant ternary and enum-typed locals, u8/int
 * return types, `static`, `int r = f(); r = r ? 1 : 0;` dying-local, `!= 0`,
 * `!!`) all land in one of two classes: keep r5=0/r4=1 and coalesce the select
 * into r5 with the trailing `mov r0,r5` (5 B), or flip the constants (0->r4,
 * 1->r5, 15 B).  Only `int r = 0; if (c) r = 1; return r;` keeps the object's
 * r5=0/r4=1 colouring, and that is the shape whose result coalesces.  The
 * vendor build writes both predicated moves straight into r0
 * (`moveq r0,r5; movne r0,r4`); 1.1p1 coalesces the result onto the live zero
 * constant.  No C-level lever moves it.  See
 * docs/idioms/an-if-converted-selects-destination-register-is-the-front-ends.md
 *
 * w8 (this lane): 3 further tail spellings, all the same two classes.  A
 * `switch (call) { case 0: r = 0; break; default: r = 1; }` emitted the exact
 * 5-B coalesced form as the committed shape, and `r = call ? 1 : r;` (r == 0
 * false arm) flipped the constants to r4=0/r5=1 for 15 B.  No new lever.
 *
 * 2026-10-01 (ov SDK wave 2): wh_trace/wh are now the object's two .bss statics
 *   (wh_trace +0, wh +4) instead of one extern struct: inert, still 5 B. Also inert:
 *   the callee as a TU static with a body (IPA-visible); ternary and if-return
 *   tails re-measured with the statics (15 B).
 *
 * 2026-10-01 (w3 lane19): still 5 B. Vendor .o has no aligned section (no
 *   asm-mode lever); re-measured `return call ? 1 : 0` (coalesces onto the 1
 *   register instead, 15 B). No new lever.
 */
int DWCi_MOV_WH_Initialize(void)
{
    wh->f12a4 = 0;
    wh->f12a0 = 0;
    wh->f48 = 0;
    wh->f50 = 0;
    wh->f52 = 1;
    wh->f54 = 0;
    wh->f0 = 0;
    wh->f4 = 0;
    wh->f4c = 0;
    switch (DWCi_MOV_WH_StateInInitialize())
    {
    case 0:
        return 0;
    default:
        return 1;
    }
}


static void DWCi_MOV_WH_IndicateHandler(void *arg)
{
    WMIndCallback *cb = (WMIndCallback *)arg;

    if (cb->errcode == 8) {
        DWCi_MOV_WH_ChangeSysState(9);
        OS_Terminate();
    }
}


/*
 * Select port 3, run the 0x021D371C script on the global tail, then fall back.
 * Addresses are Black-image addresses.
 */
int DWCi_MOV_WH_StateInInitialize(void)
{
    int *g = (int *)0x021DE660;
    int rs;

    DWCi_MOV_WH_ChangeSysState(3);
    rs = WM_Initialize(g[1] + 0x80, (int)0x021D371C, 2);
    if (rs == 2)
        return 1;
    DWCi_MOV_WH_SetError(rs);
    DWCi_MOV_WH_ChangeSysState(0xa);
    return 0;
}


static void DWCi_MOV_WH_StateOutInitialize(void *arg)
{
    int result;
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != 0) {
        DWCi_MOV_WH_SetError(cb->errcode);
        DWCi_MOV_WH_ChangeSysState(10);
        return;
    }
    result = WM_SetIndCallback(DWCi_MOV_WH_IndicateHandler);
    if (result != 0) {
        DWCi_MOV_WH_SetError(result);
        DWCi_MOV_WH_ChangeSysState(10);
        return;
    }
    DWCi_MOV_WH_ChangeSysState(1);
}


int DWCi_MOV_WH_ParentConnect(int mode, unsigned short tgid, unsigned short channel)
{
    if (((WHWork *)dwc_mov_wh_bss.wh)->sysState != 1)
        OS_Terminate();
    ((WHWork *)dwc_mov_wh_bss.wh)->recvBufSize = 0x180;
    ((WHWork *)dwc_mov_wh_bss.wh)->sendBufSize = 0xE0;
    if (dwc_mov_wh_bss.wh_trace)
        dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13820, ((WHWork *)dwc_mov_wh_bss.wh)->recvBufSize);
    if (dwc_mov_wh_bss.wh_trace)
        dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_13821, ((WHWork *)dwc_mov_wh_bss.wh)->sendBufSize);
    ((WHWork *)dwc_mov_wh_bss.wh)->connectMode = mode;
    DWCi_MOV_WH_ChangeSysState(3);
    ((WHWork *)dwc_mov_wh_bss.wh)->tgid = tgid;
    ((WHWork *)dwc_mov_wh_bss.wh)->pchannel = channel;
    ((WHWork *)dwc_mov_wh_bss.wh)->f_18 = WM_GetDispersionBeaconPeriod();
    ((WHWork *)dwc_mov_wh_bss.wh)->f_34 = 0xD0;
    ((WHWork *)dwc_mov_wh_bss.wh)->f_36 = 0x44;
    ((WHWork *)dwc_mov_wh_bss.wh)->f_10 = 2;
    ((WHWork *)dwc_mov_wh_bss.wh)->f_16 = 0;
    ((WHWork *)dwc_mov_wh_bss.wh)->f_12 = 0;
    ((WHWork *)dwc_mov_wh_bss.wh)->f_0E = 1;
    ((WHWork *)dwc_mov_wh_bss.wh)->f_14 = (mode == 2) ? 1 : 0;
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


/*
 * Store a word at +0x4c of the object behind the pointer at 0x021DE664.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MOV_WH_SetJudgeAcceptFunc.c \
 *       --func DWCi_MOV_WH_SetJudgeAcceptFunc --addr 0x021D38C8 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_MOV_WH_SetJudgeAcceptFunc(unsigned int v)
{
    char **p = (char **)0x021DE660;
    unsigned int *q = (unsigned int *)(p[1] + 0x4c);
    *q = v;
}


/*
 * Tail-call WM_GetSharedDataAddress with two views of the block behind 0x021DE660.
 * Addresses are Black-image addresses.
 */
void DWCi_MOV_WH_GetSharedDataAdr(int a)
{
    int *g = (int *)0x021DE660;
    char *p = (char *)g[1];

    WM_GetSharedDataAddress(p + 0x13e0, p + 0x1c00, a);
}


int DWCi_MOV_WH_StepDS(void *data)
{
    int result;

    result = WM_StepDataSharing(((WHWork *)dwc_mov_wh_bss.wh)->dsInfo, (unsigned short *)data, ((WHWork *)dwc_mov_wh_bss.wh)->receiveData);
    if (result == 7) {
        if (dwc_mov_wh_bss.wh_trace)
            dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_14361);
        return 0;
    }
    if (result == 5) {
        if (dwc_mov_wh_bss.wh_trace)
            dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_14362);
        DWCi_MOV_WH_SetError(result);
        return 0;
    }
    if (result != 0) {
        DWCi_MOV_WH_SetError(result);
        return 0;
    }
    return 1;
}


void DWCi_MOV_WH_Reset(void)
{
    if (DWCi_MOV_WH_StateInReset())
        return;
    DWCi_MOV_WH_ChangeSysState(10);
}


void DWCi_MOV_WH_Finalize(void)
{
    if (((WHWork *)dwc_mov_wh_bss.wh)->sysState == 1) {
        if (dwc_mov_wh_bss.wh_trace)
            dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_14400);
    } else {
        if (dwc_mov_wh_bss.wh_trace)
            dwc_mov_wh_bss.wh_trace(0x8000000, dwc_mov_wh_str_14401, ((WHWork *)dwc_mov_wh_bss.wh)->sysState);
        if (((WHWork *)dwc_mov_wh_bss.wh)->sysState != 6 && ((WHWork *)dwc_mov_wh_bss.wh)->sysState != 5 && ((WHWork *)dwc_mov_wh_bss.wh)->sysState != 4) {
            DWCi_MOV_WH_ChangeSysState(3);
            DWCi_MOV_WH_Reset();
            return;
        }
        DWCi_MOV_WH_ChangeSysState(3);
        switch (((WHWork *)dwc_mov_wh_bss.wh)->connectMode) {
        case 3:
            if (!DWCi_MOV_WH_StateInEndChildKeyShare())
                DWCi_MOV_WH_Reset();
            break;
        case 1:
        case 5:
            if (!DWCi_MOV_WH_StateInEndChildMP())
                DWCi_MOV_WH_Reset();
            break;
        case 2:
            if (!DWCi_MOV_WH_StateInEndParentKeyShare())
                DWCi_MOV_WH_Reset();
            break;
        case 0:
        case 4:
            if (!DWCi_MOV_WH_StateInEndParentMP())
                DWCi_MOV_WH_Reset();
            break;
        }
    }
}


/*
 * Wake the sound system when idle, select port 3 and run the 0x021D3200 script.
 * Addresses are Black-image addresses.
 */
int DWCi_MOV_WH_End(void)
{
    int *g = (int *)0x021DE660;

    if (*(int *)(g[1] + 0x40) != 1)
        OS_Terminate();
    DWCi_MOV_WH_ChangeSysState(3);
    if (WM_End((int)0x021D3200) == 2)
        return 1;
    DWCi_MOV_WH_ChangeSysState(9);
    return 0;
}
