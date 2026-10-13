/*
 * function: DWCi_USBAPlBegin
 * address:  0x021D0B44
 * packet:   pkt_ov016_021D0B44
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_USBAPlBegin (libdwcutil.TWL.HYB.a usbap.o)
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   OS_GetTick  0x020870D0  arm
 *   WM_Initialize  0x0208F370  arm
 *   WM_ReadStatus  0x0208EBE4  arm
 *   WM_GetDispersionScanPeriod  0x0208EFC4  arm
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021D0CB8  0x021D0CB8  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gUsbapWork  0x021DE654  data
 *   func_021D0DE0  0x021D0DE0  arm  ov016
 *   sUsbApScanParam  0x021DA958  data
 *   sUsbApSsid  0x021DA94E  data
 *   func_021D10D8  0x021D10D8  arm  ov016
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
 *       --func DWCi_USBAPlBegin --addr 0x021D0B44 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

typedef struct {
    void *scanBuf;
    u16 scanBufSize;
    u16 channelList;
    u16 maxChannelTime;
    u8 bssid[6];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[32];
    u16 ssidMatchLength;
    u16 rsv2[7];
} ScanParamT;

typedef struct {
    u16 state;
    u8 pad[0x7d0 - 2];
} WmStatusT;

typedef struct {
    u8 wmBuf[3840];
    u8 scanBuf[1024];
    u8 ap[16][7];
    void (*callback)(int);
    ScanParamT param;
    WmStatusT status;
    u64 start;
    void *task;
    u8 end;
    u8 stack;
    u8 wait;
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

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern u64 OS_GetTick(void);
extern int WM_Initialize(void *wmBuf, void (*callback)(void *), int dmaNo);
extern void WM_ReadStatus(void *status);
extern u16 WM_GetDispersionScanPeriod(void);
extern void OS_GetOwnerInfo(OwnerT *info);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
extern int func_021D0CB8(void);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void DWCi_HEAPlFree_(void **mem);
extern MemUsbT *gUsbapWork;
extern void func_021D0DE0(void *arg);
extern ScanParamT sUsbApScanParam;
extern char sUsbApSsid[9];
extern void func_021D10D8(void *task);

int DWCi_USBAPlBegin(void (*callback)(int))
{
    OwnerT owner;
    int rs;
    u64 tick;

    gUsbapWork = DWCi_HEAPlAllocEx(0x1ba0, 0x20);
    gUsbapWork->callback = callback;
    tick = OS_GetTick();
    gUsbapWork->start = tick;
    rs = WM_Initialize(*(MemUsbT *volatile *)&gUsbapWork, func_021D0DE0, 3);
    if (rs != 2)
        goto fail;
    do {
        WM_ReadStatus(&gUsbapWork->status);
    } while (gUsbapWork->status.state != 2);
    gUsbapWork->param = sUsbApScanParam;
    gUsbapWork->param.scanBuf = gUsbapWork->scanBuf;
    gUsbapWork->param.maxChannelTime = WM_GetDispersionScanPeriod();
    OS_GetOwnerInfo(&owner);
    MI_CpuCopy8(sUsbApSsid, gUsbapWork->param.ssid, 8);
    gUsbapWork->param.ssid[9] = 1;
    MI_CpuCopy8(owner.nickName, &gUsbapWork->param.ssid[12], owner.nickNameLength * 2);
    if (!func_021D0CB8())
        goto fail;
    gUsbapWork->task = DWCi_TSKlForm(0, func_021D10D8, 0, 0x78);
    return 1;
fail:
    DWCi_HEAPlFree_((void *)0x021DE654);
    return 0;
}
