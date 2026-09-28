/*
 * function: func_0205E64C
 * address:  0x0205E64C
 * packet:   pkt_0205E64C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SearchEndCheck (search.o)
 *
 * symbols:
 *   WCM_EndSearchAsync  0x02165204  arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef unsigned long long u64;
typedef int BOOL;

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

typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capaInfo;
    u16 rateSet[2];
    u16 beaconPeriod;
    u16 dtimPeriod;
    u16 channel;
    u8 rest[0xc0 - 0x38];
} WMBssDesc;

typedef struct NCFGSlotInfo {
    u8 pad0[0x40];
    u8 ssid[32];
    u8 pad1[0x20];
    u8 wep[0x50];
    u8 pad2[0x16];
    u8 wepMode : 2;
    u8 wepNotation : 6;
    u8 pad3[3];
    u16 mtu;
    u8 pad4[0x100 - 0xec];
} NCFGSlotInfo;

typedef struct NCFGSlotInfoEx {
    u8 f000[0x20];
    u8 f020[0x20];
    u8 pad0[0xe6 - 0x40];
    u8 wepMode : 2;
    u8 wepNotation : 6;
    u8 wpaMode;
    u8 pad1[0x181 - 0xe8];
    u8 wpaSecurity;
    u8 proxyMode;
    u8 proxyAuthType;
    u8 proxyHost[100];
    u16 proxyPort;
    u8 pad2[0x200 - 0x1ea];
} NCFGSlotInfoEx;

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

extern void DWCi_AC_SetError(int error);
extern BOOL DWCi_AC_IsSupportWPA(WMBssDesc *bssDesc);
extern BOOL WCM_EndSearchAsync(void);

u8 func_0205E64C(ACWORK *wk, u8 phase)
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
