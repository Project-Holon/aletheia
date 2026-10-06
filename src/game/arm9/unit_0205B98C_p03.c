/*
 * file:     unit_0205B98C_p03.c
 * unit:     yes
 * function: func_0205BE6C, func_0205BEA8, func_0205BF1C, func_0205BFD4, func_0205BFEC, func_0205C018, func_0205C038, func_0205C080, func_0205C0EC, func_0205C214
 * address:  0x0205BE6C
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
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   MIi_CpuCopy32                    0x02082a90 arm
 *   s_ac_work  0x02146AC0  data  a4
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

typedef struct NCFGSlotInfo_0205BEA8 {
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
} NCFGSlotInfo_0205BEA8;

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
    NCFGSlotInfo_0205BEA8 userInfo[3];
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
} ACWORK_0205B98C;

typedef struct NCFGSlotInfo_0205BF1C {
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
} NCFGSlotInfo_0205BF1C;

typedef struct NCFGApInfo {
    unsigned char data[0xF0];
} NCFGApInfo;

typedef struct NCFGSlotInfo_0205BFEC {
    NCFGApInfo ap;
    unsigned char rest[0x10];
} NCFGSlotInfo_0205BFEC;

typedef struct tagACWORK_0205BFEC {
    NCFGSlotInfo_0205BFEC userInfo[3];
} tagACWORK_0205BFEC;

typedef struct tagACWORK_0205C018 {
    unsigned char before[0x14BC];
    unsigned char connectType : 4;
    unsigned char skipNetCheck : 1;
    unsigned char useDSWireless : 1;
    unsigned char duplicateFlag : 1;
    unsigned char wpaSetting : 1;
} tagACWORK_0205C018;

typedef struct NCFGSlotInfo_0205C038 {
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
} NCFGSlotInfo_0205C038;

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

extern u8 DWCi_AC_GetPhase(void);
extern void DWCi_AC_FreeAll(void);
extern int DWCi_AC_CloseNetwork(u8 *phase);
extern void DWCi_AC_SetPhase(u8 phase);
extern void *DWCi_AC_GetMemPtr(u32 name);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void DWC_AC_SetSpecifyAp(void *ssid, void *wep, int wepMode);
extern int DWCi_AC_CheckNintendoShopAP(void *ssid, int len);
extern void MIi_CpuCopy32(const void *srcp, void *destp, unsigned long size);
BOOL func_0205BE6C(void);
void func_0205BEA8(void *ssid, void *wep, int wepMode, u16 mtu, char *apSpotInfo, int overrideType);
void func_0205BF1C(void *ssid, void *wep, int wepMode);
int DWC_AC_CheckWiFiStation(void *ssid, unsigned short len);
void func_0205BFEC(int no, NCFGApInfo *info);
void func_0205C018(void);
void *func_0205C038(u32 name, s32 size);
void func_0205C080(u32 name, void *ptr, s32 size);
void func_0205C0EC(void);
void *func_0205C214(u32 name);



/*
 * sdk:      DWC_AC_Destroy (dwc_ac.o)
 */
BOOL func_0205BE6C(void)
{
    u8 phase = DWCi_AC_GetPhase();

    if (phase == 0 || phase == 0x12) {
        DWCi_AC_FreeAll();
        return 1;
    }
    DWCi_AC_CloseNetwork(&phase);
    DWCi_AC_SetPhase(phase);
    return 0;
}



/*
 * sdk:      DWC_AC_SetSpecifyApEx (dwc_ac.o)
 */
void func_0205BEA8(void *ssid, void *wep, int wepMode, u16 mtu, char *apSpotInfo, int overrideType)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);
    ACWORK_0205B98C *wk = DWCi_AC_GetMemPtr(0x10);

    if (apSpotInfo) {
        MI_CpuCopy8(apSpotInfo, hd->apSpotInfo, 10);
    } else {
        MI_CpuFill8(hd->apSpotInfo, 0, 10);
    }
    hd->overrideType = (u8)overrideType;
    DWC_AC_SetSpecifyAp(ssid, wep, wepMode);
    wk->userInfo[0].mtu = mtu;
}



/*
 * sdk:      DWC_AC_SetSpecifyAp (dwc_ac.o)
 */
void func_0205BF1C(void *ssid, void *wep, int wepMode)
{
    ACWORK_0205B98C *wk = DWCi_AC_GetMemPtr(0x10);
    int i;
    u32 len;

    wk->connectType = 1;
    MI_CpuFill8(&wk->userInfo[0], 0, 0xf0);
    for (i = 0; i < 0x20; i++) {
        if (((u8 *)ssid)[i] == 0) {
            break;
        }
        wk->userInfo[0].ssid[i] = ((u8 *)ssid)[i];
    }
    if (wep == 0 || wepMode == 0) {
        wk->userInfo[0].wepMode = 0;
        return;
    }
    if (wepMode == 1) {
        len = 5;
    } else if (wepMode == 2) {
        len = 0xd;
    } else {
        len = 0x10;
    }
    MI_CpuCopy8(wep, wk->userInfo[0].wep, len);
    wk->userInfo[0].wepMode = (u8)wepMode;
}



int DWC_AC_CheckWiFiStation(void *ssid, unsigned short len)
{
    if (len != 32)
        return 0;
    return DWCi_AC_CheckNintendoShopAP(ssid, len);
}



/*
 * sdk:      DWCi_AC_InsertApInfo (dwc_ac.o)
 */
void func_0205BFEC(int no, NCFGApInfo *info)
{
    tagACWORK_0205BFEC *wk = (tagACWORK_0205BFEC *)func_0205C214(0x10);

    MIi_CpuCopy32(info, &wk->userInfo[no], sizeof(NCFGApInfo));
}



/*
 * sdk:      DWCi_AC_InvalidatePriorityWPA (dwc_ac.o)
 */
void func_0205C018(void)
{
    tagACWORK_0205C018 *wk = (tagACWORK_0205C018 *)func_0205C214(0x10);

    wk->wpaSetting = 0;
}



/*
 * sdk:      DWCi_AC_Alloc (dwc_ac.o)
 */
void *func_0205C038(u32 name, s32 size)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);

    if (hd->allocState & name) {
        return 0;
    }
    hd->allocState |= name;
    return hd->alloc(1, size);
}



static struct {
    void *wcmBuffer;
    void *socConfig;
    void *netCheck;
    ACHOLD *acHold;
    ACWORK_0205B98C *acWork;
} s_ac_work;



/*
 * sdk:      DWCi_AC_Free (dwc_ac.o)
 */
void func_0205C080(u32 name, void *ptr, s32 size)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);

    if (hd == 0) {
        return;
    }
    if ((hd->allocState & name) == 0) {
        return;
    }
    hd->allocState &= ~name;
    hd->free(1, ptr, size);
    if (name == 1) {
        s_ac_work.acHold = 0;
    }
}



/*
 * sdk:      DWCi_AC_FreeAll (dwc_ac.o)
 */
void func_0205C0EC(void)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);

    if (hd == 0) {
        return;
    }
    if (hd->allocState & 0x10) {
        ACWORK_0205B98C *wk = DWCi_AC_GetMemPtr(0x10);
        hd->allocState &= ~0x10;
        hd->free(1, wk, sizeof(ACWORK_0205B98C));
    }
    if (hd->allocState & 8) {
        void *wk = DWCi_AC_GetMemPtr(8);
        hd->allocState &= ~8;
        hd->free(1, wk, 0xc);
    }
    if (hd->allocState & 4) {
        void *wk = DWCi_AC_GetMemPtr(4);
        hd->allocState &= ~4;
        hd->free(1, wk, 0x58);
    }
    if (hd->allocState & 2) {
        void *wk = DWCi_AC_GetMemPtr(2);
        hd->allocState &= ~2;
        hd->free(1, wk, 0x4800);
    }
    if (hd->allocState & 1) {
        hd->allocState &= ~1;
        hd->free(1, hd, sizeof(ACHOLD));
        s_ac_work.acHold = 0;
    }
}



/*
 * sdk:      DWCi_AC_GetMemPtr (dwc_ac.o)
 */
void *func_0205C214(u32 name)
{
    if (name & 1) return s_ac_work.acHold;
    if (name & 2) return s_ac_work.wcmBuffer;
    if (name & 4) return s_ac_work.socConfig;
    if (name & 8) return s_ac_work.netCheck;
    if (name & 0x10) return s_ac_work.acWork;
    return 0;
}
