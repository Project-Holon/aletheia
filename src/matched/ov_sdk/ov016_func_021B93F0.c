/*
 * function: APC_SearchStart
 * address:  0x021B93F0
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
 *   WCM_Bssid_Any         0x021A1988  data
 *   WCM_Essid_Any         0x021A1990  data
 *   MI_CpuFill8           0x02082BCC  arm
 *   WCM_SearchAsync       0x02165144  arm
 *   APCi_MoveIdleState    0x021B9344  thumb
 *   apci_bssid_buf        0x021DD488  data
 *   apci_essid_buf        0x021DD4C0  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol APC_SearchStart (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Close to apc.o's copy (ov016_func_021B8D40.c): here the buffer pointers are set first,
 * the ESSID bound is < 32, and the search passes apci_bssid_buf itself, not apci_bssid_ptr.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B93F0.c \
 *       --func APC_SearchStart --addr 0x021B93F0 --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern unsigned char apci_bssid_buf[6];
extern unsigned char apci_essid_buf[32];
extern unsigned char WCM_Bssid_Any[];
extern unsigned char WCM_Essid_Any[];
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
extern int APCi_MoveIdleState(void);

int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option)
{
    unsigned long enabled;
    int i;

    enabled = OS_DisableInterrupts();
    atermset_bss.apci_search_option = option;
    atermset_bss.apci_bssid_ptr = apci_bssid_buf;
    if (bssid != 0) {
        for (i = 0; i < 6; i++)
            apci_bssid_buf[i] = *bssid++;
    } else {
        MI_CpuFill8(apci_bssid_buf, 0xFF, 6);
        atermset_bss.apci_bssid_ptr = WCM_Bssid_Any;
    }
    atermset_bss.apci_essid_ptr = apci_essid_buf;
    if (essid != 0 && essid_len > 0 && essid_len < 32) {
        for (i = 0; i < essid_len; i++)
            apci_essid_buf[i] = *essid++;
        for (; i < 32; i++)
            apci_essid_buf[i] = 0;
    } else {
        MI_CpuFill8(apci_essid_buf, 0xFF, 32);
        atermset_bss.apci_essid_ptr = WCM_Essid_Any;
    }
    if (atermset_bss.apci_state == 3) {
        if (WCM_SearchAsync(apci_bssid_buf, atermset_bss.apci_essid_ptr, atermset_bss.apci_search_option) == 3) {
            atermset_bss.apci_state = 6;
            OS_RestoreInterrupts(enabled);
            return 1;
        }
    } else if (APCi_MoveIdleState() == 1) {
        atermset_bss.apci_state = 6;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}
