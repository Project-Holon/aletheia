/*
 * file:     dwc_ac_beacon.c
 * unit:     yes
 * function: DWCi_AC_GetBeacon, DWCi_AC_CheckNintendoSSID, DWCi_AC_IsSupportWPA, CompareList, CompareListDiff, AddList, SetDataListTail, UpDateList, SortList
 * address:  0x0205A938
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_AC_GetMemPtr 0x0205C214 arm
 *   DWCi_AC_GetPhase 0x0205C2C4 arm
 *   DWCi_AC_SetStealthChannel 0x0205DF6C arm
 *   DWCi_AC_CheckNintendoUsbAP 0x0205EAFC arm
 *   DWCi_AC_CheckNintendoShopAP 0x0205EA08 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   NWM_GetInfoElements 0x02703208 arm
 *   NWM_GetVenderInfoElements 0x02703250 arm
 *   g_020A161C 0x020A161C data
 *   DWCi_AC_CheckNintendoSSID 0x0205AAB0 arm
 *   strncmp 0x020949F4 arm
 *   WCMi_BssDescCopy 0x02166040 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   DWCi_AC_IsSupportWPA 0x0205AB54 arm
 *   MIi_CpuClear32 0x02082A7C arm
 */
#include "../sdk_ncfg.h"

#include "../sdk_wm.h"

typedef struct {
    unsigned char state;
    unsigned char type;
    unsigned char rssi;
    unsigned char channel:7;
    unsigned char find:1;
} ACFL;

typedef struct {
    unsigned char find:4;
    unsigned char duplicate:4;
    unsigned char type;
    unsigned char channel;
    unsigned char length;
    unsigned char ssid[32];
} ACSL;

typedef struct {
    unsigned char mode;
    unsigned char keyId;
    unsigned char key[80];
} WCMWepDesc;

typedef struct {
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx userInfoEx[3];
    ACSL searchList[21];
    ACFL findList[11];
    WMBssDesc bssDesc[11];
    unsigned long long timeOut;
    WCMWepDesc wepKey;
    unsigned char dmaNo;
    unsigned char powerMode:2;
    unsigned char authMode:2;
    unsigned char aroundCount:4;
    unsigned char connectType:4;
    unsigned char skipNetCheck:1;
    unsigned char useDSWireless:1;
    unsigned char duplicateFlag:1;
    unsigned char wpaSetting:1;
    unsigned char connectApType;
    unsigned char phaseBak;
    unsigned char searchListNo;
    unsigned char searchListNum;
    signed char searchChannel;
    unsigned char findListNum;
    unsigned char connectNo;
    unsigned char connectResult;
    unsigned char count;
    unsigned short stealthChannel;
    long rwin;
    unsigned char wontExecuteEULACheck;
    unsigned short maxChannel;
    unsigned char padding;
    unsigned short passiveScanTime;
    unsigned short activeScanTime;
} ACWORK;

typedef struct {
    unsigned char pad[0xb];
    unsigned char beacon:4;
} ACHOLD;

typedef struct WCMBssDesc WCMBssDesc;

typedef struct NWMInfoElements NWMInfoElements;

typedef struct {
    unsigned char b[4];
} WPATAG;

#include "dwc_ac.h"
#include "dwc_ac_search.h"
#include "dwc_ac_shop_usb.h"
#include "os_emulator.h"
#include "../twl/nwm_startscan.h"
extern int DWCi_AC_CheckNintendoSSID(WMBssDesc *bssdesc);
extern int strncmp(const char *s1, const char *s2, unsigned long n) __attribute__((pure));
#include "../ov009/wcm_aplist.h"
#include "mi_memory.h"
extern int DWCi_AC_IsSupportWPA(WMBssDesc *bssDesc);
void DWCi_AC_GetBeacon(WMBssDesc *bssdesc);
int CompareList(WMBssDesc *bssdesc, unsigned char num, ACSL *list);
int CompareListDiff(WMBssDesc *bssdesc, ACWORK *wk);
int AddList(int type, WMBssDesc *bssdesc, unsigned char channel, ACWORK *wk);
void SetDataListTail(unsigned char type, WMBssDesc *bssdesc, unsigned char channel, ACWORK *wk);
void UpDateList(int no, WMBssDesc *bssdesc, unsigned char channel, ACWORK *wk);
void SortList(int no, ACWORK *wk);
extern const WPATAG g_020A161C;


/*
 * sdk:      DWCi_AC_GetBeacon (beacon.o)
 */
void DWCi_AC_GetBeacon(WMBssDesc *bssdesc)
{
    int ap_type = -1;
    unsigned char channel;
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);
    int no;

    hd->beacon = 1;
    switch (DWCi_AC_GetPhase()) {
    case 3:
        channel = wk->searchChannel;
        if (bssdesc->ssidLength == 0 || bssdesc->ssid[0] == 0) {
            DWCi_AC_SetStealthChannel(bssdesc->channel);
        } else if (bssdesc->ssidLength == 1 && bssdesc->ssid[0] == 0x20) {
            DWCi_AC_SetStealthChannel(bssdesc->channel);
            ap_type = CompareList(bssdesc, wk->searchListNum, wk->searchList);
        } else {
            ap_type = CompareList(bssdesc, wk->searchListNum, wk->searchList);
        }
        break;
    case 4:
        channel = wk->bssDesc[wk->searchListNo].channel - 1;
        ap_type = CompareListDiff(bssdesc, wk);
        if (ap_type >= 0) {
            wk->findList[wk->searchListNo].find = 1;
        }
        break;
    case 5:
        channel = wk->searchChannel;
        ap_type = CompareList(bssdesc, 1, &wk->searchList[wk->searchListNo]);
        if (ap_type >= 0) {
            wk->searchList[wk->searchListNo].find = 1;
        }
        break;
    default:
        return;
    }
    if (ap_type >= 0) {
        no = AddList(ap_type, bssdesc, channel, wk);
        SortList(no, wk);
    }
}


/*
 * sdk:      DWCi_AC_CheckNintendoSSID (beacon.o)
 */
int DWCi_AC_CheckNintendoSSID(WMBssDesc *bssdesc)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);

    if ((wk->connectType == 0 || wk->connectType == 4) && ((bssdesc->capaInfo >> 4) & 1) == 1) {
        if (DWCi_AC_CheckNintendoUsbAP((char *)bssdesc->ssid) == 1) {
            return 0x12;
        }
    }
    if ((wk->connectType == 0 || wk->connectType == 5) && ((bssdesc->capaInfo >> 4) & 1) == 1) {
        if (DWCi_AC_CheckNintendoShopAP((char *)bssdesc->ssid) == 1) {
            return 0x13;
        }
    }
    return -1;
}


/*
 * sdk:      DWCi_AC_IsSupportWPA (beacon.o)
 *
 * g_020A161C is the initialiser of wpaTag (@16091: 00 50 F2 01, the WPA OUI
 * and type); the object copies it bytewise, spelled here as a struct copy.
 */
int DWCi_AC_IsSupportWPA(WMBssDesc *bssDesc)
{
    WPATAG wpaTag;
    NWMInfoElements *elem;

    if (OS_IsRunOnTwl()) {
        elem = (struct NWMInfoElements *)NWM_GetInfoElements((unsigned char *)bssDesc, 0x30);
        if (elem == 0) {
            wpaTag = g_020A161C;
            elem = (struct NWMInfoElements *)NWM_GetVenderInfoElements((unsigned char *)bssDesc, 0xdd, wpaTag.b);
            if (elem == 0) {
                return 0;
            }
        }
    }
    return 1;
}


/*
 * sdk:      CompareList (beacon.o)
 *
 * strncmp is declared pure: the object keeps loads of *bssdesc (and of wk)
 * live across the call, which only a side-effect-free callee allows.
 */
int CompareList(WMBssDesc *bssdesc, unsigned char num, ACSL *list)
{
    int i;
    int type;

    if (bssdesc->ssidLength == 32 && (type = DWCi_AC_CheckNintendoSSID(bssdesc)) > 0) {
        return type;
    }
    for (i = 0; i < num; i++, list++) {
        if ((unsigned char)bssdesc->ssidLength == list->length
            && strncmp((char *)bssdesc->ssid, (char *)list->ssid, bssdesc->ssidLength) == 0) {
            return list->type;
        }
    }
    return -1;
}


/*
 * sdk:      CompareListDiff (beacon.o)
 *
 * strncmp is declared pure: the object keeps loads of *bssdesc (and of wk)
 * live across the call, which only a side-effect-free callee allows.
 */
int CompareListDiff(WMBssDesc *bssdesc, ACWORK *wk)
{
    int i;
    int type;

    if (bssdesc->ssidLength == 32 && (type = DWCi_AC_CheckNintendoSSID(bssdesc)) > 0) {
        return type;
    }
    for (i = 0; i < wk->findListNum; i++) {
        if (bssdesc->ssidLength == wk->bssDesc[i].ssidLength
            && strncmp((char *)bssdesc->ssid, (char *)wk->bssDesc[i].ssid, bssdesc->ssidLength) == 0) {
            return wk->findList[i].type;
        }
    }
    return -1;
}


static inline int IsBssidEqual(const void *a, const void *b)
{
    return ((const unsigned char *)a)[0] == ((const unsigned char *)b)[0] && ((const unsigned char *)a)[1] == ((const unsigned char *)b)[1] && ((const unsigned char *)a)[2] == ((const unsigned char *)b)[2] && ((const unsigned char *)a)[3] == ((const unsigned char *)b)[3] && ((const unsigned char *)a)[4] == ((const unsigned char *)b)[4] && ((const unsigned char *)a)[5] == ((const unsigned char *)b)[5];
}


/*
 * sdk:      AddList (beacon.o)
 *
 * strncmp is declared pure: the object keeps bssid[0] and findListNum live
 * across the call. The BSSID compare is an inline over const void pointers.
 */
int AddList(int type, WMBssDesc *bssdesc, unsigned char channel, ACWORK *wk)
{
    int i;
    int find = -1;

    for (i = 0; i < wk->findListNum; i++) {
        if (IsBssidEqual(bssdesc->bssid, wk->bssDesc[i].bssid)
            && strncmp((char *)bssdesc->ssid, (char *)wk->bssDesc[i].ssid, bssdesc->ssidLength) == 0) {
            find = i;
            break;
        }
    }
    if (find == -1) {
        SetDataListTail(type, bssdesc, channel, wk);
        if (wk->findListNum < 10) {
            wk->findListNum++;
        }
        find = 10;
    } else {
        UpDateList(find, bssdesc, channel, wk);
    }
    return find;
}


/*
 * sdk:      SetDataListTail (beacon.o)
 */
void SetDataListTail(unsigned char type, WMBssDesc *bssdesc, unsigned char channel, ACWORK *wk)
{
    WMBssDesc *bssdesc_end = &wk->bssDesc[10];
    ACFL *list_end = &wk->findList[10];
    unsigned short rssi;

    list_end->type = type;
    rssi = bssdesc->rssi;
    if (wk->useDSWireless == 1) {
        if (rssi & 2) {
            rssi = (unsigned char)(rssi >> 2);
        } else {
            rssi = (unsigned char)((rssi >> 2) + 25);
        }
    }
    list_end->rssi = rssi;
    list_end->channel = channel;
    WCMi_BssDescCopy(bssdesc, bssdesc_end);
}


/*
 * sdk:      UpDateList (beacon.o)
 */
void UpDateList(int no, WMBssDesc *bssdesc, unsigned char channel, ACWORK *wk)
{
    ACFL *list = &wk->findList[no];
    WMBssDesc *bssdesc_no = &wk->bssDesc[no];
    unsigned short rssi;

    rssi = bssdesc->rssi;
    if (wk->useDSWireless == 1) {
        if (rssi & 2) {
            rssi = (unsigned char)(rssi >> 2);
        } else {
            rssi = (unsigned char)((rssi >> 2) + 25);
        }
    }
    if ((unsigned char)rssi > list->rssi) {
        list->rssi = rssi;
        list->channel = channel;
    }
    MIi_CpuCopy32(bssdesc, bssdesc_no, sizeof(WMBssDesc));
}


/*
 * sdk:      SortList (beacon.o)
 */
void SortList(int no, ACWORK *wk)
{
    int i;
    ACFL list_buf;
    WMBssDesc bssdesc_buf;
    ACFL *list = wk->findList;
    WMBssDesc *bssdesc = wk->bssDesc;
    int swap;

    for (i = no - 1; i >= 0; i--) {
        swap = 0;
        if (wk->wpaSetting == 1 && DWCi_AC_IsSupportWPA(&bssdesc[no]) == 1) {
            if (list[no].rssi < list[i].rssi) {
                if (DWCi_AC_IsSupportWPA(&bssdesc[i]) == 0)
                    swap = 1;
            } else {
                swap = 1;
            }
        } else if (list[no].type >= 0x13 && list[no].type <= 0x16) {
            if (list[no].rssi >= list[i].rssi) {
                if ((list[i].type >= 0x13 && list[i].type <= 0x16)
                    || list[i].state + list[i].type + list[i].rssi + list[i].channel + list[i].find == 0)
                    swap = 1;
            }
        } else {
            if (list[no].rssi >= list[i].rssi) {
                if (wk->wpaSetting == 1) {
                    if (DWCi_AC_IsSupportWPA(&bssdesc[i]) == 0)
                        swap = 1;
                } else {
                    swap = 1;
                }
            } else if (list[i].type >= 0x13 && list[i].type <= 0x16) {
                swap = 1;
            }
        }
        if (swap == 1) {
            MIi_CpuCopy32(&list[i], &list_buf, sizeof(ACFL));
            MIi_CpuCopy32(&list[no], &list[i], sizeof(ACFL));
            MIi_CpuCopy32(&list_buf, &list[no], sizeof(ACFL));
            MIi_CpuCopy32(&bssdesc[i], &bssdesc_buf, sizeof(WMBssDesc));
            MIi_CpuCopy32(&bssdesc[no], &bssdesc[i], sizeof(WMBssDesc));
            MIi_CpuCopy32(&bssdesc_buf, &bssdesc[no], sizeof(WMBssDesc));
            no = i;
        }
    }
    MIi_CpuClear32(0, &list[10], sizeof(ACFL));
    MIi_CpuClear32(0, &bssdesc[10], sizeof(WMBssDesc));
}
