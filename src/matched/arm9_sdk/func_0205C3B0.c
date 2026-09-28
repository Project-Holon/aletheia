/*
 * function: func_0205C3B0
 * address:  0x0205C3B0
 * packet:   pkt_0205C3B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_CopyExSetting (dwc_ac.o)
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
    u8 findAP_ipCollision;
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

typedef struct tagACFL {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} ACFL;

typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u8 rest[0xc0 - 0x2c];
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
    u8 searchList[21][36];
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

extern u8 DWCi_ConvConnectAPType(u8 type);
extern BOOL OS_IsRunOnTwl(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);

void func_0205C3B0(u8 type)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);
    ACWORK *wk = DWCi_AC_GetMemPtr(0x10);
    u8 ap_type = DWCi_ConvConnectAPType(type);

    if (ap_type >= 0xa && ap_type <= 0xc && OS_IsRunOnTwl()) {
        ap_type -= 0xa;
        hd->proxyMode = wk->userInfoEx[ap_type].proxyMode;
        hd->proxyAuthType = wk->userInfoEx[ap_type].proxyAuthType;
        hd->proxyPort = wk->userInfoEx[ap_type].proxyPort;
        MI_CpuCopy8(wk->userInfoEx[ap_type].proxyHost, hd->proxyHost, 100);
        MI_CpuCopy8(wk->userInfoEx[ap_type].f000, hd->proxyId, 0x20);
        MI_CpuCopy8(wk->userInfoEx[ap_type].f020, hd->proxyPass, 0x20);
        if ((u8)(wk->userInfoEx[ap_type].wpaMode + 0xf0) <= 3) {
            hd->security = wk->userInfoEx[ap_type].wpaSecurity;
        } else {
            hd->security = wk->userInfoEx[ap_type].wepMode;
        }
    } else {
        if ((u8)(type + 0xee) <= 1) {
            hd->security = 2;
        } else {
            hd->security = wk->userInfo[ap_type].wepMode;
        }
    }
}
