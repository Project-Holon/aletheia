/*
 * file:     unit_02164D64_p02.c
 * unit:     yes
 * function: func_02164F38, func_02164F98, func_02165088
 * address:  0x02164F38
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WCMi_GetDefaultDeviceId         0x02165b68 arm
 *   OS_IsRunOnTwl                   0x02085d3c arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_021657D8  0x021657D8  arm  ov009
 *   func_0208EE60  0x0208EE60  arm
 *   func_02166880  0x02166880  arm  ov009
 *   func_0273199C  0x0273199C  arm  twl
 *   g_021AA7D4  0x021AA7D4  data ov009
 *   func_021669B8  0x021669B8  arm  ov009
 *   func_02731A84  0x02731A84  arm  twl
 */
#include "../../matched/include/G_WCMState.h"

struct WCMConfig;
typedef struct WCMWork {
    unsigned char pad0[0x12DE];
    unsigned char phase;
    unsigned char deviceId;
} WCMWork;

typedef struct WCMState WCMState;

extern unsigned char WCMi_GetDefaultDeviceId(void);
extern int OS_IsRunOnTwl(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void func_021657D8(struct WCMConfig *config, void (*notify)(void *));
extern unsigned short func_0208EE60(void);
extern long func_02166880(void);
extern long func_0273199C(void);
extern long func_021669B8(void);
extern long func_02731A84(void);
int WCM_GetWorkSize(long *workSize, unsigned char deviceId);
long func_02164F98(void *config, void (*notify)(void *));
long func_02165088(void);
extern struct WCMState g_021AA7D4;


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
long func_02164F98(void *config, void (*notify)(void *))
{
    unsigned long e;
    long wcmResult;

    e = OS_DisableInterrupts();
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (((WCMWork *)g_021AA7D4.work)->phase) {
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
    switch (((WCMWork *)g_021AA7D4.work)->deviceId) {
    case 1:
        wcmResult = func_02166880();
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = func_0273199C();
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
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (((WCMWork *)g_021AA7D4.work)->phase) {
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
    switch (((WCMWork *)g_021AA7D4.work)->deviceId) {
    case 1:
        wcmResult = func_021669B8();
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = func_02731A84();
            break;
        }
    default:
        wcmResult = 7;
        break;
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}
