/*
 * file:     unit_0216F014_p04.c
 * unit:     yes
 * function: func_0216F770, func_0216FAD4
 * address:  0x0216F770
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_021685CC  0x021685CC  arm  ov009
 *   func_0219F00C  0x0219F00C  arm  ov009
 *   func_0219EED4  0x0219EED4  arm  ov009
 *   OS_SNPrintf    0x02084F80  arm
 *   OS_GetTick     0x020870D0  arm
 *   stGameMatchKeys          0x021AAA40  data
 *   s_anybodyServerSearchRatio 0x021A203C  data
 *   s_bInNNThink             0x021AAA20  data
 *   d_021A2090     0x021A2090  data
 *   d_021A209C     0x021A209C  data
 *   d_021A20A4     0x021A20A4  data
 *   d_021A20AC     0x021A20AC  data
 *   d_021A20D4     0x021A20D4  data
 *   d_021A20E0     0x021A20E0  data
 *   func_02084F80  0x02084F80  arm
 *   func_0209477C  0x0209477C  arm
 *   g_021A20E0     0x021A20E0  data
 *   g_021A20F0     0x021A20F0  data
 *   g_021A209C     0x021A209C  data
 *   g_021A20A4     0x021A20A4  data
 *   g_021A2170     0x021A2170  data
 *   g_021A217C     0x021A217C  data
 *   g_021A2108     0x021A2108  data
 *   g_021A2164     0x021A2164  data
 */
#include "../../matched/include/G_NNThinkGlobal.h"
#include "../../matched/include/G_MatchAnchorA.h"

struct ServerBrowser;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

typedef enum { E0 = 0, E6 = 6 } EFld;

typedef enum { SBFalse, SBTrue } SBBool;

typedef enum { sbe_noError, sbe_socketError, sbe_dnsError, sbe_connectError, sbe_dataError, sbe_allocError, sbe_paramError, sbe_duplicateUpdateError } SBError;

typedef struct {
    u8 keyID;
    u8 pad[11];
} DWCstGameMatchKeyData;

typedef struct {
    u8 pad0[0x15];
    u8 qr2MatchType;            /* 0x015 */
    u8 pad16;
    u8 qr2NumEntry;             /* 0x017 */
    u8 pad18[0x5e0 - 0x18];
    void *sbObj;                /* 0x5e0 */
    u8 pad5e4[0x5f0 - 0x5e4];
    u64 sbUpdateTick;           /* 0x5f0 */
    u8 pad5f8[0x61c - 0x5f8];
    int state;                  /* 0x61c */
    u8 pad620[0x678 - 0x620];
    int profileID;              /* 0x678 */
    int reqProfileID;           /* 0x67c */
    u8 pad680[0x790 - 0x680];
    int gameID;                 /* 0x790 */
    u8 pad794[0x7a8 - 0x794];
    u8 friendToggle;            /* 0x7a8 */
    u8 pad7a9[3];
    int sbUpdateCount;          /* 0x7ac */
} DWCstMatchControl;

extern DWCstMatchControl *func_02175F3C(void);
extern u32 func_021685CC(u32 max);
extern void func_0219F00C(char *p);
extern int func_0219EED4(struct ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers);
extern int OS_SNPrintf(char *dst, u32 len, const char *fmt, ...);
extern u64 OS_GetTick(void);
extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
extern int func_0209477C(const u8 *s);
int func_0216FAD4(char *filter, int profileID, unsigned char numEntry, unsigned char matchType, unsigned char hostState);
extern DWCstGameMatchKeyData stGameMatchKeys[154];
extern struct MatchAnchorA s_anybodyServerSearchRatio;
extern struct NNThinkGlobal s_bInNNThink;
extern char d_021A2090[];
extern char d_021A209C[];
extern char d_021A20A4[];
extern char d_021A20AC[];
extern char d_021A20D4[];
extern char d_021A20E0[];
extern char g_021A20E0[];
extern char g_021A20F0[];
extern char g_021A209C[];
extern char g_021A20A4[];
extern char g_021A2170[];
extern char g_021A217C[];
extern char g_021A2108[];
extern char g_021A2164[];


/*
 * 2026-10-01 (lane 05): rebuilt from the vendor listing, 868/868 bytes and
 *           6 concrete bytes (was 212 via permuter scaffolding).  Fixes: the
 *           ratio tests are -2 then -1 (not -1 then 0) with a signed rand
 *           compare; s_bInNNThink+0xc is a char * static passed as the
 *           SNPrintf argument; cases 3/4/0x16 and 9-11 print profileID (the
 *           parameter, still in r4) with fmt d_021A209C/d_021A20A4;
 *           searchHostType is set only in case 2; sbBlock/sbError are enums
 *           (DWARF); a real u64 tick across DWCi_GetMatchCnt; the key loop
 *           stores then increments; declarations in DWARF order.  Stand-in:
 *           the enum `n` (6 before the byte stores, then the retry counter)
 *           is not in the DWARF but is what keeps `mov sl,#6; add r7,sl,#3`
 *           and the do-while counter (an int folds both away; a 6-trip
 *           unrollable loop is not unrolled by 1.1p1).  Residue: the three
 *           DWCi_GetDefaultMatchFilter argument loads (image ldr r1 / ldrb r2
 *           / ldrb r3, ours ldrb r3 first); const members inert.
 * 2026-10-01 (wave 2 lane 20): EXACT.  The three argument loads read
 *           through `(volatile DWCstMatchControl *)` casts, which pins them
 *           in source (argument) order as the 4.0.0.1025 image has them;
 *           volatile on fewer than two of them leaves the 6 B residue.
 *
 * sdk:      DWCi_SBUpdateAsync (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
static SBError func_0216F770(int profileID)
{
    char filter[511];
    u8 basicFields[204];
    int len;
    int numBasicFields;
    int i;
    SBError sbError;
    SBBool sbBlock;
    u8 searchHostType;
    EFld n;

    n = E6;
    basicFields[0] = 8;
    basicFields[1] = 0xa;
    basicFields[2] = 0x32;
    basicFields[3] = 0x33;
    basicFields[4] = 0x34;
    basicFields[5] = 0x35;
    basicFields[6] = 0x36;
    basicFields[7] = 0x37;
    basicFields[8] = 0x38;
    numBasicFields = n + 3;
    sbBlock = SBTrue;
    if (func_02175F3C()->qr2MatchType == 0 || func_02175F3C()->qr2MatchType == 1) {
        for (i = 0; i < 154; i++) {
            if (stGameMatchKeys[i].keyID) {
                basicFields[numBasicFields] = stGameMatchKeys[i].keyID;
                numBasicFields++;
            }
        }
    }
    switch (func_02175F3C()->state) {
    case 2:
        if ((*(int *)&s_anybodyServerSearchRatio) == -2) {
            searchHostType = (u8)(func_02175F3C()->friendToggle == 1 ? 2 : 3);
            func_02175F3C()->friendToggle = 0;
        } else if ((*(int *)&s_anybodyServerSearchRatio) == -1) {
            searchHostType = (u8)(func_02175F3C()->friendToggle ? 2 : 0);
            func_02175F3C()->friendToggle ^= 1;
        } else {
            searchHostType = (u8)((int)func_021685CC(100) < (*(int *)&s_anybodyServerSearchRatio) ? 2 : 0);
        }
        len = func_0216FAD4(filter, ((volatile DWCstMatchControl *)func_02175F3C())->profileID, ((volatile DWCstMatchControl *)func_02175F3C())->qr2NumEntry, ((volatile DWCstMatchControl *)func_02175F3C())->qr2MatchType, searchHostType);
        if (s_bInNNThink.addFilter) {
            OS_SNPrintf(filter + len, 511 - len, d_021A2090, s_bInNNThink.addFilter);
            filter[510] = 0;
        }
        func_02175F3C()->sbUpdateCount++;
        break;
    case 3:
    case 4:
    case 0x16:
        OS_SNPrintf(filter, 511, d_021A209C, d_021A20A4, profileID);
        func_02175F3C()->reqProfileID = profileID;
        break;
    case 9:
    case 10:
    case 11:
        OS_SNPrintf(filter, 511, d_021A209C, d_021A20A4, profileID);
        sbBlock = SBFalse;
        break;
    case 12:
        OS_SNPrintf(filter, 511, d_021A20AC, d_021A20D4, func_02175F3C()->gameID, d_021A20E0, 2, d_021A20A4, func_02175F3C()->profileID);
        break;
    }

    func_0219F00C(func_02175F3C()->sbObj);
    n = E0;
    do {
        sbError = func_0219EED4(func_02175F3C()->sbObj, sbBlock, SBFalse, basicFields, numBasicFields, filter, func_02175F3C()->state == 0x16 ? 1 : 6);
        if (sbError == 0 || sbError != 2)
            break;
        n++;
    } while (n < 1);
    if (sbError == 0) {
        u64 tick = OS_GetTick();
        func_02175F3C()->sbUpdateTick = tick + 0xefb5f7;
    }
    return sbError;
}


/*
 * sdk:      DWCi_GetDefaultMatchFilter (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_0216FAD4(char *filter, int profileID, unsigned char numEntry, unsigned char matchType,
                  unsigned char hostState)
{
    char tempFilter[511];

    if (hostState == 3)
        func_02084F80(tempFilter, 511, g_021A20F0, g_021A20E0, 0, g_021A20E0, 2);
    else
        func_02084F80(tempFilter, 511, g_021A209C, g_021A20E0, hostState);
    func_02084F80(filter, 511, g_021A2108, g_021A2164, 90, g_021A20A4, profileID, numEntry, numEntry,
                  g_021A2170, matchType, g_021A217C, 0, tempFilter);
    return func_0209477C((const u8 *)filter);
}
