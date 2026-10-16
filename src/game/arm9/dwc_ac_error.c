/*
 * file:     dwc_ac_error.c
 * unit:     yes
 * function: DWCi_AC_Error, DWCi_AC_GetResult, GetProgramaError, GetIrregularError, GetNotFoundAP, GetNotFoundInet
 * address:  0x0205D0E4
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
 *   DWCi_AC_CloseNetwork 0x0205B1E4  arm
 *   DWCi_AC_GetError   0x0205C308  arm
 *   GetNotFoundInet    0x0205D1E4  arm
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
extern int DWCi_AC_CloseNetwork(u8 *phase);
extern int DWCi_AC_GetError(void);
extern int GetNotFoundInet(ACHOLD *hd);
u8 DWCi_AC_Error(void);
int DWCi_AC_GetResult(void);
int GetProgramaError(int err);
int GetIrregularError(void);
int GetNotFoundAP(ACHOLD *hd);



/*
 * sdk:      DWCi_AC_Error (error.o)
 */
u8 DWCi_AC_Error(void)
{
    ACHOLD *hd = (ACHOLD *)DWCi_AC_GetMemPtr(1);

    if (DWCi_AC_CloseNetwork(&hd->phaseError) == 1) {
        return 0x12;
    }
    return 0x11;
}


/*
 * sdk:      DWCi_AC_GetResult (error.o)
 */
int DWCi_AC_GetResult(void)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);
    int error = DWCi_AC_GetError();

    if (error < 4) {
        return GetProgramaError(error);
    }
    if (error < 5) {
        return GetIrregularError();
    }
    if (error == 5) {
        return GetNotFoundAP(hd);
    }
    if (error == 7) {
        return -50599;
    }
    if (error == 8) {
        return -50699;
    }
    return GetNotFoundInet(hd);
}


int GetProgramaError(int err)
{
    switch (err) {
    case 1:
        return -9;
    case 0:
        return -10;
    case 2:
        return -8;
    case 3:
        return -7;
    default:
        return 0;
    }
}

int GetIrregularError(void)
{
    return ~5;
}


int GetNotFoundAP(ACHOLD *hd)
{
    if (hd->findAP == 0) {
        return -50099;
    }
    return -51099;
}



/*
 * sdk:      GetNotFoundInet (error.o)
 */
int GetNotFoundInet(ACHOLD *hd)
{
    u8 type;
    int ret;

    type = hd->overrideType ? hd->overrideType : hd->endType;
    if (hd->endSequence < 0xa) {
        if (hd->endState == 3) {
            ret = -51100 - type;
        } else if (hd->endState == 4) {
            ret = -51200 - type;
        } else {
            ret = -51300 - type;
        }
    } else if (hd->endSequence < 0xd) {
        ret = -52000 - type;
    } else {
        ret = hd->errorTest;
        if (ret == 0) {
            ret = -50000 - type;
        } else if (hd->ipCollision == 1) {
            ret = -52700 - type;
        } else if (ret == -1) {
            ret = -52100 - type;
        } else if (ret == -2) {
            ret = -52200 - type;
        } else if (ret == -3) {
            ret = -52300 - type;
        } else if (ret == -4) {
            ret = -53000 - type;
        } else if (ret == -5) {
            ret = -53100 - type;
        } else if (ret == -6) {
            ret = -53200 - type;
        }
    }
    return ret;
}
