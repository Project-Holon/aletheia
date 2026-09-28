/*
 * function: AtermApc_callback
 * address:  0x021B976C
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   atermset_bss  0x021DCFD0  data
 *   event_buf     0x021DD054  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol AtermApc_callback (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B976C.c \
 *       --func AtermApc_callback --addr 0x021B976C --region ov016 --cc ../2.0/sp1p2 --thumb
 */
/*
 * atermset.o's .bss scalars from 0x021DCFD0 (btAutoResult): the vendor object addresses
 * every word here through btAutoResult's pool word plus an offset, so they are declared as
 * one object in the object's own order; member names are the vendor symbols. The arrays
 * and aggregates of the same section (event_buf, AllocLock, gAtermThread,
 * gAtermApConfigParam, AutoProfile) are pooled by their own symbols and declared apart.
 */
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

extern int event_buf[4];

static void AtermApc_callback(int event)
{
    if (atermset_bss.event_set_ptr + 1 == atermset_bss.event_get_ptr)
        return;
    if (atermset_bss.event_set_ptr == atermset_bss.event_get_ptr + 3)
        return;
    event_buf[atermset_bss.event_set_ptr] = event;
    atermset_bss.event_set_ptr++;
    if (atermset_bss.event_set_ptr >= 4)
        atermset_bss.event_set_ptr = 0;
}
