/*
 * file:     unit_0205B98C_p01.c
 * unit:     yes
 * function: func_0205B98C
 * address:  0x0205B98C
 * packet:   pkt_0205B98C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_AC_Create (dwc_ac.o)
 *
 * symbols:
 *   s_ac_work  0x02146AC0  data  a4
 *   WCM_InitEx  0x02164D74  arm
 *   WCM_Init    0x02164D64  arm
 *   MIi_CpuClear32  0x02082A7C  arm
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

static struct {
    void *wcmBuffer;
    void *socConfig;
    void *netCheck;
    ACHOLD *acHold;
    ACWORK *acWork;
} s_ac_work;

typedef struct tagDWCACOption {
    u8 connectType;
    u8 skipNetCheck : 4;
    u8 useDSWireless : 4;
} DWCACOption;

typedef struct tagDWCACConfig {
    void *(*alloc)(u32 name, s32 size);
    void (*free)(u32 name, void *ptr, s32 size);
    u8 dmaNo;
    u8 powerMode;
    DWCACOption option;
    s32 rwin;
    u8 wontExecuteEULACheck;
} DWCACConfig;

typedef struct DWCNetcheckParam {
    void *(*alloc)(u32 name, s32 size);
    void (*free)(u32 name, void *ptr, s32 size);
    void *bmworkarea;
} DWCNetcheckParam;

extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void *DWCi_AC_Alloc(u32 name, s32 size);
extern BOOL DWCi_BM_GetApInfo(NCFGSlotInfo *buf);
extern BOOL OS_IsRunOnTwl(void);
extern BOOL DWCi_BM_GetApInfoEx(NCFGSlotInfoEx *buf);
extern s32 WCM_InitEx(void *buf, s32 len, u8 deviceId);
extern s32 WCM_Init(void *buf, s32 len);
extern void DWCi_AC_FreeAll(void);

/*
 * sdk:      DWC_AC_Create (dwc_ac.o)
 */
BOOL func_0205B98C(DWCACConfig *config)
{
    int result;
    ACHOLD *hd;
    ACWORK *wk;
    DWCNetcheckParam *nc;

    s_ac_work.acHold = config->alloc(1, sizeof(ACHOLD));
    MIi_CpuClear32(0, s_ac_work.acHold, sizeof(ACHOLD));
    hd = s_ac_work.acHold;
    hd->alloc = config->alloc;
    hd->free = config->free;
    hd->phase = 1;
    hd->endSequence = 1;
    hd->allocState = 1;

    s_ac_work.acWork = DWCi_AC_Alloc(0x10, sizeof(ACWORK));
    s_ac_work.wcmBuffer = DWCi_AC_Alloc(2, 0x4800);
    s_ac_work.socConfig = DWCi_AC_Alloc(4, 0x58);
    s_ac_work.netCheck = DWCi_AC_Alloc(8, sizeof(DWCNetcheckParam));
    MIi_CpuClear32(0, s_ac_work.acWork, sizeof(ACWORK));
    MIi_CpuClear32(0, s_ac_work.wcmBuffer, 0x4800);
    MIi_CpuClear32(0, s_ac_work.socConfig, 0x58);
    MIi_CpuClear32(0, s_ac_work.netCheck, sizeof(DWCNetcheckParam));

    wk = s_ac_work.acWork;
    wk->dmaNo = config->dmaNo;
    wk->powerMode = config->powerMode;
    wk->rwin = config->rwin;
    wk->wontExecuteEULACheck = config->wontExecuteEULACheck;
    nc = s_ac_work.netCheck;
    nc->alloc = config->alloc;
    nc->free = config->free;
    nc->bmworkarea = 0;
    wk->connectType = config->option.connectType;
    wk->skipNetCheck = config->option.skipNetCheck;
    wk->useDSWireless = config->option.useDSWireless;

    DWCi_BM_GetApInfo(wk->userInfo);
    if (OS_IsRunOnTwl()) {
        wk->wpaSetting = 0;
        DWCi_BM_GetApInfoEx(wk->userInfoEx);
        if (wk->connectType == 0) {
            if ((wk->userInfoEx[0].wpaMode >= 0x10 && wk->userInfoEx[0].wpaMode != 0xff) ||
                (wk->userInfoEx[1].wpaMode >= 0x10 && wk->userInfoEx[1].wpaMode != 0xff) ||
                (wk->userInfoEx[2].wpaMode >= 0x10 && wk->userInfoEx[2].wpaMode != 0xff)) {
                wk->wpaSetting = 1;
            }
        } else if (wk->connectType == 0xb) {
            if (wk->userInfoEx[0].wpaMode >= 0x10 && wk->userInfoEx[0].wpaMode != 0xff) {
                wk->wpaSetting = 1;
            }
        } else if (wk->connectType == 0xc) {
            if (wk->userInfoEx[1].wpaMode >= 0x10 && wk->userInfoEx[1].wpaMode != 0xff) {
                wk->wpaSetting = 1;
            }
        } else if (wk->connectType == 0xd) {
            if (wk->userInfoEx[2].wpaMode >= 0x10 && wk->userInfoEx[1].wpaMode != 0xff) {
                wk->wpaSetting = 1;
            }
        }
    }

    if (OS_IsRunOnTwl()) {
        if (wk->useDSWireless == 1) {
            result = WCM_Init(s_ac_work.wcmBuffer, 0x4800);
        } else {
            result = WCM_InitEx(s_ac_work.wcmBuffer, 0x4800, 2);
        }
    } else {
        result = WCM_Init(s_ac_work.wcmBuffer, 0x4800);
    }
    if (result == 1 || result > 4) {
        DWCi_AC_FreeAll();
        return 0;
    }
    return 1;
}
