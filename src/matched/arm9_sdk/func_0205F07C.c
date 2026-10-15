/*
 * function: DWCi_AC_ConnectTest
 * address:  0x0205F07C
 * packet:   pkt_0205F07C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_ConnectTest (libdwcac.TWL.HYB.a(test.o))
 *
 * symbols:
 *   DWCi_AC_GetPhase                 0x0205c2c4 arm
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   WCM_GetPhase                     0x021656a0 arm
 *   ConnectTestStart                 0x0205f154 arm
 *   GetIPAddress                     0x0205f1b8 arm
 *   ConnectTestCreate                0x0205f298 arm
 *   ConnectTestProcess               0x0205f2c4 arm
 *   ConnectTestEnd                   0x0205f35c arm
 *   ConnectTestRetry                 0x0205f384 arm
 *   DWC_Netcheck_Abort               0x0217aa20 arm
 *   DWC_Netcheck_Destroy             0x0217a950 arm
 */

typedef struct tagACFL {
    unsigned char state;
    unsigned char pad[3];
} tagACFL;

typedef struct tagACWORK {
    unsigned char pad0[0xbf4];
    tagACFL findList[11];
    unsigned char pad1[0x14bd - 0xc20];
    unsigned char connectApType;
    unsigned char phaseBak;
    unsigned char searchListNo;
    unsigned char searchListNum;
    signed char searchChannel;
    unsigned char findListNum;
    unsigned char connectNo;
    unsigned char connectResult;
    unsigned char count;
    unsigned short stealthChannel;
    long rwin;
    unsigned char wontExecuteEULACheck;
    unsigned short maxChannel;
    unsigned char padding;
    unsigned short passiveScanTime;
    unsigned short activeScanTime;
} tagACWORK;

typedef struct tagACHOLD {
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
    unsigned char allocState;
    unsigned char phase;
    unsigned char phaseError;
    unsigned char findAP : 4;
    unsigned char ipCollision : 4;
    int error;
    int errorTest;
    unsigned char endState;
    unsigned char endType;
    unsigned char endSequence;
    unsigned char type;
    char apSpotInfo[10];
    unsigned char overrideType;
    unsigned char security;
    unsigned char proxyMode;
    unsigned char proxyAuthType;
    unsigned short proxyPort;
    unsigned char proxyHost[100];
    unsigned char proxyId[32];
    unsigned char proxyPass[32];
} tagACHOLD;

extern void *DWCi_AC_GetMemPtr(unsigned long name);

extern unsigned char DWCi_AC_GetPhase(void);
extern long WCM_GetPhase(void);
extern unsigned char ConnectTestStart(tagACWORK *wk);
extern unsigned char GetIPAddress(tagACWORK *wk);
extern unsigned char ConnectTestCreate(void);
extern unsigned char ConnectTestProcess(tagACWORK *wk);
extern unsigned char ConnectTestEnd(tagACWORK *wk);
extern unsigned char ConnectTestRetry(void);
extern void DWC_Netcheck_Abort(void);
extern void DWC_Netcheck_Destroy(void);

unsigned char DWCi_AC_ConnectTest(void)
{
    unsigned char phase;
    tagACWORK *wk;

    phase = DWCi_AC_GetPhase();
    wk = (tagACWORK *)DWCi_AC_GetMemPtr(0x10);
    if (WCM_GetPhase() == 9) {
        switch (phase) {
        case 10:
            phase = ConnectTestStart(wk);
            break;
        case 12:
            phase = GetIPAddress(wk);
            break;
        case 13:
            phase = ConnectTestCreate();
            break;
        case 14:
            phase = ConnectTestProcess(wk);
            break;
        case 15:
            phase = ConnectTestEnd(wk);
            break;
        case 11:
            phase = ConnectTestRetry();
            break;
        }
    } else {
        switch (phase) {
        case 15:
            phase = ConnectTestEnd(wk);
            break;
        case 11:
            phase = ConnectTestRetry();
            break;
        case 14:
            DWC_Netcheck_Abort();
            DWC_Netcheck_Destroy();
        default:
            wk->findList[wk->connectNo].state = 2;
            phase = 11;
            break;
        }
    }
    return phase;
}
