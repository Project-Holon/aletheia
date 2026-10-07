/*
 * function: AutoConfigThreadEx
 * address:  0x021BA804
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p -ipa file
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SDK: TwlDWC/lib/ARM9-TS/Rom/libdwcutil.TWL.HYB.a(atermset.o).
 * Object stamped Metrowerks 3.0.0.126 -> ../2.0/sp1p2.
 *
 * CLOSED 2026-10-01 (user-approved build setting): atermset.o was built with `-O4,p -ipa file`.
 *   The Debug/Release libdwcutil archives show the real text at the code-less lines 643-647:
 *   `} else { if (g_021DAB58.bDebug) OS_Printf(fmt, eid); }` with OS_Printf compiling to
 *   nothing in Rom. That source is EXACT under -ipa file and replaces the earlier redundant
 *   `if (bAtermApCanceled) break;` stand-in. The trailing g_AutoConfigThreadEx_entry pointer
 *   models the object's address-taking use (thread entry), without which -ipa file drops
 *   the static. All 55 other matched atermset.o functions stay EXACT under -ipa file.
 *   Earlier lane notes below are history.
 *
 * lane 06 (2026-10-01): 843 -> 3 B under the header's ../2.0/sp1p2 (the earlier
 *   blocker text measured 1.1p1). What closed it: the sibling ATERMSET_BSS/ATERMSET_DATA
 *   layouts instead of raw offsets; SOC_Socket(2, 2, 0); __builtin__clear of `server`
 *   before the field stores; memcpy(aKeySource, lpe, 8) through string.h (the countdown
 *   byte loop); GetMacEncKey called with (aMacEncKey, &target) through an unprototyped
 *   declaration (the image sets r1 before the call); bfinish = 0 as a statement after
 *   iretry; the AutoProfile check as if/else stores; and two second names: the
 *   SetSingleElement argument is `&btAutoResult` (its own pool word at the same address
 *   as the .bss base) and the Ssid test reads g_021DD310[0x14] (pool word AutoProfile+0xec,
 *   index 0x14; every AutoProfile spelling folds to +0x100/#0). Residue: three Thumb
 *   branch-island targets (+010E, +011A, +01B0 jump to the `b` at +01FC, image +01EA);
 *   case-6 spelled with gotos, &&/if-else, nested ifs and else-if all pick +01FC.
 * lane09 wave2 (2026-10-01): still 3 B. Measured: the far conditional branches reuse
 *   only a fixer-made island (`bcc skip; b L`), never a plain `break` b (removing the
 *   retry6 test makes the eid test invert into its own island at +01B2, which case 4
 *   then reuses; retry6 written before the eid test makes the eid island the shared one).
 *   Islands appear to be made last-branch-first, so ours makes retry6's +01FC first; the
 *   image's +01EA must have been an island when the case-4/eid branches were fixed.
 *   Inert here: case-4 failures as `continue`, eid as `if (eid == 257) {..} break/continue`,
 *   retry6 as `if (>=) AutoPhase = 5;`.
 * lane03 wave3 (2026-10-01): still 3 B. New evidence: atermset.o carries a
 *   DWARF2 .debug_line (parse it with the object's relocations): case 4 breaks
 *   right after SendNotify (603), case 6's b at +01EA is a separate `break`
 *   at 648, five lines after the eid-if's SendNotify (642), and the retry
 *   test/AutoPhase=5/break are 651/653/655. Body reshaped to that (n as the
 *   DWARF local, nested ifs, break after the eid-if, `if (>=) {..} break;`),
 *   same 3 B. Far-branch survey of matched Thumb code: every far Bcc that
 *   lands on a non-island `b` lands on a cross-jumped hop (a join that held
 *   real code when jumps were threaded). Measured inert (sp1p2, 40+ shapes):
 *   switch(eid) forms, else/empty-else/else-break arms, continue variants,
 *   do/while(0), labels, debug-flag ifs, inline-constant ifs, &&-merged
 *   tests, separate file statics, -g; all 2.0 builds give the same 3 B.
 * wave4 (2026-10-01): EXACT. The fixer reuses only a `b L` that starts its
 *   own basic block; the image's +01EA is one because the join after the
 *   eid-if (source lines 643-647 emit no code) held a conditional test
 *   when jumps were threaded, so the eid bne kept targeting it, and the
 *   test (both arms break) was dropped later. Any condition gives the same
 *   bytes (bfinish, eid == 257 tested too); the original one is unknown.
 *
 * symbols:
 *   OS_Sleep          0x02085a38 arm
 *   ScanAP            0x021b9bf8 thumb
 *   SendNotify        0x021bc804 thumb
 *   ConnectAP         0x021b98a4 thumb
 *   SOC_Socket        0x0215f428 arm
 *   SOC_Bind          0x0215f454 arm
 *   GetTickCount      0x021bc584 thumb
 *   SOC_Close         0x0215f644 arm
 *   GetMacEncKey      0x021ba2f8 thumb
 *   SOC_RecvFrom      0x0215f500 arm
 *   IsSearchCommand   0x021ba12c thumb
 *   SetSearchRes      0x021ba250 thumb
 *   SendFrame         0x021b9ee0 thumb
 *   GetCommandElement 0x021ba200 thumb
 *   GetFirstElement   0x021b9fac thumb
 *   MD5Encode         0x021bc55c thumb
 *   SetSingleElement  0x021ba104 thumb
 *   SetFrameData      0x021b9fe0 thumb
 *   GetWLanSetElement 0x021ba3f4 thumb
 *   APC_GetState      0x021b96a8 thumb
 *   StoreNetParam     0x021ba67c thumb
 *   g_021DCFD0        0x021dcfd0 data
 *   btAutoResult      0x021dcfd0 data
 *   g_021DAB58        0x021dab58 data
 *   g_021DD490        0x021dd490 data
 *   g_021DDD04        0x021ddd04 data
 *   g_021DD020        0x021dd020 data
 *   g_021DD504        0x021dd504 data
 *   g_021DD4A0        0x021dd4a0 data
 *   g_021DD4A8        0x021dd4a8 data
 *   g_021DD224        0x021dd224 data
 *   g_021DD310        0x021dd310 data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../include/G_ATERMSET_DATA.h"
#include "../include/G_ATERMSET_BSS.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct SOCInAddr {
    u32 addr;
};

struct SOCSockAddrIn {
    u8 len;
    u8 family;
    u16 port;
    struct SOCInAddr addr;
};

typedef struct {
    char ConfigName[256];
    char Ssid[32];
    u32 NetworkType;
    u32 Channel;
    u32 PowerManagement;
    u8 EncryptData[0x118];
    u32 AdHocBand;
    u32 AdHocChannel;
    u32 scanMode;
    u32 tpc;
} WS11G_PROFILE_DATA;

struct WCMConfig;

typedef struct {
    unsigned char             btAutoResult;
    void                   *(*gAtermAlloc)(unsigned long size);
    struct WCMConfig         *apci_IWConfig;
    void                    (*gAtermFree)(void *ptr);
    int                       bAtermApCanceled;
    int                       cbFrameData;
    int                       gAPId;
    int                       AutoPhase;
    int                       bApConnect;
    int                       bSO_Startup;
    unsigned char            *apci_Wep;
    int                       apci_state;
    unsigned long long       *gThreadStack;
    int                       cbElementData;
    int                       gAtermApState;
} ATERMSET_BSS;

typedef struct {
    unsigned char *lpElementData;
    int            bDebug;
    unsigned long  gThreadStackSize;
    unsigned long  gAtermApTimeout;
    int            gMaxBssIdList;
} ATERMSET_DATA;

extern struct ATERMSET_BSS g_021DCFD0;
extern unsigned char btAutoResult;
/* OS_Printf compiles to nothing in the Rom (FINALROM) build. */
#define OS_Printf(fmt, arg) ((void)0)

extern struct ATERMSET_DATA g_021DAB58;
extern u8 g_021DD490[16];
extern u8 g_021DDD04[2048];
extern int g_021DD020;
extern u8 g_021DD504[2048];
extern u8 g_021DD4A0[8];
extern u8 g_021DD4A8[8];
extern WS11G_PROFILE_DATA g_021DD224;
extern signed char g_021DD310[];

extern void OS_Sleep(u32 msec);
extern int ScanAP(void);
extern void SendNotify(void);
extern int ConnectAP(void);
extern int SOC_Socket(int pf, int type, int protocol);
extern int SOC_Bind(int s, void *sockAddr);
extern u32 GetTickCount(void);
extern int SOC_Close(int s);
extern int GetMacEncKey();
extern int SOC_RecvFrom(int s, void *buf, int len, int flags, void *sockFrom);
extern int IsSearchCommand(u8 *lpframe, int *pdual);
extern int SetSearchRes(u8 *lpframe);
extern int SendFrame(int sock, void *lpb, void *frame, int size);
extern int GetCommandElement(u8 *lpframe, int cmdid, u8 *lpelement, u8 *lpkey);
extern u8 *GetFirstElement(u8 *lpelement, int *pid, int *psize);
extern void MD5Encode(u8 *digest, u8 *psrc, int srclen);
extern int SetSingleElement(u8 *lpbuff, int eid, u8 *pele, int esize);
extern int SetFrameData(u8 *lpframe, int id, u8 *pbody, int size, u8 *lpkey);
extern int GetWLanSetElement(u8 *lpelement);
extern int APC_GetState(void);
extern int StoreNetParam(void);

static int AutoConfigThreadEx(void)
{
    int sock = 0;
    int ret;
    struct SOCSockAddrIn server;
    struct SOCSockAddrIn target;
    int n;
    unsigned long dwSendTick;
    u8 *lpe;
    int eid;
    int esize;
    int iretry;
    int bfinish;
    unsigned long dw;
    int state;

    ret = -5;
    dwSendTick = 0;
    iretry = 0;
    bfinish = 0;
    g_021DCFD0.AutoPhase = 1;

    while (!bfinish && g_021DCFD0.bAtermApCanceled == 0) {
        OS_Sleep(500);
        switch (g_021DCFD0.AutoPhase) {
        case 1:
            ret = ScanAP();
            if (ret != 1) {
                bfinish = 1;
                break;
            }
            g_021DCFD0.gAtermApState = 3;
            SendNotify();
            g_021DCFD0.AutoPhase = 2;
            break;
        case 2:
            ret = ConnectAP();
            if (ret != 1) {
                bfinish = 1;
                break;
            }
            g_021DCFD0.AutoPhase = 3;
            break;
        case 3:
            sock = SOC_Socket(2, 2, 0);
            if (sock < 0) {
                ret = -2;
                bfinish = 1;
                break;
            }
            __builtin__clear(&server, sizeof(server));
            server.len = sizeof(server);
            server.family = 2;
            server.port = 486;
            server.addr.addr = 0;
            ret = SOC_Bind(sock, &server);
            if (ret < 0) {
                ret = -2;
                bfinish = 1;
                break;
            }
            g_021DCFD0.AutoPhase = 4;
            break;
        case 4:
            if (GetTickCount() >= g_021DAB58.gAtermApTimeout) {
                SOC_Close(sock);
                ret = -3;
                bfinish = 1;
                break;
            }
            target.len = sizeof(target);
            GetMacEncKey(g_021DD490, &target);
            n = SOC_RecvFrom(sock, g_021DDD04, 0x800, 4, &target);
            if (n > 0) {
                if (IsSearchCommand(g_021DDD04, &g_021DD020)) {
                    g_021DAB58.gAtermApTimeout = GetTickCount() + 30000;
                    g_021DCFD0.AutoPhase = 5;
                    g_021DCFD0.gAtermApState = 4;
                    SendNotify();
                    break;
                }
            }
            break;
        case 5:
            g_021DCFD0.cbFrameData = SetSearchRes(g_021DDD04);
            SendFrame(sock, &target, g_021DDD04, g_021DCFD0.cbFrameData);
            dwSendTick = GetTickCount();
            g_021DCFD0.AutoPhase = 6;
            break;
        case 6:
            if (GetTickCount() >= g_021DAB58.gAtermApTimeout) {
                SOC_Close(sock);
                ret = -4;
                bfinish = 1;
                break;
            }
            n = SOC_RecvFrom(sock, g_021DDD04, 0x800, 4, &target);
            if (n > 0) {
                if (GetCommandElement(g_021DDD04, 3, g_021DD504, g_021DD490)) {
                    lpe = GetFirstElement(g_021DD504, &eid, &esize);
                    if (eid == 257) {
                        dw = GetTickCount();
                        memcpy(g_021DD4A0, lpe, 8);
                        MD5Encode(g_021DD4A8, (u8 *)&dw, 4);
                        iretry = 0;
                        g_021DCFD0.AutoPhase = 7;
                        g_021DCFD0.gAtermApState = 5;
                        g_021DAB58.gAtermApTimeout = -1;
                        SendNotify();
                    } else {
                        if (g_021DAB58.bDebug)
                            OS_Printf("eid %d
", eid);
                    }
                    break;
                }
            }
            if (GetTickCount() >= dwSendTick + 1000) {
                g_021DCFD0.AutoPhase = 5;
            }
            break;
        case 7:
            g_021DCFD0.cbElementData = SetSingleElement(g_021DD504, 258, g_021DD4A8, 8);
            g_021DCFD0.cbFrameData = SetFrameData(g_021DDD04, 4, g_021DD504, g_021DCFD0.cbElementData, g_021DD490);
            SendFrame(sock, &target, g_021DDD04, g_021DCFD0.cbFrameData);
            dwSendTick = GetTickCount();
            __builtin__clear(&g_021DD224, sizeof(g_021DD224));
            g_021DCFD0.AutoPhase = 8;
            break;
        case 8:
            if (SOC_RecvFrom(sock, g_021DDD04, 0x800, 4, &target) > 0
                && (g_021DCFD0.cbElementData = GetCommandElement(g_021DDD04, 5, g_021DD504, g_021DD4A0)) != 0
                && GetWLanSetElement(g_021DD504)) {
                if (g_021DD310[0x14] != 0)
                    g_021DCFD0.btAutoResult = 1;
                else
                    g_021DCFD0.btAutoResult = 0;
                iretry = 0;
                g_021DCFD0.AutoPhase = 9;
                break;
            }
            if (GetTickCount() < dwSendTick + 1000)
                break;
            if (++iretry >= 10) {
                SOC_Close(sock);
                ret = -2;
                bfinish = 1;
                break;
            }
            g_021DCFD0.AutoPhase = 7;
            break;
        case 9:
            g_021DCFD0.cbElementData = SetSingleElement(g_021DD504, 769, &btAutoResult, 1);
            g_021DCFD0.cbFrameData = SetFrameData(g_021DDD04, 6, g_021DD504, g_021DCFD0.cbElementData, g_021DD4A0);
            state = APC_GetState();
            if (state != 7) {
                dwSendTick = GetTickCount() + 1000;
                iretry = 10;
                g_021DCFD0.AutoPhase = 10;
                break;
            }
            SendFrame(sock, &target, g_021DDD04, g_021DCFD0.cbFrameData);
            dwSendTick = GetTickCount();
            g_021DCFD0.AutoPhase = 10;
            break;
        case 10:
            if (GetTickCount() < dwSendTick + 1000)
                break;
            if (++iretry >= 10) {
                bfinish = 1;
                ret = StoreNetParam();
                break;
            }
            g_021DCFD0.AutoPhase = 9;
            break;
        }
    }
    if (sock != 0)
        SOC_Close(sock);
    if (g_021DCFD0.bAtermApCanceled != 0)
        ret = -8;
    return ret;
}

/* atermset.o takes this static's address (the thread entry passed to
 * OS_CreateThread); without an address-taking use, -ipa file drops it. */
void *g_AutoConfigThreadEx_entry = (void *)AutoConfigThreadEx;
