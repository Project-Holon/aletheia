/*
 * function: SearchDifferChannel
 * address:  0x0205E29C
 * packet:   pkt_0205E29C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SearchDifferChannel (search.o)
 *
 * symbols:
 *   _ll_udiv               0x0209C00C  arm
 *   NextSearchCheck        0x0205E590  arm
 *   WCM_GetAllowedChannel  0x0216576C  arm
 *   WCM_SearchAsync        0x02165144  arm
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

extern u64 OS_GetTick(void);
extern u8 NextSearchCheck(ACWORK *wk, u8 phase);
extern u16 WCM_GetAllowedChannel(void);
extern s32 WCM_SearchAsync(void *bssid, void *essid, u32 option);

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
