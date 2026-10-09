/*
 * file:     unit_021BA2F8_p09.c
 * unit:     yes
 * function: PutHex, func_021BC608, func_021BC63C, ATERMi_ApConfigEnd, ATERMi_ApConfigGetState
 * address:  0x021BC5D4
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B97A8  0x021b97a8  thumb  ov016
 *   func_020853B0  0x020853b0  arm
 *   func_020853C0  0x020853c0  arm
 *   func_021BC584  0x021bc584  thumb  ov016
 *   func_021BC804  0x021bc804  thumb  ov016
 *   func_02085868  0x02085868  arm
 *   g_021DCFD0  0x021dcfd0  data
 *   g_021DAB58  0x021dab58  data
 *   g_021DD07C  0x021dd07c  data
 *   func_021BABE8  0x021babe8  thumb  ov016
 *   g_021DD13C  0x021dd13c  data
 *   atermset_bss           0x021DCFD0  data
 *   OS_Sleep               0x02085A38  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   OS_JoinThread          0x02085710  arm
 *   SendNotify             0x021BC804  thumb
 *   FreeAtermApcNetwork    0x021B984C  thumb
 *   gAtermThread           0x021DD07C  data
 *   atermset_data  0x021DAB58  data
 *   GetTickCount   0x021BC584  thumb
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G__ATERMApConfigParam.h"

#define BSS atermset_bss
#define DAT atermset_data
struct WCMConfig;
struct WMBssDesc;
struct _ATERMApConfigState;
struct _OSThread;
typedef struct {
    unsigned char             btAutoResult;
    void                   *(*gAtermAlloc)(unsigned long size);
    struct WCMConfig         *apci_IWConfig;
    void                    (*gAtermFree)(void *ptr);
    int                       bAtermApCanceled;
    int                       cbFrameData;
    int                       gAPId;
    int                       AutoPhase;          /* enum PHASE */
    int                       bApConnect;
    int                       bSO_Startup;
    unsigned char            *apci_Wep;
    int                       apci_state;         /* enum */
    unsigned long long       *gThreadStack;
    int                       cbElementData;
    int                       gAtermApState;
    unsigned char            *apci_IWBuffer;
    unsigned char            *apc_work;
    unsigned char            *apci_bssid_ptr;
    unsigned char            *apci_essid_ptr;
    struct WMBssDesc         *apci_wmbssdesc;
    int                       bDualCfg;
    unsigned char            *atermapc_work;
    unsigned long             apci_connect_option;
    struct WMBssDesc         *ap_list;
    unsigned long             apci_search_option;
    int                       gAtermThreadId;
    int                       event_set_ptr;
    int                       event_get_ptr;
    int                       gMaxApList;
    int                       bInitAtermApNetwork;
    int                       gAtermApResult;
    void                    (*gAtermNotify)(struct _ATERMApConfigState *state);
    void                    (*apci_user_callback)(int event, void *arg);
} ATERMSET_BSS;

/*
 * atermset.o's .data words from 0x021DAB58 (lpElementData), addressed through
 * lpElementData's pool word plus an offset; member names are the vendor symbols.
 */
typedef struct {
    unsigned char *lpElementData;
    int            bDebug;
    unsigned long  gThreadStackSize;
    unsigned long  gAtermApTimeout;
    int            gMaxBssIdList;
} ATERMSET_DATA;

typedef struct _OSThread OSThread;

typedef struct _ATERMApConfigState {
    int state;
    int timeout;
    int result;
} ATERMApConfigState;

extern int func_021B97A8(int maxap);
extern int func_020853B0(void);
extern void func_020853C0(struct _OSThread *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern unsigned long func_021BC584(void);
extern void func_021BC804(void);
extern void func_02085868(struct _OSThread *thread);
extern void func_021BABE8(void *arg);
extern void OS_Sleep(unsigned long msec);
extern int OS_IsThreadTerminated(OSThread *thread);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void OS_JoinThread(OSThread *thread);
extern void SendNotify(void);
extern int FreeAtermApcNetwork(void);
extern unsigned long GetTickCount(void);
int PutHex(char *lpwrite, char ch);
int PutMac(char *lpwrite, char *lps);
int func_021BC63C(int prio, int maxap, void (*notify)(struct _ATERMApConfigState *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize);
int ATERMi_ApConfigEnd(void);
int ATERMi_ApConfigGetState(ATERMApConfigState *state);
extern ATERMSET_DATA atermset_data;
extern struct _OSThread g_021DD07C;
extern struct _ATERMApConfigParam g_021DD13C;
extern ATERMSET_BSS atermset_bss;
extern OSThread gAtermThread;



int PutHex(char *lpwrite, char ch)
{
    char *lpw;
    int i;
    int val;

    lpw = lpwrite;
    val = ((unsigned char)ch & 0xF0) >> 4;
    for (i = 0; i < 2; i++) {
        if (val <= 9)
            val += '0';
        else
            val += 'A' - 10;
        *lpw++ = val;
        val = (unsigned char)ch & 0x0F;
    }
    *lpw = 0;
    return lpw - lpwrite;
}





int PutMac(char *lpwrite, char *lps)
{
    char *lpw;
    int i;

    lpw = lpwrite;
    for (i = 0; i < 6; i++) {
        lpw += PutHex(lpw, *lps++);
        if (i < 5)
            *lpw++ = ':';
    }
    *lpw = 0;
    return lpw - lpwrite;
}





int func_021BC63C(int prio, int maxap, void (*notify)(struct _ATERMApConfigState *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize)
{
    int ret;

    if (BSS.gAtermApState >= 1 && BSS.gAtermApState <= 5)
        return -10;
    *(volatile int *)&DAT.gMaxBssIdList = maxap;
    *(volatile int *)&BSS.gAtermApState = 7;
    *(volatile void **)&BSS.gAtermNotify = (void *)notify;
    *(volatile void **)&BSS.gAtermAlloc = (void *)alloc;
    *(volatile void **)&BSS.gAtermFree = (void *)free;
    *(volatile unsigned long *)&DAT.gThreadStackSize = stackSize;
    ret = func_021B97A8(maxap);
    BSS.bInitAtermApNetwork = 1;
    if (ret < 0) {
        BSS.gAtermApResult = ret;
        return ret;
    }
    BSS.gThreadStack = (unsigned long long *)BSS.gAtermAlloc(DAT.gThreadStackSize);
    if (BSS.gThreadStack == 0) {
        BSS.gAtermApResult = -1;
        return -1;
    }
    if (func_020853B0() != 1) {
        BSS.gAtermApResult = -9;
        return -9;
    }
    func_020853C0(&g_021DD07C, func_021BABE8, 0, (unsigned char *)BSS.gThreadStack + (DAT.gThreadStackSize & ~7), DAT.gThreadStackSize, prio);
    BSS.gAtermApState = 1;
    DAT.gAtermApTimeout = func_021BC584() + 60000;
    BSS.bAtermApCanceled = 0;
    memset(&g_021DD13C, 0, 232);
    func_021BC804();
    func_02085868(&g_021DD07C);
    BSS.gAtermThreadId = 1;
    return 1;
}



int ATERMi_ApConfigEnd(void)
{
    int retv;
    int laststate;

    if (atermset_bss.gAtermThreadId) {
        laststate = atermset_bss.gAtermApState;
        atermset_bss.bAtermApCanceled = 1;
        while (atermset_bss.gAtermApState >= 1 && atermset_bss.gAtermApState <= 5)
            OS_Sleep(100);
        OS_Sleep(500);
        while (!OS_IsThreadTerminated(&gAtermThread)) {
            OS_WakeupThreadDirect(&gAtermThread);
            OS_JoinThread(&gAtermThread);
        }
        if (atermset_bss.gThreadStack) {
            atermset_bss.gAtermFree(atermset_bss.gThreadStack);
            atermset_bss.gThreadStack = 0;
        }
        atermset_bss.gAtermThreadId = 0;
        if (laststate != atermset_bss.gAtermApState)
            SendNotify();
    }
    if (atermset_bss.bInitAtermApNetwork > 0) {
        retv = FreeAtermApcNetwork();
        atermset_bss.bInitAtermApNetwork = 0;
        return retv;
    }
    return -10;
}


int ATERMi_ApConfigGetState(ATERMApConfigState *state)
{
    state->state = atermset_bss.gAtermApState;
    if (atermset_data.gAtermApTimeout == -1)
        state->timeout = -1;
    else
        state->timeout = atermset_data.gAtermApTimeout - GetTickCount();
    state->result = atermset_bss.gAtermApResult;
    return 1;
}
