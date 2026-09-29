/*
 * function: func_021BC63C
 * address:  0x021BC63C
 * packet:   pkt_ov016_021BC63C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * sdk:      ATERMi_ApConfigStart (libdwcutil.TWL.HYB.a(atermset.o))
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
 */

#include "../../matched/arm9_sdk/libc/string.h"

struct WCMConfig;
struct WMBssDesc;
struct _ATERMApConfigState;

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
} ATERMSET_BSS;

extern ATERMSET_BSS g_021DCFD0;

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

extern ATERMSET_DATA g_021DAB58;

struct _OSThread;
typedef struct _ATERMApConfigParam {
    char ssid[32];
    int auth_mode;
    int wepkeyid;
    char wepkey[4][32];
    char wpakey[64];
} ATERMApConfigParam;

extern struct _OSThread g_021DD07C;
extern ATERMApConfigParam g_021DD13C;

extern int func_021B97A8(int maxap);
extern int func_020853B0(void);
extern void func_020853C0(struct _OSThread *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern unsigned long func_021BC584(void);
extern void func_021BC804(void);
extern void func_02085868(struct _OSThread *thread);
extern void func_021BABE8(void *arg);

#define BSS g_021DCFD0
#define DAT g_021DAB58

int func_021BC63C(int prio, int maxap, void (*notify)(struct _ATERMApConfigState *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stackSize)
{
    int ret;

    if (BSS.gAtermApState >= 1 && BSS.gAtermApState <= 5)
        return -10;
    BSS.gAtermNotify = notify;
    BSS.gAtermAlloc = alloc;
    DAT.gMaxBssIdList = maxap;
    BSS.gAtermApState = 7;
    BSS.gAtermNotify = notify;
    BSS.gAtermAlloc = alloc;
    BSS.gAtermFree = free;
    DAT.gThreadStackSize = stackSize;
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
