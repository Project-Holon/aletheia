/*
 * file:     unit_0205B98C_p06.c
 * unit:     yes
 * function: func_0205C31C, func_0205C3B0, func_0205C4C8, func_0205C528, func_0205C55C, func_0205C600, func_0205C670
 * address:  0x0205C31C
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
 *   s_ac_work  0x02146AC0  data  a4
 *   strncmp  0x020949F4  arm
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
extern u8 *WCM_GetApEssid(u16 *length);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern BOOL DWCi_AC_GetPostalCode(char *ssid, u8 *pos);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern BOOL OS_IsRunOnTwl(void);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void DWCi_AC_Free(u32 name, void *ptr, s32 size);
extern int strncmp(const char *s1, const char *s2, u32 n);
extern BOOL OS_IsAgreeEULA(void);
extern u8 OS_GetAgreedEULAVersion(void);
extern u8 OS_GetROMHeaderEULAVersion(void);
extern BOOL OS_IsAvailableWireless(void);
extern BOOL OS_IsForceDisableWireless(void);
void func_0205C31C(u8 type);
void func_0205C3B0(u8 type);
u8 func_0205C4C8(u8 type);
void func_0205C528(void);
BOOL func_0205C55C(void);
BOOL func_0205C600(void);
BOOL func_0205C670(void);


static struct {
    void *wcmBuffer;
    void *socConfig;
    void *netCheck;
    ACHOLD *acHold;
    ACWORK *acWork;
} s_ac_work;


/*
 * sdk:      DWCi_AC_SetApType (dwc_ac.o)
 */
void func_0205C31C(u8 type)
{
    u8 *essid;

    if (s_ac_work.acHold->overrideType == 0) {
        type = DWCi_ConvConnectAPType(type);
    } else {
        type = s_ac_work.acHold->overrideType;
    }
    s_ac_work.acHold->type = type;
    essid = WCM_GetApEssid(0);
    if (essid) {
        DC_InvalidateRange(essid, 0x20);
        if (DWCi_AC_GetPostalCode((char *)essid, (u8 *)s_ac_work.acHold->apSpotInfo)) {
            return;
        }
        MI_CpuFill8(s_ac_work.acHold->apSpotInfo, 0, 10);
    } else {
        MI_CpuFill8(s_ac_work.acHold->apSpotInfo, 0, 10);
    }
}


/*
 * sdk:      DWCi_AC_CopyExSetting (dwc_ac.o)
 */
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


/*
 * sdk:      DWCi_ConvConnectAPType (dwc_ac.o)
 */
u8 func_0205C4C8(u8 type)
{
    if (type >= 0x12) return (u8)(type - 0xf);
    if (type >= 0xf) return (u8)(type - 5);
    if (type >= 0xc) return (u8)(type - 2);
    if (type >= 9) return (u8)(type + 1);
    if (type >= 6) return (u8)(type + 4);
    if (type >= 3) return (u8)(type - 3);
    return type;
}


/*
 * sdk:      Free_Disused (dwc_ac.o)
 */
void func_0205C528(void)
{
    DWCi_AC_Free(8, s_ac_work.netCheck, 0xc);
    DWCi_AC_Free(0x10, s_ac_work.acWork, sizeof(ACWORK));
}


/*
 * sdk:      CheckDuplicate (dwc_ac.o)
 */
BOOL func_0205C55C(void)
{
    u8 i;
    u8 *ssid1;
    u8 connectNo;
    ACWORK *wk;
    u8 num;

    wk = s_ac_work.acWork;
    connectNo = wk->connectNo;
    ssid1 = wk->bssDesc[connectNo].bssid;
    if (wk->connectApType >= 0x12) {
        return 1;
    }
    num = wk->findListNum;
    for (i = 0; i < num; i++) {
        if (i != connectNo && wk->findList[i].b1 < 0x12 &&
            strncmp((char *)ssid1, (char *)wk->bssDesc[i].bssid, wk->bssDesc[i].ssidLength) == 0) {
            return 2;
        }
    }
    return 1;
}


/*
 * sdk:      CheckEULA (dwc_ac.o)
 */
BOOL func_0205C600(void)
{
    if (OS_IsRunOnTwl()) {
        if (s_ac_work.acWork->wontExecuteEULACheck ||
            (OS_IsAgreeEULA() && OS_GetAgreedEULAVersion() != 0 &&
             OS_GetAgreedEULAVersion() >= OS_GetROMHeaderEULAVersion())) {
            return 1;
        }
        return 0;
    }
    return 1;
}


/*
 * sdk:      CheckWirelessPowerON (dwc_ac.o)
 */
BOOL func_0205C670(void)
{
    if (OS_IsRunOnTwl()) {
        if (OS_IsAvailableWireless() == 1 && OS_IsForceDisableWireless() == 0) {
            return 1;
        }
        return 0;
    }
    return 1;
}
