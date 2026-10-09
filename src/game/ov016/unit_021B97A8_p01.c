/*
 * file:     unit_021B97A8_p01.c
 * unit:     yes
 * function: func_021B97A8, func_021B984C, ConnectAP, DisconnectAP, func_021B9A2C
 * address:  0x021B97A8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   AtermApc_InitEventBuf  0x021B970C  thumb  ov016
 *   APC_Init  0x021B95EC  thumb  ov016
 *   OS_Sleep  0x02085A38  arm
 *   AtermApc_GetEvent  0x021B9734  thumb  ov016
 *   AtermApc_callback  0x021B976C  thumb  ov016
 *   atermset_bss  0x021DCFD0  data
 *   APC_End            0x021B9510  thumb
 *   atermset_data      0x021DAB58  data
 *   APC_Connect        0x021B9568  thumb
 *   OS_CreateAlarm     0x02087254  arm
 *   OS_SetAlarm        0x0208738C  arm
 *   GetTickCount       0x021BC584  thumb
 *   OS_CancelAlarm     0x020873F8  arm
 *   SOC_Startup        0x0215F8FC  arm
 *   alarmCallback      0x021B979C  thumb
 *   AtermSOConfig      0x021DAB6C  data
 *   APC_Disconnect     0x021B94D8  thumb
 *   SOC_Cleanup        0x0215FA90  arm
 *   memcpy  0x02092344  arm
 *   strlen  0x0209477C  arm
 *   memcmp  0x020923F0  arm
 *   g_021DABC4  0x021DABC4  data
 */
#include "../../matched/arm9_sdk/libc/memcmp/string.h"

struct WCMConfig;
struct _ATERMApConfigState;
struct WMBssDesc;
typedef unsigned char u8;

typedef unsigned long u32;

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

/*
 * atermset.o's .data words from 0x021DAB58 (lpElementData), addressed through
 * lpElementData's pool word plus an offset; member names are the vendor symbols.
 */
typedef struct {
    unsigned char *lpElementData;
    int            bDebug;
    unsigned long  gThreadStackSize;
    unsigned long  gAtermApTimeout;
    int            gMaxBssIdList;
} ATERMSET_DATA;

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

typedef struct SOCConfig SOCConfig;

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

extern void AtermApc_InitEventBuf(void);
extern int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
extern void OS_Sleep(unsigned long msec);
extern int AtermApc_GetEvent(void);
extern void AtermApc_callback(int event);
extern int APC_End(void);
extern void alarmCallback(void *arg);
extern int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option);
extern void OS_CreateAlarm(OSAlarm *alarm);
extern void OS_SetAlarm(OSAlarm *alarm, unsigned long long tick, void (*handler)(void *), void *arg);
extern unsigned long GetTickCount(void);
extern void OS_CancelAlarm(OSAlarm *alarm);
extern int SOC_Startup(SOCConfig *config);
extern int APC_Disconnect(void);
extern int SOC_Cleanup(void);
int InitAtermApcNetwork(int maxap);
int FreeAtermApcNetwork(void);
int ConnectAP(void);
void DisconnectAP(void);
extern ATERMSET_BSS atermset_bss;
extern ATERMSET_DATA atermset_data;
extern SOCConfig AtermSOConfig;
extern char g_021DABC4[7];



#define APC_WORK_SIZE(n) ((n) * 0xd0 + 0x2490)



#define ROUNDUP32(x) (((x) + 31LL) & ~31LL)





int InitAtermApcNetwork(int maxap)
{
    int loop_flag;
    int retv;

    loop_flag = 1;
    atermset_bss.gMaxApList = maxap;
    AtermApc_InitEventBuf();
    atermset_bss.atermapc_work = atermset_bss.gAtermAlloc(APC_WORK_SIZE(maxap) + 64 + maxap * sizeof(struct WMBssDesc));
    if (atermset_bss.atermapc_work == 0)
        return -1;
    atermset_bss.apc_work = (u8 *)ROUNDUP32((u32)atermset_bss.atermapc_work);
    atermset_bss.ap_list = (struct WMBssDesc *)ROUNDUP32((u32)atermset_bss.apc_work + APC_WORK_SIZE(maxap));
    if (APC_Init((void (*)(int, void *))AtermApc_callback, atermset_bss.apc_work, APC_WORK_SIZE(maxap)) == 0)
        return -2;
    do {
        int event;

        OS_Sleep(10);
        while ((event = AtermApc_GetEvent()) != 0) {
            switch (event) {
            case 4:
            case 5:
                break;
            case 6:
                loop_flag = 0;
                retv = 1;
                break;
            default:
                loop_flag = 0;
                retv = -2;
                break;
            }
        }
    } while (loop_flag);
    return retv;
}





int FreeAtermApcNetwork(void)
{
    int loop_flag;

    loop_flag = 1;
    if (APC_End()) {
        while (loop_flag) {
            int event;

            OS_Sleep(10);
            while ((event = AtermApc_GetEvent()) != 0) {
                switch (event) {
                case 4:
                case 5:
                    break;
                case 20:
                    loop_flag = 0;
                    break;
                default:
                    loop_flag = 0;
                    break;
                }
            }
        }
    }
    if (atermset_bss.atermapc_work) {
        atermset_bss.gAtermFree(atermset_bss.atermapc_work);
        atermset_bss.atermapc_work = 0;
    }
    return 1;
}




#define WMBSSDESC_SIZE 0xC0




int ConnectAP(void)
{
    int loop_flag;
    struct WMBssDesc *wmbssdesc;
    int ret;
    int retv;
    OSAlarm alarm;

    loop_flag = 1;
    retv = -2;
    wmbssdesc = (struct WMBssDesc *)((unsigned char *)atermset_bss.ap_list + atermset_bss.gAPId * WMBSSDESC_SIZE);
    if (wmbssdesc == 0)
        return 0;
    if (APC_Connect(wmbssdesc, 0, 0x30000) == 0)
        return -2;
    OS_CreateAlarm(&alarm);
    OS_SetAlarm(&alarm, 0x3FEC42, alarmCallback, (void *)0x12);
    while (loop_flag) {
        if (GetTickCount() >= atermset_data.gAtermApTimeout) {
            retv = -3;
            break;
        }
        if (atermset_bss.bAtermApCanceled) {
            retv = -8;
            break;
        }
        OS_Sleep(10);
        while ((ret = AtermApc_GetEvent()) != 0) {
            switch (ret) {
            case 4:
            case 5:
            case 18:
            case 19:
                break;
            case 12:
                loop_flag = 0;
                retv = 1;
                break;
            case 13:
                if (atermset_bss.bAtermApCanceled) {
                    loop_flag = 0;
                    retv = -8;
                } else if (APC_Connect(wmbssdesc, 0, 0x30000) == 0) {
                    return retv;
                }
                break;
            default:
                loop_flag = 0;
                break;
            }
        }
    }
    OS_CancelAlarm(&alarm);
    while (AtermApc_GetEvent() != 0)
        ;
    if (retv > 0) {
        atermset_bss.bApConnect = 1;
        if (SOC_Startup(&AtermSOConfig) < 0)
            retv = -2;
        else
            atermset_bss.bSO_Startup = 1;
    }
    return retv;
}



void DisconnectAP(void)
{
    int loop_flag;

    loop_flag = 1;
    if (atermset_bss.bApConnect) {
        if (APC_Disconnect()) {
            while (loop_flag) {
                int event;

                OS_Sleep(10);
                while ((event = AtermApc_GetEvent()) != 0) {
                    switch (event) {
                    case 4:
                    case 5:
                        break;
                    case 14:
                        loop_flag = 0;
                        break;
                    default:
                        loop_flag = 0;
                        break;
                    }
                }
            }
        }
        atermset_bss.bApConnect = 0;
    }
    if (atermset_bss.bSO_Startup) {
        atermset_bss.bSO_Startup = 0;
        SOC_Cleanup();
    }
}


/*
 * sdk:      CheckAccessPoint (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * atermset.o carries the 3.0.0.126 stamp (the 2.0/sp1p2 front end), as the other
 * atermset.o files do. memcmp must come from a header named string.h so the
 * inner loop keeps pOldList->NumberOfItems and SsidLength across the calls;
 * the libc/memcmp/string.h variant declares it. The DWARF places i in r6 (the
 * stealth scan over the old list); the other ranges of i share one stack slot.
 */
static int func_021B9A2C(BSSID_LIST *pNewList, BSSID_LIST *pOldList, unsigned long *ApNo)
{
    int flagDetect;
    int Result;
    int flagNew;
    int flagOld;
    WLAN_BSSID *pNewBss;
    WLAN_BSSID *pOldBss;
    unsigned long j;
    unsigned long i;

    flagDetect = 0;
    Result = 0;
    pNewBss = pNewList->Bssid;
    pOldBss = pOldList->Bssid;
    for (i = 0; i < pNewList->NumberOfItems; i++) {
        char newSSID[34] = {0};

        memcpy(newSSID, pNewBss->Ssid.Ssid, 32);
        newSSID[pNewBss->Ssid.SsidLength] = 0;
        for (j = 0; j < pOldList->NumberOfItems; j++) {
            if (pNewBss->Ssid.SsidLength == 0 || pNewBss->Ssid.SsidLength > 32)
                break;
            if (pNewBss->Ssid.SsidLength == 1 &&
                (pNewBss->Ssid.Ssid[0] == 0 || pNewBss->Ssid.Ssid[0] == ' '))
                break;
            if (memcmp(newSSID, pOldBss->Ssid.Ssid, strlen(newSSID)) == 0 &&
                memcmp(pNewBss->MacAddress, pOldBss->MacAddress, 6) == 0 &&
                pNewBss->Privacy != pOldBss->Privacy && pNewBss->Privacy == 0) {
                flagDetect = 1;
                break;
            }
            pOldBss++;
        }
        if (flagDetect)
            break;
        pNewBss++;
        pOldBss = pOldList->Bssid;
    }

    if (!flagDetect) {
        char newSSID[34] = {0};

        flagNew = 0;
        flagOld = 0;
        pNewBss = pNewList->Bssid;
        pOldBss = pOldList->Bssid;
        for (i = 0; i < pOldList->NumberOfItems; i++) {
            memcpy(newSSID, pOldBss->Ssid.Ssid, 32);
            newSSID[pOldBss->Ssid.SsidLength] = 0;
            if (memcmp(newSSID, g_021DABC4, strlen(g_021DABC4)) == 0 && pOldBss->Privacy == 0) {
                flagOld = 1;
                break;
            }
            pOldBss++;
        }
        for (i = 0; i < pNewList->NumberOfItems; i++) {
            memcpy(newSSID, pNewBss->Ssid.Ssid, 32);
            newSSID[pNewBss->Ssid.SsidLength] = 0;
            if (strlen(newSSID) == strlen(g_021DABC4) &&
                memcmp(newSSID, g_021DABC4, strlen(g_021DABC4)) == 0 && pNewBss->Privacy == 0) {
                flagNew = 1;
                break;
            }
            pNewBss++;
        }
        if (flagNew && !flagOld)
            flagDetect = 1;
    }
    if (flagDetect) {
        *ApNo = i;
        Result = 1;
    }
    return Result;
}
