/*
 * file:     unit_0205B98C_p02.c
 * unit:     yes
 * function: func_0205BC78, func_0205BD64, func_0205BDD0, func_0205BE00, func_0205BE58
 * address:  0x0205BC78
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
 *   CheckEULA             0x0205C600  arm
 *   CheckWirelessPowerON  0x0205C670  arm
 *   CheckDuplicate        0x0205C55C  arm
 *   Free_Disused          0x0205C528  arm
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

extern u8 DWCi_AC_GetPhase(void);
extern BOOL CheckEULA(void);
extern BOOL CheckWirelessPowerON(void);
extern u8 DWCi_AC_Start(void);
extern void DWCi_AC_SetError(int error);
extern u32 OS_DisableInterrupts(void);
extern u8 DWCi_AC_SearchAP(void);
extern void DWCi_AC_SetPhase(u8 phase);
extern u32 OS_RestoreInterrupts(u32 state);
extern u8 DWCi_AC_ConnectAP(void);
extern u8 DWCi_AC_ConnectRetryAP(void);
extern u8 DWCi_AC_ConnectTest(void);
extern u8 DWCi_AC_Error(void);
extern BOOL CheckDuplicate(void);
extern void Free_Disused(void);
extern int DWCi_AC_GetResult(void);
extern void *DWCi_AC_GetMemPtr(u32 name);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
int func_0205BC78(void);
int func_0205BD64(void);
u8 func_0205BDD0(void);
BOOL func_0205BE00(u8 *apSpotInfo);
unsigned int DWC_AC_GetSecuritySetting(void);



/*
 * sdk:      DWC_AC_Process (dwc_ac.o)
 */
int func_0205BC78(void)
{
    int ret;
    u32 irq;
    u8 phase = DWCi_AC_GetPhase();

    if (phase == 1) {
        if (CheckEULA()) {
            if (CheckWirelessPowerON()) {
                phase = DWCi_AC_Start();
            } else {
                DWCi_AC_SetError(8);
                phase = DWCi_AC_Error();
            }
        } else {
            DWCi_AC_SetError(7);
            phase = DWCi_AC_Error();
        }
    } else if (phase < 7) {
        irq = OS_DisableInterrupts();
        phase = DWCi_AC_SearchAP();
        DWCi_AC_SetPhase(phase);
        OS_RestoreInterrupts(irq);
    } else if (phase < 9) {
        phase = DWCi_AC_ConnectAP();
    } else if (phase < 0xa) {
        phase = DWCi_AC_ConnectRetryAP();
    } else if (phase < 0x10) {
        phase = DWCi_AC_ConnectTest();
    } else if (phase == 0x11) {
        phase = DWCi_AC_Error();
    }
    DWCi_AC_SetPhase(phase);
    if (phase == 0x10) {
        ret = CheckDuplicate();
        Free_Disused();
        return ret;
    }
    if (phase == 0x12) {
        Free_Disused();
        return -1;
    }
    return 0;
}



/*
 * sdk:      DWC_AC_GetStatus (dwc_ac.o)
 */
int func_0205BD64(void)
{
    u8 phase = DWCi_AC_GetPhase();

    if (phase <= 1) return 0;
    if (phase < 7) return 1;
    if (phase == 9) return 4;
    if (phase < 0xa) return 2;
    if (phase == 0xb) return 4;
    if (phase < 0x10) return 3;
    if (phase == 0x10) return 5;
    if (phase == 0x11) return 4;
    return DWCi_AC_GetResult();
}



static struct {
    void *wcmBuffer;
    void *socConfig;
    void *netCheck;
    ACHOLD *acHold;
    ACWORK *acWork;
} s_ac_work;



/*
 * sdk:      DWC_AC_GetApType (dwc_ac.o)
 */
u8 func_0205BDD0(void)
{
    u8 type = 0xff;
    u8 phase = DWCi_AC_GetPhase();

    if (phase >= 0xa && phase <= 0x10) {
        type = s_ac_work.acHold->type;
    }
    return type;
}



/*
 * sdk:      DWC_AC_GetApSpotInfo (dwc_ac.o)
 */
BOOL func_0205BE00(u8 *apSpotInfo)
{
    BOOL result = 0;
    u8 phase = DWCi_AC_GetPhase();

    if (phase >= 0xa && phase <= 0x10) {
        if (s_ac_work.acHold->type == 4 || s_ac_work.acHold->type == 8) {
            MI_CpuCopy8(s_ac_work.acHold->apSpotInfo, apSpotInfo, 10);
            result = 1;
        }
    }
    return result;
}



unsigned int DWC_AC_GetSecuritySetting(void)
{
    unsigned char *hd = (unsigned char *)DWCi_AC_GetMemPtr(1);
    return hd[35];
}
