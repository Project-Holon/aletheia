/*
 * file:     unit_02164D64_p03.c
 * unit:     yes
 * function: func_02165144, func_02165164, func_02165204
 * address:  0x02165144
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02166A24  0x02166A24  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_02731AF0  0x02731AF0  arm  twl
 *   g_021AA7D4  0x021AA7D4  data ov009
 *   func_02165A4C  0x02165A4C  arm  ov009
 */
#include "../../matched/include/G_WCMState.h"

typedef struct WCMWork_02165164 {
    unsigned char pad0[0x12DF];
    unsigned char deviceId;
} WCMWork_02165164;

typedef struct WCMState WCMState;

typedef struct WCMWork_02165204 {
    unsigned char pad0[0x12DA];
    unsigned short notify;
    unsigned char pad1[2];
    unsigned char phase;
} WCMWork_02165204;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern long func_02166A24(void *bssid, void *essid, unsigned long option);
extern int OS_IsRunOnTwl(void);
extern long func_02731AF0(void *bssid, void *essid, unsigned long option);
extern void func_02165A4C(unsigned char phase);
void func_02165144(void *a, void *b, unsigned long a2);
long func_02165164(void *bssid, void *essid, unsigned long option);
long func_02165204(int a, int b);
extern struct WCMState g_021AA7D4;


/*
 * Dispatches on whether either argument is missing.
 */
void func_02165144(void *a, void *b, unsigned long a2)
{
    if (a == 0 || b == 0) {
        func_02165204((int)a, (int)b);
        return;
    }

    func_02165164(a, b, a2);
}


long func_02165164(void *bssid, void *essid, unsigned long option)
{
    long wcmResult;
    unsigned long e;

    e = OS_DisableInterrupts();
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (((WCMWork_02165164 *)g_021AA7D4.work)->deviceId) {
    case 1:
        wcmResult = func_02166A24(bssid, essid, option);
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            wcmResult = func_02731AF0(bssid, essid, option);
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
long func_02165204(int a, int b)
{
    unsigned long e;

    e = OS_DisableInterrupts();
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (((WCMWork_02165204 *)g_021AA7D4.work)->phase) {
    case 6:
        func_02165A4C(7);
        ((WCMWork_02165204 *)g_021AA7D4.work)->notify = 4;
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
