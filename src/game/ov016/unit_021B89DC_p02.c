/*
 * file:     unit_021B89DC_p02.c
 * unit:     yes
 * function: func_021B8E30, func_021B8E6C, func_021B8EA4, func_021B8EFC, func_021B8F80
 * address:  0x021B8E30
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
 *   apc_bss               0x021DCF80  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   WCM_SearchAsync       0x02165144  arm
 *   WCM_DisconnectAsync   0x02165478  arm
 *   WCM_CleanupAsync      0x02165088  arm
 *   APCi_MoveIdleState    0x021B8C94  thumb
 *   MI_CpuCopy8           0x02082D44  arm
 *   MI_CpuFill8           0x02082BCC  arm
 *   MIi_CpuCopy32         0x02082A90  arm
 *   WCM_ConnectAsync      0x021652A4  arm
 *   APCi_Notify           0x021B89DC  thumb
 *   WCM_Init              0x02164D64  arm
 *   WCM_StartupAsync      0x02164F98  arm
 */
#include "../../matched/include/G_APC_BSS.h"

typedef struct {
    long  dmano;
    void *pbdbuffer;
    long  nbdbuffer;
    long  nbdmode;
} WCMConfig;

/*
 * apc.o's .bss statics from 0x021DCF80 (the ten words before apci_bssid_buf): the
 * vendor object addresses them through apci_WCMBuffer's pool word plus an offset, so
 * they are declared as one object in the object's own order; members are the vendor names.
 */
typedef struct {
    void          *apci_WCMBuffer;        /* +0x00 */
    unsigned long  apci_search_option;    /* +0x04 */
    WCMConfig     *apci_WCMConfig;        /* +0x08 */
    unsigned long  apci_connect_option;   /* +0x0C */
    unsigned char *apci_bssid_ptr;        /* +0x10 */
    unsigned char *apci_essid_ptr;        /* +0x14 */
    int            apci_state;            /* +0x18 */
    void         (*apci_user_callback)(int, void *); /* +0x1C */
    void          *apci_wmbssdesc;        /* +0x20 */
    unsigned char *apci_Wep;              /* +0x24 */
} APC_BSS;

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
extern int WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
extern int WCM_DisconnectAsync(void);
extern int WCM_CleanupAsync(void);
extern int APCi_MoveIdleState(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);
extern int WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option);
extern void APCi_Notify(void *arg);
extern int WCM_Init(void *buf, long len);
extern int WCM_StartupAsync(WCMConfig *config, void (*notify)(void *));
int APC_SearchEnd(void);
int APC_Disconnect(void);
int APC_End(void);
int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option);
int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
extern struct APC_BSS apc_bss;


int APC_SearchEnd(void)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (apc_bss.apci_state == 5 && WCM_SearchAsync(0, 0, 0) == 3) {
        apc_bss.apci_state = 4;
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
    if (apc_bss.apci_state == 7 && WCM_DisconnectAsync() == 3) {
        apc_bss.apci_state = 4;
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
    if (apc_bss.apci_state == 3) {
        if (WCM_CleanupAsync() != 3) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        apc_bss.apci_state = 2;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (APCi_MoveIdleState() == 1) {
        apc_bss.apci_state = 2;
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
    apc_bss.apci_connect_option = option;
    if (wep_buf != 0)
        MI_CpuCopy8(wep_buf, apc_bss.apci_Wep, 0x50);
    else
        MI_CpuFill8(apc_bss.apci_Wep, 0, 0x50);
    MIi_CpuCopy32(wmbssdesc, apc_bss.apci_wmbssdesc, sizeof(struct WMBssDesc));
    if (APCi_MoveIdleState() == 1) {
        apc_bss.apci_state = 8;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (apc_bss.apci_state == 3 &&
        WCM_ConnectAsync(apc_bss.apci_wmbssdesc, apc_bss.apci_Wep, apc_bss.apci_connect_option) == 3) {
        apc_bss.apci_state = 8;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}


int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    apc_bss.apci_Wep = workbuffer;
    apc_bss.apci_WCMConfig = (WCMConfig *)(((unsigned long)workbuffer + 0x50 + 3) & ~3);
    apc_bss.apci_WCMBuffer = (void *)(((unsigned long)((WCMConfig *)apc_bss.apci_WCMConfig) + sizeof(WCMConfig) + 0x1F) & ~0x1F);
    apc_bss.apci_wmbssdesc = (void *)(((unsigned long)apc_bss.apci_WCMBuffer + 0x2300 + 0x1F) & ~0x1F);
    ((WCMConfig *)apc_bss.apci_WCMConfig)->pbdbuffer = (void *)(((unsigned long)apc_bss.apci_wmbssdesc + 0xC0 + 0x1F) & ~0x1F);
    ((WCMConfig *)apc_bss.apci_WCMConfig)->nbdbuffer = ((unsigned long)workbuffer + work_size) - (unsigned long)((WCMConfig *)apc_bss.apci_WCMConfig)->pbdbuffer;
    ((WCMConfig *)apc_bss.apci_WCMConfig)->nbdmode = 0;
    ((WCMConfig *)apc_bss.apci_WCMConfig)->dmano = 3;
    apc_bss.apci_user_callback = user_callback;
    if (apc_bss.apci_state == 0) {
        if (WCM_Init(apc_bss.apci_WCMBuffer, 0x2300) != 0) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        apc_bss.apci_state = 1;
    }
    if (apc_bss.apci_state == 1) {
        if (WCM_StartupAsync(apc_bss.apci_WCMConfig, APCi_Notify) != 3) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        apc_bss.apci_state = 4;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}
