/*
 * function: DisconnectAP
 * address:  0x021B99C8
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   atermset_bss       0x021DCFD0  data
 *   APC_Disconnect     0x021B94D8  thumb
 *   OS_Sleep           0x02085A38  arm
 *   AtermApc_GetEvent  0x021B9734  thumb
 *   SOC_Cleanup        0x0215FA90  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol DisconnectAP (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B99C8.c \
 *       --func DisconnectAP --addr 0x021B99C8 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
/*
 * atermset.o's .bss scalars from 0x021DCFD0 (btAutoResult): the vendor object addresses
 * every word here through btAutoResult's pool word plus an offset, so they are declared as
 * one object in the object's own order; member names are the vendor symbols. The arrays
 * and aggregates of the same section (event_buf, AllocLock, gAtermThread,
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
    void                    (*apci_user_callback)(int event, void *arg);
} ATERMSET_BSS;

extern ATERMSET_BSS atermset_bss;

extern int APC_Disconnect(void);
extern void OS_Sleep(unsigned long msec);
extern int AtermApc_GetEvent(void);
extern int SOC_Cleanup(void);

void DisconnectAP(void)
{
    int loop_flag;

    loop_flag = 1;
    if (atermset_bss.bApConnect) {
        if (APC_Disconnect()) {
            while (loop_flag) {
                int event;

                OS_Sleep(10);
                while ((event = AtermApc_GetEvent()) != 0) {
                    switch (event) {
                    case 4:
                    case 5:
                        break;
                    case 14:
                        loop_flag = 0;
                        break;
                    default:
                        loop_flag = 0;
                        break;
                    }
                }
            }
        }
        atermset_bss.bApConnect = 0;
    }
    if (atermset_bss.bSO_Startup) {
        atermset_bss.bSO_Startup = 0;
        SOC_Cleanup();
    }
}
