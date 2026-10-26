/*
 * file:     dwc_ac_start.c
 * function: DWCi_AC_Start
 * address:  0x0205EFF0
 * packet:   pkt_0205EFF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_Start (start.o)
 *
 * symbols:
 *   WCM_GetPhase         0x021656A0  arm
 *   WCM_StartupAsync     0x02164F98  arm
 *   DWCi_AC_CallBackWCM  0x0205B148  arm
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
#include "dwc_ac_makelist.h"
#include "dwc_ac_callback.h"

u8 DWCi_AC_Start(void)
{
    WCMConfig config;
    int result;
    int phase = WCM_GetPhase();
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);

    if (phase == 1) {
        config.dmano = wk->dmaNo;
        config.pbdbuffer = 0;
        config.nbdbuffer = 0;
        config.nbdmode = 0;
        DWCi_AC_MakeSearchList(0);
        result = WCM_StartupAsync(&config, DWCi_AC_CallBackWCM);
        if (result == 1 || result >= 4) {
            DWCi_AC_SetError(1);
            return 0x11;
        }
    } else {
        return 1;
    }
    return 2;
}
