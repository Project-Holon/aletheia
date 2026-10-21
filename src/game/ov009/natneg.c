/*
 * file:     natneg.c
 * unit:     yes
 * function: GetClientUniqueID, FindNegotiatorForCookie, AddNegotiator, RemoveNegotiator, NNFreeNegotiateList, CheckMagic, SendPacket, GetLocalIP, GetLocalPort, SendReportPacket, StartReport, SendPreinitPacket, SendInitPackets, SendPingPacket, CheckNatifyStatus, NameToIp, ResolveServer, ResolveServers, NNBeginNegotiationWithSocket, NNCancel, RemoveFinishedNegotiator, NegotiateThink, NNThink, SendConnectAck, ProcessConnectPacket, ProcessPingPacket, ProcessPreinitAckPacket, ProcessInitPacket, NNProcessData
 * address:  0x021990A0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      NameToIp (natify.o)
 *
 * symbols:
 *   current_time     0x0217F264  arm  ov009
 *   Util_RandSeed     0x0217F790  arm  ov009
 *   Util_RandInt     0x0217F7AC  arm  ov009
 *   sNatnegNegotiateList     0x021AE698  data
 *   Matchup3Hostname  0x021AE69C  data
 *   sNatnegNatMappingScheme  0x021AE6A0  data
 *   sNatnegNatifyCallback    0x021AE6A4  data
 *   sNatnegNatifyStartTime   0x021AE6A8  data
 *   ClientUniqueID    0x021AE6AC  data
 *   Matchup2Hostname  0x021AE6B0  data
 *   Matchup1Hostname  0x021AE6B4  data
 *   activeNatify      0x021AE6B8  data
 *   matchup3ip        0x021AE6BC  data
 *   matchup2ip        0x021AE6C0  data
 *   matchup1ip        0x021AE6C4  data
 *   ArrayLength  0x02184200  arm  ov009
 *   ArrayNth  0x02184208  arm  ov009
 *   ArrayNew  0x02184144  arm  ov009
 *   ArrayAppend  0x02184234  arm  ov009
 *   ArrayRemoveAt  0x02184324  arm  ov009
 *   gsDebugFormat  0x0217D254 arm
 *   ArrayFree      0x021841B0 arm
 *   gNatNegFreeFmt     0x021A5A84 data
 *   gNatNegMagic  0x021A5A7C  data
 *   sendto  0x0217ECA4  arm  ov009
 *   getlocalhost  0x0217EFB8  arm  ov009
 *   IsPrivateIP  0x0217F038  arm  ov009
 *   getsockname  0x0217ED0C  arm  ov009
 *   strlen         0x0209477C  arm
 *   memcpy         0x02092344  arm
 *   strcpy  0x02094798  arm
 *   SOC_InetNtoA   0x0215FA9C  arm  ov009
 *   SendPacket     0x021992A8  arm  ov009
 *   current_time   0x0217F264  arm  ov009
 *   GetClientUniqueID  0x021990A0  arm  ov009
 *   NNCancel  0x02199FB4  arm  ov009
 *   NatifyThink        0x02198E74  arm  ov009
 *   DetermineNatType   0x02198E80  arm  ov009
 *   closesocket        0x0217EB2C  arm  ov009
 *   gGsAvailabilityGameName     0x021ACEFC  data
 *   gNatSocks     0x021A5A70  data
 *   gNatnegGlobals     0x021AE698  data
 *   gNatNegServer1IP     0x021AE6C4  data
 *   gNatNegServer2IP     0x021AE6C0  data
 *   gNatNegServer3IP     0x021AE6BC  data
 *   gNatNegNat     0x021AE6C8  data
 *   gNatNegSendReportFmt     0x021A5AB4  data
 *   gNatNegReportFailFmt     0x021A5AF8  data
 *   gNatNegReportDoneFmt     0x021A5B30  data
 *   gNatNegPreinitFmt     0x021A5B70  data
 *   gNatNegInitGpFmt     0x021A5B8C  data
 *   gNatNegInitNn1Fmt     0x021A5BAC  data
 *   gNatNegInitNn2Fmt     0x021A5BE8  data
 *   gNatNegInitNn3Fmt     0x021A5C24  data
 *   gNatNegSendPingFmt     0x021A5C60  data
 *   inet_addr  0x0217ED38  arm
 *   SOC_GetHostByName  0x0215F650  arm
 *   OS_SNPrintf            0x02084F80  arm
 *   gNatNegHostnameFmt               0x021A5CA8  data
 *   gNatNegServer1Name               0x021A5CB0  data
 *   gNatNegServer2Name               0x021A5CCC  data
 *   gNatNegServer3Name               0x021A5CE8  data
 *   socket            0x0217EB18  arm ov009
 *   gGsAvailabilityState               0x021ACEF8  data
 *   gNatNegBackendUnavailFmt               0x021A5D04  data
 *   gNatNegResolveFailFmt               0x021A5D44  data
 *   gNatNegAllocFailFmt               0x021A5D90  data
 *   gNatNegSocketFailFmt               0x021A5DD0  data
 *   gNatNegSocketFmt               0x021A5E14  data
 *   FindNegotiatorForCookie  0x021990D4  arm
 *   gNatNegCancelNotFoundFmt               0x021A5E2C  data
 *   gNatNegCancelFmt               0x021A5E5C  data
 *   CanReceiveOnSocket            0x0217EF50  arm ov009
 *   recvfrom            0x0217EC60  arm ov009
 *   GOAGetLastError            0x0217ED54  arm ov009
 *   gNatNegThinkNullFmt               0x021A5E88  data
 *   gNatNegThinkRemoveFmt               0x021A5EAC  data
 *   gNatNegRecvBuf               0x021AE7A0  data
 *   gNatNegRecvErrFmt               0x021A5EE8  data
 *   gNatNegInitTimeoutFmt               0x021A5F1C  data
 *   gNatNegResendInitFmt               0x021A5F5C  data
 *   gNatNegNoPingFmt               0x021A5FA0  data
 *   gNatNegPingTimeoutFmt               0x021A5FE8  data
 *   gNatNegResendPingFmt               0x021A6028  data
 *   gNatNegReportTimeoutFmt               0x021A606C  data
 *   gNatNegResendReportFmt               0x021A60B8  data
 *   gNatNegBothDoneFmt               0x021A60FC  data
 *   gNatNegLingerDoneFmt               0x021A6150  data
 *   gNatNegRemovePostFmt               0x021A61A0  data
 *   ArrayLength            0x02184200  arm ov009
 *   gNatNegSendConnectAckFmt               0x021A61E8  data
 *   gNatNegConnectPacketFmt               0x021A621C  data
 *   gNatNegAlreadyConnectedFmt               0x021A6274  data
 *   gNatNegDeadbeatFmt               0x021A62CC  data
 *   gNatNegConnectTimeoutFmt               0x021A6300  data
 *   gNatNegPingPacketFmt               0x021A6330  data
 *   gNatNegPingEarlyFmt               0x021A6384  data
 *   gNatNegGotPingFmt               0x021A63D8  data
 *   gNatNegConnectFinishedFmt               0x021A640C  data
 *   gNatNegPreinitAckFmt               0x021A6450  data
 *   gNatNegInitAckFmt               0x021A6470  data
 *   gNatNegErtFmt               0x021A648C  data
 *   gNatNegReportAckFmt               0x021A6498  data
 *   gNatNegBadHeaderFmt               0x021A64D4  data
 *   gNatNegPacketFmt               0x021A6504  data
 *   gNatNegConnectTooSmallFmt               0x021A6538  data
 *   gNatNegNoNegotiatorFmt               0x021A657C  data
 *   gNatNegPacketTooSmallFmt               0x021A65BC  data
 */
#include "soc.h"
#include "ov009_globals.h"
#include "../../matched/arm9_sdk/libc/string.h"

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
#define NN_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
#define NN_HTONS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define NN_NTOHL(x) NN_SWAP32(x)
#define NN_NTOHS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
struct DArrayImplementation;
#include "natneg_types.h"

/* the u32 address words of this module passed as the SOCInAddr struct */
#define INADDR(x) (*(struct SOCInAddr *)&(x))
struct SOCSockAddr;
typedef struct DArrayImplementation *DArray;

#include "../types.h"

#include "darray.h"

#include "../sdk_soc.h"

/* byte-wise copy of a socket address (alignment 1) */
typedef struct NNSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned char port[2];
    unsigned char addr[4];
} NNSockAddr;

typedef struct _NATNegotiator {
    int gameSock;                                    /* 0x00 */
    int cookie;                                      /* 0x04 */
    int clientIndex;                                 /* 0x08 */
    void (*progressCallback)(int state, void *userdata);                              /* 0x0C */
    void (*completedCallback)(int result, int gameSocket, SOCSockAddrIn *remoteaddr, void *userdata); /* 0x10 */
    void *userdata;                                  /* 0x14 */
    int negotiateSock;                               /* 0x18 */
    int state;                                       /* 0x1C */
    int initAckRecv[4];                              /* 0x20 */
    int retryCount;                                  /* 0x30 */
    int maxRetryCount;                               /* 0x34 */
    unsigned int retryTime;                          /* 0x38 */
    unsigned int guessedIP;                          /* 0x3C */
    unsigned short guessedPort;                      /* 0x40 */
    unsigned char gotRemoteData;                     /* 0x42 */
    unsigned char sendGotRemoteData;                 /* 0x43 */
    int result;                                      /* 0x44 */
    int socket;                                      /* 0x48 */
    NNSockAddr remoteaddr;                           /* 0x4C */
} NATNegotiator;

/* One packet, four views of the union at 0x0C. 0x4A bytes, 0x4C as a local. */
typedef struct NatNegPacket
{
    u8 magic[6];                                     /* 0x00 */
    u8 version;                                      /* 0x06 */
    u8 packettype;                                   /* 0x07 */
    int cookie;                                      /* 0x08 */
    union {
        struct {
            u8 porttype;                             /* 0x0C */
            u8 clientindex;                          /* 0x0D */
            u8 usegameport;                          /* 0x0E */
            u8 localip[4];                           /* 0x0F */
            u8 localport[2];                         /* 0x13 */
        } init;
        struct {
            u8 clientindex;                          /* 0x0C */
            u8 pad0[3];                              /* 0x0D */
            int clientUniqueID;                      /* 0x10 */
        } preinit;
        struct {
            u32 ipaddr;                              /* 0x0C */
            u16 port;                                /* 0x10 */
            u8 gotyourdata;                          /* 0x12 */
            u8 finished;                             /* 0x13 */
        } connect;
        struct {
            u8 pad0;                                 /* 0x0C */
            u8 clientindex;                          /* 0x0D */
            u8 negResult;                            /* 0x0E */
            u8 pad1;                                 /* 0x0F */
            int natType;                             /* 0x10 */
            int mappingScheme;                       /* 0x14 */
            char gamename[0x32];                     /* 0x18 */
        } report;
    } u;
} NatNegPacket;

typedef struct NatnegGlobals {
    void *negotiateList;                             /* 0x00 */
    char *natneg3Override;                           /* 0x04 */
    int natMappingScheme;                            /* 0x08 */
    void (*natifyCallback)(int success, NAT nat);    /* 0x0C */
    unsigned int natifyStartTime;                    /* 0x10 */
    int pad14;                                       /* 0x14 */
    char *natneg2Override;                           /* 0x18 */
    char *natneg1Override;                           /* 0x1C */
    int natifyActive;                                /* 0x20 */
    unsigned int natneg3IP;                          /* 0x24 */
    unsigned int natneg2IP;                          /* 0x28 */
    unsigned int natneg1IP;                          /* 0x2C */
} NatnegGlobals;

/* The resolved server IPs also exist as file-scope words (gNatNegServer1IP,
   gNatNegServer2IP, gNatNegServer3IP); they alias natneg1IP/2IP/3IP but the debug calls load
   them as direct symbols, so both names stay. */

typedef struct NatSocks {
    int natType;                                     /* 0x00 */
    int ertSock;                                     /* 0x04 */
    int mappingSock;                                 /* 0x08 */
} NatSocks;

typedef enum NegotiateState {
    ns_preinitsent, ns_preinitack, ns_initsent, ns_initack, ns_connectping,
    ns_finished, ns_canceled, ns_reportsent, ns_reportack
} NegotiateState;

#include "gsplatformutil.h"
#include "darray.h"
extern void gsDebugFormat(int cat, int type, int level, char *fmt, ...);
#include "../arm9/msl_string_mem.h"
#include "gsplatformsocket.h"
extern int GetClientUniqueID();
static void SendPacket(int sock, unsigned int toaddr, unsigned short toport, void *data, int len);
extern char *strcpy(char *dst, const char *src);
extern void NNCancel(int cookie);
#include "natify.h"
#include "../arm9/os_printf.h"
extern NATNegotiator *FindNegotiatorForCookie(int cookie);
NATNegotiator *AddNegotiator(void);
void RemoveNegotiator(NATNegotiator *neg);
void NNFreeNegotiateList(void);
int CheckMagic(const u8 *a);
static unsigned int GetLocalIP(void);
static unsigned short GetLocalPort(int sock);
void SendReportPacket(NATNegotiator *neg);
void StartReport(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr);
void SendPreinitPacket(NATNegotiator *neg);
void SendInitPackets(NATNegotiator *neg);
void SendPingPacket(NATNegotiator *neg);
int CheckNatifyStatus(int sock);
unsigned int NameToIp(char *name);
unsigned int ResolveServer(char *overrideHostname, char *defaultHostname);
int ResolveServers(void);
int NNBeginNegotiationWithSocket(int gamesocket, int cookie, int clientindex, void (*progresscallback)(int, void *), void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata);
void NNCancel(int cookie);
void RemoveFinishedNegotiator(int *p);
void NegotiateThink(NATNegotiator *neg);
void NNThink(void);
void SendConnectAck(NATNegotiator *neg, SOCSockAddrIn *toaddr);
void ProcessConnectPacket(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr);
void ProcessPingPacket(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr);
void ProcessPreinitAckPacket(NATNegotiator *neg, NatNegPacket *p);
void ProcessInitPacket(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr);
void NNProcessData(char *data, int len, SOCSockAddrIn *fromaddr);
extern struct DArrayImplementation * sNatnegNegotiateList;
extern char gNatNegFreeFmt[];
extern NatNegMagic gNatNegMagic;
extern char gGsAvailabilityGameName[];
extern struct NatSocks gNatSocks;
extern NatnegGlobals gNatnegGlobals;
extern u32 gNatNegServer1IP;
extern unsigned int gNatNegServer2IP;
extern unsigned int gNatNegServer3IP;
extern NAT gNatNegNat;
extern char gNatNegSendReportFmt[];
extern char gNatNegReportFailFmt[];
extern char gNatNegReportDoneFmt[];
extern char gNatNegPreinitFmt[];
extern char gNatNegInitGpFmt[];
extern char gNatNegInitNn1Fmt[];
extern char gNatNegInitNn2Fmt[];
extern char gNatNegInitNn3Fmt[];
extern char gNatNegSendPingFmt[];
extern char gNatNegHostnameFmt[];
extern char gNatNegServer1Name[];
extern char gNatNegServer2Name[];
extern char gNatNegServer3Name[];
extern int gGsAvailabilityState;
extern char gNatNegBackendUnavailFmt[];
extern char gNatNegResolveFailFmt[];
extern char gNatNegAllocFailFmt[];
extern char gNatNegSocketFailFmt[];
extern char gNatNegSocketFmt[];
extern char gNatNegCancelNotFoundFmt[];
extern char gNatNegCancelFmt[];
extern char gNatNegThinkNullFmt[];
extern char gNatNegThinkRemoveFmt[];
extern char gNatNegRecvBuf[];
extern char gNatNegRecvErrFmt[];
extern char gNatNegInitTimeoutFmt[];
extern char gNatNegResendInitFmt[];
extern char gNatNegNoPingFmt[];
extern char gNatNegPingTimeoutFmt[];
extern char gNatNegResendPingFmt[];
extern char gNatNegReportTimeoutFmt[];
extern char gNatNegResendReportFmt[];
extern char gNatNegBothDoneFmt[];
extern char gNatNegLingerDoneFmt[];
extern char gNatNegRemovePostFmt[];
extern char gNatNegSendConnectAckFmt[];
extern char gNatNegConnectPacketFmt[];
extern char gNatNegAlreadyConnectedFmt[];
extern char gNatNegDeadbeatFmt[];
extern char gNatNegConnectTimeoutFmt[];
extern char gNatNegPingPacketFmt[];
extern char gNatNegPingEarlyFmt[];
extern char gNatNegGotPingFmt[];
extern char gNatNegConnectFinishedFmt[];
extern char gNatNegPreinitAckFmt[];
extern char gNatNegInitAckFmt[];
extern char gNatNegErtFmt[];
extern char gNatNegReportAckFmt[];
extern char gNatNegBadHeaderFmt[];
extern char gNatNegPacketFmt[];
extern char gNatNegConnectTooSmallFmt[];
extern char gNatNegNoNegotiatorFmt[];
extern char gNatNegPacketTooSmallFmt[];

unsigned int matchup2ip = 0;

unsigned int matchup3ip = 0;

static int activeNatify = 0;

char *Matchup1Hostname = 0;

char *Matchup2Hostname = 0;

int ClientUniqueID = 0;

static unsigned int sNatnegNatifyStartTime = 0;

void (*natifyCallback)(int, NAT) = 0;

static NatMappingScheme sNatnegNatMappingScheme = 0;

char *Matchup3Hostname = 0;

DArray sNatnegNegotiateList = 0;

unsigned int matchup1ip = 0;

int GetClientUniqueID(void)
{
    if (ClientUniqueID == 0)
    {
        Util_RandSeed(current_time());
        ClientUniqueID = Util_RandInt(1, 0x7fffffff);
    }
    return ClientUniqueID;
}

NATNegotiator *FindNegotiatorForCookie(int cookie)
{
    int i;
    NATNegotiator *neg;

    if (!sNatnegNegotiateList)
        return 0;
    for (i = 0; i < ArrayLength((struct DArrayImplementation *)sNatnegNegotiateList); i++) {
        neg = (NATNegotiator *)ArrayNth(sNatnegNegotiateList, i);
        if (neg->cookie == cookie)
            return neg;
    }
    return 0;
}

/*
 * sdk:      AddNegotiator (natneg.o)
 */
NATNegotiator *AddNegotiator(void)
{
    NATNegotiator _neg = {0};

    if (!sNatnegNegotiateList)
        sNatnegNegotiateList = ArrayNew(sizeof(NATNegotiator), 4, 0);
    ArrayAppend(sNatnegNegotiateList, &_neg);
    return (NATNegotiator *)ArrayNth(sNatnegNegotiateList, ArrayLength((struct DArrayImplementation *)sNatnegNegotiateList) - 1);
}

/*
 * sdk:      RemoveNegotiator (natneg.o)
 */
void RemoveNegotiator(NATNegotiator *neg)
{
    int i;

    for (i = 0; i < ArrayLength((struct DArrayImplementation *)sNatnegNegotiateList); i++) {
        if (neg == ArrayNth(sNatnegNegotiateList, i)) {
            ArrayRemoveAt(sNatnegNegotiateList, i);
            return;
        }
    }
}

void NNFreeNegotiateList(void)
{
    if (sNatnegNegotiateList == 0)
        return;
    gsDebugFormat(7, 3, 8, gNatNegFreeFmt, ArrayLength((struct DArrayImplementation *)sNatnegNegotiateList));
    ArrayFree(sNatnegNegotiateList);
    sNatnegNegotiateList = 0;
}

/*
 * Set when the six-byte test of the object at 0x021A5A7C fails.
 */
int CheckMagic(const u8 *a)
{
    return memcmp((unsigned char *)a, (unsigned char *)((char *)&gNatNegMagic), 6) == 0;
}

/*
 * sdk:      SendPacket (natneg.o)
 */
static void SendPacket(int sock, unsigned int toaddr, unsigned short toport, void *data, int len)
{
    SOCSockAddrIn saddr;

    saddr.family = 2;
    saddr.port = SWAP16(toport);
    saddr.addr = toaddr;
    sendto(sock, data, len, 0, (struct SOCSockAddr *)(&saddr), 8);
}

static unsigned int GetLocalIP(void)
{
    int num_local_ips;
    SOCHostEnt *phost;
    SOCInAddr *addr;
    unsigned int localip;

    localip = 0;
    phost = getlocalhost();
    if (!phost)
        return 0;
    for (num_local_ips = 0;; num_local_ips++) {
        addr = (SOCInAddr *)phost->addrList[num_local_ips];
        if (!addr)
            break;
        if (addr->addr != 16777343) {
            localip = *(unsigned int *)addr;
            if (IsPrivateIP((SOCInAddr *)addr))
                return localip;
        }
    }
    return localip;
}

static unsigned short GetLocalPort(int sock)
{
	int ret;
	SOCSockAddrIn saddr;
	int saddrlen;

	saddrlen = 8;
	ret = getsockname(sock, (struct SOCSockAddr *)(&saddr), &saddrlen);
	if (ret == -1)
		return 0;
	return saddr.port;
}

#define NN_SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))

void SendReportPacket(NATNegotiator *neg)
{
    NatNegPacket p;

    {
        u8 *m = (u8 *)&gNatNegMagic;
        u8 *d = (u8 *)&p;
        d[0] = m[0];
        d[1] = m[1];
        d[2] = m[2];
        d[3] = m[3];
        d[4] = m[4];
        d[5] = m[5];
    }
    p.version = 4;
    p.packettype = 13;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.u.report.clientindex = (u8)neg->clientIndex;
    p.u.report.negResult = neg->result == 0 ? 1 : 0;
    p.u.report.natType = gNatSocks.natType;
    p.u.report.mappingScheme = gNatnegGlobals.natMappingScheme;
    if (strlen(gGsAvailabilityGameName))
        memcpy(p.u.report.gamename, gGsAvailabilityGameName, 0x32);
    gsDebugFormat(7, 0, 8, gNatNegSendReportFmt, neg->cookie, SOC_InetNtoA(INADDR(gNatNegServer1IP)), 27901, p.u.report.negResult);
    SendPacket(neg->negotiateSock, gNatnegGlobals.natneg1IP, 27901, &p, 0x49);
}

void StartReport(NATNegotiator *neg, int result, int socket, SOCSockAddrIn *remoteaddr)
{
    neg->result = result;
    neg->socket = socket;
    if (remoteaddr)
        neg->remoteaddr = *(NNSockAddr *)remoteaddr;
    if (result == 1 || result == 2) {
        gsDebugFormat(7, 3, 8, gNatNegReportFailFmt, neg->cookie);
        neg->state = 5;
        neg->completedCallback(neg->result, neg->socket, (SOCSockAddrIn *)&neg->remoteaddr, neg->userdata);
        NNCancel(neg->cookie);
    } else {
        gsDebugFormat(7, 3, 8, gNatNegReportDoneFmt, neg->cookie);
        SendReportPacket((NATNegotiator *)neg);
        neg->state = 7;
        neg->retryTime = current_time() + 500;
        neg->retryCount = 0;
        neg->maxRetryCount = 4;
        neg->completedCallback(neg->result, neg->socket, (SOCSockAddrIn *)&neg->remoteaddr, neg->userdata);
    }
}

/*
 * sdk:      SendPreinitPacket (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 */
void SendPreinitPacket(NATNegotiator *neg)
{
    NatNegPacket p;

    {
        u8 *m = (u8 *)&gNatNegMagic;
        u8 *d = (u8 *)&p;
        d[0] = m[0];
        d[1] = m[1];
        d[2] = m[2];
        d[3] = m[3];
        d[4] = m[4];
        d[5] = m[5];
    }
    p.version = 4;
    p.packettype = 15;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.u.preinit.clientindex = (u8)neg->clientIndex;
    p.u.preinit.clientUniqueID = GetClientUniqueID();
    gsDebugFormat(7, 0, 8, gNatNegPreinitFmt, SOC_InetNtoA(INADDR(gNatNegServer1IP)), 27901);
    SendPacket(neg->negotiateSock, gNatnegGlobals.natneg1IP, 27901, &p, 0x12);
    if (neg->state == 1)
    {
        neg->retryTime = current_time() + 10000;
        neg->maxRetryCount = 12;
    }
    else
    {
        neg->retryTime = current_time() + 500;
        neg->maxRetryCount = 10;
        neg->state = 0;
    }
}

/*
 * sdk:      SendInitPackets (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * localip, localport and gamename are written through buffer, not p: the
 * object addresses them from sp (buffer + 0x0F, + 0x13, + 0x15) while every
 * other field goes through p in r6, and it stores localip and localport one
 * byte at a time, most significant byte first.  The swap macros evaluate
 * their argument once per term, so GetLocalIP runs four times and
 * GetLocalPort twice, as in the object.
 */
void SendInitPackets(NATNegotiator *neg)
{
    char buffer[85];
    NatNegPacket *p;
    unsigned int localip;
    unsigned short localport;
    int packetlen;

    p = (NatNegPacket *)buffer;
    memcpy(p->magic, ((unsigned char *)&gNatNegMagic), 6);
    p->version = 4;
    p->packettype = 0;
    p->cookie = NN_SWAP32((unsigned int)neg->cookie);
    p->u.init.clientindex = neg->clientIndex;
    p->u.init.usegameport = (neg->gameSock == -1) ? 0 : 1;
    localip = NN_SWAP32(GetLocalIP());
    buffer[15] = (unsigned char)(localip >> 24);
    buffer[16] = (unsigned char)(localip >> 16);
    buffer[17] = (unsigned char)(localip >> 8);
    buffer[18] = (unsigned char)localip;
    buffer[19] = 0;
    buffer[20] = 0;
    strcpy(buffer + 21, gGsAvailabilityGameName);
    packetlen = strlen(gGsAvailabilityGameName) + 22;

    if (p->u.init.usegameport && !neg->initAckRecv[0]) {
        p->u.init.porttype = 0;
        gsDebugFormat(7, 0, 8, gNatNegInitGpFmt, SOC_InetNtoA(INADDR(gNatNegServer1IP)), 27901);
        SendPacket(neg->gameSock, gNatnegGlobals.natneg1IP, 27901, p, packetlen);
    }

    if (!neg->initAckRecv[1]) {
        p->u.init.porttype = 1;
        gsDebugFormat(7, 0, 8, gNatNegInitNn1Fmt, neg->cookie, SOC_InetNtoA(INADDR(gNatNegServer1IP)), 27901);
        SendPacket(neg->negotiateSock, gNatnegGlobals.natneg1IP, 27901, p, packetlen);
    }

    localport = NN_HTONS(GetLocalPort(p->u.init.usegameport ? neg->gameSock : neg->negotiateSock));
    buffer[19] = (unsigned char)(localport >> 8);
    buffer[20] = (unsigned char)localport;

    if (!neg->initAckRecv[2]) {
        p->u.init.porttype = 2;
        gsDebugFormat(7, 0, 8, gNatNegInitNn2Fmt, neg->cookie, SOC_InetNtoA(INADDR(gNatNegServer2IP)), 27901);
        SendPacket(neg->negotiateSock, gNatnegGlobals.natneg2IP, 27901, p, packetlen);
    }

    if (!neg->initAckRecv[3]) {
        p->u.init.porttype = 3;
        gsDebugFormat(7, 0, 8, gNatNegInitNn3Fmt, neg->cookie, SOC_InetNtoA(INADDR(gNatNegServer3IP)), 27901);
        SendPacket(neg->negotiateSock, gNatnegGlobals.natneg3IP, 27901, p, packetlen);
    }

    neg->state = 2;
    neg->retryTime = current_time() + 500;
    neg->maxRetryCount = 10;
}

/*
 * sdk:      SendPingPacket (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 */
void SendPingPacket(NATNegotiator *neg)
{
    NatNegPacket p;

    {
        u8 *m = (u8 *)&gNatNegMagic;
        u8 *d = (u8 *)&p;
        d[0] = m[0];
        d[1] = m[1];
        d[2] = m[2];
        d[3] = m[3];
        d[4] = m[4];
        d[5] = m[5];
    }
    p.version = 4;
    p.packettype = 7;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.u.connect.ipaddr = neg->guessedIP;
    p.u.connect.port = NN_SWAP16(neg->guessedPort);
    p.u.connect.gotyourdata = neg->gotRemoteData;
    p.u.connect.finished = (neg->gotRemoteData && neg->sendGotRemoteData) ? 1 : 0;
    gsDebugFormat(7, 0, 8, gNatNegSendPingFmt, neg->cookie, SOC_InetNtoA(INADDR(neg->guessedIP)), neg->guessedPort, neg->gotRemoteData);
    SendPacket(neg->gameSock == -1 ? neg->negotiateSock : neg->gameSock, neg->guessedIP, neg->guessedPort, &p, 0x14);
    neg->retryTime = current_time() + 700;
    neg->maxRetryCount = 7;
}

/*
 * sdk:      CheckNatifyStatus (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 */
int CheckNatifyStatus(int sock)
{
    int active = 1;
    int success;

    if (sock != -1)
    {
        if (current_time() - gNatnegGlobals.natifyStartTime < 10000)
            active = NatifyThink(sock, &gNatNegNat);
        else
            active = 0;
        if (active)
            goto done;
        success = DetermineNatType(&gNatNegNat);
        gNatnegGlobals.natifyCallback(success, gNatNegNat);
        gNatSocks.natType = gNatNegNat.natType;
        gNatnegGlobals.natMappingScheme = gNatNegNat.mappingScheme;
        if (gNatSocks.mappingSock != -1)
        {
            closesocket(gNatSocks.mappingSock);
            gNatSocks.mappingSock = -1;
        }
        if (gNatSocks.ertSock != -1)
        {
            closesocket(gNatSocks.ertSock);
            gNatSocks.ertSock = -1;
        }
    }
done:
    return active;
}

unsigned int NameToIp(char *name)
{
    SOCHostEnt *hent;
    unsigned int ret;

    ret = inet_addr(name);
    if (ret != (unsigned int)-1)
        return ret;
    hent = SOC_GetHostByName(name);
    if (hent == 0)
        return 0;
    return ((SOCInAddr *)*hent->addrList)->addr;
}

#undef NN_SWAP16
#define NN_SWAP16(x) ((u16)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))

/*
 * sdk:      ResolveServer (natify.o)
 */
unsigned int ResolveServer(char *overrideHostname, char *defaultHostname)
{
    char hostnameBuffer[64];
    char *hostname;

    hostname = overrideHostname;
    if (!hostname) {
        hostname = hostnameBuffer;
        OS_SNPrintf(hostname, 64, gNatNegHostnameFmt, gGsAvailabilityGameName, defaultHostname);
    }
    return NameToIp(hostname);
}

/*
 * sdk:      ResolveServers (natneg.o)
 */
int ResolveServers(void)
{
    if (!gNatnegGlobals.natneg1IP)
        gNatnegGlobals.natneg1IP = ResolveServer(gNatnegGlobals.natneg1Override, gNatNegServer1Name);
    if (!gNatnegGlobals.natneg2IP)
        gNatnegGlobals.natneg2IP = ResolveServer(gNatnegGlobals.natneg2Override, gNatNegServer2Name);
    if (!gNatnegGlobals.natneg3IP)
        gNatnegGlobals.natneg3IP = ResolveServer(gNatnegGlobals.natneg3Override, gNatNegServer3Name);
    if (gNatnegGlobals.natneg1IP == 0 || gNatnegGlobals.natneg2IP == 0 || gNatnegGlobals.natneg3IP == 0)
        return 0;
    return 1;
}

/*
 * sdk:      NNBeginNegotiationWithSocket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 */
int NNBeginNegotiationWithSocket(int gamesocket, int cookie, int clientindex,
                  void (*progresscallback)(int, void *),
                  void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata)
{
    NATNegotiator *neg;
    SOCSockAddrIn saddr;
    int namelen;

    if (gGsAvailabilityState != 1) {
        gsDebugFormat(7, 0, 4, gNatNegBackendUnavailFmt, cookie);
        return 2;
    }

    if (!ResolveServers()) {
        gsDebugFormat(7, 0, 4, gNatNegResolveFailFmt, cookie);
        return 3;
    }

    neg = AddNegotiator();
    if (neg == 0) {
        gsDebugFormat(7, 2, 1, gNatNegAllocFailFmt);
        return 1;
    }

    neg->negotiateSock = socket(2, 2, 0);
    if (neg->negotiateSock == -1) {
        gsDebugFormat(7, 0, 1, gNatNegSocketFailFmt);
        RemoveNegotiator(neg);
        return 2;
    }

    neg->gameSock = gamesocket;
    neg->clientIndex = clientindex;
    neg->cookie = cookie;
    neg->progressCallback = progresscallback;
    neg->completedCallback = completedcallback;
    neg->userdata = userdata;
    neg->gotRemoteData = 0;
    neg->sendGotRemoteData = 0;
    neg->guessedIP = 0;
    neg->guessedPort = 0;
    neg->result = 5;
    neg->retryCount = 0;
    neg->maxRetryCount = 0;

    SendPreinitPacket((NATNegotiator *)neg);

    namelen = sizeof(saddr);
    getsockname(neg->negotiateSock, (struct SOCSockAddr *)(&saddr), &namelen);
    gsDebugFormat(7, 0, 8, gNatNegSocketFmt, (unsigned short)(((saddr.port >> 8) & 0xFF) | ((saddr.port << 8) & 0xFF00)));

    return 0;
}

void NNCancel(int cookie)
{
    NATNegotiator *neg = FindNegotiatorForCookie(cookie);

    if (neg == 0) {
        gsDebugFormat(7, 4, 4, gNatNegCancelNotFoundFmt, cookie);
        return;
    }
    gsDebugFormat(7, 4, 8, gNatNegCancelFmt, cookie);
    if (neg->negotiateSock != -1) {
        closesocket(neg->negotiateSock);
        neg->negotiateSock = -1;
    }
    neg->state = 6;
}

/*
 * Marks the record spent and tail calls on its second word.
 */
void RemoveFinishedNegotiator(int *p)
{
    if (p[0] == -1) {
        p[6] = -1;
    }

    NNCancel(p[1]);
}

/*
 * sdk:      NegotiateThink (libdwcgsnatneg.TWL.HYB.a natneg.o)
 *
 * State enum is compared unsigned in the two range tests (bhi), so those
 * two reads are cast to unsigned int. The receive loop is a do/while with
 * the socket test at the bottom, inside an outer socket test.
 */
void NegotiateThink(NATNegotiator *neg)
{
    SOCSockAddrIn saddr;
    int saddrlen = sizeof(SOCSockAddrIn);
    int error;

    if (neg == 0) {
        gsDebugFormat(7, 4, 4, gNatNegThinkNullFmt);
        return;
    }

    if (neg->state == ns_canceled) {
        gsDebugFormat(7, 2, 8, gNatNegThinkRemoveFmt, neg->cookie);
        RemoveNegotiator(neg);
        return;
    }

    if (neg->negotiateSock != -1) {
        do {
            if (!CanReceiveOnSocket(neg->negotiateSock))
                break;
            error = recvfrom(neg->negotiateSock, gNatNegRecvBuf, 512, 0, (struct SOCSockAddr *)(&saddr), &saddrlen);
            if (error == -1) {
                gsDebugFormat(7, 0, 8, gNatNegRecvErrFmt, neg->cookie, GOAGetLastError(neg->negotiateSock));
                break;
            }
            NNProcessData(gNatNegRecvBuf, error, &saddr);
            if (neg->state == ns_canceled)
                break;
        } while (neg->negotiateSock != -1);
    }

    if ((neg->state == ns_preinitsent || neg->state == ns_preinitack || neg->state == ns_initsent ||
         neg->state == ns_connectping) && current_time() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            gsDebugFormat(7, 0, 8, gNatNegInitTimeoutFmt, neg->cookie);
            if ((unsigned int)neg->state <= ns_initsent)
                StartReport(neg, 2, -1, 0);
            else
                StartReport(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            gsDebugFormat(7, 0, 8, gNatNegResendInitFmt, neg->cookie, neg->retryCount);
            if ((unsigned int)neg->state <= ns_preinitack)
                SendPreinitPacket((NATNegotiator *)neg);
            else if (neg->state == ns_initsent)
                SendInitPackets(neg);
            else
                SendPingPacket((NATNegotiator *)neg);
        }
    }

    if (neg->state == ns_initack && current_time() > neg->retryTime) {
        gsDebugFormat(7, 0, 8, gNatNegNoPingFmt, neg->cookie);
        StartReport(neg, 1, -1, 0);
    }

    if (neg->state == ns_connectping && current_time() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            gsDebugFormat(7, 0, 8, gNatNegPingTimeoutFmt, neg->cookie);
            StartReport(neg, 3, -1, 0);
        } else {
            neg->retryCount++;
            gsDebugFormat(7, 0, 8, gNatNegResendPingFmt, neg->cookie, neg->retryCount);
            SendPingPacket((NATNegotiator *)neg);
            neg->retryTime = current_time() + 700;
        }
    }

    if (neg->state == ns_reportsent && current_time() > neg->retryTime) {
        if (neg->retryCount > neg->maxRetryCount) {
            gsDebugFormat(7, 3, 8, gNatNegReportTimeoutFmt, neg->cookie);
            neg->state = ns_finished;
        } else {
            SendReportPacket((NATNegotiator *)neg);
            neg->retryCount++;
            gsDebugFormat(7, 0, 8, gNatNegResendReportFmt, neg->cookie, neg->retryCount);
            neg->retryTime = current_time() + 500;
        }
    }

    if (neg->state == ns_finished || neg->state == ns_reportack) {
        if (neg->sendGotRemoteData)
            gsDebugFormat(7, 3, 8, gNatNegBothDoneFmt, neg->cookie);
        else if (current_time() > neg->retryTime)
            gsDebugFormat(7, 3, 8, gNatNegLingerDoneFmt, neg->cookie);
        RemoveFinishedNegotiator((int *)neg);
    }

    if (neg->state == ns_canceled) {
        gsDebugFormat(7, 2, 8, gNatNegRemovePostFmt, neg->cookie);
        RemoveNegotiator(neg);
    }
}

/*
 * sdk:      NNThink (natneg.o)
 */
void NNThink(void)
{
    int i;

    if (gNatnegGlobals.natifyActive)
        gNatnegGlobals.natifyActive = CheckNatifyStatus(gNatSocks.mappingSock) && CheckNatifyStatus(gNatSocks.ertSock);
    if (!gNatnegGlobals.negotiateList)
        return;
    for (i = ArrayLength(gNatnegGlobals.negotiateList) - 1; i >= 0; i--)
        NegotiateThink(ArrayNth(gNatnegGlobals.negotiateList, i));
}

/*
 * sdk:      SendConnectAck (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 *
 * Builds a NATNEG connect-ack packet (6-byte magic block copy, version 4,
 * packettype 6, byte-swapped cookie and porttype) and sends it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/SendConnectAck.c \
 *       --func SendConnectAck --addr 0x0219A52C --region ov009 --arm --cc 1.1p1 --lang c99
 */
void SendConnectAck(NATNegotiator *neg, SOCSockAddrIn *toaddr)
{
    NatNegPacket p;

    {
        u8 *m = (u8 *)&gNatNegMagic;
        u8 *d = (u8 *)&p;
        d[0] = m[0];
        d[1] = m[1];
        d[2] = m[2];
        d[3] = m[3];
        d[4] = m[4];
        d[5] = m[5];
    }
    p.version = 4;
    p.packettype = 6;
    p.cookie = NN_SWAP32((u32)neg->cookie);
    p.u.init.clientindex = neg->clientIndex;
    gsDebugFormat(7, 0, 8, gNatNegSendConnectAckFmt, neg->cookie);
    SendPacket(neg->negotiateSock, toaddr->addr, NN_SWAP16(toaddr->port), &p, 0x15);
}

/*
 * sdk:      ProcessConnectPacket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 */
void ProcessConnectPacket(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr)
{
    int errcode;

    gsDebugFormat(7, 0, 8, gNatNegConnectPacketFmt, neg->cookie, p->u.connect.finished, SOC_InetNtoA(INADDR(p->u.connect.ipaddr)), NN_NTOHS(p->u.connect.port));

    if (p->u.connect.finished == 0)
        SendConnectAck((NATNegotiator *)neg, fromaddr);

    if (neg->state >= 4) {
        gsDebugFormat(7, 0, 8, gNatNegAlreadyConnectedFmt, neg->cookie);
        return;
    }

    if (p->u.connect.finished != 0) {
        errcode = 4;
        if (p->u.connect.finished == 1) {
            gsDebugFormat(7, 0, 8, gNatNegDeadbeatFmt, neg->cookie);
            errcode = 1;
        } else if (p->u.connect.finished == 2) {
            gsDebugFormat(7, 0, 8, gNatNegConnectTimeoutFmt, neg->cookie);
            errcode = 2;
        }
        StartReport(neg, errcode, -1, 0);
        return;
    }

    neg->guessedIP = p->u.connect.ipaddr;
    neg->guessedPort = NN_NTOHS(p->u.connect.port);
    neg->retryCount = 0;
    neg->state = 4;
    neg->progressCallback(4, neg->userdata);
    SendPingPacket((NATNegotiator *)neg);
}

/*
 * sdk:      ProcessPingPacket (libdwcgsnatneg.TWL.HYB.a natneg.o)
 */
void ProcessPingPacket(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr)
{
    gsDebugFormat(7, 0, 8, gNatNegPingPacketFmt, neg->cookie, SOC_InetNtoA(INADDR(fromaddr->addr)),
                  NN_NTOHS(fromaddr->port), p->u.connect.gotyourdata, p->u.connect.finished);

    if (neg->state < 4) {
        gsDebugFormat(7, 0, 8, gNatNegPingEarlyFmt, neg->cookie);
        return;
    }

    gsDebugFormat(7, 0, 8, gNatNegGotPingFmt, SOC_InetNtoA(INADDR(fromaddr->addr)), NN_NTOHS(fromaddr->port),
                  p->u.connect.gotyourdata, p->u.connect.finished);

    neg->guessedIP = fromaddr->addr;
    neg->guessedPort = NN_NTOHS(fromaddr->port);
    neg->gotRemoteData = 1;
    neg->sendGotRemoteData = p->u.connect.gotyourdata ? 1 : 0;

    SendPingPacket((NATNegotiator *)neg);

    if (neg->state == 4 && neg->sendGotRemoteData) {
        gsDebugFormat(7, 0, 8, gNatNegConnectFinishedFmt, neg->cookie);
        StartReport(neg, 0, neg->gameSock == -1 ? neg->negotiateSock : neg->gameSock, fromaddr);
    }
}

/*
 * sdk:      ProcessPreinitAckPacket (natneg.o)
 */
void ProcessPreinitAckPacket(NATNegotiator *neg, NatNegPacket *p)
{
    gsDebugFormat(7, 0, 8, gNatNegPreinitAckFmt, p->u.init.clientindex);
    if (neg->state != 1) {
        neg->state = 1;
        neg->progressCallback(1, neg->userdata);
        neg->retryTime = current_time() + 10000;
        neg->retryCount = 0;
        neg->maxRetryCount = 12;
    }
    switch (p->u.init.clientindex) {
    case 0:
    case 1:
        return;
    case 2:
        SendInitPackets(neg);
        break;
    }
}

void ProcessInitPacket(NATNegotiator *neg, NatNegPacket *p, SOCSockAddrIn *fromaddr)
{
    switch (p->packettype)
    {
    case 1:
        if (p->u.init.porttype > 3)
            return;
        gsDebugFormat(7, 0, 8, gNatNegInitAckFmt, p->u.init.porttype);
        neg->initAckRecv[p->u.init.porttype] = 1;
        if (neg->state != 2)
            return;
        if (!neg->initAckRecv[1] || !neg->initAckRecv[2] || !neg->initAckRecv[3])
            return;
        if (neg->gameSock != -1)
        {
            if (!neg->initAckRecv[0])
                return;
        }
        neg->state = 3;
        neg->retryTime = current_time() + 60000;
        neg->progressCallback(neg->state, neg->userdata);
        break;
    case 2:
        gsDebugFormat(7, 0, 8, gNatNegErtFmt);
        p->packettype = 3;
        SendPacket(neg->negotiateSock, fromaddr->addr, (u16)NN_SWAP16(fromaddr->port), p, 0x15);
        break;
    case 14:
        gsDebugFormat(7, 0, 8, gNatNegReportAckFmt, neg->cookie);
        neg->state = 8;
        break;
    }
}

void NNProcessData(char *data, int len, SOCSockAddrIn *fromaddr)
{
    NatNegPacket p;
    NATNegotiator *neg;
    unsigned char ptype;

    if (!CheckMagic((const u8 *)data)) {
        gsDebugFormat(7, 0, 4, gNatNegBadHeaderFmt);
        return;
    }

    ptype = ((NatNegPacket *)data)->packettype;
    gsDebugFormat(7, 0, 8, gNatNegPacketFmt, ptype, len, SOC_InetNtoA(INADDR(fromaddr->addr)), NN_NTOHS(fromaddr->port));

    if (ptype == 5 || ptype == 7) {
        if (len < 20) {
            gsDebugFormat(7, 0, 4, gNatNegConnectTooSmallFmt);
            return;
        }
        memcpy(&p, data, 20);
        neg = FindNegotiatorForCookie(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0) {
            gsDebugFormat(7, 0, 4, gNatNegNoNegotiatorFmt, NN_NTOHL((unsigned int)p.cookie));
            return;
        }
        if (ptype == 5)
            ProcessConnectPacket(neg, &p, fromaddr);
        else
            ProcessPingPacket(neg, &p, fromaddr);
    } else if (ptype == 16) {
        if (len < 18)
            return;
        memcpy(&p, data, 18);
        neg = FindNegotiatorForCookie(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0)
            return;
        ProcessPreinitAckPacket(neg, (NatNegPacket *)&p);
    } else {
        if (len < 21) {
            gsDebugFormat(7, 0, 4, gNatNegPacketTooSmallFmt);
            return;
        }
        memcpy(&p, data, 21);
        neg = FindNegotiatorForCookie(NN_NTOHL((unsigned int)p.cookie));
        if (neg == 0) {
            gsDebugFormat(7, 0, 4, gNatNegNoNegotiatorFmt, NN_NTOHL((unsigned int)p.cookie));
            return;
        }
        ProcessInitPacket(neg, &p, fromaddr);
    }
}
