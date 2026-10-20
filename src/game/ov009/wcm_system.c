/*
 * file:     wcm_system.c
 * unit:     yes
 * function: WCM_Init, WCM_InitEx, WCM_Finish, WCM_GetWorkSize, WCM_StartupAsync, WCM_CleanupAsync, WCM_SearchAsync, WCM_BeginSearchAsync, WCM_EndSearchAsync, WCM_ConnectAsync, WCM_DisconnectAsync, WCM_TerminateAsync, WCM_GetPhase, WCM_UpdateOption, WCM_GetAllowedChannel, WCMi_GetSystemWork, WcmConfigure, WcmInitOption, WCMi_GetNextScanChannel, WCMi_Notify, WCMi_NotifyEx, WCMi_SetPhase, WCMi_ResetKeepAliveAlarm, WcmKeepAliveAlarm, WCMi_GetDefaultDeviceId
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
 *   WCMi_GetDefaultDeviceId 0x02165B68 arm ov009
 *   OS_IsRunOnTwl        0x02085D3C arm
 *   WCM_GetWorkSize        0x02164F38 arm ov009
 *   WcmInitOption        0x021658F8 arm ov009
 *   WCMi_InitCpsif        0x02166304 arm ov009
 *   OS_IsTickAvailable        0x02087058 arm
 *   OS_InitTick        0x02086FE8 arm
 *   OS_IsAlarmAvailable        0x02087244 arm
 *   OS_InitAlarm        0x02087208 arm
 *   OS_CreateAlarm        0x02087254 arm
 *   WcmConfigure        0x021657D8 arm ov009
 *   WM_GetAllowedChannel        0x0208EE60 arm
 *   WCMi_WmifStartupAsync        0x02166880 arm ov009
 *   WCMi_NwmifStartupAsync        0x0273199C arm twl
 *   WCMi_WmifCleanupAsync        0x021669B8 arm ov009
 *   WCMi_NwmifCleanupAsync        0x02731A84 arm twl
 *   WCMi_WmifBeginSearchAsync        0x02166A24 arm ov009
 *   WCMi_NwmifBeginSearchAsync        0x02731AF0 arm twl
 *   WCMi_SetPhase        0x02165A4C arm ov009
 *   WCMi_GetSystemWork        0x021657C8 arm ov009
 *   WCM_UpdateOption        0x021656D0 arm ov009
 *   WCMi_WmifConnectAsync        0x02166B2C arm ov009
 *   WCMi_NwmifConnectAsync        0x02731BF8 arm twl
 *   WCMi_WmifDisconnectAsync        0x02166BD8 arm ov009
 *   WCMi_NwmifDisconnectAsync        0x02731CFC arm twl
 *   WCMi_WmifTerminateAsync        0x02166C44 arm ov009
 *   WCMi_NwmifTerminateAsync        0x02731D6C arm twl
 *   WCMi_WmifGetAllowedChannel  0x02166DE4 arm
 *   WCMi_NwmifGetAllowedChannel 0x02731F00 arm
 *   OS_CancelAlarm       0x020873F8 arm
 *   OS_SetAlarm          0x0208738C arm
 *   WcmKeepAliveAlarm    0x02165B5C arm ov009
 *   WCMi_OverridedDeviceId 0x021AA7D4 data
 *   wcmw                 0x021AA7D8 data
 *   WCMi_ResetKeepAliveAlarm  0x02165AF4  arm  ov009
 */
#include "../types.h"

#include "wcm_types.h"

typedef struct WCMWepDesc {
    u8 mode;
    union {
        u8 keyId;
        u8 keyLen;
    } u;
    u8 key[80];
} WCMWepDesc;

#include "../sdk_wm.h"

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern unsigned char WCMi_GetDefaultDeviceId(void);
extern int OS_IsRunOnTwl(void);
extern void WcmInitOption(void);
extern void WCMi_InitCpsif(void);
extern long OS_IsTickAvailable(void);
extern void OS_InitTick(void);
extern long OS_IsAlarmAvailable(void);
extern void OS_InitAlarm(void);
#include "../sdk_os.h"

extern void OS_CreateAlarm(struct OSiAlarm *alarm);
extern void WcmConfigure(WCMConfig *config, void (*notify)(void *));
extern unsigned short WM_GetAllowedChannel(void);
extern long WCMi_WmifStartupAsync(void);
extern u32 WCMi_NwmifStartupAsync(void);
extern long WCMi_WmifCleanupAsync(void);
extern u32 WCMi_NwmifCleanupAsync(void);
extern long WCMi_WmifBeginSearchAsync(void *bssid, void *essid, unsigned long option);
extern long WCMi_NwmifBeginSearchAsync(u32 bssid, u32 essid, u32 option);
extern void WCMi_SetPhase(unsigned char phase);
extern long WCMi_WmifConnectAsync(void);
extern u32 WCMi_NwmifConnectAsync();
extern long WCMi_WmifDisconnectAsync(void);
extern u32 WCMi_NwmifDisconnectAsync(void);
extern long WCMi_WmifTerminateAsync(void);
extern u32 WCMi_NwmifTerminateAsync();
extern unsigned short WCMi_WmifGetAllowedChannel(void);
extern unsigned short WCMi_NwmifGetAllowedChannel(void);
extern void OS_CancelAlarm(struct OSiAlarm *alarm);
extern void OS_SetAlarm(struct OSiAlarm *alarm, unsigned long long tick, void (*handler)(void *), void *arg);

long WCM_Finish(void);
int WCM_GetWorkSize(long *workSize, unsigned char deviceId);
long WCM_StartupAsync(void *config, void (*notify)(void *));
long WCM_CleanupAsync(void);
void WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
long WCM_BeginSearchAsync(void *bssid, void *essid, unsigned long option);
long WCM_EndSearchAsync(void);
long WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option);
long WCM_DisconnectAsync(void);
long WCM_TerminateAsync(void);
long WCM_GetPhase(void);
unsigned long WCM_UpdateOption(unsigned long option);
unsigned short WCM_GetAllowedChannel(void);
WCMWork *WCMi_GetSystemWork(void);
unsigned short WCMi_GetNextScanChannel(unsigned short channel);
void WCMi_Notify(short result, void *para0, void *para1, long para2);
void WCMi_NotifyEx(short notify, short result, void *para0, void *para1, long para2);
void WCMi_ResetKeepAliveAlarm(void);
extern void WCMi_ResetKeepAliveAlarm(void);
long WCM_InitEx(void *buf, long len, unsigned char deviceId);
void WcmKeepAliveAlarm(void);

long WCM_Init(void *buf, long len)
{
    return WCM_InitEx(buf, len, 1);
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
long WCM_InitEx(void *buf, long len, unsigned char deviceId)
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
            deviceId = WCMi_GetDefaultDeviceId();
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
    WcmInitOption();
    WCMi_InitCpsif();
    if (OS_IsTickAvailable() == 0) {
        OS_InitTick();
    }
    if (OS_IsAlarmAvailable() == 0) {
        OS_InitAlarm();
    }
    OS_CreateAlarm((struct OSiAlarm *)wcmw->alarm);
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
        deviceId = WCMi_GetDefaultDeviceId();

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
long WCM_StartupAsync(void *config, void (*notify)(void *))
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
        WcmConfigure(config, notify);
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
    if (WM_GetAllowedChannel() == 0) {
        return 5;
    }
    switch (wcmw->deviceId) {
    case 1:
        wcmResult = WCMi_WmifStartupAsync();
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
long WCM_CleanupAsync(void)
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
        wcmResult = WCMi_WmifCleanupAsync();
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
void WCM_SearchAsync(void *bssid, void *essid, unsigned long option)
{
    if (bssid == 0 || essid == 0) {
        WCM_EndSearchAsync();
        return;
    }

    WCM_BeginSearchAsync(bssid, essid, option);
}

long WCM_BeginSearchAsync(void *bssid, void *essid, unsigned long option)
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
        wcmResult = WCMi_WmifBeginSearchAsync(bssid, essid, option);
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = WCMi_NwmifBeginSearchAsync((u32)bssid, (u32)essid, option);
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
long WCM_EndSearchAsync(void)
{
    unsigned long e;

    e = OS_DisableInterrupts();
    if (wcmw == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (wcmw->phase) {
    case 6:
        WCMi_SetPhase(7);
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
long WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option)
{
    unsigned long e;
    WCMWork *w;
    long wcmResult;
    WCMWepDesc *privacyDesc;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
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
        WCM_UpdateOption(option);
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
        wcmResult = WCMi_WmifConnectAsync();
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
long WCM_DisconnectAsync(void)
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
        WCMi_SetPhase(10);
        wcmw->notifyId = 6;
    } else {
        switch (wcmw->deviceId) {
        case 1:
            wcmResult = WCMi_WmifDisconnectAsync();
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
long WCM_TerminateAsync(void)
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
        WCMi_SetPhase(13);
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
            WCMi_SetPhase(13);
            wcmw->notifyId = 9;
        } else {
            switch (wcmw->deviceId) {
            case 1:
                wcmResult = WCMi_WmifTerminateAsync();
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

unsigned long WCM_UpdateOption(unsigned long option)
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
    WCMWork *w = WCMi_GetSystemWork();

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
WCMWork *WCMi_GetSystemWork(void)
{
    return wcmw;
}

void WcmConfigure(WCMConfig *config, void (*notify)(void *))
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
void WcmInitOption(void)
{
    WCMWork *p = wcmw;

    p->option = 0xaaa082;
}

/*
 * sdk:      WCMi_GetNextScanChannel (libwcm.TWL.HYB.a system.o)
 *
 * Finds the next channel after the given one that is enabled in the scan mask and allowed by the region, wrapping over 13 channels.
 */
unsigned short WCMi_GetNextScanChannel(unsigned short channel)
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
    notice.parameter[0].p = para0;
    notice.parameter[1].p = para1;
    notice.parameter[2].n = para2;
    w->notify(&notice);
}

/*
 * sdk:      WCMi_SetPhase (libwcm.TWL.HYB.a system.o)
 *
 * Sets the WCM phase under a critical section, managing the keep-alive alarm when entering or leaving the connected phase.
 */
void WCMi_SetPhase(unsigned char phase)
{
    unsigned long e;

    e = OS_DisableInterrupts();
    if (wcmw->phase == 9 && phase != 9) {
        OS_CancelAlarm((struct OSiAlarm *)wcmw->alarm);
    }
    if (wcmw->phase != 0xB) {
        wcmw->phase = phase;
    }
    if (phase == 9) {
        OS_CancelAlarm((struct OSiAlarm *)wcmw->alarm);
        OS_SetAlarm((struct OSiAlarm *)wcmw->alarm, 0x022F5341ULL, (void (*)(void *))WcmKeepAliveAlarm, 0);
    }
    OS_RestoreInterrupts(e);
}

/*
 * sdk:      WCMi_ResetKeepAliveAlarm (system.o)
 */
void WCMi_ResetKeepAliveAlarm(void)
{
    unsigned long e = OS_DisableInterrupts();

    OS_CancelAlarm((struct OSiAlarm *)wcmw->alarm);
    if (wcmw->phase == 9)
        OS_SetAlarm((struct OSiAlarm *)wcmw->alarm, 0x022f5341, (void (*)(void *))WcmKeepAliveAlarm, 0);
    OS_RestoreInterrupts(e);
}

void WcmKeepAliveAlarm(void)
{
    WCMi_ResetKeepAliveAlarm();
}

/*
 * Two when the word call is non-zero, one otherwise.
 */
unsigned char WCMi_GetDefaultDeviceId(void)
{
    if (OS_IsRunOnTwl())
        return 2;
    return 1;
}
