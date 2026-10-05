/*
 * function: APC_Init
 * address:  0x021B95EC
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
 *   WCM_Init              0x02164D64  arm
 *   WCM_StartupAsync      0x02164F98  arm
 *   apci_user_callback    0x021DD050  data
 *   APCi_Notify           0x021B9038  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol APC_Init (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Same source as apc.o's copy (ov016_func_021B8F80.c); atermset.o keeps the APC statics in its own .bss.
 * The WEP descriptor at the front of the work buffer is 0x60 bytes where apc.o's is 0x50.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B95EC.c \
 *       --func APC_Init --addr 0x021B95EC --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern void (*apci_user_callback)(int event, void *arg);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

extern void APCi_Notify(void *arg);
extern int WCM_Init(void *buf, long len);
extern int WCM_StartupAsync(struct WCMConfig *config, void (*notify)(void *));

int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    atermset_bss.apci_Wep = workbuffer;
    atermset_bss.apci_IWConfig = (struct WCMConfig *)(((unsigned long)workbuffer + 0x60 + 3) & ~3);
    atermset_bss.apci_IWBuffer = (void *)(((unsigned long)atermset_bss.apci_IWConfig + sizeof(struct WCMConfig) + 0x1F) & ~0x1F);
    atermset_bss.apci_wmbssdesc = (void *)(((unsigned long)atermset_bss.apci_IWBuffer + 0x2300 + 0x1F) & ~0x1F);
    atermset_bss.apci_IWConfig->pbdbuffer = (void *)(((unsigned long)atermset_bss.apci_wmbssdesc + 0xC0 + 0x1F) & ~0x1F);
    atermset_bss.apci_IWConfig->nbdbuffer = ((unsigned long)workbuffer + work_size) - (unsigned long)atermset_bss.apci_IWConfig->pbdbuffer;
    atermset_bss.apci_IWConfig->nbdmode = 0;
    atermset_bss.apci_IWConfig->dmano = 3;
    apci_user_callback = user_callback;
    if (atermset_bss.apci_state == 0) {
        if (WCM_Init(atermset_bss.apci_IWBuffer, 0x2300) != 0) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        atermset_bss.apci_state = 1;
    }
    if (atermset_bss.apci_state == 1) {
        if (WCM_StartupAsync(atermset_bss.apci_IWConfig, APCi_Notify) != 3) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        atermset_bss.apci_state = 4;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}
