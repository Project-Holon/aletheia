/*
 * function: ATERMi_ApConfigEnd
 * address:  0x021BC724
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   atermset_bss           0x021DCFD0  data
 *   OS_Sleep               0x02085A38  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   OS_JoinThread          0x02085710  arm
 *   SendNotify             0x021BC804  thumb
 *   FreeAtermApcNetwork    0x021B984C  thumb
 *   gAtermThread           0x021DD07C  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol ATERMi_ApConfigEnd (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BC724.c \
 *       --func ATERMi_ApConfigEnd --addr 0x021BC724 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
/*
 * atermset.o's .bss scalars from 0x021DCFD0 (btAutoResult): the vendor object addresses
 * every word here through btAutoResult's pool word plus an offset, so they are declared as
 * one object in the object's own order; member names are the vendor symbols. The arrays
 * and the pointer and aggregates of the same section (apci_user_callback, event_buf, AllocLock, gAtermThread,
 * gAtermApConfigParam, AutoProfile) are pooled by their own symbols and declared apart.
 */
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

extern ATERMSET_BSS atermset_bss;

typedef struct _OSThread OSThread;

extern OSThread gAtermThread;
extern void OS_Sleep(unsigned long msec);
extern int OS_IsThreadTerminated(OSThread *thread);
extern void OS_WakeupThreadDirect(OSThread *thread);
extern void OS_JoinThread(OSThread *thread);
extern void SendNotify(void);
extern int FreeAtermApcNetwork(void);

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
