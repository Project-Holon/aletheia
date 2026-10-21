/*
 * file:     dwc_ac_search.c
 * unit:     yes
 * function: DWCi_AC_SearchAP, DWCi_AC_SetStealthChannel, DWCi_AC_SearchReStart, SearchAround1stLap, SearchAround2ndLap, SearchAround, SearchDifferChannel, SearchStealth, NextSearchCheck, SearchEndCheck, CheckStartStealthSearch, GetStartChannel, GetNextAroundChannel, GetNextStealthChannel
 * address:  0x0205DE04
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
 *   WCM_GetPhase           0x021656A0  arm
 *   WCM_GetAllowedChannel  0x0216576C  arm
 *   SearchAround1stLap     0x0205E110  arm
 *   SearchEndCheck         0x0205E64C  arm
 *   SearchAround           0x0205E1D0  arm
 *   SearchDifferChannel    0x0205E29C  arm
 *   SearchStealth          0x0205E444  arm
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   WCM_SearchAsync        0x02165144  arm
 *   DWC_AC_SEARCH_CHANNEL  0x020A1634  data
 *   WCM_Bssid_Any          0x021A1988  data
 *   WCM_Essid_Any          0x021A1990  data
 *   GetStartChannel        0x0205E818  arm
 *   DWCi_AC_MakeSearchList           0x0205d318 arm
 *   _ll_udiv               0x0209C00C  arm
 *   GetNextAroundChannel   0x0205E8BC  arm
 *   NextSearchCheck        0x0205E590  arm
 *   GetNextStealthChannel  0x0205E954  arm
 *   CheckStartStealthSearch  0x0205E790  arm
 *   SearchAround2ndLap       0x0205E17C  arm
 *   WCM_EndSearchAsync  0x02165204  arm
 */
#include "../types.h"

typedef struct tagACHOLD {
    void *(*alloc)(u32 name, s32 size);
    void (*free)(u32 name, void *ptr, s32 size);
    u8 allocState;
    u8 phase;
    u8 phaseError;
    u8 findAP : 4;
    u8 ipCollision : 4;
    int error;
    int errorTest;
    u8 endState;
    u8 endType;
    u8 endSequence;
    u8 type;
    char apSpotInfo[10];
    u8 overrideType;
    u8 security;
    u8 proxyMode;
    u8 proxyAuthType;
    u16 proxyPort;
    u8 proxyHost[100];
    u8 proxyId[32];
    u8 proxyPass[32];
} ACHOLD;

typedef struct tagACSL {
    u8 state : 4;
    u8 flag : 4;
    u8 pad[3];
    u8 essid[32];
} ACSL;

typedef struct tagACFL {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3 : 7;
    u8 searched : 1;
} ACFL;

#include "../sdk_wm.h"

#include "../sdk_ncfg.h"

typedef struct tagACWORK {
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx userInfoEx[3];
    ACSL searchList[21];
    ACFL findList[11];
    WMBssDesc bssDesc[11];
    u64 timeOut;
    u8 wepKey[0x52];
    u8 dmaNo;
    u8 powerMode : 2;
    u8 authMode : 2;
    u8 aroundCount : 4;
    u8 connectType : 4;
    u8 skipNetCheck : 1;
    u8 useDSWireless : 1;
    u8 duplicateFlag : 1;
    u8 wpaSetting : 1;
    u8 connectApType;
    u8 phaseBak;
    u8 searchListNo;
    u8 searchListNum;
    s8 searchChannel;
    u8 findListNum;
    u8 connectNo;
    u8 connectResult;
    u8 count;
    u16 stealthChannel;
    s32 rwin;
    u8 wontExecuteEULACheck;
    u16 maxChannel;
    u8 padding;
    u16 passiveScanTime;
    u16 activeScanTime;
} ACWORK;

#include "dwc_ac.h"
#include "../ov009/wcm_system.h"
#include "os_emulator.h"
extern u8 SearchAround1stLap(ACWORK *wk);
extern u8 SearchEndCheck(ACWORK *wk, u8 phase);
extern u8 SearchAround(ACWORK *wk);
extern u8 SearchDifferChannel(ACWORK *wk);
extern u8 SearchStealth(ACWORK *wk);
#include "os_tick.h"
extern s8 GetStartChannel(int lap);
#include "dwc_ac_makelist.h"
extern s8 GetNextAroundChannel(s8 now_ch);
extern u8 NextSearchCheck(ACWORK *wk, u8 phase);
extern s8 GetNextStealthChannel(void);
extern u8 CheckStartStealthSearch(ACWORK *wk);
static u8 SearchAround2ndLap(ACWORK *wk);
extern void DWCi_AC_SearchReStart(u8 phase);
#include "dwc_ac_beacon.h"
u8 DWCi_AC_SearchAP(void);
void DWCi_AC_SetStealthChannel(unsigned short channel);
extern const u32 DWC_AC_SEARCH_CHANNEL[13];
extern u8 WCM_Bssid_Any[];
extern u8 WCM_Essid_Any[];

/*
 * sdk:      DWCi_AC_SearchAP (search.o)
 */
u8 DWCi_AC_SearchAP(void)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    u8 dwc_phase = DWCi_AC_GetPhase();
    int wcm_phase = WCM_GetPhase();
    int i;
    u16 ch;

    if (dwc_phase == 2 && wcm_phase == 3) {
        ch = WCM_GetAllowedChannel();
        for (i = 0; i <= 0xc; i++) {
            if (ch & (0x1000 >> i)) {
                break;
            }
        }
        wk->maxChannel = (u16)(0xd - i);
        if (OS_IsRunOnTwl()) {
            if (wk->useDSWireless == 1) {
                wk->passiveScanTime = 0x12c;
                wk->activeScanTime = 0x96;
            } else {
                wk->passiveScanTime = 0x116;
                wk->activeScanTime = 0xcb;
            }
        } else {
            wk->passiveScanTime = 0x12c;
            wk->activeScanTime = 0x96;
        }
        dwc_phase = SearchAround1stLap(wk);
    } else if (dwc_phase == 6) {
        dwc_phase = SearchEndCheck(wk, dwc_phase);
    } else if (wcm_phase == 3 || wcm_phase == 6) {
        dwc_phase = SearchEndCheck(wk, dwc_phase);
        if (dwc_phase != 7) {
            if (dwc_phase == 3) {
                dwc_phase = SearchAround(wk);
            } else if (dwc_phase == 4) {
                dwc_phase = SearchDifferChannel(wk);
            } else if (dwc_phase == 5) {
                dwc_phase = SearchStealth(wk);
            }
        }
    } else if (wcm_phase == 0xb) {
        DWCi_AC_SetError(0);
        return 0x11;
    } else if (wcm_phase > 0xb) {
        DWCi_AC_SetError(4);
        return 0x11;
    }
    return dwc_phase;
}

/*
 * sdk:      DWCi_AC_SetStealthChannel (search.o)
 */
void DWCi_AC_SetStealthChannel(unsigned short channel)
{
    ACWORK *wk = (ACWORK *)DWCi_AC_GetMemPtr(0x10);

    if (channel > wk->maxChannel) {
        channel = wk->maxChannel;
    }
    wk->stealthChannel = (unsigned short)(wk->stealthChannel | (1 << (channel - 1)));
}

/*
 * sdk:      DWCi_AC_SearchReStart (search.o)
 */
void DWCi_AC_SearchReStart(u8 phase)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    u16 mask;
    BOOL allowed;

    switch (phase) {
    case 3:
        wk->timeOut = OS_GetTick();
        WCM_SearchAsync(WCM_Bssid_Any, WCM_Essid_Any, DWC_AC_SEARCH_CHANNEL[wk->searchChannel] | 0x200000);
        break;
    case 4:
        mask = (u16)(1 << (wk->bssDesc[wk->searchListNo].channel - 1));
        allowed = (WCM_GetAllowedChannel() & mask) ? 1 : 0;
        if (allowed == 1) {
            wk->timeOut = OS_GetTick();
            WCM_SearchAsync(wk->bssDesc[wk->searchListNo].bssid, wk->bssDesc[wk->searchListNo].ssid,
                            (u16)((wk->bssDesc[wk->searchListNo].channel - 1) | 0x300000));
        } else {
            wk->findList[wk->searchListNo].searched = 1;
        }
        break;
    case 5:
        wk->timeOut = OS_GetTick();
        WCM_SearchAsync(WCM_Bssid_Any, wk->searchList[wk->searchListNo].essid,
                        DWC_AC_SEARCH_CHANNEL[wk->searchChannel] | 0x300000);
        break;
    }
}

/*
 * sdk:      SearchAround1stLap (search.o)
 */
u8 SearchAround1stLap(ACWORK *wk)
{
    wk->timeOut = OS_GetTick();
    wk->searchChannel = GetStartChannel(0);
    wk->timeOut = OS_GetTick();
    WCM_SearchAsync(WCM_Bssid_Any, WCM_Essid_Any, DWC_AC_SEARCH_CHANNEL[wk->searchChannel] | 0x200000);
    return 3;
}

/*
 * sdk:      SearchAround2ndLap (search.o)
 */
static unsigned char SearchAround2ndLap(ACWORK *wk)
{
    wk->count = 0;
    wk->aroundCount++;
    DWCi_AC_MakeSearchList(0);
    wk->searchChannel = GetStartChannel(1);
    return 3;
}

/*
 * sdk:      SearchAround (search.o)
 */
u8 SearchAround(ACWORK *wk)
{
    u64 t = OS_GetTick() - wk->timeOut;

    if ((t * 64) / 0x82ea >= wk->passiveScanTime) {
        wk->searchChannel = GetNextAroundChannel(wk->searchChannel);
        if (wk->searchChannel == -1) {
            return NextSearchCheck(wk, 3);
        }
        wk->timeOut = OS_GetTick();
        WCM_SearchAsync(WCM_Bssid_Any, WCM_Essid_Any, DWC_AC_SEARCH_CHANNEL[wk->searchChannel] | 0x200000);
    }
    return 3;
}

/*
 * sdk:      SearchDifferChannel (search.o)
 */
u8 SearchDifferChannel(ACWORK *wk)
{
    u64 t = OS_GetTick() - wk->timeOut;
    u16 mask;
    BOOL allowed;

    if ((t * 64) / 0x82ea >= wk->activeScanTime || wk->findList[wk->searchListNo].searched == 1) {
        wk->findList[wk->searchListNo].searched = 1;
        while (wk->searchListNo < wk->findListNum) {
            if (!wk->findList[wk->searchListNo].searched) {
                break;
            }
            wk->searchListNo++;
        }
        if (wk->findListNum <= wk->searchListNo) {
            wk->searchListNo = 0;
            return NextSearchCheck(wk, 4);
        }
        mask = (u16)(1 << (wk->bssDesc[wk->searchListNo].channel - 1));
        allowed = (WCM_GetAllowedChannel() & mask) ? 1 : 0;
        if (allowed == 1) {
            wk->timeOut = OS_GetTick();
            WCM_SearchAsync(wk->bssDesc[wk->searchListNo].bssid, wk->bssDesc[wk->searchListNo].ssid,
                            (u16)((wk->bssDesc[wk->searchListNo].channel - 1) | 0x300000));
        } else {
            wk->findList[wk->searchListNo].searched = 1;
        }
    }
    return 4;
}

/*
 * sdk:      SearchStealth (search.o)
 */
u8 SearchStealth(ACWORK *wk)
{
    u64 t = OS_GetTick() - wk->timeOut;

    if ((t * 64) / 0x82ea >= wk->activeScanTime || wk->searchList[wk->searchListNo].state == 1) {
        wk->searchList[wk->searchListNo].state = 0;
        if (wk->searchListNum <= ++wk->searchListNo) {
            wk->count++;
            wk->searchListNo = 0;
            wk->searchChannel = GetNextStealthChannel();
        }
        if (wk->searchChannel < 0) {
            wk->count = 0;
            return NextSearchCheck(wk, 5);
        }
        wk->timeOut = OS_GetTick();
        WCM_SearchAsync(WCM_Bssid_Any, wk->searchList[wk->searchListNo].essid,
                        DWC_AC_SEARCH_CHANNEL[wk->searchChannel] | 0x300000);
    }
    return 5;
}

/*
 * sdk:      NextSearchCheck (search.o)
 */
u8 NextSearchCheck(ACWORK *wk, u8 phase)
{
    switch (phase) {
    case 3:
        if (wk->findListNum != 0 || wk->stealthChannel != 0) {
            if (DWCi_AC_MakeSearchList(1) == 1) {
                phase = 4;
                break;
            }
            phase = CheckStartStealthSearch(wk);
            break;
        }
        if (wk->aroundCount >= 1) {
            phase = 6;
            break;
        }
        phase = SearchAround2ndLap(wk);
        break;
    case 4:
        phase = CheckStartStealthSearch(wk);
        break;
    case 5:
        if (wk->aroundCount >= 1) {
            phase = 6;
            break;
        }
        phase = SearchAround2ndLap(wk);
        break;
    }
    DWCi_AC_SearchReStart(phase);
    return phase;
}

/*
 * sdk:      SearchEndCheck (search.o)
 */
u8 SearchEndCheck(ACWORK *wk, u8 phase)
{
    u8 no;

    if (phase == 0x11) {
        return phase;
    }
    for (no = 0; no < wk->findListNum; no++) {
        if (wk->findList[no].b0 == 0) {
            break;
        }
    }
    if (phase == 6) {
        if (wk->findListNum == no) {
            if (no == 0) {
                DWCi_AC_SetError(5);
            } else {
                DWCi_AC_SetError(6);
            }
            return 0x11;
        }
    } else {
        if (wk->findListNum == 0) {
            return phase;
        }
        if (wk->findListNum == no) {
            return phase;
        }
        if (wk->useDSWireless == 1) {
            if (wk->findList[no].b2 < 0x14) {
                return phase;
            }
        } else if (wk->findList[no].b2 < 0x16) {
            return phase;
        }
        if (wk->findList[no].b1 >= 0x13 && wk->findList[no].b1 <= 0x16) {
            return phase;
        }
        if (wk->wpaSetting == 1 && DWCi_AC_IsSupportWPA(&wk->bssDesc[no]) == 0) {
            return phase;
        }
    }
    wk->connectNo = no;
    if (WCM_EndSearchAsync() != 1) {
        wk->phaseBak = phase;
        phase = 7;
    }
    return phase;
}

/*
 * sdk:      CheckStartStealthSearch (search.o)
 */
u8 CheckStartStealthSearch(ACWORK *wk)
{
    if (wk->stealthChannel != 0 && DWCi_AC_MakeSearchList(2) == 1) {
        wk->searchChannel = GetNextStealthChannel();
        if (wk->searchChannel >= 0) {
            return 5;
        }
        wk->count = 0;
        return NextSearchCheck(wk, 5);
    }
    if (wk->aroundCount >= 1) {
        return 6;
    }
    return SearchAround2ndLap(wk);
}

/*
 * sdk:      GetStartChannel (search.o)
 */
s8 GetStartChannel(int lap)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    int i;
    u16 mask;
    u16 ch;

    if (lap == 0) {
        i = 0;
        mask = 1;
    } else {
        i = 1;
        mask = 2;
    }
    for (; i <= wk->maxChannel; mask <<= 2, i += 2) {
        ch = WCM_GetAllowedChannel();
        if (((ch & mask) ? 1 : 0) == 1) {
            break;
        }
    }
    if (i > wk->maxChannel) {
        return (s8)(lap ? 1 : 0);
    }
    return (s8)i;
}

/*
 * sdk:      GetNextAroundChannel (search.o)
 */
s8 GetNextAroundChannel(s8 now_ch)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    u16 mask;
    u16 ch;

    for (now_ch += 2, mask = (u16)(1 << now_ch); now_ch <= wk->maxChannel; mask <<= 2, now_ch += 2) {
        ch = WCM_GetAllowedChannel();
        if (((ch & mask) ? 1 : 0) == 1) {
            break;
        }
    }
    if (now_ch > wk->maxChannel) {
        now_ch = -1;
    }
    return now_ch;
}

/*
 * sdk:      GetNextStealthChannel (search.o)
 */
s8 GetNextStealthChannel(void)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    u8 i;
    u8 j;
    u16 ch;
    u16 stealth = wk->stealthChannel;

    if (stealth == 0) {
        return -1;
    }
    for (i = 0, j = 0; i < wk->maxChannel; i++) {
        if (stealth & (1 << i)) {
            if (j == wk->count) {
                ch = WCM_GetAllowedChannel();
                if (((ch & (u16)(1 << i)) ? 1 : 0) == 1) {
                    return (s8)i;
                }
                wk->count++;
            }
            j++;
        }
    }
    return -1;
}
