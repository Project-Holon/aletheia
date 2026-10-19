/*
 * file:     dwc_ac_retry.c
 * function: DWCi_AC_ConnectRetryAP
 * address:  0x0205DD2C
 * packet:   pkt_0205DD2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_ConnectRetryAP (retry.o)
 *
 * symbols:
 *   WCM_GetPhase         0x021656A0  arm
 *   WCM_EndSearchAsync   0x02165204  arm
 *   WCM_DisconnectAsync  0x02165478  arm
 *   WCM_TerminateAsync   0x02165560  arm
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

extern void *DWCi_AC_GetMemPtr(u32 name);

extern s32 WCM_GetPhase(void);
extern void DWCi_AC_SearchReStart(u8 phase);
extern long WCM_EndSearchAsync(void);
extern s32 WCM_DisconnectAsync(void);
extern s32 WCM_TerminateAsync(void);
extern void DWCi_AC_SetError(int error);

u8 DWCi_AC_ConnectRetryAP(void)
{
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    u8 phase = 9;

    switch (WCM_GetPhase()) {
    case 3:
        phase = wk->phaseBak;
        if (wk->duplicateFlag == 1) {
            phase = 7;
            wk->findList[wk->connectNo].b0 = 0;
        } else if (phase >= 3 && phase <= 5) {
            DWCi_AC_SearchReStart(phase);
        }
        break;
    case 6:
        WCM_EndSearchAsync();
        break;
    case 9:
        WCM_DisconnectAsync();
        break;
    case 12:
        WCM_TerminateAsync();
        DWCi_AC_SetError(4);
        phase = 0x11;
        break;
    case 11:
        DWCi_AC_SetError(0);
        phase = 0x11;
        break;
    }
    return phase;
}
