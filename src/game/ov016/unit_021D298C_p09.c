/*
 * file:     unit_021D298C_p09.c
 * unit:     yes
 * function: func_021D3554, func_021D3638, func_021D36B0, func_021D36D0, func_021D371C, func_021D376C, func_021D38C8, func_021D38DC, func_021D3904, func_021D39A4, func_021D39C0, func_021D3AC8
 * address:  0x021D3554
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
 *   dwc_mov_wh_bss                   0x021DE660  data
 *   DWCi_MOV_WH_StateInInitialize    0x021D36D0  arm  ov016
 *   wh_trace                         0x021DE660  data
 *   DWCi_MOV_WH_ChangeSysState       0x021D29C8  arm
 *   OS_Terminate                     0x02088234  arm
 *   DWCi_MOV_WH_SetError             0x021D2A44  arm
 *   WM_SetIndCallback                0x0208EAC8  arm
 *   WM_GetDispersionBeaconPeriod     0x0208EF30  arm
 *   DWCi_MOV_WH_StateInSetParentParam 0x021D2A64  arm
 *   dwc_mov_wh_str_13820             0x021DBE90  data
 *   dwc_mov_wh_str_13821             0x021DBEA8  data
 *   dwc_mov_wh_str_14263             0x021DBEF0  data
 *   WM_StepDataSharing               0x020902D8  arm
 *   dwc_mov_wh_str_14361             0x021DBF0C  data
 *   dwc_mov_wh_str_14362             0x021DBF3C  data
 *   DWCi_MOV_WH_StateInReset         0x021D319C  arm
 *   DWCi_MOV_WH_StateInEndChildKeyShare 0x021D308C  arm
 *   DWCi_MOV_WH_StateInEndChildMP    0x021D30D8  arm
 *   DWCi_MOV_WH_StateInEndParentKeyShare 0x021D2F8C  arm
 *   DWCi_MOV_WH_StateInEndParentMP   0x021D2FBC  arm
 *   dwc_mov_wh_str_14400             0x021DBF70  data
 *   dwc_mov_wh_str_14401             0x021DBF94  data
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

extern int DWCi_MOV_WH_StateInInitialize(void);
extern void DWCi_MOV_WH_ChangeSysState(int state);
extern void OS_Terminate(void);
extern int func_0208F370(int, int, int);
extern int func_021D29C8(int);
extern int func_021D2A44(void);
extern void DWCi_MOV_WH_SetError(int code);
extern int WM_SetIndCallback(void (*callback)(void *));
extern unsigned short WM_GetDispersionBeaconPeriod(void);
extern int DWCi_MOV_WH_StateInSetParentParam(void);
extern void func_02090B18(void *, void *, int);
extern int WM_StepDataSharing(void *dsInfo, unsigned short *sendData, void *receiveData);
extern int DWCi_MOV_WH_StateInReset(void);
extern int DWCi_MOV_WH_StateInEndChildKeyShare(void);
extern int DWCi_MOV_WH_StateInEndChildMP(void);
extern int DWCi_MOV_WH_StateInEndParentKeyShare(void);
extern int DWCi_MOV_WH_StateInEndParentMP(void);
extern void func_02088234(void);
extern int func_0208F43C(int);
int func_021D3638(void);
int func_021D36D0(void);
int DWCi_MOV_WH_ParentConnect(int mode, unsigned short tgid, unsigned short channel);
void func_021D38C8(unsigned int v);
void func_021D38DC(int a);
int DWCi_MOV_WH_StepDS(void *data);
void DWCi_MOV_WH_Reset(void);
void DWCi_MOV_WH_Finalize(void);
int func_021D3AC8(void);
extern struct DWC_MOV_WH_BSS dwc_mov_wh_bss;
extern const char dwc_mov_wh_str_13820[];
extern const char dwc_mov_wh_str_13821[];
extern const char dwc_mov_wh_str_14263[];
extern const char dwc_mov_wh_str_14361[];
extern const char dwc_mov_wh_str_14362[];
extern const char dwc_mov_wh_str_14400[];
extern const char dwc_mov_wh_str_14401[];


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
int func_021D3638(void)
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
int func_021D36D0(void)
{
    int *g = (int *)0x021DE660;

    func_021D29C8(3);
    if (func_0208F370(g[1] + 0x80, (int)0x021D371C, 2) == 2)
        return 1;
    func_021D2A44();
    func_021D29C8(0xa);
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
 *   python tools/match.py one --src src/matched/func_021D38C8.c \
 *       --func func_021D38C8 --addr 0x021D38C8 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021D38C8(unsigned int v)
{
    char **p = (char **)0x021DE660;
    unsigned int *q = (unsigned int *)(p[1] + 0x4c);
    *q = v;
}


/*
 * Tail-call func_02090B18 with two views of the block behind 0x021DE660.
 * Addresses are Black-image addresses.
 */
void func_021D38DC(int a)
{
    int *g = (int *)0x021DE660;
    char *p = (char *)g[1];

    func_02090B18(p + 0x13e0, p + 0x1c00, a);
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
int func_021D3AC8(void)
{
    int *g = (int *)0x021DE660;

    if (*(int *)(g[1] + 0x40) != 1)
        func_02088234();
    func_021D29C8(3);
    if (func_0208F43C((int)0x021D3200) == 2)
        return 1;
    func_021D29C8(9);
    return 0;
}
