/*
 * file:     wih.c
 * unit:     yes
 * function: func_02177C1C, func_02177C4C, func_02177CE4, func_02177D0C, func_02177D58, func_02177DB0, func_02177E20, func_02177E9C, func_02177EB0, func_02177EDC, func_02177EFC, func_02177F48, func_02177FC4, func_02177FF0, func_02178034, func_0217807C, func_02178098, func_021780C4, func_021780E4, func_021780FC, func_02178118, func_02178138, func_0217814C, func_02178168, func_02178198, func_021781BC, func_02178204, func_02178304, func_021783FC, func_021784AC, func_021784D0, func_021784F0, func_0217850C, func_02178524, func_021785B4, func_0217863C, func_02178714, func_0217873C, func_02178788, func_021788FC, func_02178964, DWCi_MOV_WH_StateOutEndScan, func_021789C8, func_02178A18, func_02178AB8, func_02178B98, func_02178C50, func_02178C74, func_02178C98, func_02178CC4, func_02178CDC, func_02178D00, func_02178D20, func_02178D74, func_02178D9C, func_02178DE0, func_02178E1C, func_02178E28, func_02178E38, func_02178E4C, func_02178E68, func_02178E84, func_02178F1C, func_02178F8C, func_02179010, func_02179024, func_02179050, func_021790E4, func_02179158, func_02179188, func_021791A0, func_021791EC, func_021791F8, func_02179288, func_02179328, func_0217933C, func_02179368, func_02179394, func_021793B8, func_021793F8, func_0217945C, func_02179498, func_02179570, func_021795A4, func_021795C0, func_021795D4, func_02179614, func_02179628, func_0217963C, func_02179650
 * address:  0x02177C1C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   d_0217967C     0x0217967C  data   a2
 *   func_0203D798  0x0203D798  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_0217778C  0x0217778C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 *   func_021775AC  0x021775AC  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02178E28  0x02178E28  thumb  ov014
 *   d_02179680     0x02179680  data  ov014  a2
 *   func_0217771C  0x0217771C  thumb  ov014
 *   func_02082D44  0x02082D44  arm
 *   func_02177704 0x02177704 thumb ov014
 *   d_02179678     0x02179678  data  a1
 *   func_02177AA8  0x02177AA8  thumb  ov014
 *   func_020056EC  0x020056EC  thumb
 *   func_021773E0  0x021773E0  thumb  ov014
 *   func_0217758C  0x0217758C  thumb  ov014
 *   func_02177560  0x02177560  thumb  ov014
 *   d_021797A4 0x021797A4 data ov014 a4
 *   g_021797A8 0x021797A8 data ov014 a4
 *   func_0208F480 0x0208F480 arm
 *   func_0208F644  0x0208F644  arm
 *   func_0203D650  0x0203D650  arm
 *   func_0208F938  0x0208F938  arm
 *   func_0203A338  0x0203A338  arm
 *   func_02039A2C  0x02039A2C  arm
 *   d_02179794                  0x02179794  data   ov014  a1
 *   WM_GetMPSendBufferSize      0x0208EC34  arm
 *   WM_GetMPReceiveBufferSize   0x0208ECA4  arm
 *   WM_StartMP                  0x0208FC4C  arm
 *   func_0203D7FC               0x0203D7FC  arm
 *   func_0203D7C8               0x0203D7C8  arm
 *   func_0203D5D4               0x0203D5D4  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   func_0209004C  0x0209004C  arm
 *   func_0208FDEC 0x0208FDEC arm
 *   func_021784F0 0x021784F0 thumb ov014
 *   WM_EndParent                 0x0208F654  arm
 *   DWCi_MOV_WH_SetError             0x0217814C  thumb
 *   DWCi_MOV_WH_ChangeSysState       0x02178138  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   WM_GetAllowedChannel         0x0208EE60  arm
 *   WM_GetDispersionScanPeriod   0x0208EFC4  arm
 *   WM_StartScanEx               0x0208F698  arm
 *   d_0217979C          0x0217979C  data   a1
 *   func_02178964       0x02178964  thumb  ov014
 *   func_02010864       0x02010864  thumb
 *   func_02010884       0x02010884  thumb
 *   DC_InvalidateRange  0x020862B8  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   func_02034714       0x02034714  arm
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   WM_EndScan                     0x0208F808  arm
 *   func_0208F84C  0x0208F84C  arm
 *   func_02178CC4 0x02178CC4 thumb ov014
 *   func_0208F400 0x0208F400 arm
 *   func_0208FCB4  0x0208FCB4  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_02179010  0x02179010  thumb  ov014
 *   func_0208EE60  0x0208EE60  arm
 *   WM_MeasureChannel            0x02090E50  arm
 *   func_0208F370  0x0208F370  arm
 *   func_0208F380  0x0208F380  arm
 *   func_0208EAC8  0x0208EAC8  arm
 *   func_02090DEC  0x02090DEC  arm
 *   func_0208EF30  0x0208EF30  arm
 *   func_0203D6CC  0x0203D6CC  arm
 *   func_0208EB0C 0x0208EB0C arm
 *   func_02090B18 0x02090B18 arm
 *   func_020902D8  0x020902D8  arm
 *   func_0209028C 0x0209028C arm
 *   WM_EndDataSharing   0x0209028C  arm
 *   func_0208F43C 0x0208F43C arm
 *   func_02090CD4  0x02090CD4  arm
 */
#include "../../matched/include/Obj03088.h"
#include "../../matched/include/G_W.h"
#include "../../matched/include/Obj12469.h"
#include "../../matched/include/Obj19335.h"
#include "../../matched/include/Obj19336.h"
#include "../../matched/include/Obj19337.h"
#include "../../matched/include/Obj04956.h"
#include "../../matched/include/Obj02672.h"
#include "../../matched/include/G_S.h"
#include "../../matched/include/Obj05923.h"
#include "../../matched/include/Obj05924.h"
#include "../../matched/include/Obj12472.h"
#include "../../matched/include/Obj12473.h"
#include "../../matched/include/Obj04957.h"
#include "../../matched/include/Obj12474.h"
#include "../../matched/include/Obj12475.h"
#include "../../matched/include/Obj12476.h"
#include "../../matched/include/Obj03559.h"
#include "../../matched/include/Obj12477.h"
#include "../../matched/include/Obj19343.h"

struct WMDataSet;
struct WMDataSharingInfo;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef int (*ConnFn)(void *obj, u32 a);

typedef void (*SlotFn)(u16 slot);

typedef int BOOL;

typedef struct { unsigned short apiid; unsigned short errcode; } WMCallback;

typedef struct ScanExCb {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    u16 reserved;
    u16 bssDescCount;
    void *bssDesc[16];
    u16 linkLevel[16];
} ScanExCb;

typedef void (*FoundFn)(void *desc, u32 a, u16 level);

typedef int (*FilterFn)(void *desc);

typedef signed short s16_02178524;

typedef void (*Cb)(int);

typedef struct { u16 f0, err, f4, f6, channel, level; } Msg;

typedef short s16_021791F8;

extern void *func_0203D798(void);
extern u16 func_0208F1B4(void);
extern void func_0217778C(void);
extern void func_0217727C(u32 *p, u32 v);
int func_021775AC(int a, int b, int c);
u16 func_0203F1FC(const u8 *src, u32 len);
void func_020862F0(void *p, u32 n);
void func_02178E28(void *p, u32 n);
int func_0217771C(u8 *obj);
void func_02082D44(void *d, void *s, u32 n);
extern void func_02177704(void);
int func_02177AA8(void);
u32 func_020056EC(u32 n);
int func_021773E0(u8 *p);
void func_0217758C(u8 *p);
void func_02177560(void);
extern int func_0208F480(void (*)(void *), void *);
int func_0208F644(void *fn);
u32 func_0203D650(void);
extern int func_0208F938(void (*)(u8 *), u16);
void func_0203A338(u32 a0);
void func_02039A2C(int a);
extern int WM_GetMPSendBufferSize(void);
extern int WM_GetMPReceiveBufferSize(void);
extern int WM_StartMP(void (*cb)(void *), void *recvBuf, u16 recvSize,
                      void *sendBuf, u16 sendSize, u16 mpFreq);
extern void func_0203D7FC(void *p);
extern void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
extern u32 func_0203D5D4(void);
u32 func_0203D6BC(void);
u32 func_0203D680(void);
int func_0209004C(void *p, u32 a, u32 b, u16 c, u32 d);
extern int func_0208FDEC(void (*)(void *));
extern int func_021784F0(void);
extern int WM_EndParent(void *);
extern void DWCi_MOV_WH_SetError(int code);
extern void DWCi_MOV_WH_ChangeSysState(int state);
void func_02082BCC(void *p, u32 v, u32 n);
extern u16 WM_GetAllowedChannel(void);
extern u16 WM_GetDispersionScanPeriod(void);
extern int WM_StartScanEx(void (*cb)(void *), void *param);
extern int func_02178964(void);
extern void func_02010864(u32 v);
extern void func_02010884(void);
extern void DC_InvalidateRange(void *p, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_02034714(const char *expr, u32 line, const char *file);
int func_02087988(void);
void func_0208799C(int a);
extern int WM_EndScan(void *);
int func_0208F84C(void *cb, void *a, void *b, int c, int d);
extern void func_02178CC4(u8 *);
extern int func_0208F400(void (*)(u8 *));
int func_0208FCB4(void *cb, u32 c, u32 a, u32 b, u32 d, u32 e, u32 f);
void func_02087C6C(u16 *p);
int func_02179010(void *cb, int n);
u16 func_0208EE60(void);
extern int WM_MeasureChannel(void *callback, unsigned short ccaMode, unsigned short edThreshold, unsigned short channel, unsigned short measureTime);
extern int func_0208F370(void *buf, void (*cb)(void *), int dma);
extern int func_0208F380(void *buf, void (*cb)(void *), int dma, int x);
extern int func_0208EAC8(void (*f)(void));
extern void func_02090DEC(void (*f)(void), int a, int b, int c, int d);
extern u16 func_0208EF30(void);
extern u32 func_0203D6CC(void);
extern int func_0208EB0C(int, void (*)(u8 *), void *);
extern int func_02090B18(void *info, void *buffer, u16 slot);
extern int func_020902D8(struct WMDataSharingInfo *dsInfo, const u16 *sendData, struct WMDataSet *receiveData);
extern int func_0209028C(void *);
extern int WM_EndDataSharing(void *info);
extern int func_0208F43C(void (*)(u8 *));
extern void func_02090CD4(int a, int b, u16 c, int d, u16 e, int f);
/* * evidence: C30 truncates r1 to u16 at the tail call; its extern reflects that caller width. */ int func_02177C1C(void);
int func_02177C30(int a, unsigned int b, int c);
unsigned int func_02177C3C(void);
int func_02177C44(void);
void func_02177C4C(u8 *p);
void func_02177CE4(void);
int func_02177D0C(int a);
void func_02177D58(u8 *buf, u32 len);
void func_02177DB0(void);
int func_02177E20(u32 a, u8 *b, u32 c, u32 d);
void func_02177E9C(void);
int func_02177EB0(int a);
int func_02177ED4(void);
int func_02177ED8(void);
/* * evidence: 79328 stores its r0 payload unchanged; caller passes a function pointer. */ void func_02177EDC(int a);
void func_02177EFC(u8 *a);
void func_02177F48(u8 *a);
void func_02177FC4(unsigned char *p);
void func_02177FF0(u8 *a);
int func_02178034(void);
void func_0217807C(void);
/* * Recursive MATCH unblocker: the unlabelled ov014 leaf that func_0201058C * calls at +005C. Byte-identical to func_02177B80: read g_021797A4, test the * per-slot u16 flag at +0xC40 (stride 2), then return the slot's u8 state at * +0x5C of the 0xC0-byte record, or 0. */ u8 func_02178098(u8 i);
/* * Unlabelled overlay leaf blocking ov010 func_02157760. */ void func_021780C4(u32 i);
void func_021780E4(int a);
void func_021780FC(u8 value);
/* * blocker leaf for ov122 func_021D4B74; two stores to the game-global object. */ void func_02178118(u32 callback, u32 value);
void func_02178138(int state);
void func_0217814C(int error);
int func_02178168(void);
void func_02178198(void *arg);
int func_021781BC(void);
void func_02178204(u8 *obj);
/* * Twin of func_02178AB8 (the DWC copy of the NitroSDK wh.c MP start), with a * state guard in front: states 4 and 5 (+0x1E70) already run MP, else the * state setter func_02178138(4) runs first, and the callback is * func_021783FC. */ BOOL func_02178304(void);
void func_021783FC(u16 *a);
int func_021784AC(void);
void func_021784D0(void *arg);
int DWCi_MOV_WH_StateInEndParent(void);
/* * b is const: that is what lets the ldrh of b[1] schedule above the strh of * b[2] (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md). */ int func_02178524(u32 a, const u16 *b, u32 c);
int func_021785B4(u32 a, u16 *b, u32 c);
/* * The DWC copy of the NitroSDK demo wh.c's scan start: checks * WM_GetAllowedChannel (0x8000 -> error 3, 0 -> error 0x16), picks the next * allowed channel after the one in the scan parameter's channel list (or the * fixed channel at +0x1EB2), fills the WMScanExParam at +0x1400 of the work * block behind g_021797A8 (buffer at +0x1000, 0x400, scan type 1, no SSID) * and calls WM_StartScanEx with callback func_02178788; anything but * WM_ERRCODE_OPERATING (2) goes to the error setter func_0217814C. */ BOOL func_0217863C(void);
void func_02178714(u16 value, void *src);
int func_0217873C(u8 *p);
void func_02178788(void *arg);
int func_021788FC(void);
void DWCi_MOV_WH_StateOutEndScan(u8 *m);
int func_021789C8(void);
void func_02178A18(u8 *m);
BOOL func_02178AB8(void);
void func_02178B98(u8 *m);
int func_02178C50(void);
void func_02178C74(void *arg);
int func_02178C98(void);
int func_02178CDC(void);
void func_02178D00(u8 *p);
int func_02178D20(u32 a, u32 b, u32 c);
/* * extent: two zero alignment bytes at 02178D9A precede labelled 02178D9C. */ void func_02178D74(u8 *p);
void func_02178D9C(u8 *m);
void func_02178DE0(u8 *p);
void func_02178E1C(u32 v);
void DWCi_MOV_WH_SetUserGameInfo(void *p, unsigned short h);
u16 func_02178E38(void);
int func_02178E4C(void);
int func_02178E68(void);
int func_02178E84(void);
int func_02178F1C(u16 n);
/* * note: 2026-10-05 wave P16 lane E8: older draft was DIFF 101 B / 136 B because the * two arms kept separate copies of the u16 store. Per-function pragma * opt_dead_assignments off gives 132 B EXACT (also with plain literal offsets). * Without the pragma the same source stays 136 B. Callee types from matched * definitions: func_0217814C and func_02178138 void(int), func_02178F1C int(u16). */ void func_02178F8C(const Msg *m);
int WHi_MeasureChannel(void *callback, unsigned short channel);
u16 func_02179024(void);
int func_02179050(u16 mask);
BOOL func_021790E4(u32 heap, int a, int b);
void func_02179158(void);
/* * extent: two zero alignment bytes at 0217919E precede labelled 021791A0. */ void func_02179188(u8 *p);
/* The DWC copy of WH_Initialize WM start: WM_Initialize or, with flag set, WM_InitializeForListening, on the work block at g_021797A8 +0x40 with callback func_021791F8. Other results than OPERATING go to the error setter. The follower at 021791EC makes the extent run long. */ BOOL func_021791A0(int a, int flag);
/* * Unlabelled leaf: sets state 1 by tail-calling func_02178138. Used as the * callback of func_021791F8's call to func_02090DEC. */ void func_021791EC(void);
void func_021791F8(u16 *arg);
BOOL func_02179288(int mode, u16 a, int b, u16 c);
void func_02179328(void *v);
void func_0217933C(void *cb);
/* * Guard wrapper: forwards to func_02178D20 when func_021795A4 is nonzero or * one of bits 1-7 of func_02178E38 is set, else returns 0. The unlabelled * follower at 02179394 (adds the block's +0x1C64 / +0x1444 to g_021797A8, * tail calls a thumb function) is why the extent runs long. */ BOOL func_02179368(int a, u16 b, int c);
/* * extent: existing matched 021793B8 follows the 36-byte leaf. */ int func_02179394(u16 slot);
/* * Calls the arm9 function at 0x020902D8 with the data-sharing info * (+0x1444) and buffer (+0x1C64) of the work block behind g_021797A8; result * 7 or 5 counts as failure without the error setter, other nonzero results * call func_0217814C and fail, zero succeeds. */ BOOL func_021793B8(int arg);
/* * lever: final counter store uses unsigned address arithmetic rather than * pointer arithmetic, so its offset is reloaded independently of the flag. */ void func_021793F8(void);
/* * return-chain: 0209028C result is passed to 0217814C. */ void func_0217945C(void);
/* * The DWC copy of the NitroSDK demo wh.c's WH_Finalize (DWCi_MOV_WH_*), * returning BOOL and reading its state from the work block behind * g_021797A8: +0x1E70 system state, +0x1E74 connect mode, +0x1444 the * data-sharing info, +0x1E98 an error latch, +0x1EDF a byte flag. */ BOOL func_02179498(void);
int func_02179570(void (*cb)(int));
unsigned short func_021795A4(void);
void func_021795C0(unsigned v);
/* * When the state word (+0x1E70) of the work block behind * g_021797A8 is 4 or 5, forwards the arguments to the arm9 function at * 0x02090CD4 with (0, a, b, c, d, 1) and the halfword arguments truncated. */ void func_021795D4(int a, int b, int c, int d);
unsigned short func_02179614(void);
void func_02179628(unsigned v);
/* * Recursive MATCH unblocker: the unlabelled ov014 setter that func_020103E4 * (+001A) and sub_02010360 (+0056) call: store v into word +0x1E88 of the * object behind the pointer at g_021797A8. */ void func_0217963C(u32 v);
void func_02179650(u16 v);
extern u8 *g_021797A4;
extern u16 d_0217967C[2];
extern u16 d_02179680[2];
extern u8 d_02179678[3];
extern u8 *d_021797A4;
extern u8 *g_021797A8;
extern char d_02179794[];
extern char d_0217979C[];






/*
 * evidence: C30 truncates r1 to u16 at the tail call; its extern reflects that caller width.
 */
int func_02177C1C(void) { if (func_02178E4C() == 2) return 1; return 0; }






int func_02177C30(int a, unsigned int b, int c) { return func_02179368(a, b, c); }






unsigned int func_02177C3C(void) { return func_02178E38(); }






int func_02177C44(void) { return func_021795A4(); }







void func_02177C4C(u8 *p)
{
    u16 buf[2];
    u8 *st;
    int r6;

    int mode = func_02178E4C();

    buf[0] = d_0217967C[0];
    buf[1] = d_0217967C[1];
    if (mode == 7) {
        st = func_0203D798();
        p[0xCEA] = 0;
        p[0xCEF] = 0;
        p[0xCE9] = 0;
        p[0xCE8] = 0;
        r6 = func_02179024();
        if (p[0xCE6] == 0xFF)
            p[0xCE6] = r6;
        else
            r6 = p[0xCE6];
        if (st[0x66] != 0)
            ((struct Obj03088 *)p)->fC68 = func_0208F1B4();
        func_0217778C();
        func_02179288(buf[st[0x64]], ((struct Obj03088 *)p)->fC68, r6, st[0x60] - 1);
        func_0217727C((u32 *)g_021797A4, 0);
    }
}











void func_02177CE4(void) { if (func_02178E4C() == 1 && func_02178E84() != 0) func_0217727C((unsigned int *)g_021797A4, (unsigned int)func_02177C4C); }












int func_02177D0C(int a)
{
    u8 *p = g_021797A4;
    if (((struct Obj12469 *)p)->f0 != 0)
        return 0;
    if (a != 0)
        p[0xCE6] = 0xff;
    func_0217933C(func_021775AC);
    g_021797A4[0xCE8] = 1;
    func_0217727C((u32 *)g_021797A4, (u32)func_02177CE4);
    return 1;
}












void func_02177D58(u8 *buf, u32 len)
{
    u8 *p = g_021797A4;
    u8 *st = func_0203D798();
    if (p != 0 && st != 0) {
        ((struct Obj19335 *)buf)->f0 = func_0203F1FC(buf + 2, len - 2);
        func_020862F0(buf, len);
        if (func_02178E4C() == 1) {
            func_02178E28(buf, (u16)len);
            return;
        }
        func_021795D4((int)buf, len, ((struct Obj19336 *)st)->f50, ((struct Obj19337 *)p)->fC68);
    }
}












void func_02177DB0(void)
{
    u8 *st = func_0203D798();
    u16 tab[2];
    tab[0] = d_02179680[0];
    tab[1] = d_02179680[1];
    if (func_02178E4C() == 1 || func_02178E4C() == 2) {
        func_02178524(tab[st[0x64]], (const u16 *)(g_021797A4 + 0xCDE), 0);
        func_021795C0((unsigned int)func_0217771C);
        func_0217933C(func_021775AC);
        g_021797A4[0xCE8] = 1;
        func_0217727C((u32 *)g_021797A4, 0);
    }
}












int func_02177E20(u32 a, u8 *b, u32 c, u32 d)
{
    func_0203D798();
    if (*(u32 *)g_021797A4 != 0)
        return 0;
    if (func_02178E4C() == 2) {
        g_021797A4[0xCE9] = 0;
        func_021788FC();
    }
    func_0217727C((u32 *)g_021797A4, (u32)func_02177DB0);
    if (b != 0)
        func_02082D44(b, g_021797A4 + 0xCDE, 6);
    else
        func_02082D44(g_021797A4 + 0xC + c * 0xC0, g_021797A4 + 0xCDE, 6);
    *(u32 *)(g_021797A4 + 0xC60) = d;
    return 1;
}











void func_02177E9C(void) { if (func_02178E4C() == 0) { func_02179158(); func_02177704(); } }











int func_02177EB0(int a) { if (func_02179570((void (*)(int))a) != 0) { func_0217727C((unsigned int *)g_021797A4, (unsigned int)func_02177E9C); return 1; } return 0; }











int func_02177ED4(void) { return 1; }











int func_02177ED8(void) { return 0; }











/*
 * evidence: 79328 stores its r0 payload unchanged; caller passes a function pointer.
 */
void func_02177EDC(int a) { if (a != 0) func_02179328(func_02177ED4); else func_02179328(func_02177ED8); }












void func_02177EFC(u8 *a)
{
    if (g_021797A4[0xCF3] == 0) {
        if (a[0xCF2] != 0)
            a[0xCF2]--;
        if (a[0xCF2] == 0) {
            if (func_02179498() != 0)
                func_0217727C((u32 *)g_021797A4, (u32)func_02177FF0);
        }
    }
}











void func_02177F48(u8 *a)
{
    u8 tab[3];
    if (func_02177AA8() != 0) {
        tab[0] = d_02179678[0];
        tab[1] = d_02179678[1];
        tab[2] = d_02179678[2];
        a[0xCF1] = func_020056EC(3);
        if (a[0xCF1] >= 3)
            a[0xCF1] = 0;
        func_0217778C();
        if (func_02179288(0, ((struct Obj04956 *)a)->fC68, tab[a[0xCF1]], 1) != 0) {
            a[0xCF2] = func_020056EC(0x98) + 0x3C;
            func_0217727C((u32 *)g_021797A4, (u32)func_02177EFC);
        }
    }
}










void func_02177FC4(unsigned char *p) { p[0xCF2]--; if (p[0xCF2] == 0) { func_021788FC(); func_0217727C((unsigned int *)g_021797A4, (unsigned int)func_02177F48); } }











void func_02177FF0(u8 *a)
{
    if (func_02178E4C() == 1) {
        if (func_021785B4((u32)func_021773E0, 0, 0) != 0) {
            a[0xCF2] = func_020056EC(0x28) + 0x3C;
            func_0217727C((u32 *)g_021797A4, (u32)func_02177FC4);
        }
    }
}











int func_02178034(void)
{
    u8 *p = g_021797A4;
    if (p == 0)
        return 0;
    func_021780E4(0);
    func_0217758C(p);
    func_02177560();
    func_0217933C(func_021775AC);
    p[0xCE8] = 1;
    func_0217727C((u32 *)g_021797A4, (u32)func_02177FF0);
    return 1;
}










void func_0217807C(void)
{
    if (g_021797A4[0xcec])
        g_021797A4[0xceb] = 1;
}











/*
 * Recursive MATCH unblocker: the unlabelled ov014 leaf that func_0201058C
 * calls at +005C.  Byte-identical to func_02177B80: read g_021797A4, test the
 * per-slot u16 flag at +0xC40 (stride 2), then return the slot's u8 state at
 * +0x5C of the 0xC0-byte record, or 0.
 */
u8 func_02178098(u8 i)
{
    u8 *base = g_021797A4;

    if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0)
        return *(u8 *)(base + 0x5C + i * 0xC0);
    return 0;
}










/*
 * Unlabelled overlay leaf blocking ov010 func_02157760.
 */
void func_021780C4(u32 i)
{
    u8 *p;
    u32 off;
    off = i * 0xC0;
    p = d_021797A4;
    func_02178714(*(u16 *)(p + off + 0x3E), p + 0xC + off);
}










void func_021780E4(int a)
{
    if (g_021797A4)
        *(u16 *)(g_021797A4 + 0xc6c) = 20;
}










void func_021780FC(u8 value)
{
    if (g_021797A4) {
        g_021797A4[0xcea] = value;
        func_0217778C();
    }
}










/*
 * blocker leaf for ov122 func_021D4B74; two stores to the game-global object.
 */
void func_02178118(u32 callback, u32 value)
{
    if (g_021797A4) {
        *(u32 *)(g_021797A4 + 0xc38) = callback;
        *(u32 *)(g_021797A4 + 0xc3c) = value;
    }
}










void func_02178138(int state)
{
    *(int *)(g_021797A8 + 0x1e70) = state;
}









void func_0217814C(int error)
{
    if ((unsigned)(*(int *)(g_021797A8 + 0x1e70) - 9) > 1)
        *(int *)(g_021797A8 + 0x1e98) = error;
}









int func_02178168(void)
{
    int result;
    func_02178138(3);
    result = func_0208F480(func_02178198, g_021797A8);
    if (result != 2) {
        func_0217814C(result);
        func_02178138(9);
        return 0;
    }
    return 1;
}







void func_02178198(void *arg)
{
    int result = ((u16 *)arg)[1];
    if (result != 0) {
        func_0217814C(result);
        func_02178138(9);
        return;
    }
    if (func_021781BC() == 0)
        func_02178138(9);
}







int func_021781BC(void)
{
    int r;

    if ((u32)(*(int *)(g_021797A8 + 0x1E70) - 4) <= 1)
        return 1;
    r = func_0208F644(func_02178204);
    if (r != 2) {
        func_0217814C(r);
        return 0;
    }
    *(u16 *)(g_021797A8 + 0x1EA8) = 0;
    *(u16 *)(g_021797A8 + 0x1EAA) = 1;
    return 1;
}





void func_02178204(u8 *obj)
{
    int ok = 1;
    u16 mask = 1 << ((struct Obj02672 *)obj)->f10;
    SlotFn cb;
    int res;

    if (((struct Obj02672 *)obj)->f2 != 0) {
        func_0217814C(((struct Obj02672 *)obj)->f2);
        func_02178138(9);
        return;
    }
    switch (((struct Obj02672 *)obj)->f8) {
    case 2:
        *(u16 *)(g_021797A8 + 0x1EBA) += 1;
        break;
    case 7:
        if (*(ConnFn *)(g_021797A8 + 0x1E7C) != 0)
            ok = (*(ConnFn *)(g_021797A8 + 0x1E7C))(obj, func_0203D650());
        if (ok == 0) {
            res = func_0208F938(0, ((struct Obj02672 *)obj)->f10);
            if (res != 2) {
                func_0217814C(res);
                func_02178138(9);
            }
        } else {
            *(u16 *)(g_021797A8 + 0x1EAA) |= mask;
            cb = *(SlotFn *)(g_021797A8 + 0x1E84);
            if (cb != 0)
                cb(((struct Obj02672 *)obj)->f10);
        }
        break;
    case 9:
    case 0x1A:
        if (*(u16 *)(g_021797A8 + 0x1EAA) & (1 << ((struct Obj02672 *)obj)->f10)) {
            *(u16 *)(g_021797A8 + 0x1EAA) &= ~mask;
            cb = *(SlotFn *)(g_021797A8 + 0x1E80);
            if (cb != 0)
                cb(((struct Obj02672 *)obj)->f10);
            func_0217807C();
            func_0203A338(((struct Obj02672 *)obj)->f10);
            func_02039A2C(((struct Obj02672 *)obj)->f10);
        }
        break;
    case 0:
        if (func_02178304() == 0)
            func_02178138(9);
        break;
    }
}






/*
 * Twin of func_02178AB8 (the DWC copy of the NitroSDK wh.c MP start), with a
 * state guard in front: states 4 and 5 (+0x1E70) already run MP, else the
 * state setter func_02178138(4) runs first, and the callback is
 * func_021783FC.
 */
BOOL func_02178304(void)
{
    int result;
    u16 freq;

    if (*(int *)(g_021797A8 + 0x1E70) == 4 || *(int *)(g_021797A8 + 0x1E70) == 5)
        return 1;

    func_02178138(4);

    WM_GetMPReceiveBufferSize();
    WM_GetMPSendBufferSize();

    if (*(void **)(g_021797A8 + 0x1E6C) != 0) {
        func_0203D7FC(*(void **)(g_021797A8 + 0x1E6C));
        func_0203D7FC(*(void **)(g_021797A8 + 0x1E68));
    }

    *(int *)(g_021797A8 + 0x1E90) = WM_GetMPReceiveBufferSize();
    *(int *)(g_021797A8 + 0x1E8C) = WM_GetMPSendBufferSize();

    *(void **)(g_021797A8 + 0x1E6C) =
        func_0203D7C8(*(u16 *)(g_021797A8 + 0x1EC0),
                      *(int *)(g_021797A8 + 0x1E90) + 0x20, d_02179794, 0x4A7);
    *(void **)(g_021797A8 + 0x1E68) =
        func_0203D7C8(*(u16 *)(g_021797A8 + 0x1EC0),
                      *(int *)(g_021797A8 + 0x1E8C) + 0x20, d_02179794, 0x4A8);

    freq = (func_0203D5D4() == 2) ? 1 : 2;

    result = WM_StartMP((void (*)(void *))func_021783FC,
                        *(void **)(g_021797A8 + 0x1E6C),
                        (u16)*(int *)(g_021797A8 + 0x1E90),
                        *(void **)(g_021797A8 + 0x1E68),
                        (u16)*(int *)(g_021797A8 + 0x1E8C),
                        freq);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}






void func_021783FC(u16 *a)
{
    u16 v1 = a[1];
    u16 mask;
    u32 id;
    u32 flag;
    u32 n;
    int r;
    if (v1 != 0) {
        func_0217814C(v1);
        func_02178138(9);
        return;
    }
    switch (a[2]) {
    case 10:
        if (*(int *)(g_021797A8 + 0x1E74) == 4) {
            id = func_0203D6BC();
            n = func_0203D680() - 1;
            mask = (1 << (n + 1)) - 1;
            flag = 1;
            if (func_0203D5D4() == 2)
                flag = 0;
            r = func_0209004C(g_021797A8 + 0x1444, 13, mask, id, flag);
            if (r != 0) {
                func_0217814C(r);
                func_02178138(9);
                return;
            }
            func_02178138(5);
            return;
        }
        func_02178138(4);
        break;
    case 11:
    case 12:
    case 13:
        break;
    }
}





int func_021784AC(void)
{
    int result;
    func_02178138(3);
    result = func_0208FDEC(func_021784D0);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}




void func_021784D0(void *arg)
{
    int result = ((u16 *)arg)[1];
    if (result != 0) {
        func_0217814C(result);
        func_0217945C();
        return;
    }
    if (func_021784F0() == 0)
        func_0217945C();
}


static void DWCi_MOV_WH_StateOutEndParent(void *arg);




int DWCi_MOV_WH_StateInEndParent(void)
{
	int r = WM_EndParent((void *)DWCi_MOV_WH_StateOutEndParent);
	if (r != 2)
	{
		func_0217814C(r);
		return 0;
	}
	return 1;
}




static void DWCi_MOV_WH_StateOutEndParent(void *arg)
{
	WMCallback *cb = (WMCallback *)arg;

	if (cb->errcode != 0)
	{
		DWCi_MOV_WH_SetError(cb->errcode);
		return;
	}
	DWCi_MOV_WH_ChangeSysState(1);
}















/*
 * b is const: that is what lets the ldrh of b[1] schedule above the strh of
 * b[2] (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md).
 */
int func_02178524(u32 a, const u16 *b, u32 c)
{
    func_02178138(2);
    if (b != 0) {
        *(u16 *)(g_021797A8 + 0x140E) = b[2];
        *(u16 *)(g_021797A8 + 0x140C) = b[1];
        *(u16 *)(g_021797A8 + 0x140A) = b[0];
    } else {
        func_02082BCC(g_021797A8 + 0x140A, 0xff, 6);
    }
    *(u32 *)(g_021797A8 + 0x1E74) = a;
    *(u32 *)(g_021797A8 + 0x1E94) = 0;
    *(u16 *)(g_021797A8 + 0x1EB2) = c;
    *(u16 *)(g_021797A8 + 0x1406) = 1;
    *(u16 *)(g_021797A8 + 0x1EB4) = 1;
    if (func_0217863C() == 0) {
        func_02178138(9);
        return 0;
    }
    return 1;
}















int func_021785B4(u32 a, u16 *b, u32 c)
{
    func_02178138(2);
    *(u32 *)(g_021797A8 + 0x1E94) = a;
    *(u16 *)(g_021797A8 + 0x1EB2) = c;
    *(u16 *)(g_021797A8 + 0x1406) = 1;
    *(u16 *)(g_021797A8 + 0x1EB4) = 0;
    *(u16 *)(g_021797A8 + 0x1EBC) = 0;
    if (b != 0) {
        *(u16 *)(g_021797A8 + 0x140E) = b[2];
        *(u16 *)(g_021797A8 + 0x140C) = b[1];
        *(u16 *)(g_021797A8 + 0x140A) = b[0];
    } else {
        func_02082BCC(g_021797A8 + 0x140A, 0xff, 6);
    }
    if (func_0217863C() == 0) {
        func_02178138(9);
        return 0;
    }
    return 1;
}















/*
 * The DWC copy of the NitroSDK demo wh.c's scan start: checks
 * WM_GetAllowedChannel (0x8000 -> error 3, 0 -> error 0x16), picks the next
 * allowed channel after the one in the scan parameter's channel list (or the
 * fixed channel at +0x1EB2), fills the WMScanExParam at +0x1400 of the work
 * block behind g_021797A8 (buffer at +0x1000, 0x400, scan type 1, no SSID)
 * and calls WM_StartScanEx with callback func_02178788; anything but
 * WM_ERRCODE_OPERATING (2) goes to the error setter func_0217814C.
 */
BOOL func_0217863C(void)
{
    int result;
    u16 chanpat;
    u8 *w;

    chanpat = WM_GetAllowedChannel();
    if (chanpat == 0x8000) {
        func_0217814C(3);
        return 0;
    }
    if (chanpat == 0) {
        func_0217814C(0x16);
        return 0;
    }

    w = g_021797A8;
    if (((struct Obj05923 *)w)->f1EB2 == 0) {
        int n;
        u32 channel = ((struct Obj05923 *)w)->f1406;

        for (n = 0; n < 32; n++) {
            if (channel & 1)
                break;
            channel >>= 1;
        }
        channel = n + 1;

        while (1) {
            channel++;
            if (channel > 16)
                channel = 1;
            if (chanpat & (1 << (channel - 1)))
                break;
        }
        ((struct Obj05923 *)w)->f1406 = (u16)(1 << (channel - 1));
    } else {
        ((struct Obj05923 *)w)->f1406 = (u16)(1 << (((struct Obj05923 *)w)->f1EB2 - 1));
    }

    *(u16 *)(g_021797A8 + 0x1408) = WM_GetDispersionScanPeriod();
    *(u8 **)(g_021797A8 + 0x1400) = g_021797A8 + 0x1000;
    *(u16 *)(g_021797A8 + 0x1404) = 0x400;
    *(u16 *)(g_021797A8 + 0x1410) = 1;
    *(u16 *)(g_021797A8 + 0x1412) = 0;

    result = WM_StartScanEx(func_02178788, g_021797A8 + 0x1400);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}













void func_02178714(u16 value, void *src)
{
    *(u16 *)(g_021797A8 + 0x1eb2) = value;
    func_02082D44(src, g_021797A8 + 0x140a, 6);
}













int func_0217873C(u8 *p)
{
    u32 v = ((struct Obj05924 *)p)->f3C;

    if (v < 0x10 || v > 0x80 || v != (u32)p[0x4A] + 0x10 || ((struct Obj05924 *)p)->f40 != 1 || v < 8
        || ((struct Obj05924 *)p)->f44 != *(u32 *)(g_021797A8 + 8))
        return 0;
    if ((p[0x4B] & 3) == 1)
        return 1;
    return 0;
}












/*
 * The WM_StartScanEx callback that func_0217863C installs (the DWC copy of
 * the NitroSDK demo wh.c's scan callback).  arg is a WMStartScanExCallback:
 * errcode +2, state +8, bssDescCount +0xE, bssDesc[] +0x10, linkLevel[]
 * +0x50.  Each found BSS is copied to +0xF40 of the work block behind
 * g_021797A8 and offered to the hooks at +0x1E88 and +0x1E94.
 */
void func_02178788(void *arg)
{
    ScanExCb *cb = arg;
    u16 state = cb->state;
    int found;
    int i;
    u8 *w;

    *(u16 *)(g_021797A8 + 0x1EBC) += 1;
    *(u16 *)(g_021797A8 + 0x1EBE) = 0;

    if (cb->errcode != 0) {
        func_0217814C(cb->errcode);
        func_02178138(9);
        return;
    }
    if (*(int *)(g_021797A8 + 0x1E70) != 2) {
        *(u16 *)(g_021797A8 + 0x1EB4) = 0;
        if (func_02178964() == 0)
            func_02178138(9);
        return;
    }
    *(u16 *)(g_021797A8 + 0x1EBE) = *(u16 *)(g_021797A8 + 0x1EC2);

    switch (state) {
    case 4:
        func_02010884();
        return;
    case 5:
        if (cb->bssDescCount != 0)
            DC_InvalidateRange(g_021797A8 + 0x1000, 0x400);
        found = 0;
        for (i = 0; i < cb->bssDescCount; i++) {
            w = g_021797A8;
            MI_CpuCopy8(cb->bssDesc[i], w + 0xF40, 0xC0);
            func_02010864((u8)cb->linkLevel[i]);
            if (*(FoundFn *)(g_021797A8 + 0x1E88) != 0)
                (*(FoundFn *)(g_021797A8 + 0x1E88))(w + 0xF40, func_0203D650(),
                                                    cb->linkLevel[i]);
            if (func_0217873C(w + 0xF40) != 0) {
                if (*(FilterFn *)(g_021797A8 + 0x1E94) == 0)
                    func_02034714(d_0217979C, 0, d_0217979C);
                if ((*(FilterFn *)(g_021797A8 + 0x1E94))(w + 0xF40) != 0)
                    found = 1;
            }
        }
        if (*(u16 *)(g_021797A8 + 0x1EB4) != 0 && found != 0) {
            *(u16 *)(g_021797A8 + 0x1EBE) = 0;
            if (func_02178964() == 0)
                func_02178138(9);
        }
        break;
    }
}














int func_021788FC(void)
{
    int irq;
    int r = 0;

    irq = func_02087988();

    if (*(u32 *)(g_021797A8 + 0x1E70) == 2) {
        if (*(s16_02178524 *)(g_021797A8 + 0x1EBE) != 0) {
            if (func_0217863C() == 0)
                func_02178138(9);
        }
        *(s16_02178524 *)(g_021797A8 + 0x1EBE) = -1;
        *(u16 *)(g_021797A8 + 0x1EB4) = 0;
        r = 1;
        g_021797A8[0x1EDF] = 1;
        func_02178138(3);
    }
    func_0208799C(irq);
    return r;
}














static int DWCi_MOV_WH_StateInEndScan(void)
{
	int result;

	result = WM_EndScan((void *)DWCi_MOV_WH_StateOutEndScan);
	if (result != 2)
	{
		DWCi_MOV_WH_SetError(result);
		return 0;
	}
	return 1;
}














void DWCi_MOV_WH_StateOutEndScan(u8 *m)
{
    u8 *g;

    g_021797A8[0x1EDF] = 0;
    if (((struct Obj12472 *)m)->f2 != 0) {
        func_0217814C(((struct Obj12472 *)m)->f2);
        return;
    }
    func_02178138(1);
    g = g_021797A8;
    if (((struct Obj12473 *)g)->f1EB4 != 0) {
        ((struct Obj12473 *)g)->f1EB4 = 0;
        if (func_021789C8() == 0)
            func_02178138(9);
    }
}













int func_021789C8(void)
{
    int r;

    if (*(u32 *)(g_021797A8 + 0x1E70) - 4 <= 1)
        return 1;
    func_02178138(3);
    r = func_0208F84C((void *)func_02178A18, g_021797A8 + 0xF40, g_021797A8 + 0x1EC4, 1, 0);
    if (r != 2) {
        func_0217814C(r);
        return 0;
    }
    return 1;
}












void func_02178A18(u8 *m)
{
    u32 v;
    void (*cb)(int);

    if (((struct Obj04957 *)m)->f2 != 0) {
        func_0217814C(((struct Obj04957 *)m)->f2);
        v = ((struct Obj04957 *)m)->f2;
        if (v == 0xC) {
            func_02178138(9);
            return;
        }
        if (v == 0xB) {
            func_02178138(9);
            return;
        }
        if (v == 1) {
            func_02178138(8);
            return;
        }
        func_02178138(9);
        return;
    }
    v = ((struct Obj04957 *)m)->f8;
    if (v == 8)
        return;
    if (v == 7) {
        func_02178138(4);
        if (func_02178AB8() == 0) {
            func_02178138(3);
            return;
        }
        *(u16 *)(g_021797A8 + 0x1EA8) = ((struct Obj04957 *)m)->fA;
        cb = *(void (**)(int))(g_021797A8 + 0x1E84);
        if (cb != 0)
            cb(((struct Obj04957 *)m)->fA);
        return;
    }
    if (v == 6)
        return;
    if (v == 9) {
        func_0217814C(0x14);
        func_02178138(9);
        return;
    }
    if (v == 0x1A)
        return;
    func_02178138(9);
}










/*
 * The DWC copy of the NitroSDK demo wh.c's MP start (DWCi_MOV_WH_*): frees
 * and re-allocates the MP receive and send buffers (sizes from
 * WM_GetMP{Receive,Send}BufferSize, kept at +0x1E90/+0x1E8C of the work
 * block behind g_021797A8, buffers at +0x1E6C/+0x1E68, heap at +0x1EC0),
 * then calls WM_StartMP with callback func_02178B98; anything but
 * WM_ERRCODE_OPERATING (2) goes to the error setter func_0217814C.
 */
BOOL func_02178AB8(void)
{
    int result;
    u16 freq;

    WM_GetMPReceiveBufferSize();
    WM_GetMPSendBufferSize();

    if (*(void **)(g_021797A8 + 0x1E6C) != 0) {
        func_0203D7FC(*(void **)(g_021797A8 + 0x1E6C));
        func_0203D7FC(*(void **)(g_021797A8 + 0x1E68));
    }

    *(int *)(g_021797A8 + 0x1E90) = WM_GetMPReceiveBufferSize();
    *(int *)(g_021797A8 + 0x1E8C) = WM_GetMPSendBufferSize();

    *(void **)(g_021797A8 + 0x1E6C) =
        func_0203D7C8(*(u16 *)(g_021797A8 + 0x1EC0),
                      *(int *)(g_021797A8 + 0x1E90) + 0x20, d_02179794, 0x7FA);
    *(void **)(g_021797A8 + 0x1E68) =
        func_0203D7C8(*(u16 *)(g_021797A8 + 0x1EC0),
                      *(int *)(g_021797A8 + 0x1E8C) + 0x20, d_02179794, 0x7FB);

    freq = (func_0203D5D4() == 2) ? 1 : 2;

    result = WM_StartMP((void (*)(void *))func_02178B98,
                        *(void **)(g_021797A8 + 0x1E6C),
                        (u16)*(int *)(g_021797A8 + 0x1E90),
                        *(void **)(g_021797A8 + 0x1E68),
                        (u16)*(int *)(g_021797A8 + 0x1E8C),
                        freq);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}












void func_02178B98(u8 *m)
{
    u32 v = ((struct Obj12474 *)m)->f2;
    u32 mask;
    u32 who;
    int c;

    if (v != 0) {
        if (v == 0xF || v == 9 || v == 0xD)
            return;
        func_0217814C(v);
        func_02178138(9);
        return;
    }
    switch (((struct Obj12474 *)m)->f4) {
    case 0xA:
        if (*(u32 *)(g_021797A8 + 0x1E74) == 5) {
            int r;
            int n;

            who = func_0203D6BC();
            n = func_0203D680() - 1;
            mask = (u16)((1 << (n + 1)) - 1);
            c = 1;
            if (func_0203D5D4() == 2)
                c = 0;
            r = func_0209004C(g_021797A8 + 0x1444, 0xD, mask, (u16)who, c);
            if (r != 0) {
                func_0217814C(r);
                func_02179498();
                return;
            }
            func_02178138(5);
            return;
        }
        func_02178138(4);
        break;
    case 0xB:
    case 0xC:
    case 0xD:
        break;
    }
}











int func_02178C50(void)
{
    int result;
    func_02178138(3);
    result = func_0208FDEC(func_02178C74);
    if (result != 2) {
        func_0217814C(result);
        return 0;
    }
    return 1;
}











void func_02178C74(void *arg)
{
    int result = ((u16 *)arg)[1];
    if (result != 0) {
        func_0217814C(result);
        func_02179498();
        return;
    }
    if (func_02178C98() == 0)
        func_02178138(9);
}











int func_02178C98(void) {
 int r;
 int result = 0;
 func_02178138(3);
 r = func_0208F938(func_02178CC4, 0);
 if (r != 2) { func_0217814C(r); func_0217945C(); return result; }
 return 1;
}












static void DWCi_MOV_WH_StateOutEndChild(void *arg)
{
	WMCallback *cb = (WMCallback *)arg;

	if (cb->errcode != 0)
	{
		DWCi_MOV_WH_SetError(cb->errcode);
		return;
	}
	DWCi_MOV_WH_ChangeSysState(1);
}











int func_02178CDC(void) {
 int r;
 func_02178138(3);
 r = func_0208F400(func_02178D00);
 if (r != 2) { func_0217814C(r); return 0; }
 return 1;
}











void func_02178D00(u8 *p) { if (((struct Obj12475 *)p)->f2 != 0) { func_02178138(9); func_0217814C(((struct Obj12475 *)p)->f2); } else { func_02178138(1); } }












int func_02178D20(u32 a, u32 b, u32 c)
{
    func_020862F0(*(void **)(g_021797A8 + 0x1E68), *(u32 *)(g_021797A8 + 0x1E8C));
    if (func_0208FCB4((void *)func_02178D74, c, a, b, 0xFFFF, 0xE, 2) == 2)
        return 1;
    return 0;
}











/*
 * extent: two zero alignment bytes at 02178D9A precede labelled 02178D9C.
 */
void func_02178D74(u8 *p) {
 int v = ((struct Obj12476 *)p)->f2;
 if (v != 0 && v != 15) { func_0217814C(v); }
 else { Cb cb = *(Cb *)&((struct Obj12476 *)p)->f20; if (cb != 0) cb(v == 0); }
}












void func_02178D9C(u8 *m)
{
    void (*cb)(u32, u32, u32);

    if (((struct Obj03559 *)m)->f2 != 0) {
        func_0217814C(((struct Obj03559 *)m)->f2);
        return;
    }
    cb = *(void (**)(u32, u32, u32))(g_021797A8 + 0x1E78);
    if (cb != 0) {
        if (((struct Obj03559 *)m)->f4 == 0x15)
            cb(((struct Obj03559 *)m)->f12, ((struct Obj03559 *)m)->fC, ((struct Obj03559 *)m)->f10);
        else if (((struct Obj03559 *)m)->f4 == 9)
            cb(((struct Obj03559 *)m)->f12, 0, 0);
    }
}











void func_02178DE0(u8 *p) {
 Cb cb = *(Cb *)(g_021797A8 + 0x1E64);
 if (cb != 0) cb(((struct Obj12477 *)p)->f2 == 0 ? 1 : 0);
 if (((struct Obj12477 *)p)->f2 != 0) func_02178138(10); else func_02178138(0);
}












void func_02178E1C(u32 v)
{
    *(u32 *)(*(u32 *)0x021797A8 + 8) = v;
}












void DWCi_MOV_WH_SetUserGameInfo(void *p, unsigned short h)
{
	*(void **)g_021797A8 = p;
	*(u16 *)(g_021797A8 + 4) = h;
}











u16 func_02178E38(void) { return *(u16 *)(g_021797A8 + 0x1EAA); }











int func_02178E4C(void) { if (g_021797A8 == 0) return 0; return *(int *)(g_021797A8 + 0x1E70); }











int func_02178E68(void) { if (g_021797A8 != 0) return *(int *)(g_021797A8 + 0x1E98); return 0; }










int func_02178E84(void)
{
    u16 t[3];
    int r;
    int ok;
    u32 x;

    func_02087C6C(t);
    x = *(volatile u32 *)0x02FFFC3C;
    *(u32 *)(g_021797A8 + 0x1E9C) = t[2] + (t[1] + (t[0] + x));
    *(u32 *)(g_021797A8 + 0x1E9C) = *(u32 *)(g_021797A8 + 0x1E9C) * 0x10DCD + 0x3039;
    *(u16 *)(g_021797A8 + 0x1EAC) = 0;
    *(u16 *)(g_021797A8 + 0x1EAE) = 0x65;
    func_02178138(3);
    ok = 1;
    r = func_02178F1C(1);
    if (r == 0x18) {
        func_0217814C(0x18);
        func_02178138(9);
        return 0;
    }
    if (r != 2) {
        func_0217814C(r);
        func_02178138(9);
        return 0;
    }
    return ok;
}









int func_02178F1C(u16 n)
{
    u32 m = func_0208EE60();

    if (m == 0x8000) {
        func_0217814C(3);
        func_02178138(9);
        return 3;
    }
    if (m == 0) {
        func_0217814C(0x16);
        func_02178138(9);
        return 0x18;
    }
    if (!((1 << (n - 1)) & m)) {
        do {
            n = n + 1;
            if (n > 0x10)
                return 0x18;
        } while (!((1 << (n - 1)) & m));
    }
    return (u16)func_02179010((void *)func_02178F8C, n);
}








#pragma opt_dead_assignments off








/*
 * note: 2026-10-05 wave P16 lane E8: older draft was DIFF 101 B / 136 B because the
 *   two arms kept separate copies of the u16 store. Per-function pragma
 *   opt_dead_assignments off gives 132 B EXACT (also with plain literal offsets).
 *   Without the pragma the same source stays 136 B. Callee types from matched
 *   definitions: func_0217814C and func_02178138 void(int), func_02178F1C int(u16).
 */
void func_02178F8C(const Msg *m)
{
    u32 a;
    u32 b;
    u32 t;
    int r;
    if (m->err != 0) {
        func_0217814C(m->err);
        func_02178138(9);
        return;
    }
    a = m->channel;
    b = m->level;
    t = *(u16 *)(g_021797A8 + 0x1EAE);
    if (t > b) {
        *(u16 *)(g_021797A8 + 0x1EAE) = b;
        t = 1 << (a - 1);
        *(u16 *)(g_021797A8 + 0x1EB0) = t;
    } else if (t == b) {
        t = (u16)(1 << (a - 1)) | *(u16 *)(g_021797A8 + 0x1EB0);
        *(u16 *)(g_021797A8 + 0x1EB0) = t;
    }
    r = func_02178F1C(a + 1);
    if (r == 0x18 && *(u32 *)(g_021797A8 + 0x1E70) != 9) {
        func_02178138(7);
        return;
    }
    if (r != 2) func_02178138(9);
}









#pragma opt_dead_assignments reset








int WHi_MeasureChannel(void *callback, unsigned short channel)
{
    return WM_MeasureChannel(callback, 3, 0x11, channel, 0x1E);
}







u16 func_02179024(void) {
 func_02178138(1);
 *(u16 *)(g_021797A8 + 0x1EAC) = func_02179050(*(u16 *)(g_021797A8 + 0x1EB0));
 return *(u16 *)(g_021797A8 + 0x1EAC);
}








int func_02179050(u16 mask)
{
    s16_02178524 last = 0;
    s16_02178524 i;
    u16 cnt = 0;
    u32 k;

    for (i = 0; i < 16; i++) {
        if (mask & (1 << i)) {
            last = i + 1;
            cnt++;
        }
    }
    if (cnt > 1) {
        s16_02178524 j;

        *(u32 *)(g_021797A8 + 0x1E9C) = *(u32 *)(g_021797A8 + 0x1E9C) * 0x10DCD + 0x3039;
        k = (u32)(cnt * (u8) * (u32 *)(g_021797A8 + 0x1E9C)) << 8 >> 16;
        for (j = 0; j < 16; j++) {
            if (mask & 1) {
                if (k == 0)
                    return (s16_02178524)(j + 1);
                k = (u16)(k - 1);
            }
            mask = mask >> 1;
        }
        return 0;
    }
    return last;
}






BOOL func_021790E4(u32 heap, int a, int b)
{
    BOOL ok;

    if (g_021797A8 != 0)
        return 0;
    g_021797A8 = func_0203D7C8(heap, 0x1F00, d_02179794, 0xC33);
    func_02082BCC(g_021797A8, 0, 0x1EE0);
    *(u16 *)(g_021797A8 + 0x1EC2) = 1;
    *(u16 *)(g_021797A8 + 0x1EAA) = 1;
    *(int *)(g_021797A8 + 0x1E98) = 0;
    *(u16 *)(g_021797A8 + 0x1EC0) = heap;
    ok = 1;
    if (!func_021791A0(a, b))
        ok = 0;
    return ok;
}




void func_02179158(void) {
 if (g_021797A8 != 0) {
 func_0203D7FC(*(void **)(g_021797A8 + 0x1E6C));
 func_0203D7FC(*(void **)(g_021797A8 + 0x1E68));
 func_0203D7FC(g_021797A8);
 g_021797A8 = 0;
 }
}




/*
 * extent: two zero alignment bytes at 0217919E precede labelled 021791A0.
 */
void func_02179188(u8 *p) { if (((struct Obj19343 *)p)->f2 == 8) { func_02178138(9); func_0217814C(25); } }





/* The DWC copy of WH_Initialize WM start: WM_Initialize or, with flag set, WM_InitializeForListening, on the work block at g_021797A8 +0x40 with callback func_021791F8. Other results than OPERATING go to the error setter. The follower at 021791EC makes the extent run long. */
/*
 * The DWC copy of WH_Initialize's WM start: WM_Initialize (0208F370) or, when
 * the flag is set, WM_InitializeForListening (0208F380), on the work block
 * behind g_021797A8 +0x40 with completion callback func_021791F8.  Anything
 * but WM_ERRCODE_OPERATING goes to the error setter.  The unlabelled
 * follower at 021791EC (`movs r0,#1; bx` tail call to func_02178138) is why
 * the extent runs long.
 */
BOOL func_021791A0(int a, int flag)
{
    int r;

    func_02178138(3);
    if (flag == 0)
        r = func_0208F370(g_021797A8 + 0x40, (void (*)(void *))func_021791F8, 2);
    else
        r = func_0208F380(g_021797A8 + 0x40, (void (*)(void *))func_021791F8, 2, 0);
    if (r != 2) {
        func_0217814C(r);
        func_02178138(10);
        return 0;
    }
    return 1;
}





/*
 * Unlabelled leaf: sets state 1 by tail-calling func_02178138.  Used as the
 * callback of func_021791F8's call to func_02090DEC.
 */
void func_021791EC(void)
{
    func_02178138(1);
}








/*
 * WM_Initialize completion callback of the DWC WH copy: on an error result,
 * or when func_02179188's check fails, it sets the error state (10) and
 * calls the user callback at +0x1E64 of the work block with 0; otherwise it
 * sets state 1, calls func_02090DEC with the unlabelled leaf func_021791EC
 * and calls the user callback with 1.
 */
void func_021791F8(u16 *arg)
{
    Cb cb;

    int r;

    if (arg[1] != 0) {
        func_0217814C(arg[1]);
        func_02178138(10);
        cb = *(Cb *)(g_021797A8 + 0x1E64);
        if (cb != 0)
            cb(0);
        return;
    }
    r = func_0208EAC8((void (*)(void))func_02179188);
    if (r != 0) {
        func_0217814C(r);
        func_02178138(10);
        cb = *(Cb *)(g_021797A8 + 0x1E64);
        if (cb != 0)
            cb(0);
        return;
    }
    func_02178138(1);
    func_02090DEC(func_021791EC, 0xFFFF, 0x28, 5, 0x28);
    cb = *(Cb *)(g_021797A8 + 0x1E64);
    if (cb != 0)
        cb(1);
}








BOOL func_02179288(int mode, u16 a, int b, u16 c)
{
    *(u16 *)(g_021797A8 + 0x1EBA) = 0;
    *(int *)(g_021797A8 + 0x1E74) = mode;
    func_02178138(3);
    *(u16 *)(g_021797A8 + 0xC) = a;
    *(u16 *)(g_021797A8 + 0x32) = b;
    *(u16 *)(g_021797A8 + 0x18) = func_0208EF30();
    if (func_0203D6CC() != 0) {
        *(u16 *)(g_021797A8 + 0x34) = func_0203D6CC();
    } else {
        *(u16 *)(g_021797A8 + 0x34) = func_0203D6BC() * func_0203D680() + 4;
    }
    *(u16 *)(g_021797A8 + 0x36) = func_0203D6BC();
    *(u16 *)(g_021797A8 + 0x10) = c;
    *(u16 *)(g_021797A8 + 0x16) = 0;
    *(u16 *)(g_021797A8 + 0x12) = 0;
    *(u16 *)(g_021797A8 + 0xE) = 1;
    *(u16 *)(g_021797A8 + 0x14) = (mode == 2);
    if (mode == 0 || mode == 2 || mode == 4)
        return func_02178168();
    return 0;
}






void func_02179328(void *v) { *(void **)(g_021797A8 + 0x1E7C) = v; }





void func_0217933C(void *cb)
{
    *(void **)(g_021797A8 + 0x1E78) = cb;
    if (func_0208EB0C(14, func_02178D9C, 0) != 0) func_02178138(9);
}






/*
 * Guard wrapper: forwards to func_02178D20 when func_021795A4 is nonzero or
 * one of bits 1-7 of func_02178E38 is set, else returns 0.  The unlabelled
 * follower at 02179394 (adds the block's +0x1C64 / +0x1444 to g_021797A8,
 * tail calls a thumb function) is why the extent runs long.
 */
BOOL func_02179368(int a, u16 b, int c)
{
    if (func_021795A4() == 0 && (func_02178E38() & 0xFE) == 0)
        return 0;
    return func_02178D20(a, b, c);
}





/*
 * extent: existing matched 021793B8 follows the 36-byte leaf.
 */
int func_02179394(u16 slot)
{
    return func_02090B18(g_021797A8 + 0x1444, g_021797A8 + 0x1C64, slot);
}





/*
 * Calls the arm9 function at 0x020902D8 with the data-sharing info
 * (+0x1444) and buffer (+0x1C64) of the work block behind g_021797A8; result
 * 7 or 5 counts as failure without the error setter, other nonzero results
 * call func_0217814C and fail, zero succeeds.
 */
BOOL func_021793B8(int arg)
{
    int r;

    r = func_020902D8((struct WMDataSharingInfo *)(g_021797A8 + 0x1444), (const u16 *)arg, (struct WMDataSet *)(g_021797A8 + 0x1C64));
    if (r == 7)
        return 0;
    if (r == 5)
        return 0;
    if (r != 0) {
        func_0217814C(r);
        return 0;
    }
    return 1;
}




/*
 * lever: final counter store uses unsigned address arithmetic rather than
 *   pointer arithmetic, so its offset is reloaded independently of the flag.
 */
void func_021793F8(void)
{
    if (g_021797A8 != 0 && *(s16_021791F8 *)(g_021797A8 + 0x1EBE) > 0) {
        *(s16_021791F8 *)(g_021797A8 + 0x1EBE) =
            (*(int *)(g_021797A8 + 0x1E70) != 2) ? 0 : *(s16_021791F8 *)(g_021797A8 + 0x1EBE) - 1;
        if (*(s16_021791F8 *)(g_021797A8 + 0x1EBE) == 0) {
            if (*(int *)(g_021797A8 + 0x1E70) == 2 && g_021797A8[0x1EDE] == 0) {
                if (func_0217863C() == 0) func_02178138(9);
            } else {
                *(s16_021791F8 *)((unsigned int)g_021797A8 + 0x1EBE) = 1;
            }
        }
    }
}




/*
 * return-chain: 0209028C result is passed to 0217814C.
 */
void func_0217945C(void)
{
    int error;
    if (*(int *)(g_021797A8 + 0x1E70) == 5) {
        error = func_0209028C(g_021797A8 + 0x1444);
        if (error != 0) func_0217814C(error);
    }
    if (func_02178CDC() == 0) func_02178138(10);
}





/*
 * The DWC copy of the NitroSDK demo wh.c's WH_Finalize (DWCi_MOV_WH_*),
 * returning BOOL and reading its state from the work block behind
 * g_021797A8: +0x1E70 system state, +0x1E74 connect mode, +0x1444 the
 * data-sharing info, +0x1E98 an error latch, +0x1EDF a byte flag.
 */
BOOL func_02179498(void)
{
    int state;

    if (g_021797A8 == 0 || (state = *(int *)(g_021797A8 + 0x1E70)) == 1)
        return 1;

    if (*(int *)(g_021797A8 + 0x1E98) != 0) {
        func_0217945C();
        return 1;
    }

    if (state == 3)
        return 0;

    if (state == 2) {
        if (!func_021788FC())
            func_0217945C();
        return 1;
    }

    if (g_021797A8[0x1EDF] != 0)
        return 1;

    if (state != 5 && state != 4) {
        func_02178138(3);
        func_0217945C();
        return 1;
    }

    func_02178138(3);

    switch (*(int *)(g_021797A8 + 0x1E74)) {
    case 5:
        if (WM_EndDataSharing(g_021797A8 + 0x1444) != 0) {
            func_0217945C();
            break;
        }
    case 1:
        if (!func_02178C50())
            func_0217945C();
        break;
    case 2:
    case 3:
        break;
    case 4:
        if (WM_EndDataSharing(g_021797A8 + 0x1444) != 0) {
            func_0217945C();
            break;
        }
    case 0:
        if (!func_021784AC())
            func_0217945C();
        break;
    }
    return 1;
}




int func_02179570(void (*cb)(int))
{
    *(void (**)(int))(g_021797A8 + 0x1E64) = cb;
    func_02178138(3);
    if (func_0208F43C(func_02178DE0) != 2) {
        func_02178138(9);
        return 0;
    }
    return 1;
}




unsigned short func_021795A4(void)
{
    if (g_021797A8 != 0) return *(unsigned short *)(g_021797A8 + 0x1EA8);
    return 0;
}




void func_021795C0(unsigned v) { *(unsigned *)(g_021797A8 + 0x1E94) = v; }





/*
 * When the state word (+0x1E70) of the work block behind
 * g_021797A8 is 4 or 5, forwards the arguments to the arm9 function at
 * 0x02090CD4 with (0, a, b, c, d, 1) and the halfword arguments truncated.
 */
void func_021795D4(int a, int b, int c, int d)
{
    if (g_021797A8 != 0 && (unsigned)(*(int *)(g_021797A8 + 0x1E70) - 4) <= 1)
        func_02090CD4(0, a, (u16)b, c, (u16)d, 1);
}




unsigned short func_02179614(void) { return *(unsigned short *)(g_021797A8 + 0x1EBA); }




void func_02179628(unsigned v) { *(unsigned *)(g_021797A8 + 0x1E84) = v; }





/*
 * Recursive MATCH unblocker: the unlabelled ov014 setter that func_020103E4
 * (+001A) and sub_02010360 (+0056) call: store v into word +0x1E88 of the
 * object behind the pointer at g_021797A8.
 */
void func_0217963C(u32 v)
{
    *(u32 *)(g_021797A8 + 0x1E88) = v;
}




void func_02179650(u16 v)
{
    *(u16 *)(g_021797A8 + 0x1ec2) = v;
}
