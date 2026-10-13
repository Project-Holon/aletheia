/*
 * file:     usbap.c
 * unit:     yes
 * function: func_021D0B44, func_021D0CB8, func_021D0CEC, func_021D0DC8, func_021D0DE0, func_021D0E74, func_021D0FCC, func_021D10D8
 * address:  0x021D0B44
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   OS_GetTick  0x020870D0  arm
 *   WM_Initialize  0x0208F370  arm
 *   WM_ReadStatus  0x0208EBE4  arm
 *   WM_GetDispersionScanPeriod  0x0208EFC4  arm
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE654  0x021DE654  data
 *   g_021DA958  0x021DA958  data
 *   g_021DA94E  0x021DA94E  data
 *   func_0208F698  0x0208F698  arm
 *   func_0208EBE4  0x0208EBE4  arm
 *   WM_Reset  0x0208F400  arm
 *   WM_End  0x0208F43C  arm
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   g_021DE654_b   0x021DE654  data
 *   func_02088234  0x02088234  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   memcmp  0x020923F0  arm
 *   g_021DA948  0x021DA948  data
 *   func_021D7724  0x021D7724  arm  ov016
 */
#include "../../matched/arm9_sdk/libc/memcmp/string.h"

struct WMStatus;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef struct {
    void *scanBuf;
    unsigned short scanBufSize;
    unsigned short channelList;
    unsigned short maxChannelTime;
    unsigned char bssid[6];
    unsigned short scanType;
    unsigned short ssidLength;
    unsigned char ssid[32];
    unsigned short ssidMatchLength;
    unsigned short rsv2[7];
} ScanParamT;

typedef struct {
    unsigned short state;
    unsigned char pad[0x7d0 - 2];
} WmStatusT;

typedef struct {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned short ssidLength;
    unsigned char ssid[32];
} BssDescT;

typedef struct {
    unsigned short apiid;
    unsigned short errcode;
    unsigned short wlCmdID;
    unsigned short wlResult;
    unsigned short state;
    unsigned short channelList;
    unsigned char reserved[2];
    unsigned short bssDescCount;
    BssDescT *bssDesc[16];
} ScanCbT;

typedef struct {
    unsigned char bssid[6];
    unsigned char used;
} UsbApT;

typedef struct {
    unsigned char wmBuf[3840];
    unsigned char scanBuf[1024];
    UsbApT ap[16];
    void (*callback)(int);
    ScanParamT param;
    WmStatusT status;
    unsigned long long start;
    void *task;
    volatile unsigned char end;
    unsigned char stack;
    unsigned char wait;
} MemUsbT;

typedef struct {
    u8 language;
    u8 favoriteColor;
    u16 birthday;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OwnerT;

enum WMErrCode {
    WM_ERRCODE_SUCCESS = 0,
    WM_ERRCODE_FAILED = 1,
    WM_ERRCODE_OPERATING = 2
};

extern void *func_021D6414(unsigned long size, int alignment);
extern u64 OS_GetTick(void);
extern int WM_Initialize(void *wmBuf, void (*callback)(void *), int dmaNo);
extern void WM_ReadStatus(void *status);
extern u16 WM_GetDispersionScanPeriod(void);
extern void OS_GetOwnerInfo(OwnerT *info);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
extern void *func_021D7680(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_021D6438(void **mem);
extern int func_0208F698();
extern int func_0208EBE4(struct WMStatus *statusBuf);
extern enum WMErrCode WM_Reset(void (*)(void *));
extern enum WMErrCode WM_End(void (*)(void *));
extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void func_02088234(void);
extern void DC_InvalidateRange(void *ptr, unsigned long nBytes);
extern void func_021D7724(int kind, void *task);
int func_021D0B44(void (*callback)(int));
int func_021D0CB8(void);
int func_021D0CEC(void);
void func_021D0DC8(unsigned int v);
void func_021D0DE0(void *arg);
void func_021D0E74(ScanCbT *prm);
void func_021D0FCC(ScanCbT *prm);
void func_021D10D8(void *task);
extern MemUsbT *g_021DE654;
extern ScanParamT g_021DA958;
extern char g_021DA94E[9];
extern MemUsbT *g_021DE654_b;
extern u8 g_021DA948[6];







/*
 * sdk:      DWCi_USBAPlBegin (libdwcutil.TWL.HYB.a usbap.o)
 *
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so it
 * stays on the default dsi/1.1p1.
 *
 * The image re-reads the global for the WM_Initialize argument (`ldr r0, [r5]` at +0040) instead of
 * reusing the load it already made for the u64 store; a plain read lets mwcc 1.1p1 CSE it into r4 and
 * emit `mov r0, r4` (9 bytes, 4 lines out, size exact). Reading the pointer through a volatile
 * cast forces the re-read and closes the function. ../2.0/base and ../2.0/sp1p2 give 392 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021D0B44.c \
 *       --func func_021D0B44 --addr 0x021D0B44 --region ov016 --cc 1.1p1 --arm --lang c99
 */
int func_021D0B44(void (*callback)(int))
{
    OwnerT owner;
    int rs;
    u64 tick;

    g_021DE654 = func_021D6414(0x1ba0, 0x20);
    g_021DE654->callback = callback;
    tick = OS_GetTick();
    g_021DE654->start = tick;
    rs = WM_Initialize(*(MemUsbT *volatile *)&g_021DE654, func_021D0DE0, 3);
    if (rs != 2)
        goto fail;
    do {
        WM_ReadStatus(&g_021DE654->status);
    } while (g_021DE654->status.state != 2);
    g_021DE654->param = g_021DA958;
    g_021DE654->param.scanBuf = g_021DE654->scanBuf;
    g_021DE654->param.maxChannelTime = WM_GetDispersionScanPeriod();
    OS_GetOwnerInfo(&owner);
    MI_CpuCopy8(g_021DA94E, g_021DE654->param.ssid, 8);
    g_021DE654->param.ssid[9] = 1;
    MI_CpuCopy8(owner.nickName, &g_021DE654->param.ssid[12], owner.nickNameLength * 2);
    if (!func_021D0CB8())
        goto fail;
    g_021DE654->task = func_021D7680(0, func_021D10D8, 0, 0x78);
    return 1;
fail:
    func_021D6438((void *)0x021DE654);
    return 0;
}







/*
 * sdk:      startScan (libdwcutil.TWL.HYB.a usbap.o)
 */
int func_021D0CB8(void)
{
    int rs = func_0208F698(func_021D0DE0, &g_021DE654->param);
    return rs == 2;
}







/*
 * note:     wave8 (2026-09-30): EXACT, 220 bytes, 9/9 relocs.  The old
 *           +0094/+0098 residue (`ldr r1,[r0,#0xb90]` vs `ldr r0,[r0,#0xb90]`)
 *           was not an allocator tie: `DWCi_TSKlDeleteByIndex` is a 12-byte veneer to
 *           0x021D7750, whose body opens `mov r4, r1` then `ldrb r1,[r4,#0x11]`
 *           and passes r4 on -- it takes the task pointer as a *second*
 *           argument.  The image keeps `g->task` in r1 across the guard
 *           because the guarded call passes that same value again:
 *           `DWCi_TSKlDeleteByIndex(0, g_021DE654->task)`.  The one-argument spelling
 *           lets the dying base coalesce into the load destination, which is
 *           the 2-byte residue.  The general lever is
 *           docs/idioms/a-guard-value-still-in-r1-at-the-call-is-the-callees-second-argument.md.
 *           `task` must be plain (`void *`), not volatile, or the second
 *           argument re-loads; `end` stays volatile.
 *
 * sdk:      DWCi_USBAPlEnd (libdwcutil.TWL.HYB.a usbap.o)
 *
 * vendor DWARF of usbap.o (Metrowerks 4.0.0.1025):
 *   bool DWCi_USBAPlEnd(void);
 *   variable enum WMErrCode rs            r0      - the only local
 *   declarations enum WMErrCode WM_ReadStatus(struct WMStatus *);
 *                enum WMErrCode WM_Reset(void (*)(void *));
 *                enum WMErrCode WM_End(void (*)(void *));
 *                void DWCi_HEAPlFree_(void **);
 *                extern struct tagMEMUSB *MemUsb;
 *                static void cbWm(void *);
 *   DWCi_HEAPlFree_ is declared `void **` in the DWARF, but the call site
 *   passes `&MemUsb`, i.e. an `M **`, which a `void **` parameter rejects;
 *   the extern here is therefore left unprototyped.  Codegen is unaffected.
 *   struct tagMEMUSB (7072 bytes): +0x0 wmBuf[3840], +0xf00 scanBuf[1024],
 *     +0x1300 ap[16], +0x1370 callback, +0x1374 param, +0x13b8 status
 *     (struct WMStatus), +0x1b88 start, +0x1b90 task (void *), +0x1b94 end,
 *     +0x1b95 stack, +0x1b96 wait.  struct WMStatus's first member is `state`,
 *     read here as a plain halfword (`ldrh`, no mask), so it is declared u16.
 *   enum WMErrCode (values read out of the object's DWARF): SUCCESS 0,
 *     FAILED 1, OPERATING 2, ILLEGAL_STATE 3, WM_DISABLE 4, NO_KEYSET 5,
 *     NO_DATASET 5, INVALID_PARAM 6, NO_CHILD 7, FIFO_ERROR 8, TIMEOUT 9,
 *     SEND_QUEUE_FULL 10, NO_ENTRY 11, OVER_MAX_ENTRY 12,
 *     INVALID_POLLBITMAP 13, NO_DATA 14, SEND_FAILED 15, DCF_TEST 16,
 *     WL_INVALID_PARAM 17, WL_LENGTH_ERR 18, FLASH_ERROR 19, MAX 20.
 *     Every `cmp #2` in the image is therefore WM_ERRCODE_OPERATING.
 *
 * 0x021D0DE0, reached by the two ABS32 sites that pass a callback to WM_Reset
 * and WM_End, is not a data struct: it is `cbWm` itself, the file-static
 * `static void cbWm(void *arg)` (148 bytes, the callback for
 * struct WMStartScanExCallback) that also lives in usbap.o.  It is `func
 * local` in the object's symbol table and [open-sdk] only because no C for it
 * has been matched yet; the site resolves on the `sdk` class from
 * layout/symbols_sdk.json, so it never gated this function.
 */
int func_021D0CEC(void)
{
    enum WMErrCode rs;
    g_021DE654->end = 1;
    func_0208EBE4((struct WMStatus *)(&g_021DE654->status.state));
    if (g_021DE654->status.state != WM_ERRCODE_OPERATING) {
        rs = WM_Reset(func_021D0DE0);
        if (rs != WM_ERRCODE_OPERATING)
            return 0;
        do {
            func_0208EBE4((struct WMStatus *)(&g_021DE654->status.state));
        } while (g_021DE654->status.state != WM_ERRCODE_OPERATING);
    }
    rs = WM_End(func_021D0DE0);
    if (rs != WM_ERRCODE_OPERATING)
        return 0;
    if (g_021DE654->task != 0)
        DWCi_TSKlDeleteByIndex(0, g_021DE654->task);
    while (g_021DE654->end != 2)
        ;
    func_021D6438((void **)(&g_021DE654_b));
    return 1;
}






/*
 * Store a word at +0x1370 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D0DC8.c \
 *       --func func_021D0DC8 --addr 0x021D0DC8 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021D0DC8(unsigned int v)
{
    *(unsigned int *)(*(char **)0x021DE654 + 0x1370) = v;
}





/*
 * sdk:      cbWm (libdwcutil.TWL.HYB.a usbap.o)
 *
 * vendor DWARF of usbap.o (Metrowerks 4.0.0.1025):
 *   static void cbWm(void *arg);
 *   variable struct WMStartScanExCallback *prm   r0
 *
 * wave3 lane23 (2026-10-01): EXACT, 148 bytes, 6/6 relocs.  Closed by making
 *   MemUsb->end a volatile field (as the sibling DWCi_USBAPlEnd needs for its
 *   `while (end != 2)` spin) together with the plain `if (apiid == END) end = 2;
 *   return;` arm.  With a volatile field the store is not if-converted, so the
 *   object's `cmp / popne / mov / strb / pop` comes back.  Earlier lanes had only
 *   tried a volatile store (cast), which stays predicated, and the earlier
 *   144 B / 87 history (if-conversion "compiler wall", -O1 coincidence) is
 *   superseded.  The if/else-if spelling with a volatile field still predicates;
 *   the arm needs the explicit `return` and the 0x26 test as a separate guard.
 */
void func_021D0DE0(void *arg)
{
    ScanCbT *prm = (ScanCbT *)arg;

    if (prm->errcode != 0)
        return;
    if (g_021DE654->end != 0) {
        if (prm->apiid == 2)
            g_021DE654->end = 2;
        return;
    }
    if (prm->apiid != 0x26)
        return;
    switch (prm->state) {
    case 5:
        if (g_021DE654->wait)
            func_021D0FCC(prm);
        else
            func_021D0E74(prm);
        func_021D0CB8();
        break;
    case 4:
        func_021D0CB8();
        break;
    default:
        func_02088234();
        break;
    }
}




void func_021D0E74(ScanCbT *prm)
{
    BssDescT *info;
    int i;
    int j;

    for (i = 0; i < prm->bssDescCount; i++) {
        info = prm->bssDesc[i];
        DC_InvalidateRange(info, 0xc0);
        if (memcmp(info->ssid, g_021DA94E, 8) != 0)
            continue;
        for (j = 0; j < 16; j++) {
            if (memcmp(info->bssid, g_021DE654->ap[j].bssid, 6) == 0) {
                if (g_021DE654->ap[j].used)
                    goto next;
                if (!(info->ssid[9] & 1))
                    goto next;
                if (g_021DE654->callback)
                    g_021DE654->callback(1);
                return;
            }
        }
        for (j = 0; j < 16; j++) {
            if (memcmp(g_021DE654->ap[j].bssid, g_021DA948, 6) == 0) {
                MI_CpuCopy8(info->bssid, ((UsbApT *)g_021DE654->ap)[j].bssid, 6);
                g_021DE654->ap[j].used = (info->ssid[9] & 1) ? 1 : 0;
                break;
            }
        }
    next:;
    }
}



/*
 * sdk:      scanWait (libdwcutil.TWL.HYB.a usbap.o)
 */
void func_021D0FCC(ScanCbT *prm)
{
    BssDescT *info;
    int i;
    int j;

    if (g_021DE654->stack) {
        if (g_021DE654->callback)
            g_021DE654->callback(g_021DE654->stack);
        return;
    }
    DC_InvalidateRange(g_021DE654->scanBuf, 1024);
    for (i = 0; i < prm->bssDescCount; i++) {
        info = prm->bssDesc[i];
        if (memcmp(info->ssid, g_021DA94E, 8) != 0)
            continue;
        if (!(info->ssid[9] & 1))
            continue;
        for (j = 0; j < 16; j++) {
            if (memcmp(info->bssid, g_021DE654->ap[j].bssid, 6) == 0) {
                if (g_021DE654->ap[j].used)
                    goto next;
                if (g_021DE654->callback == 0) {
                    g_021DE654->stack = 1;
                    return;
                }
                g_021DE654->callback(1);
                return;
            }
        }
    next:;
    }
}


/*
 * sdk:      taskFirst (libdwcutil.TWL.HYB.a usbap.o)
 */
void func_021D10D8(void *task)
{
    u64 tick;
    int i;
    int admit;
    int not;

    tick = OS_GetTick();
    if (tick < g_021DE654->start + 0x17F898)
        return;
    not = 0;
    admit = 0;
    for (i = 0; i < 16; i++) {
        if (memcmp(g_021DE654->ap[i].bssid, g_021DA948, 6) != 0) {
            if (g_021DE654->ap[i].used)
                admit = 1;
            else
                not = 1;
        }
    }
    if (admit && not) {
        if (g_021DE654->callback)
            g_021DE654->callback(2);
    } else if (admit) {
        if (g_021DE654->callback)
            g_021DE654->callback(1);
    } else if (!not) {
        if (g_021DE654->callback)
            g_021DE654->callback(0);
    }
    g_021DE654->task = 0;
    g_021DE654->wait = 1;
    func_021D7724(0, task);
}
