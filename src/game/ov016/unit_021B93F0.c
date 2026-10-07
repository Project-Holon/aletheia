/*
 * file:     unit_021B93F0.c
 * unit:     yes
 * function: func_021B93F0, func_021B94D8, func_021B9510, func_021B9568, func_021B95EC
 * address:  0x021B93F0
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
 *   WCM_DisconnectAsync   0x02165478  arm
 *   WCM_CleanupAsync      0x02165088  arm
 *   MI_CpuCopy8           0x02082D44  arm
 *   MIi_CpuCopy32         0x02082A90  arm
 *   WCM_ConnectAsync      0x021652A4  arm
 *   WCM_Init              0x02164D64  arm
 *   WCM_StartupAsync      0x02164F98  arm
 *   apci_user_callback    0x021DD050  data
 *   APCi_Notify           0x021B9038  thumb
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

struct WCMConfig {
    long  dmano;
    void *pbdbuffer;
    long  nbdbuffer;
    long  nbdmode;
};

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

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
extern int APCi_MoveIdleState(void);
extern int WCM_DisconnectAsync(void);
extern int WCM_CleanupAsync(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);
extern int WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option);
extern void APCi_Notify(void *arg);
extern int WCM_Init(void *buf, long len);
extern int WCM_StartupAsync(struct WCMConfig *config, void (*notify)(void *));
int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option);
int APC_Disconnect(void);
int APC_End(void);
int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option);
int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
extern ATERMSET_BSS atermset_bss;
extern unsigned char apci_bssid_buf[6];
extern unsigned char apci_essid_buf[32];
extern unsigned char WCM_Bssid_Any[];
extern unsigned char WCM_Essid_Any[];


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


int APC_End(void)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (atermset_bss.apci_state == 3) {
        if (WCM_CleanupAsync() != 3) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        atermset_bss.apci_state = 2;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (APCi_MoveIdleState() == 1) {
        atermset_bss.apci_state = 2;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}


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


extern void (*apci_user_callback)(int event, void *arg);


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
