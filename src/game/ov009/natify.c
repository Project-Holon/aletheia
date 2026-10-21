/*
 * file:     natify.c
 * unit:     yes
 * function: AddressToString, GetLocalIP, GetLocalPort, OutputMapping, Think, NatifyThink, DetermineNatType
 * address:  0x02198850
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 * sdk:      DetermineNatType (libdwcgsnatneg.TWL.HYB.a natify.o)
 * abs is declared __attribute__((const)): the object keeps ipRestricted and
 * portRestricted in registers across every abs call, which a plain extern
 * prototype does not allow.
 *
 * symbols:
 *   SOC_InetNtoA  0x0215FA9C  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   g_021A5960  0x021A5960  data
 *   g_021A5968  0x021A5968  data
 *   g_021A596C  0x021A596C  data
 *   getlocalhost  0x0217EFB8  arm  ov009
 *   IsPrivateIP  0x0217F038  arm  ov009
 *   getsockname  0x0217ED0C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   g_021A5970  0x021A5970  data
 *   g_021A5994  0x021A5994  data
 *   CanReceiveOnSocket  0x0217EF50  arm  ov009
 *   recvfrom  0x0217EC60  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   memcmp  0x020923F0  arm
 *   gotADDRESS1b   0x021AE44C  data
 *   gotERT3        0x021AE450  data
 *   gotERT2        0x021AE454  data
 *   gotERT1        0x021AE458  data
 *   gotADDRESS2    0x021AE45C  data
 *   gotADDRESS3    0x021AE460  data
 *   gotADDRESS1a   0x021AE464  data
 *   sNatifyNIndex         0x021AE468  data
 *   strAddressArray 0x021AE46C data
 *   g_021AE498     0x021AE498  data
 *   g_021A59B4     0x021A59B4  data
 *   gNatNegMagic     0x021A5A7C  data
 *   g_021AE4A7     0x021AE4A7  data
 *   g_021AE4AB     0x021AE4AB  data
 *   g_021A59CC     0x021A59CC  data
 *   g_021A59F0     0x021A59F0  data
 *   g_021A5A20     0x021A5A20  data
 *   g_021A5A50     0x021A5A50  data
 *   abs  0x02091588  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "ov009_globals.h"

#define NN_NTOHS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define NN_NTOHL(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
#include "natneg_types.h"
#include "../sdk_soc.h"

typedef struct _InitPacket {
    unsigned char porttype;                          /* 0x00 */
    unsigned char clientindex;                       /* 0x01 */
    unsigned char usegameport;                       /* 0x02 */
    unsigned int localip;                            /* 0x04 */
    unsigned short localport;                        /* 0x08 */
} InitPacket;

typedef struct _NatNegPacket {
    unsigned char magic[6];                          /* 0x00 */
    unsigned char version;                           /* 0x06 */
    unsigned char packettype;                        /* 0x07 */
    unsigned int cookie;                             /* 0x08 */
    union {
        InitPacket Init;
        unsigned char raw[64];
    } Packet;                                        /* 0x0C */
} NatNegPacket;

#include "soc.h"
#include "../arm9/os_printf.h"
#include "gsplatformsocket.h"
struct SOCSockAddr;
#include "gsdebug.h"
#include "../arm9/msl_string_mem.h"
extern int abs(int x) __attribute__((const));
char *AddressToString(unsigned int ip, unsigned short port, char *string);
static unsigned int GetLocalIP(void);
static unsigned short GetLocalPort(int sock);
void OutputMapping(AddressMapping *theMap);
int Think(int sock, NAT *nat);
int NatifyThink(int sock, void *nat);
int DetermineNatType(NAT *nat);
extern char g_021A5960[];
extern char g_021A5968[];
extern char g_021A596C[];
extern char g_021A5970[];
extern char g_021A5994[];
extern char g_021AE498[];
extern char g_021A59B4[];
extern NatNegMagic gNatNegMagic;
extern char g_021A59CC[];
extern char g_021A59F0[];
extern char g_021A5A20[];
extern char g_021A5A50[];

static int sNatifyNIndex = 0;


static int gotADDRESS1a = 0;


static int gotADDRESS3 = 0;


static int gotADDRESS2 = 0;


static int gotERT1 = 0;


static int gotERT2 = 0;


static int gotERT3 = 0;


static int gotADDRESS1b = 0;


static char strAddressArray[2][22] = {0};






/*
 * sdk:      AddressToString (natify.o)
 */
char *AddressToString(unsigned int ip, unsigned short port, char *string)
{
    SOCInAddr inAddr;
    char *strAddress;

    if (!string) {
        sNatifyNIndex ^= 1;
        string = strAddressArray[sNatifyNIndex];
    }
    if (ip) {
        inAddr.addr = ip;
        if (port) {
            strAddress = SOC_InetNtoA(inAddr);
            OS_SPrintf(string, g_021A5960, strAddress, port);
        } else {
            strAddress = SOC_InetNtoA(inAddr);
            OS_SPrintf(string, g_021A5968, strAddress);
        }
    } else if (port) {
        OS_SPrintf(string, g_021A596C, port);
    } else {
        string[0] = 0;
    }
    return string;
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





/*
 * sdk:      GetLocalPort (libdwcgsnatneg.TWL.HYB.a(natify.o))
 */
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




/*
 * sdk:      OutputMapping (natify.o)
 */
void OutputMapping(AddressMapping *theMap)
{
    char *a;
    char *b;

    if (!theMap) {
        gsDebugFormat(7, 0, 0x10, g_021A5970);
        return;
    }
    a = AddressToString(theMap->privateIp, theMap->privatePort, 0);
    b = AddressToString(theMap->publicIp, theMap->publicPort, 0);
    gsDebugFormat(7, 0, 0x10, g_021A5994, a, b);
}



/* natify.o .bss (from 0x021AE44C), at the vendor layout */


/*
 * old blocker: register-allocation tie: the first (21-byte) inline memcpy in the
 *           ptype==2 branch takes r3 in the image and sb here, rotating the
 *           whole NN_ERTREPLY branch (flag base r1<->r3, data+0xf r3<->r2,
 *           ptype r2<->r1) and the three switch arms. No source shape found.
 *
 * sdk:      Think (libdwcgsnatneg.TWL.HYB.a natify.o)
 *
 * notes: DIFF, same size (1128 B). Residue is register choice only in the
 * NN_ERTREPLY branch (+0x11C..+0x1C0): the object puts the memcpy loop
 * counter in r3, the flag base (gotADDRESS1b) in r1 and porttype in r2;
 * this draft gives sb/r3/r1 (the NN_ADDRESS_REPLY branch matches). Tried:
 * flag struct vs int array, switch vs if chain, case order, local order,
 * ptype spelling, switch(ptype), compilers 1.1/1.2/1.2p1. g_021AE4A7 and
 * g_021AE4AB are data+0xf and data+0x13 (interior of the static buffer),
 * referenced through g_021AE498 + 15 / + 19.
 *
 * lane T14 (2026-09-30): `cookie` is unsigned in the object.  NN_NTOHL's
 * >>24 and the fused (x>>8)&0xff<<8 rematerialisation are `lsr` in the
 * image and were `asr` here; declaring the field unsigned fixed +02B8 and
 * +02C4 (88 -> 86 concrete bytes, 41 -> 39 rows) and is the correct field
 * type.  Residue after that: the three-way register rotation r1/r3/r2
 * (flags base / g_021AE4A7 / ptype) at +0134..+018C plus the store/load
 * order that follows it at +01A8/+01F8/+0238; a local `char *buf =
 * g_021AE498`, a local `NatifyFlags *f`, a local for porttype, `saddrlen`
 * first and a flattening of the memcpy block all measured worse or
 * byte-identical.
 *
 * lane U62 (2026-09-30): 1128/1128, 86 concrete (39 sites). Upstream NATify.c in the GameSpy
 *           clone (scratch/U2/gs/src/GameSpy/natneg/NATify.c) confirms this source's shape and
 *           declaration order (length, ptype, p, saddr, saddrlen = the DWARF print order
 *           reversed) and the object's listing is byte-identical to the image, including the
 *           three-memcpy form (21 then 4 at data+15 then 2 at data+19) that the draft already
 *           has. The whole 39-site cascade follows one register: the 21-byte memcpy's inline
 *           counter is r3 in the image and r9(sb) here. Image consequence: r3 is then reused
 *           for the data+0xf constant, the flags base gets r1, and the byte temps r2/r8/lr/ip;
 *           here the counter took the just-died r9 (`length`), the flags base took r3 and the
 *           constant r2, shifting cases 2/3 (+01F8..+0264) as well. No source lever found:
 *           declaration order and the memcpy spelling are already the vendor's. Parked as the
 *           two-simultaneously-live-temporaries class.
 *
 * lane04 (2026-10-01): EXACT. The flags are seven separate globals in
 *           natify.o's .bss (gotADDRESS1b first), not one struct: modelled as
 *           zero-initialised file statics (plus AddressToString's sNatifyNIndex and
 *           strAddressArray, which share the section) in the definition order
 *           that gives the vendor layout, all anchored on .bss+0 like the
 *           vendor. Distinct objects free the allocator (105 -> 19). The rest
 *           was the DWARF local `ptype`: `ptype = *(unsigned char *)(data + 7);`
 *           just before the `length < 21` test (ldrb, scheduled early).
 *           `data` stays extern: as a local static it joins .bss and moves
 *           the code (vendor keeps it in its own section).
 */
int Think(int sock, NAT *nat)
{
    int length;
    unsigned char ptype;
    NatNegPacket p;
    SOCSockAddrIn saddr;
    int saddrlen = sizeof(SOCSockAddrIn);

    if (gotERT1 && gotERT2 && gotERT3 && gotADDRESS1a &&
        gotADDRESS1b && gotADDRESS2 && gotADDRESS3)
        return 0;

    if (sock != -1 && CanReceiveOnSocket(sock)) do {
        length = recvfrom(sock, g_021AE498, 512, 0, (struct SOCSockAddr *)(&saddr), &saddrlen);
        if (length == -1) {
            gsDebugFormat(7, 0, 8, g_021A59B4, GOAGetLastError(sock));
            break;
        }

        if (memcmp((unsigned char *)g_021AE498, (unsigned char *)(((char *)&gNatNegMagic)), 6) != 0)
            return 1;

        ptype = *(unsigned char *)(g_021AE498 + 7);
        if (length < 21)
            return 1;

        if (ptype == 2) {
            memcpy(&p, g_021AE498, 21);
            memcpy(&p.Packet.Init.localip, g_021AE498 + 15, 4);
            memcpy(&p.Packet.Init.localport, g_021AE498 + 19, 2);
            switch (p.Packet.Init.porttype) {
            case 1:
                gotERT1 = 1;
                gsDebugFormat(7, 0, 16, g_021A59CC, AddressToString(saddr.addr, NN_NTOHS(saddr.port), 0));
                break;
            case 2:
                nat->ipRestricted = 0;
                gotERT2 = 1;
                gsDebugFormat(7, 0, 16, g_021A59F0, AddressToString(saddr.addr, NN_NTOHS(saddr.port), 0));
                break;
            case 3:
                nat->portRestricted = 0;
                gotERT3 = 1;
                gsDebugFormat(7, 0, 16, g_021A5A20, AddressToString(saddr.addr, NN_NTOHS(saddr.port), 0));
                break;
            }
        } else if (ptype == 11) {
            memcpy(&p, g_021AE498, 21);
            memcpy(&p.Packet.Init.localip, g_021AE498 + 15, 4);
            memcpy(&p.Packet.Init.localport, g_021AE498 + 19, 2);
            p.cookie = NN_NTOHL(p.cookie);
            switch (p.cookie) {
            case 0:
                gotADDRESS1a = 1;
                break;
            case 3:
                gotADDRESS1b = 1;
                break;
            case 1:
                gotADDRESS2 = 1;
                break;
            case 2:
                gotADDRESS3 = 1;
                break;
            }
            nat->mappings[p.cookie].privateIp = GetLocalIP();
            nat->mappings[p.cookie].privatePort = NN_NTOHS(GetLocalPort(sock));
            nat->mappings[p.cookie].publicIp = p.Packet.Init.localip;
            nat->mappings[p.cookie].publicPort = NN_NTOHS(p.Packet.Init.localport);
            gsDebugFormat(7, 0, 16, g_021A5A50, p.cookie, AddressToString(saddr.addr, NN_NTOHS(saddr.port), 0));
            OutputMapping(&nat->mappings[p.cookie]);
        }
    } while (sock != -1 && CanReceiveOnSocket(sock));

    return 1;
}


int NatifyThink(int sock, void *nat)
{
    return Think(sock, nat);
}


/*
 * sdk:      DetermineNatType (libdwcgsnatneg.TWL.HYB.a natify.o)
 *
 * abs is declared __attribute__((const)): the object keeps ipRestricted and
 * portRestricted in registers across every abs call, which a plain extern
 * prototype does not allow.
 */
int DetermineNatType(NAT *nat)
{
    nat->natType = unknown;
    nat->promiscuity = promiscuity_not_applicable;
    nat->qr2Compatible = 1;

    if (nat->mappings[0].publicIp == 0 || nat->mappings[1].publicIp == 0 || nat->mappings[2].publicIp == 0)
        return 0;

    if (!nat->portRestricted && !nat->ipRestricted && nat->mappings[0].publicIp == nat->mappings[0].privateIp)
        nat->natType = no_nat;
    else if (nat->mappings[0].publicIp == nat->mappings[0].privateIp)
        nat->natType = firewall_only;
    else {
        if (!nat->ipRestricted && !nat->portRestricted
            && abs(nat->mappings[2].publicPort - nat->mappings[1].publicPort) >= 1) {
            nat->natType = symmetric;
            nat->promiscuity = promiscuous;
        } else if (nat->ipRestricted && !nat->portRestricted
                   && abs(nat->mappings[2].publicPort - nat->mappings[1].publicPort) >= 1) {
            nat->natType = symmetric;
            nat->promiscuity = port_promiscuous;
        } else if (!nat->ipRestricted && nat->portRestricted
                   && abs(nat->mappings[2].publicPort - nat->mappings[1].publicPort) >= 1) {
            nat->natType = symmetric;
            nat->promiscuity = ip_promiscuous;
        } else if (nat->ipRestricted && nat->portRestricted
                   && abs(nat->mappings[2].publicPort - nat->mappings[1].publicPort) >= 1) {
            nat->natType = symmetric;
            nat->promiscuity = not_promiscuous;
        } else if (nat->portRestricted)
            nat->natType = port_restricted_cone;
        else if (nat->ipRestricted && !nat->portRestricted)
            nat->natType = restricted_cone;
        else if (!nat->ipRestricted && !nat->portRestricted)
            nat->natType = full_cone;
        else
            nat->natType = unknown;
    }

    if (nat->mappings[0].publicPort == nat->mappings[0].privatePort
        && nat->mappings[1].publicPort == nat->mappings[1].privatePort
        && nat->mappings[2].publicPort == nat->mappings[2].privatePort)
        nat->mappingScheme = private_as_public;
    else if (nat->mappings[0].publicPort == nat->mappings[1].publicPort
             && nat->mappings[1].publicPort == nat->mappings[2].publicPort)
        nat->mappingScheme = consistent_port;
    else if (nat->mappings[0].publicPort == nat->mappings[0].privatePort
             && nat->mappings[2].publicPort - nat->mappings[1].publicPort == 1)
        nat->mappingScheme = mixed;
    else if (nat->mappings[2].publicPort - nat->mappings[1].publicPort == 1)
        nat->mappingScheme = incremental;
    else
        nat->mappingScheme = unrecognized;

    if (nat->mappings[3].publicPort != 0 && nat->mappings[0].publicPort != nat->mappings[3].publicPort)
        nat->qr2Compatible = 0;

    return 1;
}
