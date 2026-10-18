/*
 * function: soAlloc
 * address:  0x021B96B4
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   atermset_bss    0x021DCFD0  data
 *   OS_LockMutex    0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   AllocLock       0x021DD064  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol soAlloc (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * DWARF leaves out the unused first parameter (SOCAlloc's name word).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B96B4.c \
 *       --func soAlloc --addr 0x021B96B4 --region ov016 --cc ../2.0/sp1p2 --thumb
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

typedef struct OSMutex OSMutex;
extern OSMutex AllocLock;
extern void OS_LockMutex(OSMutex *mutex);
extern void OS_UnlockMutex(OSMutex *mutex);

static void *soAlloc(unsigned long name, long size)
{
    void *ptr;

    if (size > 0) {
        OS_LockMutex(&AllocLock);
        ptr = atermset_bss.gAtermAlloc(size);
        OS_UnlockMutex(&AllocLock);
        return ptr;
    }
    return 0;
}
