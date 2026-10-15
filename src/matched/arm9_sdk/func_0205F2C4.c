/*
 * function: ConnectTestProcess
 * address:  0x0205F2C4
 * packet:   pkt_0205F2C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ConnectTestProcess (libdwcac.TWL.HYB.a(test.o))
 *
 * symbols:
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   DWC_Netcheck_GetError            0x0217aaa0 arm
 *   DWCi_ConvConnectAPType           0x0205c4c8 arm
 *   DWC_Netcheck_GetReturnCode       0x0217aadc arm
 *   DWC_Netcheck_Destroy             0x0217a950 arm
 *   CPSNoIpReason                    0x021a82b8 data
 *   g_021A82B8                       0x021A82B8 data
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

extern int CPSNoIpReason;
extern int DWC_Netcheck_GetError(void);
extern unsigned char DWCi_ConvConnectAPType(unsigned char type);
extern int DWC_Netcheck_GetReturnCode(void);
extern void DWC_Netcheck_Destroy(void);

unsigned char ConnectTestProcess(tagACWORK *wk)
{
    tagACHOLD *hd;
    int result;

    hd = (tagACHOLD *)DWCi_AC_GetMemPtr(1);
    result = DWC_Netcheck_GetError();
    if (result != 0) {
        if (hd->endType == DWCi_ConvConnectAPType(wk->connectApType)) {
            hd->errorTest = DWC_Netcheck_GetReturnCode();
        }
        DWC_Netcheck_Destroy();
        if (result != 11) {
            wk->findList[wk->connectNo].state = 1;
            if (CPSNoIpReason == 4) {
                hd->ipCollision = 1;
            } else {
                hd->ipCollision = 0;
            }
            return 0xb;
        }
        return 0xf;
    }
    return 0xe;
}
