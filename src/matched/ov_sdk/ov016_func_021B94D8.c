/*
 * function: APC_Disconnect
 * address:  0x021B94D8
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   atermset_bss          0x021DCFD0  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   WCM_DisconnectAsync   0x02165478  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol APC_Disconnect (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Same source as apc.o's copy (ov016_func_021B8E6C.c); atermset.o keeps the APC statics in its own .bss.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B94D8.c \
 *       --func APC_Disconnect --addr 0x021B94D8 --region ov016 --cc ../2.0/sp1p2 --thumb
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

struct WCMConfig {
    long  dmano;
    void *pbdbuffer;
    long  nbdbuffer;
    long  nbdmode;
};

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

extern int WCM_DisconnectAsync(void);

int APC_Disconnect(void)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (atermset_bss.apci_state == 7 && WCM_DisconnectAsync() == 3) {
        atermset_bss.apci_state = 4;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}
