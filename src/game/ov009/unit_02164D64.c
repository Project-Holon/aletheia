/*
 * file:     unit_02164D64.c
 * unit:     yes
 * function: func_02164D64, func_02164D74, func_02164EE0, func_02164F38, func_02164F98, func_02165088, func_02165144, func_02165164, func_02165204, func_021652A4, func_02165478, func_02165560, WCM_GetPhase, func_021656D0, WCM_GetAllowedChannel, func_021657C8, func_021657D8, func_021658F8, func_02165918, WCMi_Notify, WCMi_NotifyEx, func_02165A4C, WCMi_ResetKeepAliveAlarm, func_02165B5C, func_02165B68
 * address:  0x02164D64
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WCM_InitEx                   0x02164D74  arm
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   MI_CpuFill8          0x02082BCC arm
 *   MI_CpuCopy8          0x02082D44 arm
 *   func_02165B68 0x02165B68 arm ov009
 *   OS_IsRunOnTwl        0x02085D3C arm
 *   func_02164F38        0x02164F38 arm ov009
 *   func_021658F8        0x021658F8 arm ov009
 *   func_02166304        0x02166304 arm ov009
 *   func_02087058        0x02087058 arm
 *   func_02086FE8        0x02086FE8 arm
 *   func_02087244        0x02087244 arm
 *   func_02087208        0x02087208 arm
 *   func_02087254        0x02087254 arm
 *   func_021657D8        0x021657D8 arm ov009
 *   func_0208EE60        0x0208EE60 arm
 *   func_02166880        0x02166880 arm ov009
 *   WCMi_NwmifStartupAsync        0x0273199C arm twl
 *   func_021669B8        0x021669B8 arm ov009
 *   WCMi_NwmifCleanupAsync        0x02731A84 arm twl
 *   func_02166A24        0x02166A24 arm ov009
 *   WCMi_NwmifBeginSearchAsync        0x02731AF0 arm twl
 *   func_02165A4C        0x02165A4C arm ov009
 *   func_021657C8        0x021657C8 arm ov009
 *   func_021656D0        0x021656D0 arm ov009
 *   func_02166B2C        0x02166B2C arm ov009
 *   WCMi_NwmifConnectAsync        0x02731BF8 arm twl
 *   func_02166BD8        0x02166BD8 arm ov009
 *   WCMi_NwmifDisconnectAsync        0x02731CFC arm twl
 *   func_02166C44        0x02166C44 arm ov009
 *   WCMi_NwmifTerminateAsync        0x02731D6C arm twl
 *   WCMi_WmifGetAllowedChannel  0x02166DE4 arm
 *   WCMi_NwmifGetAllowedChannel 0x02731F00 arm
 *   OS_CancelAlarm       0x020873F8 arm
 *   OS_SetAlarm          0x0208738C arm
 *   WcmKeepAliveAlarm    0x02165B5C arm ov009
 *   WCMi_OverridedDeviceId 0x021AA7D4 data
 *   wcmw                 0x021AA7D8 data
 *   func_02165AF4  0x02165AF4  arm  ov009
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#include "wcm_types.h"

typedef struct WCMWepDesc {
    u8 mode;
    union {
        u8 keyId;
        u8 keyLen;
    } u;
    u8 key[80];
} WCMWepDesc;

typedef struct WCMNotice {
    short notify;
    short result;
    void *para0;
    void *para1;
    long para2;
} WCMNotice;


extern void WCM_InitEx(void *buf, long len, unsigned char deviceId);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern unsigned char func_02165B68(void);
extern int OS_IsRunOnTwl(void);
extern void func_021658F8(void);
extern void func_02166304(void);
extern long func_02087058(void);
extern void func_02086FE8(void);
extern long func_02087244(void);
extern void func_02087208(void);
extern void func_02087254(void *alarm);
extern void func_021657D8(WCMConfig *config, void (*notify)(void *));
extern unsigned short func_0208EE60(void);
extern long func_02166880(void);
extern long WCMi_NwmifStartupAsync(void);
extern long func_021669B8(void);
extern long WCMi_NwmifCleanupAsync(void);
extern long func_02166A24(void *bssid, void *essid, unsigned long option);
extern long WCMi_NwmifBeginSearchAsync(void *bssid, void *essid, unsigned long option);
extern void func_02165A4C(unsigned char phase);
extern long func_02166B2C(void);
extern long WCMi_NwmifConnectAsync();
extern long func_02166BD8(void);
extern long WCMi_NwmifDisconnectAsync(void);
extern long func_02166C44(void);
extern long WCMi_NwmifTerminateAsync();
extern unsigned short WCMi_WmifGetAllowedChannel(void);
extern unsigned short WCMi_NwmifGetAllowedChannel(void);
extern void OS_CancelAlarm(void *alarm);
extern void OS_SetAlarm(void *alarm, unsigned long long tick, void (*handler)(void *), void *arg);
extern void WcmKeepAliveAlarm(void *arg);

long func_02164D74(void *buf, long len, unsigned char deviceId);
long WCM_Finish(void);
int WCM_GetWorkSize(long *workSize, unsigned char deviceId);
long func_02164F98(void *config, void (*notify)(void *));
long func_02165088(void);
void func_02165144(void *bssid, void *essid, unsigned long option);
long func_02165164(void *bssid, void *essid, unsigned long option);
long func_02165204(void *bssid, void *essid);
long func_021652A4(void *bssDesc, void *wepDesc, unsigned long option);
long func_02165478(void);
long func_02165560(void);
long WCM_GetPhase(void);
unsigned long func_021656D0(unsigned long option);
unsigned short WCM_GetAllowedChannel(void);
WCMWork *func_021657C8(void);
void func_021657D8(WCMConfig *config, void (*notify)(void *));
void func_021658F8(void);
unsigned short func_02165918(unsigned short channel);
void WCMi_Notify(short result, void *para0, void *para1, long para2);
void WCMi_NotifyEx(short notify, short result, void *para0, void *para1, long para2);
void func_02165A4C(unsigned char phase);
void WCMi_ResetKeepAliveAlarm(void);
extern void func_02165AF4(void);
void func_02165B5C(void);

void WCM_Init(void *buf, long len)
{
    WCM_InitEx(buf, len, 1);
}


static unsigned char WCMi_OverridedDeviceId = 0;

static WCMWork *wcmw = 0;


/*
 * sdk:      WCM_InitEx (libwcm.TWL.HYB.a system.o)
 *
 * lane04 (2026-10-01): EXACT. WCMi_OverridedDeviceId and wcmw are two
 * separate statics in system.o's .bss (0x021AA7D4 / +4), not one struct:
 * defined here as zero-initialised file statics (layout matches the vendor,
 * .bss anchored on WCMi_OverridedDeviceId), the `p` stand-in local is gone,
 * and the pool load / expectLen spill schedule falls out as in the image.
 *
 * near miss (history): 364 B both; only the +0x18..+0x28 schedule differs (original loads
 * the 0x021AA7D4 pool word before `mov r1,#0`, ours after).  wave7: sdkobj
 * confirms the object is Metrowerks 4.0.0.1024 -> dsi/1.1p1, so this residue is
 * a shape this front end has not been given (the DWARF locals are exactly
 * expectLen [fb+0], e r5, matching the source); wave7 re-measured declaration
 * swap, `if (wcmw)` and the guard-before-init forms, all still 18.
 *
 * lane T5 (2026-09-30).  HEADER REPAIR: the `symbols:` block used bare hex
 * addresses (`OS_DisableInterrupts 02087988 arm`), which SYMBOL_RE rejects, so the
 * whole block was dropped (`symbols_lines` empty) and the one ABS32 stayed
 * wildcarded.  With `0x` addresses the sites go 18 of 18 resolved, the ABS32
 * g_021AA7D4 resolving as sole-ref - the row's ceiling is now EXACT rather than
 * MATCH.  The instruction residue is unchanged at 18 concrete bytes.
 * Pin sweep (all 9 dsi compilers x 4 flag sets): 1.1p1 -O4,p is the unique best.
 * Residue is a six-instruction schedule rotation at +0018..+0028, same 364 bytes:
 *   +0018  image `ldr sb, [pc, #0x148]`  | ours `mov r1, #0`
 *   +0028  image `str r1, [sp]`          | ours `mov r5, r0`
 *   i.e. the image loads the 0x021AA7D4 pool word first and sinks the spill of
 *   expectLen below the wcmw load, this build materialises the zero and spills it
 *   immediately.  Measured worse: `long expectLen = 0;` as a declaration
 *   initialiser (396/345), `expectLen` before the OS_DisableInterrupts call (396),
 *   both as declaration initialisers (400).  lane U22 adds nine more shapes, all
 *   at exactly 18: `expectLen = 0;` sunk to just before MI_CpuFill8 (70), after
 *   the first wcmw guard (28), a comma expression `e = ..., expectLen = 0;`,
 *   swapped local declaration order, `if (wcmw)` without `!= 0`,
 *   both locals as declaration initialisers, a volatile-cast read of `wcmw`,
 *   `expectLen` zeroed as `unsigned long`, and `expectLen = 0;` moved after the
 *   two pointer guards.  The pool load and the spill are one independent
 *   instruction pair and this front end will not rotate them into the image's
 * order from any statement position.
 *
 * wave8: tried the const-pointer hoist lever from
 * docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md
 * on the field read (`const WCMSysState *` local over &g_021AA7D4, and an
 * inline `((const WCMSysState *)&g_021AA7D4)->wcmw` cast at the guard); both
 * still 18 bytes, schedule unchanged.  The lever needs a pointer parameter;
 * it does not reach a load through a global object.  Also tried: caching the
 * read in a `WCMWork *wcmw` local before and after `expectLen = 0`, and a
 * non-const named `WCMSysState *p = &g_021AA7D4` with the guard written
 * `wcmw`; all three still emit exactly `mov r1,#0; ldr sb; str r1,[sp];
 * ldr r2,[sb,#4]; mov r5,r0` (18 concrete bytes), i.e. the front end never
 * hoists the address load above the zero materialisation.  blocker: the
 * `ldr sb` address load and the `str r1,[sp]` expectLen spill will not swap.
 */
long func_02164D74(void *buf, long len, unsigned char deviceId)
{
    long expectLen;
    unsigned long e;

    e = OS_DisableInterrupts();
    expectLen = 0;
    if (wcmw != 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (buf == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (((unsigned long)buf & 0x1f) != 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    MI_CpuFill8(buf, 0, len);
    if (deviceId == 0) {
        deviceId = WCMi_OverridedDeviceId;
        if (deviceId == 0) {
            deviceId = func_02165B68();
        }
    }
    if (WCM_GetWorkSize(&expectLen, deviceId) == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (len < expectLen) {
        OS_RestoreInterrupts(e);
        return 6;
    }
    wcmw = buf;
    ((WCMWork *)buf)->phase = 1;
    wcmw->notifyId = 0;
    wcmw->maxScanTime = 0;
    wcmw->apListLock = 0;
    wcmw->resetting = 0;
    wcmw->deviceId = deviceId;
    func_021658F8();
    func_02166304();
    if (func_02087058() == 0) {
        func_02086FE8();
    }
    if (func_02087244() == 0) {
        func_02087208();
    }
    func_02087254(wcmw->alarm);
    OS_RestoreInterrupts(e);
    return 0;
}


long WCM_Finish(void)
{
    unsigned long e = OS_DisableInterrupts();

    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (wcmw->phase != 1) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    wcmw = 0;
    OS_RestoreInterrupts(e);
    return 0;
}


int WCM_GetWorkSize(long *workSize, unsigned char deviceId)
{
    if (deviceId == 0)
        deviceId = func_02165B68();

    switch (deviceId) {
    case 1:
        *workSize = 0x2300;
        break;
    case 2:
        if (!OS_IsRunOnTwl())
            return 0;
        *workSize = 0x4800;
        break;
    default:
        return 0;
    }
    return 1;
}


/*
 * sdk:      WCM_StartupAsync (libwcm.TWL.HYB.a system.o)
 *
 * Starts up the WCM: configures it in the idle phase, then starts the WM or NWM device if a channel is allowed.
 */
long func_02164F98(void *config, void (*notify)(void *))
{
    unsigned long e;
    long wcmResult;

    e = OS_DisableInterrupts();
    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (wcmw->phase) {
    case 1:
        func_021657D8(config, notify);
        break;
    case 2:
        OS_RestoreInterrupts(e);
        return 2;
    case 3:
        OS_RestoreInterrupts(e);
        return 0;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    }
    if (func_0208EE60() == 0) {
        return 5;
    }
    switch (wcmw->deviceId) {
    case 1:
        wcmResult = func_02166880();
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = WCMi_NwmifStartupAsync();
            break;
        }
    default:
        wcmResult = 7;
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}


/*
 * sdk:      WCM_CleanupAsync (libwcm.TWL.HYB.a system.o)
 *
 * Requests cleanup of the WCM: only valid in the idle phase, dispatched to the WM or NWM cleanup by device id.
 */
long func_02165088(void)
{
    unsigned long e;
    long wcmResult;

    e = OS_DisableInterrupts();
    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (wcmw->phase) {
    case 4:
        OS_RestoreInterrupts(e);
        return 2;
    case 1:
        OS_RestoreInterrupts(e);
        return 0;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    case 3:
        break;
    }
    switch (wcmw->deviceId) {
    case 1:
        wcmResult = func_021669B8();
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = WCMi_NwmifCleanupAsync();
            break;
        }
    default:
        wcmResult = 7;
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}


/*
 * Dispatches on whether either argument is missing.
 */
void func_02165144(void *bssid, void *essid, unsigned long option)
{
    if (bssid == 0 || essid == 0) {
        func_02165204(bssid, essid);
        return;
    }

    func_02165164(bssid, essid, option);
}


long func_02165164(void *bssid, void *essid, unsigned long option)
{
    long wcmResult;
    unsigned long e;

    e = OS_DisableInterrupts();
    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (wcmw->deviceId) {
    case 1:
        wcmResult = func_02166A24(bssid, essid, option);
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = WCMi_NwmifBeginSearchAsync(bssid, essid, option);
            break;
        }
    default:
        wcmResult = 7;
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}


/*
 * sdk:      WCM_EndSearchAsync (libwcm.TWL.HYB.a system.o)
 *
 * Ends an AP search: only valid in the search phases, moves to the search-ending phase and reports pending.
 */
long func_02165204(void *bssid, void *essid)
{
    unsigned long e;

    e = OS_DisableInterrupts();
    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (wcmw->phase) {
    case 6:
        func_02165A4C(7);
        wcmw->notifyId = 4;
        break;
    case 7:
        OS_RestoreInterrupts(e);
        return 2;
    case 3:
        OS_RestoreInterrupts(e);
        return 0;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    }
    OS_RestoreInterrupts(e);
    return 3;
}


/*
 * sdk:      WCM_ConnectAsync (libwcm.TWL.HYB.a(system.o))
 *
 * The 0x40 bound reads keyLen from the work area before it is stored, as the object does.
 */
long func_021652A4(void *bssDesc, void *wepDesc, unsigned long option)
{
    unsigned long e;
    WCMWork *w;
    long wcmResult;
    WCMWepDesc *privacyDesc;

    e = OS_DisableInterrupts();
    w = func_021657C8();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (w->phase) {
    case 3:
        if (bssDesc == 0) {
            OS_RestoreInterrupts(e);
            return 1;
        }
        if (((u16 *)bssDesc)[0x1E] != 0) {
            OS_RestoreInterrupts(e);
            return 1;
        }
        privacyDesc = (WCMWepDesc *)wepDesc;
        if (privacyDesc != 0) {
            if ((privacyDesc->mode <= 3 && privacyDesc->u.keyId >= 4) || w->privacyDesc.u.keyLen > 0x40) {
                OS_RestoreInterrupts(e);
                return 1;
            }
            w->privacyDesc.mode = privacyDesc->mode;
            if (privacyDesc->mode == 0) {
                MI_CpuFill8(w->privacyDesc.key, 0, 0x50);
            } else if (privacyDesc->mode <= 3) {
                w->privacyDesc.u.keyId = privacyDesc->u.keyId;
                MI_CpuCopy8(privacyDesc->key, w->privacyDesc.key, 0x50);
            } else {
                w->privacyDesc.u.keyLen = privacyDesc->u.keyLen;
                MI_CpuCopy8(privacyDesc->key, w->privacyDesc.key, w->privacyDesc.u.keyLen);
            }
        } else {
            MI_CpuFill8(&w->privacyDesc, 0, 0x54);
        }
        MI_CpuCopy8(bssDesc, w->bssDesc, 0xC0);
        func_021656D0(option);
        break;
    case 8:
        OS_RestoreInterrupts(e);
        return 2;
    case 9:
        OS_RestoreInterrupts(e);
        return 0;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (w->deviceId) {
    case 1:
        wcmResult = func_02166B2C();
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = WCMi_NwmifConnectAsync();
            break;
        }
    default:
        wcmResult = 7;
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}


/*
 * sdk:      WCM_DisconnectAsync (libwcm.TWL.HYB.a system.o)
 *
 * Requests disconnection: valid only in the connected phase, either flagging the reset or dispatching to the WM or NWM disconnect.
 */
long func_02165478(void)
{
    unsigned long e;
    long wcmResult;

    e = OS_DisableInterrupts();
    wcmResult = 0;
    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (wcmw->phase) {
    case 10:
        OS_RestoreInterrupts(e);
        return 2;
    case 3:
        OS_RestoreInterrupts(e);
        return wcmResult;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    case 9:
        break;
    }
    if (wcmw->resetting == 1) {
        func_02165A4C(10);
        wcmw->notifyId = 6;
    } else {
        switch (wcmw->deviceId) {
        case 1:
            wcmResult = func_02166BD8();
            break;
        case 2:
            if (OS_IsRunOnTwl()) {
                wcmResult = WCMi_NwmifDisconnectAsync();
                break;
            }
        default:
            wcmResult = 7;
            break;
        }
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}


/*
 * sdk:      WCM_TerminateAsync (libwcm.TWL.HYB.a system.o)
 *
 * Starts asynchronous termination of the WCM state machine: switches on the phase and dispatches to the WM or NWM terminate call by device id.
 */
long func_02165560(void)
{
    unsigned long e;
    long wcmResult;

    e = OS_DisableInterrupts();
    wcmResult = 0;
    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (wcmw->phase) {
    case 13:
        OS_RestoreInterrupts(e);
        return 2;
    case 1:
        OS_RestoreInterrupts(e);
        return wcmResult;
    case 6:
        func_02165A4C(13);
        wcmw->notifyId = 9;
        OS_RestoreInterrupts(e);
        return 3;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    case 3:
    case 9:
    case 12:
        if (wcmw->resetting == 1) {
            func_02165A4C(13);
            wcmw->notifyId = 9;
        } else {
            switch (wcmw->deviceId) {
            case 1:
                wcmResult = func_02166C44();
                break;
            case 2:
                if (OS_IsRunOnTwl()) {
                    wcmResult = WCMi_NwmifTerminateAsync();
                    break;
                }
            default:
                wcmResult = 7;
                break;
            }
        }
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}


long WCM_GetPhase(void)
{
    unsigned long e = OS_DisableInterrupts();
    long phase = 0;
    WCMWork *w = wcmw;

    if (w != 0)
        phase = w->phase;
    OS_RestoreInterrupts(e);
    return phase;
}


unsigned long func_021656D0(unsigned long option)
{
    unsigned long e;
    unsigned long filter;
    unsigned long oldOption;

    e = OS_DisableInterrupts();
    filter = 0;
    oldOption = wcmw->option;
    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    if ((option & 0x8000) != 0) {
        filter |= 0x3FFE;
        if ((option & 0x3FFE) == 0) {
            option |= 0xA082;
        }
    }
    if ((option & 0x20000) != 0) {
        filter |= 0x10000;
    }
    if ((option & 0x80000) != 0) {
        filter |= 0x40000;
    }
    if ((option & 0x200000) != 0) {
        filter |= 0x100000;
    }
    if ((option & 0x800000) != 0) {
        filter |= 0x400000;
    }
    wcmw->option = option | (oldOption & ~filter);
    OS_RestoreInterrupts(e);
    return oldOption;
}


unsigned short WCM_GetAllowedChannel(void)
{
    WCMWork *w = func_021657C8();

    if (w->phase >= 3 && w->phase <= 10) {
        switch (w->deviceId) {
        case 1:
            return WCMi_WmifGetAllowedChannel();
        case 2:
            if (OS_IsRunOnTwl())
                return WCMi_NwmifGetAllowedChannel();
            break;
        }
    }
    return 0;
}


/*
 * The word at +4 of the module state block.
 */
WCMWork *func_021657C8(void)
{
    return wcmw;
}


void func_021657D8(WCMConfig *config, void (*notify)(void *))
{
    if (config == 0) {
        wcmw->config.dmano = 3;
        wcmw->config.pbdbuffer = 0;
        wcmw->config.nbdbuffer = 0;
        wcmw->config.nbdmode = 0;
    } else {
        wcmw->config.dmano = config->dmano & 3;
        if (((4 - ((unsigned long)config->pbdbuffer & 3)) & 3) + 12 > (unsigned long)config->nbdbuffer) {
            wcmw->config.pbdbuffer = 0;
            wcmw->config.nbdbuffer = 0;
        } else {
            wcmw->config.pbdbuffer = (void *)(((unsigned long)config->pbdbuffer + 3) & ~3UL);
            wcmw->config.nbdbuffer = config->nbdbuffer - ((4 - ((unsigned long)config->pbdbuffer & 3)) & 3);
            MI_CpuFill8(wcmw->config.pbdbuffer, 0, wcmw->config.nbdbuffer);
        }
        wcmw->config.nbdmode = config->nbdmode;
    }
    wcmw->notify = notify;
}


/*
 * Stores the constant 0xaaa082 at +0x12d4 of the block the state object holds.
 */
void func_021658F8(void)
{
    WCMWork *p = wcmw;

    p->option = 0xaaa082;
}


/*
 * sdk:      WCMi_GetNextScanChannel (libwcm.TWL.HYB.a system.o)
 *
 * Finds the next channel after the given one that is enabled in the scan mask and allowed by the region, wrapping over 13 channels.
 */
unsigned short func_02165918(unsigned short channel)
{
    long i;

    for (i = 0; i < 13; i++) {
        if ((wcmw->option & (1 << ((channel + i) % 13 + 1))) != 0) {
            if ((WCM_GetAllowedChannel() & (1 << ((channel + i) % 13))) != 0) {
                break;
            }
        }
    }
    return (unsigned short)((channel + i) % 13 + 1);
}


void WCMi_Notify(short result, void *para0, void *para1, long para2)
{
    short notifyId = wcmw->notifyId;

    wcmw->notifyId = 0;
    WCMi_NotifyEx(notifyId, result, para0, para1, para2);
}


void WCMi_NotifyEx(short notify, short result, void *para0, void *para1, long para2)
{
    WCMWork *w = wcmw;
    WCMNotice notice;

    if (w->notify == 0)
        return;
    notice.notify = notify;
    notice.result = result;
    notice.para0 = para0;
    notice.para1 = para1;
    notice.para2 = para2;
    w->notify(&notice);
}


/*
 * sdk:      WCMi_SetPhase (libwcm.TWL.HYB.a system.o)
 *
 * Sets the WCM phase under a critical section, managing the keep-alive alarm when entering or leaving the connected phase.
 */
void func_02165A4C(unsigned char phase)
{
    unsigned long e;

    e = OS_DisableInterrupts();
    if (wcmw->phase == 9 && phase != 9) {
        OS_CancelAlarm(wcmw->alarm);
    }
    if (wcmw->phase != 0xB) {
        wcmw->phase = phase;
    }
    if (phase == 9) {
        OS_CancelAlarm(wcmw->alarm);
        OS_SetAlarm(wcmw->alarm, 0x022F5341ULL, WcmKeepAliveAlarm, 0);
    }
    OS_RestoreInterrupts(e);
}


/*
 * sdk:      WCMi_ResetKeepAliveAlarm (system.o)
 */
void WCMi_ResetKeepAliveAlarm(void)
{
    unsigned long e = OS_DisableInterrupts();

    OS_CancelAlarm(wcmw->alarm);
    if (wcmw->phase == 9)
        OS_SetAlarm(wcmw->alarm, 0x022f5341, WcmKeepAliveAlarm, 0);
    OS_RestoreInterrupts(e);
}


void func_02165B5C(void)
{
    func_02165AF4();
}

/*
 * Two when the word call is non-zero, one otherwise.
 */
unsigned char func_02165B68(void)
{
    if (OS_IsRunOnTwl())
        return 2;
    return 1;
}
