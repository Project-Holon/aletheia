/*
 * function: APC_Connect
 * address:  0x021B9568
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
 *   MI_CpuCopy8           0x02082D44  arm
 *   MI_CpuFill8           0x02082BCC  arm
 *   MIi_CpuCopy32         0x02082A90  arm
 *   WCM_ConnectAsync      0x021652A4  arm
 *   APCi_MoveIdleState    0x021B9344  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol APC_Connect (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Same source as apc.o's copy (ov016_func_021B8EFC.c); atermset.o keeps the APC statics in its own .bss.
 * The WEP descriptor copied here is 0x60 bytes where apc.o's is 0x50.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B9568.c \
 *       --func APC_Connect --addr 0x021B9568 --region ov016 --cc ../2.0/sp1p2 --thumb
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

struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
};

struct wlla_rateset {
    unsigned long Count;
    unsigned char Rate[16];
};

struct wlla_bss_info {
    struct wlla_ssid    Ssid;
    unsigned long       Channel;
    unsigned long       Noise;
    unsigned long       Signal;
    unsigned char       Bssid[6];
    struct wlla_rateset SupportRates;
    unsigned long       BeaconPeriod;
    unsigned long       Capability;
};

typedef struct {
    unsigned short basic;
    unsigned short support;
} WMRateSet;

struct WMBssDesc {
    unsigned short length;
    unsigned short rssi;
    unsigned char  bssid[6];
    unsigned short ssidLength;
    unsigned char  ssid[32];
    unsigned short capaInfo;
    WMRateSet      rateSet;
    unsigned short beaconPeriod;
    unsigned short dtimPeriod;
    unsigned short channel;
    unsigned short cfpPeriod;
    unsigned short cfpMaxDuration;
    unsigned short gameInfoLength;
    unsigned short otherElementCount;
    unsigned char  gameInfo[0x80];   /* struct WMGameInfo, not needed here */
};

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);
extern int APCi_MoveIdleState(void);
extern int WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option);

int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    atermset_bss.apci_connect_option = option;
    if (wep_buf != 0)
        MI_CpuCopy8(wep_buf, atermset_bss.apci_Wep, 0x60);
    else
        MI_CpuFill8(atermset_bss.apci_Wep, 0, 0x60);
    MIi_CpuCopy32(wmbssdesc, atermset_bss.apci_wmbssdesc, sizeof(struct WMBssDesc));
    if (APCi_MoveIdleState() == 1) {
        atermset_bss.apci_state = 8;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (atermset_bss.apci_state == 3 &&
        WCM_ConnectAsync(atermset_bss.apci_wmbssdesc, atermset_bss.apci_Wep, atermset_bss.apci_connect_option) == 3) {
        atermset_bss.apci_state = 8;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}
