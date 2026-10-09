/*
 * file:     unit_021B97A8_p02.c
 * unit:     yes
 * function: ScanAP, func_021B9E8C, func_021B9EA4
 * address:  0x021B9BF8
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p -ipa file
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   atermset_bss                   0x021DCFD0  data
 *   atermset_data                  0x021DAB58  data
 *   Calloc                         0x021BC5A0  thumb
 *   GetTickCount                   0x021BC584  thumb
 *   APC_SearchStart                0x021B93F0  thumb
 *   OS_CreateAlarm                 0x02087254  arm
 *   OS_SetAlarm                    0x0208738C  arm
 *   OS_Sleep                       0x02085A38  arm
 *   AtermApc_GetEvent              0x021B9734  thumb
 *   APC_GetAPList                  0x021B93AC  thumb
 *   OS_CancelAlarm                 0x020873F8  arm
 *   memcpy                         0x02092344  arm
 *   CheckAccessPoint               0x021B9A2C  thumb
 *   strcpy                         0x02094798  arm
 *   PutMac                         0x021BC608  thumb
 *   SendNotify                     0x021BC804  thumb
 *   Free                           0x021BC5C4  thumb
 *   alarmCallback                  0x021B979C  thumb
 *   btAutoResult                   0x021DCFD0  data
 *   lpElementData                  0x021DAB58  data
 *   gAPSSID                        0x021DD4E0  data
 *   gAPMac                         0x021DD480  data
 *   SOC_SendTo  0x0215F5B4  arm
 *   SOCL_GetHostID         0x0215EF48  arm
 *   SOC_U32to4U8           0x0215FBAC  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"

struct WCMConfig;
struct _ATERMApConfigState;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct OSiAlarm OSAlarm;

struct OSiAlarm {
    void             (*handler)(void *);
    void              *arg;
    unsigned long      tag;
    unsigned long long fire;
    OSAlarm           *prev;
    OSAlarm           *next;
    unsigned long long period;
    unsigned long long start;
};

typedef struct _NDIS_802_11_SSID {
    unsigned long SsidLength;
    unsigned char Ssid[32];
    unsigned char pad[4];
} NDIS_802_11_SSID;

typedef struct _WLAN_BSSID {
    NDIS_802_11_SSID Ssid;          /* +0x00 */
    unsigned char MacAddress[6];    /* +0x28 */
    unsigned short Privacy;         /* +0x2e */
} WLAN_BSSID;

typedef struct _BSSID_LIST {
    unsigned long NumberOfItems;
    WLAN_BSSID Bssid[1];
} BSSID_LIST;

typedef struct {
    unsigned short basic;
    unsigned short support;
} WMRateSet;

typedef struct WMBssDesc {
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
    unsigned char  gameInfo[0x80];
} WMBssDesc;

typedef struct {
    unsigned char             btAutoResult;
    void                   *(*gAtermAlloc)(unsigned long size);
    struct WCMConfig         *apci_IWConfig;
    void                    (*gAtermFree)(void *ptr);
    int                       bAtermApCanceled;
    int                       cbFrameData;
    int                       gAPId;
    int                       AutoPhase;
    int                       bApConnect;
    int                       bSO_Startup;
    unsigned char            *apci_Wep;
    int                       apci_state;
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

typedef struct {
    u8 *lpElementData;
    int bDebug;
    u32 gThreadStackSize;
    u32 gAtermApTimeout;
    int gMaxBssIdList;
} ATERMSET_DATA;

typedef struct {
    unsigned long addr;
} SOCInAddr;

typedef struct {
    unsigned char  len;
    unsigned char  family;
    unsigned short port;
    SOCInAddr      addr;
} SOCSockAddrIn;

extern void *Calloc(u32 nmemb, u32 size);
extern u32 GetTickCount(void);
extern int APC_SearchStart(u8 *bssid, u8 *essid, int essid_len, u32 option);
extern void OS_CreateAlarm(OSAlarm *alarm);
extern void OS_SetAlarm(OSAlarm *alarm, unsigned long long tick,
                        void (*handler)(void *), void *arg);
extern void OS_Sleep(u32 msec);
extern int AtermApc_GetEvent(void);
extern int APC_GetAPList(WMBssDesc *buf, int list_max);
extern void OS_CancelAlarm(OSAlarm *alarm);
extern int CheckAccessPoint(BSSID_LIST *pNewList, BSSID_LIST *pOldList, u32 *ApNo);
extern int PutMac(char *lpwrite, char *lps);
extern void SendNotify(void);
extern void Free(void *ptr);
extern void alarmCallback(void *event);
extern int SOC_SendTo(int s, void *buf, int len, int flags, void *sockTo);
extern unsigned long SOCL_GetHostID(void);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
int ScanAP(void);
int SendFrameViaInterface(int sock, SOCSockAddrIn *target, unsigned char *ipaddr, unsigned char *lpdata, int cbdata);
int SendBroadcast(int sock, unsigned char *lpb, int size);
extern ATERMSET_BSS atermset_bss;
extern ATERMSET_DATA atermset_data;
extern u8 gAPSSID[34];
extern u8 gAPMac[6];


int ScanAP(void)
{
    int retv;
    int retry;
    int i, n;
    unsigned long ApNo;
    unsigned long BssListSize;
    BSSID_LIST *pBssList;
    BSSID_LIST *pOldList;
    WLAN_BSSID *pBssid;
    char apBSSID[32];
    int loop_flag;
    OSAlarm alarm;
    int ap_count;
    int nfound;
    WMBssDesc *wmbssdesc;

    retv = -1;
    pOldList = 0;
    ApNo = 0;
    BssListSize = sizeof(BSSID_LIST) + atermset_bss.gMaxApList * sizeof(WLAN_BSSID);
    pBssList = Calloc(1, BssListSize);
    if (pBssList == 0)
        goto end;
    pOldList = Calloc(1, BssListSize);
    if (pOldList == 0)
        goto end;
    for (retry = 0; retry < 30 && !atermset_bss.bAtermApCanceled; retry++) {
        if (GetTickCount() >= atermset_data.gAtermApTimeout)
            break;
        if (APC_SearchStart(0, 0, 0, 0x30BFFE) == 0) {
            retv = -2;
            goto end;
        }
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0xFFB10, alarmCallback, (void *)0x13);
        loop_flag = 1;
        ap_count = 0;
        while (loop_flag) {
            OS_Sleep(10);
            if (GetTickCount() >= atermset_data.gAtermApTimeout)
                break;
            if (atermset_bss.bAtermApCanceled)
                break;
            while ((nfound = AtermApc_GetEvent()) != 0) {
                switch (nfound) {
                case 4:
                case 8:
                case 18:
                    break;
                case 19:
                    loop_flag = 0;
                    break;
                case 5:
                    nfound = APC_GetAPList(atermset_bss.ap_list, atermset_bss.gMaxApList);
                    if (nfound > ap_count) {
                        ap_count = nfound;
                        OS_CancelAlarm(&alarm);
                        OS_SetAlarm(&alarm, 0xFFB10, alarmCallback, (void *)0x13);
                    }
                    break;
                case 10:
                    loop_flag = 0;
                    break;
                case 1:
                case 2:
                case 3:
                case 6:
                case 7:
                case 9:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                default:
                    loop_flag = 0;
                    break;
                }
            }
        }
        OS_CancelAlarm(&alarm);
        while (AtermApc_GetEvent() != 0)
            ;
        if (atermset_bss.bAtermApCanceled)
            break;
        n = 0;
        if (ap_count >= atermset_bss.gMaxApList) {
            retv = -6;
            goto end;
        }
        for (i = 0, wmbssdesc = atermset_bss.ap_list; i < ap_count; i++, wmbssdesc++) {
            memcpy(pBssList->Bssid[n].Ssid.Ssid, wmbssdesc->ssid, 32);
            pBssList->Bssid[n].Ssid.SsidLength = wmbssdesc->ssidLength;
            pBssList->Bssid[n].Ssid.Ssid[wmbssdesc->ssidLength] = 0;
            pBssList->Bssid[n].Privacy = (wmbssdesc->capaInfo & 0x10) ? 1 : 0;
            memcpy(pBssList->Bssid[n].MacAddress, wmbssdesc->bssid, 6);
            n++;
        }
        pBssList->NumberOfItems = ap_count;
        if (atermset_bss.gAtermApState != 1 && CheckAccessPoint(pBssList, pOldList, &ApNo)) {
            pBssid = &pBssList->Bssid[ApNo];
            atermset_bss.gAPId = ApNo;
            strcpy((char *)gAPSSID, (char *)pBssid->Ssid.Ssid);
            memcpy(gAPMac, pBssid->MacAddress, 6);
            PutMac(apBSSID, (char *)gAPMac);
            break;
        }
        memcpy(pOldList, pBssList, BssListSize);
        atermset_bss.gAtermApState = 2;
        SendNotify();
    }
    if (retry >= 30 || GetTickCount() > atermset_data.gAtermApTimeout)
        retv = -3;
    else if (atermset_bss.bAtermApCanceled)
        retv = -8;
    else
        retv = 1;
end:
    if (pBssList)
        Free(pBssList);
    if (pOldList)
        Free(pOldList);
    return retv;
}



int SendFrameViaInterface(int sock, SOCSockAddrIn *target, unsigned char *ipaddr, unsigned char *lpdata, int cbdata)
{
    int ret;

    ret = SOC_SendTo(sock, lpdata, cbdata, 0, target);
    if (ret < 0)
        return -4;
    return ret;
}



int SendBroadcast(int sock, unsigned char *lpb, int size)
{
    int retv;
    SOCSockAddrIn target;
    unsigned char ipaddr[4];

    target.len = sizeof(target);
    target.family = 2;
    target.addr.addr = 0xFFFFFFFF;
    target.port = 0x1E6;
    SOC_U32to4U8(SOCL_GetHostID(), ipaddr);
    retv = SendFrameViaInterface(sock, &target, ipaddr, lpb, size);
    return retv;
}
