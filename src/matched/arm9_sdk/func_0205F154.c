/*
 * function: func_0205F154
 * address:  0x0205F154
 * packet:   pkt_0205F154
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ConnectTestStart (libdwcac.TWL.HYB.a(test.o))
 *
 * symbols:
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   MakeSOCConfig                    0x0205f3b0 arm
 *   SOC_Startup                      0x0215f8fc arm
 *   DWCi_AC_SetError                 0x0205c2e4 arm
 *   SOCLiYieldWait                   0x021aa440 data
 *   g_021AA440                       0x021AA440 data
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

struct SOCConfig;
extern int SOCLiYieldWait;
extern void MakeSOCConfig(tagACHOLD *hd, tagACWORK *wk, struct SOCConfig *sc);
extern int SOC_Startup(struct SOCConfig *config);
extern void DWCi_AC_SetError(int error);

unsigned char func_0205F154(tagACWORK *wk)
{
    tagACHOLD *hd;
    struct SOCConfig *sc;

    hd = (tagACHOLD *)DWCi_AC_GetMemPtr(1);
    sc = (struct SOCConfig *)DWCi_AC_GetMemPtr(4);
    MakeSOCConfig(hd, wk, sc);
    SOCLiYieldWait = 4;
    if (SOC_Startup(sc) == 0) {
        return 0xc;
    }
    DWCi_AC_SetError(2);
    return 0x11;
}
