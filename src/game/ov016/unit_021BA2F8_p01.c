/*
 * file:     unit_021BA2F8_p01.c
 * unit:     yes
 * function: func_021BA2F8, func_021BA3F4, AsciiToHex, func_021BA67C, AutoConfigThreadEx
 * address:  0x021BA2F8
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p -ipa file
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA2EC  0x021ba2ec  thumb  ov016
 *   func_020923F0  0x020923f0  arm
 *   func_021BC608  0x021bc608  thumb  ov016
 *   g_021DAC18  0x021dac18  data
 *   g_021DD480  0x021dd480  data
 *   g_021DD478  0x021dd478  data
 *   g_021DAB58  0x021dab58  data
 *   memcmp  0x020923F0  arm
 *   memcpy  0x02092344  arm
 *   memset  0x020923B0  arm
 *   func_021B9F5C  0x021B9F5C  thumb  ov016
 *   func_021BC5D4  0x021BC5D4  thumb  ov016
 *   g_021DD224  0x021DD224  data
 *   g_021DD324  0x021DD324  data
 *   g_021DD350  0x021DD350  data
 *   g_021DD388  0x021DD388  data
 *   g_021DD420  0x021DD420  data
 *   strcpy  0x02094798  arm
 *   strlen  0x0209477C  arm
 *   func_021BA5C8  0x021BA5C8  thumb  ov016
 *   g_021DD13C  0x021DD13C  data
 *   g_021DD150  0x021DD150  data
 *   g_021DD164  0x021DD164  data
 *   g_021DD1E4  0x021DD1E4  data
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
 *   g_021DD490        0x021dd490 data
 *   g_021DDD04        0x021ddd04 data
 *   g_021DD020        0x021dd020 data
 *   g_021DD504        0x021dd504 data
 *   g_021DD4A0        0x021dd4a0 data
 *   g_021DD4A8        0x021dd4a8 data
 *   g_021DD310        0x021dd310 data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G__ATERMApConfigParam.h"
#include "../../matched/include/G_ATERMSET_DATA.h"
#include "../../matched/include/G_ATERMSET_BSS.h"

#define SWAP16(x) ((u16)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
struct WCMConfig;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
    int keyType;
    int keyLen;
    char key[32];
} WepEntry;

typedef struct {
    char ConfigName[256];
    char Ssid[32];
    u32 NetworkType;
    u32 Channel;
    u32 PowerManagement;
    struct {
        u8 pad0[0x30];
        WepEntry wep[4];
        u8 pad1[0x118 - 0x30 - 0xA0];
    } EncryptData;
    u32 AdHocBand;
    u32 AdHocChannel;
    u32 scanMode;
    u32 tpc;
} WS11G_PROFILE_DATA;

typedef struct {
    int type;
    int defkey;
    char pad[0x28];
    int f30;
} EncCommon;

typedef struct { int w[18]; } Key72;

typedef struct { int w[16]; } Key64;

typedef struct {
    unsigned char *lpElementData;
    int            bDebug;
    unsigned long  gThreadStackSize;
    unsigned long  gAtermApTimeout;
    int            gMaxBssIdList;
} ATERMSET_DATA;

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

extern int func_021BA2EC(unsigned char *lpmac);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern int func_021BC608(char *lpwrite, char *lps);
extern u8 *func_021B9F5C(u8 **lplpb, u8 *lplimit, int *pid, int *psize);
extern int func_021BC5D4(char *lpwrite, char ch);
extern int func_021BA5C8(unsigned char *byDest, char *szStr, int nLen);
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
int func_021BA2F8(unsigned char *lpkey);
int func_021BA3F4(u8 *lpelement);
int AsciiToHex(unsigned char *byDest, char *szStr, int nLen);
int func_021BA67C(void);
extern const unsigned char g_021DAC18[];
extern unsigned char g_021DD480[6];
extern unsigned char g_021DD478[6];
extern struct ATERMSET_DATA g_021DAB58;
extern WS11G_PROFILE_DATA g_021DD224;
extern struct { int w[8]; } g_021DD324;
extern EncCommon g_021DD350;
extern char g_021DD388[4][0x28];
extern Key72 g_021DD420;
extern struct _ATERMApConfigParam g_021DD13C;
extern struct {
    int pad[3];
    int auth_mode;
    int wepkeyid;
} g_021DD150;
extern char g_021DD164[4][32];
extern Key64 g_021DD1E4;
extern struct ATERMSET_BSS g_021DCFD0;
extern unsigned char btAutoResult;
extern u8 g_021DD490[16];
extern u8 g_021DDD04[2048];
extern int g_021DD020;
extern u8 g_021DD504[2048];
extern u8 g_021DD4A0[8];
extern u8 g_021DD4A8[8];
extern signed char g_021DD310[];





/*
 * sdk:      GetMacEncKey (libdwcutil.TWL.HYB.a(atermset.o))
 */
int func_021BA2F8(unsigned char *lpkey)
{
    char strmac[32];
    char strap[32];
    unsigned char ap_mac[6];
    unsigned char sta_mac[6];
    int ret;

    memcpy(lpkey + 12, g_021DAC18, 4);
    memcpy(ap_mac, g_021DD480, 6);
    ap_mac[0] &= 0xfd;
    func_021BA2EC(sta_mac);
    memcpy(g_021DD478, sta_mac, 6);
    ret = memcmp(ap_mac, sta_mac, 6);
    if (ret <= 0) {
        memcpy(lpkey, sta_mac, 6);
        memcpy(lpkey + 6, ap_mac, 6);
    } else {
        memcpy(lpkey, ap_mac, 6);
        memcpy(lpkey + 6, sta_mac, 6);
    }
    if (g_021DAB58.bDebug) {
        func_021BC608(strmac, (char *)sta_mac);
        func_021BC608(strap, (char *)ap_mac);
    }
    return 1;
}





int func_021BA3F4(u8 *lpelement)
{
    int retv;
    u8 *lpb;
    u8 *lpw;
    int eid;
    int esize;
    int i;
    u16 len;
    u8 *lpe;
    char *wp;

    lpe = lpelement;
    lpe += 8;
    lpb = lpe;
    retv = 0;
    len = SWAP16(*(u16 *)lpelement);
    while ((lpw = func_021B9F5C(&lpb, lpe + len, &eid, &esize)) != 0) {
        switch (eid) {
        case 0x201:
            __builtin__clear(&g_021DD324, 32);
            memcpy(&g_021DD324, lpw, esize);
            retv = 1;
            break;
        case 0x202:
            g_021DD350.type = SWAP16(*(u16 *)lpw);
            break;
        case 0x203:
            {
                u16 v = SWAP16(*(u16 *)lpw);
                for (i = 0; i < 4; i++)
                    g_021DD224.EncryptData.wep[i].keyType = v;
            }
            break;
        case 0x204:
            {
                u16 v = SWAP16(*(u16 *)lpw);
                for (i = 0; i < 4; i++)
                    g_021DD224.EncryptData.wep[i].keyLen = v;
            }
            break;
        case 0x205:
            g_021DD350.defkey = SWAP16(*(u16 *)lpw);
            break;
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x209:
            memset(g_021DD388[eid - 0x206], 0, 32);
            if (g_021DD350.f30 == 1) {
                wp = g_021DD388[eid - 0x206];
                for (i = 0; i < esize; i++)
                    wp += func_021BC5D4(wp, *(char *)lpw++);
            } else {
                memcpy(g_021DD388[eid - 0x206], lpw, esize);
            }
            break;
        case 0x20a:
            __builtin__clear(&g_021DD420, 72);
            memcpy(&g_021DD420, lpw, esize);
            break;
        }
    }
    return retv;
}



int AsciiToHex(unsigned char *byDest, char *szStr, int nLen)
{
    int ch;
    int b;
    int i;

    b = 0;
    for (i = 0; i < nLen; i++) {
        ch = szStr[i];
        switch (ch) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            b += ch - '0';
            break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            b += ch - 'a' + 10;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
            b += ch - 'A' + 10;
            break;
        default:
            return 0;
        }
        if (i % 2 == 0) {
            b <<= 4;
        } else {
            byDest[i / 2] = b;
            b = 0;
        }
    }
    return 1;
}



int func_021BA67C(void)
{
    char szwep[36];
    int i;
    int defkey;
    char *lpwep;
    int ret;

    ret = 1;
    strcpy(((char *)&g_021DD13C), (char *)&g_021DD324);
    switch (g_021DD350.type) {
    case 0:
        g_021DD150.auth_mode = 0;
        break;
    case 1:
        defkey = g_021DD350.defkey;
        if (defkey == 0) {
            ret = -7;
            break;
        }
        g_021DD150.wepkeyid = defkey;
        for (i = 0; i < 4; i++) {
            lpwep = szwep;
            memcpy(szwep, g_021DD388[i], 32);
            szwep[32] = 0;
            switch (strlen(szwep)) {
            case 0:
                break;
            case 5:
                g_021DD150.auth_mode = 1;
                memcpy(g_021DD164[i], lpwep, 5);
                break;
            case 10:
                g_021DD150.auth_mode = 1;
                func_021BA5C8((unsigned char *)g_021DD164[i], lpwep, 10);
                break;
            case 13:
                g_021DD150.auth_mode = 2;
                memcpy(g_021DD164[i], lpwep, 13);
                break;
            case 26:
                g_021DD150.auth_mode = 2;
                func_021BA5C8((unsigned char *)g_021DD164[i], lpwep, 26);
                break;
            case 16:
                g_021DD150.auth_mode = 3;
                memcpy(g_021DD164[i], lpwep, 16);
                break;
            case 32:
                g_021DD150.auth_mode = 3;
                func_021BA5C8((unsigned char *)g_021DD164[i], lpwep, 32);
                break;
            default:
                ret = -7;
                break;
            }
        }
        break;
    case 2:
        g_021DD150.auth_mode = 4;
        memcpy(&g_021DD1E4, &g_021DD420, 64);
        break;
    case 3:
        g_021DD150.auth_mode = 5;
        memcpy(&g_021DD1E4, &g_021DD420, 64);
        break;
    default:
        ret = -7;
        break;
    }
    return ret;
}

/* OS_Printf compiles to nothing in the Rom (FINALROM) build. */
#define OS_Printf(fmt, arg) ((void)0)


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
