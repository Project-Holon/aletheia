/*
 * function: AutoConfigThreadEx
 * address:  0x021BA804
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * SDK: TwlDWC/lib/ARM9-TS/Rom/libdwcutil.TWL.HYB.a(atermset.o).
 * Object stamped Metrowerks 3.0.0.126 -> ../2.0/sp1p2.
 *
 * blocker: 952/996 bytes under ../2.0/sp1p2 -O4,p -thumb.  All callee and
 *   global relocations resolve once the data symbols are attested; the
 *   residual is the AutoProfile zero-fill.  The original emits the MWCC
 *   large-aggregate idiom (2x-unrolled stm of zeroed registers with a loop
 *   counter in ip, ~8 stm) while a plain `for` zero loop and `memset()` both
 *   come out ~40 bytes shorter; `(WS11G_PROFILE_DATA){0}` instead spills a
 *   596-byte stack temporary (frame 0x280 vs the original 0x2c).  Frame and
 *   most locals are otherwise right.  Several data globals (0x021DD490,
 *   0x021DDD04, 0x021DD020, 0x021DD4A0, 0x021DD4A8, 0x021DD224, 0x021DD310)
 *   still need an outside witness, so the verdict can not reach MATCH.
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

extern void OS_Sleep(u32 msec);
extern int ScanAP(void);
extern void SendNotify(void);
extern int ConnectAP(void);
extern int SOC_Socket(int type);
extern int SOC_Bind(int s, void *sockAddr);
extern u32 GetTickCount(void);
extern void SOC_Close(int s);
extern int GetMacEncKey(u8 *lpkey);
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

extern char g_021DCFD0[];
extern char g_021DAB58[];
extern u8 g_021DD490[16];
extern u8 g_021DDD04[2048];
extern int g_021DD020;
extern u8 g_021DD504[2048];
extern u8 g_021DD4A0[32];
extern u8 g_021DD4A8[32];
extern WS11G_PROFILE_DATA g_021DD224;
extern char g_021DD310[];

#define ASTATE (*(int *)(g_021DCFD0 + 0x1C))
#define ARESULT (*(int *)(g_021DCFD0 + 0x14))
#define AFIELD34 (*(int *)(g_021DCFD0 + 0x34))
#define AFLAG10 (*(int *)(g_021DCFD0 + 0x10))
#define ATIMEOUT (*(int *)(g_021DAB58 + 0xC))
#define BTDUALCFG (*(int *)(g_021DCFD0 + 0x38))
#define BTAR (*(u8 *)(g_021DCFD0 + 0x0))

int AutoConfigThreadEx(void)
{
    int sock = 0;
    int ret;
    int iretry;
    int esize;
    int eid;
    unsigned long dw;
    unsigned long dwSendTick;
    struct SOCSockAddrIn target;
    struct SOCSockAddrIn server;
    int bfinish = 0;
    u8 *lpe;
    int n;

    ret = -5;
    dwSendTick = 0;
    iretry = 0;
    ASTATE = 1;

    while (!bfinish && AFLAG10 == 0) {
        OS_Sleep(500);
        switch (ASTATE) {
        case 1:
            ret = ScanAP();
            if (ret != 1) {
                bfinish = 1;
                break;
            }
            BTDUALCFG = 3;
            SendNotify();
            ASTATE = 2;
            break;
        case 2:
            ret = ConnectAP();
            if (ret != 1) {
                bfinish = 1;
                break;
            }
            ASTATE = 3;
            break;
        case 3:
            sock = SOC_Socket(2);
            if (sock < 0) {
                ret = -2;
                bfinish = 1;
                break;
            }
            server.len = 8;
            server.family = 2;
            server.port = 486;
            server.addr.addr = 0;
            ret = SOC_Bind(sock, &server);
            if (ret < 0) {
                ret = -2;
                bfinish = 1;
                break;
            }
            ASTATE = 4;
            break;
        case 4:
            if (GetTickCount() >= (u32)ATIMEOUT) {
                SOC_Close(sock);
                ret = -3;
                bfinish = 1;
                break;
            }
            target.len = 8;
            GetMacEncKey(g_021DD490);
            if (SOC_RecvFrom(sock, g_021DDD04, 0x800, 4, &target) <= 0)
                break;
            if (!IsSearchCommand(g_021DDD04, &g_021DD020))
                break;
            ATIMEOUT = GetTickCount() + 30000;
            ASTATE = 5;
            BTDUALCFG = 4;
            SendNotify();
            break;
        case 5:
            ARESULT = SetSearchRes(g_021DDD04);
            SendFrame(sock, &target, g_021DDD04, ARESULT);
            dwSendTick = GetTickCount();
            ASTATE = 6;
            break;
        case 6:
            if (GetTickCount() >= (u32)ATIMEOUT) {
                SOC_Close(sock);
                ret = -4;
                bfinish = 1;
                break;
            }
            if (SOC_RecvFrom(sock, g_021DDD04, 0x800, 4, &target) <= 0)
                goto retry6;
            if (!GetCommandElement(g_021DDD04, 3, g_021DD504, g_021DD490))
                goto retry6;
            lpe = GetFirstElement(g_021DD504, &eid, &esize);
            if (eid != 257)
                break;
            dw = GetTickCount();
            for (n = 0; n < 8; n++)
                g_021DD4A0[n] = lpe[n];
            MD5Encode(g_021DD4A8, (u8 *)&dw, 4);
            iretry = 0;
            ASTATE = 7;
            BTDUALCFG = 5;
            ATIMEOUT = -1;
            SendNotify();
            break;
        retry6:
            if (GetTickCount() < dwSendTick + 1000)
                break;
            ASTATE = 5;
            break;
        case 7:
            AFIELD34 = SetSingleElement(g_021DD504, 258, g_021DD4A8, 8);
            ARESULT = SetFrameData(g_021DDD04, 4, g_021DD504, AFIELD34, g_021DD490);
            SendFrame(sock, &target, g_021DDD04, ARESULT);
            dwSendTick = GetTickCount();
            for (n = 0; n < (int)(sizeof(WS11G_PROFILE_DATA) / 4); n++)
                ((u32 *)&g_021DD224)[n] = 0;
            ASTATE = 8;
            break;
        case 8:
            if (SOC_RecvFrom(sock, g_021DDD04, 0x800, 4, &target) <= 0)
                goto retry8;
            AFIELD34 = GetCommandElement(g_021DDD04, 5, g_021DD504, g_021DD4A0);
            if (AFIELD34 == 0)
                goto retry8;
            if (!GetWLanSetElement(g_021DD504))
                goto retry8;
            BTAR = (*(signed char *)(g_021DD310 + 0x14) != 0) ? 1 : 0;
            iretry = 0;
            ASTATE = 9;
            break;
        retry8:
            if (GetTickCount() < dwSendTick + 1000)
                break;
            if (++iretry >= 10) {
                SOC_Close(sock);
                ret = -2;
                bfinish = 1;
                break;
            }
            ASTATE = 7;
            break;
        case 9:
            AFIELD34 = SetSingleElement(g_021DD504, 769, (u8 *)g_021DCFD0, 1);
            ARESULT = SetFrameData(g_021DDD04, 6, g_021DD504, AFIELD34, g_021DD4A0);
            if (APC_GetState() != 7) {
                dwSendTick = GetTickCount() + 1000;
                iretry = 10;
                ASTATE = 10;
                break;
            }
            SendFrame(sock, &target, g_021DDD04, ARESULT);
            dwSendTick = GetTickCount();
            ASTATE = 10;
            break;
        case 10:
            if (GetTickCount() < dwSendTick + 1000)
                break;
            if (++iretry >= 10) {
                bfinish = 1;
                ret = StoreNetParam();
                break;
            }
            ASTATE = 9;
            break;
        default:
            break;
        }
    }
    if (sock != 0)
        SOC_Close(sock);
    if (AFLAG10 != 0)
        ret = -8;
    return ret;
}
