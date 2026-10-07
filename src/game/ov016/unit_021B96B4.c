/*
 * file:     unit_021B96B4.c
 * unit:     yes
 * function: func_021B96B4, func_021B96E4, func_021B970C, func_021B9734, func_021B976C
 * address:  0x021B96B4
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
 *   atermset_bss    0x021DCFD0  data
 *   OS_LockMutex    0x02086028  arm
 *   OS_UnlockMutex  0x02086078  arm
 *   AllocLock       0x021DD064  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   event_buf             0x021DD054  data
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

typedef struct OSMutex OSMutex;

extern void OS_LockMutex(OSMutex *mutex);
extern void OS_UnlockMutex(OSMutex *mutex);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern ATERMSET_BSS atermset_bss;
extern OSMutex AllocLock;
extern int event_buf[4];


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


static void soFree(unsigned long name, void *ptr, long size)
{
    if (ptr != 0 && size > 0) {
        OS_LockMutex(&AllocLock);
        atermset_bss.gAtermFree(ptr);
        OS_UnlockMutex(&AllocLock);
    }
}


static void AtermApc_InitEventBuf(void)
{
    int i;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    atermset_bss.event_set_ptr = 0;
    atermset_bss.event_get_ptr = 0;
    for (i = 0; i < 4; i++)
        event_buf[i] = 0;
    OS_RestoreInterrupts(enabled);
}


static int AtermApc_GetEvent(void)
{
    unsigned long enabled;
    int event;

    enabled = OS_DisableInterrupts();
    if (atermset_bss.event_set_ptr == atermset_bss.event_get_ptr) {
        event = 0;
    } else {
        event = event_buf[atermset_bss.event_get_ptr];
        atermset_bss.event_get_ptr++;
        if (atermset_bss.event_get_ptr >= 4)
            atermset_bss.event_get_ptr = 0;
    }
    OS_RestoreInterrupts(enabled);
    return event;
}


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
