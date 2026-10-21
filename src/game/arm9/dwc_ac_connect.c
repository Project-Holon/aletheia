/*
 * file:     dwc_ac_connect.c
 * unit:     yes
 * function: DWCi_AC_ConnectAP, ConnectStart, ConnectAP, GetConnectType, GetPowerMode, GetAuthMode, GetWepKey
 * address:  0x0205B33C
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
 *   DWCi_AC_GetPhase 0x0205C2C4 arm
 *   DWCi_AC_GetMemPtr 0x0205C214 arm
 *   ConnectStart 0x0205B37C arm
 *   ConnectAP 0x0205B488 arm
 *   GetConnectType 0x0205B5EC arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GetWepKey 0x0205B7D0 arm
 *   WCM_GetPhase 0x021656A0 arm
 *   GetPowerMode 0x0205B790 arm
 *   GetAuthMode 0x0205B7B0 arm
 *   WCM_ConnectAsync 0x021652A4 arm
 *   OS_GetTick 0x020870D0 arm
 *   DWCi_AC_SetError 0x0205C2E4 arm
 *   DWCi_AC_GetSearchListNum 0x0205D434 arm
 *   DWCi_AC_CheckNintendoSSID 0x0205AAB0 arm
 *   DWCi_AC_CheckFreespot 0x0205D3E0 arm
 *   strncmp 0x020949F4 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   DWCi_AC_GetNintendoUSBWepKey 0x0205EB20 arm
 *   DWCi_AC_GetNintendoShopWepKey 0x0205EA44 arm
 */
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

#include "../sdk_ncfg.h"

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

#include "dwc_ac.h"
#include "mi_memory.h"
#include "../ov009/wcm_system.h"
#include "os_tick.h"
#include "dwc_ac_makelist.h"
#include "dwc_ac_beacon.h"
#include "msl_string_str.h"
#include "dwc_ac_shop_usb.h"
unsigned char DWCi_AC_ConnectAP(void);
unsigned char ConnectStart(ACWORK *wk);
static unsigned char ConnectAP(ACWORK *wk);
unsigned char GetConnectType(ACWORK *wk);
unsigned long GetPowerMode(ACWORK *wk);
unsigned long GetAuthMode(ACWORK *wk);
int GetWepKey(ACWORK *wk, unsigned char type, WCMWepDesc *wepkey);


/*
 * sdk:      DWCi_AC_ConnectAP (connect.o)
 */
unsigned char DWCi_AC_ConnectAP(void)
{
    ACWORK *wk;
    unsigned char phase;

    phase = DWCi_AC_GetPhase();
    wk = DWCi_AC_GetMemPtr(0x10);
    switch (phase) {
    case 7:
        phase = ConnectStart(wk);
        break;
    case 8:
        phase = ConnectAP(wk);
        break;
    }
    return phase;
}

/*
 * sdk:      ConnectStart (connect.o)
 */
unsigned char ConnectStart(ACWORK *wk)
{
    WMBssDesc *bssdesc = &wk->bssDesc[wk->connectNo];

    wk->connectApType = GetConnectType(wk);
    MI_CpuFill8(&wk->wepKey, 0, sizeof(WCMWepDesc));
    if (GetWepKey(wk, wk->connectApType, &wk->wepKey)) {
        wk->authMode = 1;
        if (((bssdesc->capaInfo >> 4) & 1) == 0) {
            wk->findList[wk->connectNo].state = 3;
            return 9;
        }
        if (wk->connectApType == 0x12 && bssdesc->ssid[9] == 0) {
            wk->findList[wk->connectNo].state = 3;
            return 9;
        }
    } else {
        wk->authMode = 0;
        if (((bssdesc->capaInfo >> 4) & 1) == 1) {
            wk->findList[wk->connectNo].state = 3;
            return 9;
        }
    }
    wk->count = 0;
    wk->connectResult = 0;
    return 8;
}


/*
 * sdk:      ConnectAP (connect.o)
 */
static unsigned char ConnectAP(ACWORK *wk)
{
    int phase;
    WMBssDesc *bssdesc;
    unsigned long power_mode;
    unsigned long auth_mode;

    phase = WCM_GetPhase();
    bssdesc = &wk->bssDesc[wk->connectNo];
    if (phase == 3) {
        power_mode = GetPowerMode(wk);
        if (++wk->count > 3) {
            wk->count = 0;
            wk->findList[wk->connectNo].state = 1;
            return 9;
        }
        if (wk->count != 1) {
            if (wk->connectResult == 1) {
                wk->authMode = 0;
            } else if (wk->connectResult == 2) {
                wk->count = 0;
                wk->findList[wk->connectNo].state = 3;
                return 9;
            } else if (wk->connectResult == 3) {
                wk->count = 0;
                wk->findList[wk->connectNo].state = 4;
                return 9;
            } else if (wk->count == 3) {
                wk->authMode = 0;
            }
        }
        auth_mode = GetAuthMode(wk);
        WCM_ConnectAsync(bssdesc, &wk->wepKey, power_mode | auth_mode);
    } else if (phase == 9) {
        wk->count = 0;
        wk->timeOut = OS_GetTick();
        return 10;
    } else if (phase == 11) {
        DWCi_AC_SetError(0);
        return 0x11;
    } else if (phase > 11) {
        DWCi_AC_SetError(4);
        return 0x11;
    }
    return 8;
}

/*
 * sdk:      GetConnectType (connect.o)
 */
unsigned char GetConnectType(ACWORK *wk)
{
    WMBssDesc *bssdesc;
    int type;
    int i;
    int j;
    unsigned char max;

    bssdesc = &wk->bssDesc[wk->connectNo];
    type = 0;
    j = 0;
    max = DWCi_AC_GetSearchListNum();
    if (!wk->duplicateFlag) {
        if (bssdesc->ssidLength == 32) {
            if ((type = DWCi_AC_CheckNintendoSSID(bssdesc)) > 0) {
                j++;
            } else {
                type = 0;
            }
        } else if (bssdesc->ssidLength == 8) {
            if ((type = DWCi_AC_CheckFreespot(bssdesc)) != 0) {
                j++;
            } else {
                type = 0;
            }
        }
        for (i = 0; i < max; i++) {
            if (bssdesc->ssidLength == wk->searchList[i].length
                && strncmp((const char *)bssdesc->ssid, (const char *)wk->searchList[i].ssid, bssdesc->ssidLength) == 0) {
                if (j == 0) {
                    type = wk->searchList[i].type;
                } else {
                    wk->searchList[i].duplicate = 1;
                    wk->duplicateFlag = 1;
                }
                j++;
            }
        }
    } else {
        j = 0;
        i = 0;
        for (; j < max; j++) {
            if (wk->searchList[j].duplicate == 1) {
                if (i == 0) {
                    wk->searchList[j].duplicate = 0;
                    type = wk->searchList[j].type;
                }
                i++;
            }
        }
        if (i == 1) {
            wk->duplicateFlag = 0;
        }
    }
    return (unsigned char)type;
}


unsigned long GetPowerMode(ACWORK *wk)
{
    return wk->powerMode == 1 ? 0x30000 : 0x20000;
}


unsigned long GetAuthMode(ACWORK *wk)
{
    return wk->authMode == 1 ? 0xc0000 : 0x80000;
}


/*
 * sdk:      GetWepKey (connect.o)
 */
int GetWepKey(ACWORK *wk, unsigned char type, WCMWepDesc *wepkey)
{
    NCFGSlotInfo *info;
    NCFGSlotInfoEx *info2;

    info = wk->userInfo;
    info2 = wk->userInfoEx;
    switch (type) {
    case 2:
        info++;
    case 1:
        info++;
    case 0:
        wepkey->mode = info->ap.wepMode;
        MI_CpuCopy8(info->ap.wep[0], wepkey->key, 0x10);
        break;
    case 5:
        info++;
    case 4:
        info++;
    case 3:
        wepkey->mode = 1;
        MI_CpuCopy8(info->ap.wep2[0], wepkey->key, 5);
        break;
    case 8:
        info2++;
    case 7:
        info2++;
    case 6:
        if (info2->ap.setType == 0x10 || info2->ap.setType == 0x12 || info2->ap.setType == 0x13) {
            wepkey->mode = info2->apEx.wpaMode;
            wepkey->keyId = 0x20;
            MI_CpuCopy8(info2->apEx.passphrase, wepkey->key, 0x20);
            wepkey->key[0x20] = 0;
        } else {
            wepkey->mode = info2->ap.wepMode;
            MI_CpuCopy8(info2->ap.wep[0], wepkey->key, 0x10);
        }
        break;
    case 11:
        info2++;
    case 10:
        info2++;
    case 9:
        wepkey->mode = 1;
        MI_CpuCopy8(info2->ap.wep2[0], wepkey->key, 5);
        break;
    case 14:
        info2++;
    case 13:
        info2++;
    case 12:
        wepkey->mode = 4;
        wepkey->keyId = 0x20;
        MI_CpuCopy8(info2->apEx.passphrase, wepkey->key, 0x20);
        wepkey->key[0x20] = 0;
        break;
    case 17:
        info2++;
    case 16:
        info2++;
    case 15:
        wepkey->mode = 6;
        wepkey->keyId = 0x20;
        MI_CpuCopy8(info2->apEx.pmk, wepkey->key, 0x20);
        wepkey->key[0x20] = 0;
        break;
    case 18:
        wepkey->mode = 2;
        DWCi_AC_GetNintendoUSBWepKey((char *)wk->bssDesc[wk->connectNo].ssid, wepkey->key);
        break;
    case 19:
        wepkey->mode = 2;
        DWCi_AC_GetNintendoShopWepKey((char *)wk->bssDesc[wk->connectNo].ssid, wepkey->key);
        break;
    case 20:
        break;
    }
    return wepkey->mode != 0;
}
