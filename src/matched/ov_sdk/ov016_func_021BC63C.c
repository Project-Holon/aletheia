/*
 * function: func_021BC63C
 * address:  0x021BC63C
 * packet:   pkt_ov016_021BC63C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * U16 pass: the eight-store prefix (two of them duplicates) is now the six the
 * image wants, in the image's order - DAT.gMaxBssIdList, BSS.gAtermApState=7,
 * BSS.gAtermNotify, BSS.gAtermAlloc, BSS.gAtermFree, DAT.gThreadStackSize -
 * which takes the object from 236 bytes / 195 differing to 232 bytes (size
 * exact) / 18 differing.  Residue: the image loads both bases first
 * (`ldr r5,[pc]` DAT then `ldr r0,[pc]` BSS at +001A/+001C) and stores maxap
 * second; mwcc 2.0/sp1p2 (the object's 3.0.0.126 stamp) sinks that store to
 * the end of the run: image `+0020 str r1,[r5,#0x10]` | ours
 * `+002C str r1,[r5,#0x10]`.  Statement order, a volatile member and the
 * 2.0/base|sp1 trees do not move it.
 *
 * U64 (2026-09-30): CLOSED, byte-exact 232 B, 11/11 relocations.
 * The +001A..+002C residue was the order of the six global stores.  The object
 * emits them in source order - gMaxBssIdList, gAtermApState, gAtermNotify,
 * gAtermAlloc, gAtermFree, gThreadStackSize - with both pool bases hoisted to
 * the head of the block (DAT first), while ../2.0/sp1p2 sinks the two
 * g_021DAB58 stores into one run at the end of the block and loads that base
 * late.  Spelling all six stores as volatile-qualified lvalues
 * (`*(volatile int *)&DAT.gMaxBssIdList = maxap;` ...) pins the selection
 * order and closes the row.  Pointer locals, raw offsets, a named int copy of
 * maxap, splitting the guard and reordering the statements were all inert at
 * 19 diffs; ../2.0/base and ../2.0/sp1 are also 232/19 and 1.1p1 is 224.
 *
 * sdk:      ATERMi_ApConfigStart (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * symbols:
 *   func_021B97A8  0x021b97a8  thumb  ov016
 *   OS_IsThreadAvailable  0x020853b0  arm
 *   OS_CreateThread  0x020853c0  arm
 *   func_021BC584  0x021bc584  thumb  ov016
 *   func_021BC804  0x021bc804  thumb  ov016
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   g_021DCFD0  0x021dcfd0  data
 *   g_021DAB58  0x021dab58  data
 *   g_021DD07C  0x021dd07c  data
 *   func_021BABE8  0x021babe8  thumb  ov016
 *   gAtermsetBlock2  0x021dd13c  data
 */

#include "../../matched/arm9_sdk/libc/string.h"
#include "../include/G_ATERMSET_DATA.h"
#include "../include/G__ATERMApConfigParam.h"
#include "../include/G_ATERMSET_BSS.h"

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

extern struct ATERMSET_BSS g_021DCFD0;

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

extern struct ATERMSET_DATA g_021DAB58;

struct _OSThread;

extern struct _OSThread g_021DD07C;
extern struct _ATERMApConfigParam gAtermsetBlock2;

extern int func_021B97A8(int maxap);
extern int OS_IsThreadAvailable(void);
extern void OS_CreateThread(struct _OSThread *thread, void (*func)(void *), void *arg, void *stack, unsigned long stackSize, unsigned long prio);
extern unsigned long func_021BC584(void);
extern void func_021BC804(void);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern void func_021BABE8(void *arg);

#define BSS g_021DCFD0
#define DAT g_021DAB58

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
    if (OS_IsThreadAvailable() != 1) {
        BSS.gAtermApResult = -9;
        return -9;
    }
    OS_CreateThread(&g_021DD07C, func_021BABE8, 0, (unsigned char *)BSS.gThreadStack + (DAT.gThreadStackSize & ~7), DAT.gThreadStackSize, prio);
    BSS.gAtermApState = 1;
    DAT.gAtermApTimeout = func_021BC584() + 60000;
    BSS.bAtermApCanceled = 0;
    memset(&gAtermsetBlock2, 0, 232);
    func_021BC804();
    OS_WakeupThreadDirect(&g_021DD07C);
    BSS.gAtermThreadId = 1;
    return 1;
}
