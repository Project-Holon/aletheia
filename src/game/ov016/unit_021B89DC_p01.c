/*
 * file:     unit_021B89DC_p01.c
 * unit:     yes
 * function: func_021B8CFC, func_021B8D40
 * address:  0x021B8CFC
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
 *   WCM_LockApList   0x02165C28  arm
 *   WCM_CountApList  0x02165BD0  arm
 *   WCM_PointApList  0x02165CA0  arm
 *   MIi_CpuCopy32    0x02082A90  arm
 *   apc_bss               0x021DCF80  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   apci_bssid_buf        0x021DCFA8  data
 *   apci_essid_buf        0x021DCFB0  data
 *   WCM_Bssid_Any         0x021A1988  data
 *   WCM_Essid_Any         0x021A1990  data
 *   MI_CpuFill8           0x02082BCC  arm
 *   WCM_SearchAsync       0x02165144  arm
 *   APCi_MoveIdleState    0x021B8C94  thumb
 */
#include "../../matched/include/G_APC_BSS.h"

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

extern int WCM_LockApList(int lock);
extern int WCM_CountApList(void);
extern struct WMBssDesc *WCM_PointApList(unsigned short index);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
extern int APCi_MoveIdleState(void);
int APC_GetAPList(struct WMBssDesc *WMBssdescBuf, int list_max);
int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option);
extern struct APC_BSS apc_bss;
extern unsigned char apci_bssid_buf[6];
extern unsigned char apci_essid_buf[32];
extern unsigned char WCM_Bssid_Any[];
extern unsigned char WCM_Essid_Any[];


int APC_GetAPList(struct WMBssDesc *WMBssdescBuf, int list_max)
{
    int ap_count;
    int ap_index;
    struct WMBssDesc *wmbssdesc;
    struct WMBssDesc *dest;

    WCM_LockApList(1);
    ap_count = WCM_CountApList();
    if (ap_count > 0) {
        for (ap_index = 0; ap_index < ap_count; ap_index++) {
            if (ap_index >= list_max)
                break;
            wmbssdesc = WCM_PointApList(ap_index);
            dest = &WMBssdescBuf[ap_index];
            MIi_CpuCopy32(wmbssdesc, dest, sizeof(struct WMBssDesc));
        }
    }
    WCM_LockApList(0);
    return ap_count;
}


int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option)
{
    unsigned long enabled;
    int i;

    enabled = OS_DisableInterrupts();
    apc_bss.apci_search_option = option;
    if (bssid != 0) {
        for (i = 0; i < 6; i++)
            apci_bssid_buf[i] = *bssid++;
        apc_bss.apci_bssid_ptr = apci_bssid_buf;
    } else {
        MI_CpuFill8(apci_bssid_buf, 0xFF, 6);
        apc_bss.apci_bssid_ptr = WCM_Bssid_Any;
    }
    if (essid != 0 && essid_len > 0 && essid_len <= 32) {
        for (i = 0; i < essid_len; i++)
            apci_essid_buf[i] = *essid++;
        for (; i < 32; i++)
            apci_essid_buf[i] = 0;
        apc_bss.apci_essid_ptr = apci_essid_buf;
    } else {
        MI_CpuFill8(apci_essid_buf, 0xFF, 32);
        apc_bss.apci_essid_ptr = WCM_Essid_Any;
    }
    if (apc_bss.apci_state == 3) {
        if (WCM_SearchAsync(apc_bss.apci_bssid_ptr, apc_bss.apci_essid_ptr, apc_bss.apci_search_option) == 3) {
            apc_bss.apci_state = 6;
            OS_RestoreInterrupts(enabled);
            return 1;
        }
    } else if (APCi_MoveIdleState() == 1) {
        apc_bss.apci_state = 6;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}
