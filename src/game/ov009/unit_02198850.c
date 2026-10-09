/*
 * file:     unit_02198850.c
 * unit:     yes
 * function: func_02198850, func_021988F4, func_02198958, func_0219898C, func_02198A0C
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
 * symbols:
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   func_02084F40  0x02084F40  arm
 *   g_021A5960  0x021A5960  data
 *   g_021A5968  0x021A5968  data
 *   g_021A596C  0x021A596C  data
 *   func_0217EFB8  0x0217EFB8  arm  ov009
 *   func_0217F038  0x0217F038  arm  ov009
 *   func_0217ED0C  0x0217ED0C  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A5970  0x021A5970  data
 *   g_021A5994  0x021A5994  data
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   gotADDRESS1b   0x021AE44C  data
 *   gotERT3        0x021AE450  data
 *   gotERT2        0x021AE454  data
 *   gotERT1        0x021AE458  data
 *   gotADDRESS2    0x021AE45C  data
 *   gotADDRESS3    0x021AE460  data
 *   gotADDRESS1a   0x021AE464  data
 *   nIndex         0x021AE468  data
 *   strAddressArray 0x021AE46C data
 *   g_021AE498     0x021AE498  data
 *   g_021A59B4     0x021A59B4  data
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021AE4A7     0x021AE4A7  data
 *   g_021AE4AB     0x021AE4AB  data
 *   g_021A59CC     0x021A59CC  data
 *   g_021A59F0     0x021A59F0  data
 *   g_021A5A20     0x021A5A20  data
 *   g_021A5A50     0x021A5A50  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G_Magic6.h"

#define NN_NTOHS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define NN_NTOHL(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))
typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct SOCHostEnt {
    unsigned char pad0[0xC];
    SOCInAddr **addrList;
} SOCHostEnt;

typedef struct SOCSockAddrIn {
	unsigned char len;
	unsigned char family;
	unsigned short port;
	unsigned int addr;
} SOCSockAddrIn;

typedef struct _AddressMapping {
    unsigned int privateIp;
    unsigned short privatePort;
    unsigned int publicIp;
    unsigned short publicPort;
} AddressMapping;

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

typedef struct _NAT {
    char brand[32];                                  /* 0x00 */
    char model[32];                                  /* 0x20 */
    char firmware[64];                               /* 0x40 */
    int ipRestricted;                                /* 0x80 */
    int portRestricted;                              /* 0x84 */
    int promiscuity;                                 /* 0x88 */
    int natType;                                     /* 0x8C */
    int mappingScheme;                               /* 0x90 */
    AddressMapping mappings[4];                      /* 0x94 */
    int qr2Compatible;                               /* 0xD4 */
} NAT;

extern char *func_0215FA9C(SOCInAddr in);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern SOCHostEnt *func_0217EFB8(void);
extern int func_0217F038(SOCInAddr *addr);
extern int func_0217ED0C(int sock, void *addr, int *len);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
extern int func_0217ED54(int sock);
extern int func_020923F0(const void *s1, const void *s2, unsigned long n);
char *func_02198850(unsigned int ip, unsigned short port, char *string);
unsigned int func_021988F4(void);
unsigned short func_02198958(int sock);
void func_0219898C(AddressMapping *theMap);
int func_02198A0C(int sock, NAT *nat);
static int nIndex = 0;

static int gotADDRESS1a = 0;

static int gotADDRESS3 = 0;

static int gotADDRESS2 = 0;

static int gotERT1 = 0;

static int gotERT2 = 0;

static int gotERT3 = 0;

static int gotADDRESS1b = 0;

static char strAddressArray[2][22] = {0};

extern char g_021A5960[];
extern char g_021A5968[];
extern char g_021A596C[];
extern char g_021A5970[];
extern char g_021A5994[];
extern char g_021AE498[];
extern char g_021A59B4[];
extern struct Magic6 g_021A5A7C;
extern char g_021A59CC[];
extern char g_021A59F0[];
extern char g_021A5A20[];
extern char g_021A5A50[];





/*
 * sdk:      AddressToString (natify.o)
 */
char *func_02198850(unsigned int ip, unsigned short port, char *string)
{
    SOCInAddr inAddr;
    char *strAddress;

    if (!string) {
        nIndex ^= 1;
        string = strAddressArray[nIndex];
    }
    if (ip) {
        inAddr.addr = ip;
        if (port) {
            strAddress = func_0215FA9C(inAddr);
            func_02084F40(string, g_021A5960, strAddress, port);
        } else {
            strAddress = func_0215FA9C(inAddr);
            func_02084F40(string, g_021A5968, strAddress);
        }
    } else if (port) {
        func_02084F40(string, g_021A596C, port);
    } else {
        string[0] = 0;
    }
    return string;
}





unsigned int func_021988F4(void)
{
    int num_local_ips;
    SOCHostEnt *phost;
    SOCInAddr *addr;
    unsigned int localip;

    localip = 0;
    phost = func_0217EFB8();
    if (!phost)
        return 0;
    for (num_local_ips = 0;; num_local_ips++) {
        addr = phost->addrList[num_local_ips];
        if (!addr)
            break;
        if (addr->addr != 16777343) {
            localip = *(unsigned int *)addr;
            if (func_0217F038((SOCInAddr *)addr))
                return localip;
        }
    }
    return localip;
}




/*
 * sdk:      GetLocalPort (libdwcgsnatneg.TWL.HYB.a(natify.o))
 */
unsigned short func_02198958(int sock)
{
	int ret;
	SOCSockAddrIn saddr;
	int saddrlen;

	saddrlen = 8;
	ret = func_0217ED0C(sock, &saddr, &saddrlen);
	if (ret == -1)
		return 0;
	return saddr.port;
}



/*
 * sdk:      OutputMapping (natify.o)
 */
void func_0219898C(AddressMapping *theMap)
{
    char *a;
    char *b;

    if (!theMap) {
        func_0217D254(7, 0, 0x10, g_021A5970);
        return;
    }
    a = func_02198850(theMap->privateIp, theMap->privatePort, 0);
    b = func_02198850(theMap->publicIp, theMap->publicPort, 0);
    func_0217D254(7, 0, 0x10, g_021A5994, a, b);
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
 *           zero-initialised file statics (plus AddressToString's nIndex and
 *           strAddressArray, which share the section) in the definition order
 *           that gives the vendor layout, all anchored on .bss+0 like the
 *           vendor. Distinct objects free the allocator (105 -> 19). The rest
 *           was the DWARF local `ptype`: `ptype = *(unsigned char *)(data + 7);`
 *           just before the `length < 21` test (ldrb, scheduled early).
 *           `data` stays extern: as a local static it joins .bss and moves
 *           the code (vendor keeps it in its own section).
 */
int func_02198A0C(int sock, NAT *nat)
{
    int length;
    unsigned char ptype;
    NatNegPacket p;
    SOCSockAddrIn saddr;
    int saddrlen = sizeof(SOCSockAddrIn);

    if (gotERT1 && gotERT2 && gotERT3 && gotADDRESS1a &&
        gotADDRESS1b && gotADDRESS2 && gotADDRESS3)
        return 0;

    if (sock != -1 && func_0217EF50(sock)) do {
        length = func_0217EC60(sock, g_021AE498, 512, 0, &saddr, &saddrlen);
        if (length == -1) {
            func_0217D254(7, 0, 8, g_021A59B4, func_0217ED54(sock));
            break;
        }

        if (func_020923F0(g_021AE498, ((char *)&g_021A5A7C), 6) != 0)
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
                func_0217D254(7, 0, 16, g_021A59CC, func_02198850(saddr.addr, NN_NTOHS(saddr.port), 0));
                break;
            case 2:
                nat->ipRestricted = 0;
                gotERT2 = 1;
                func_0217D254(7, 0, 16, g_021A59F0, func_02198850(saddr.addr, NN_NTOHS(saddr.port), 0));
                break;
            case 3:
                nat->portRestricted = 0;
                gotERT3 = 1;
                func_0217D254(7, 0, 16, g_021A5A20, func_02198850(saddr.addr, NN_NTOHS(saddr.port), 0));
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
            nat->mappings[p.cookie].privateIp = func_021988F4();
            nat->mappings[p.cookie].privatePort = NN_NTOHS(func_02198958(sock));
            nat->mappings[p.cookie].publicIp = p.Packet.Init.localip;
            nat->mappings[p.cookie].publicPort = NN_NTOHS(p.Packet.Init.localport);
            func_0217D254(7, 0, 16, g_021A5A50, p.cookie, func_02198850(saddr.addr, NN_NTOHS(saddr.port), 0));
            func_0219898C(&nat->mappings[p.cookie]);
        }
    } while (sock != -1 && func_0217EF50(sock));

    return 1;
}
