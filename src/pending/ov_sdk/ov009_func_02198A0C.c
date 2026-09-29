/*
 * function: func_02198A0C
 * address:  0x02198A0C
 * packet:   pkt_ov009_02198A0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      Think (libdwcgsnatneg.TWL.HYB.a natify.o)
 *
 * symbols:
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   func_02198850  0x02198850  arm  ov009
 *   func_021988F4  0x021988F4  arm  ov009
 *   func_02198958  0x02198958  arm  ov009
 *   func_0219898C  0x0219898C  arm  ov009
 *   g_021AE44C     0x021AE44C  data
 *   g_021AE498     0x021AE498  data
 *   g_021A59B4     0x021A59B4  data
 *   g_021A5A7C     0x021A5A7C  data
 *   g_021AE4A7     0x021AE4A7  data
 *   g_021AE4AB     0x021AE4AB  data
 *   g_021A59CC     0x021A59CC  data
 *   g_021A59F0     0x021A59F0  data
 *   g_021A5A20     0x021A5A20  data
 *   g_021A5A50     0x021A5A50  data
 *
 * notes: DIFF, same size (1128 B). Residue is register choice only in the
 * NN_ERTREPLY branch (+0x11C..+0x1C0): the object puts the memcpy loop
 * counter in r3, the flag base (gotADDRESS1b) in r1 and porttype in r2;
 * this draft gives sb/r3/r1 (the NN_ADDRESS_REPLY branch matches). Tried:
 * flag struct vs int array, switch vs if chain, case order, local order,
 * ptype spelling, switch(ptype), compilers 1.1/1.2/1.2p1. g_021AE4A7 and
 * g_021AE4AB are data+0xf and data+0x13 (interior of the static buffer),
 * referenced through g_021AE498 + 15 / + 19.
 */

#include "../../matched/arm9_sdk/libc/string.h"

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

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
    int cookie;                                      /* 0x08 */
    union {
        InitPacket Init;
        unsigned char raw[64];
    } Packet;                                        /* 0x0C */
} NatNegPacket;

typedef struct _AddressMapping {
    unsigned int privateIp;
    unsigned short privatePort;
    unsigned int publicIp;
    unsigned short publicPort;
} AddressMapping;

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

/* natify.o .bss flags, addressed from gotADDRESS1b */
typedef struct NatifyFlags {
    int gotADDRESS1b;                                /* 0x00 */
    int gotERT3;                                     /* 0x04 */
    int gotERT2;                                     /* 0x08 */
    int gotERT1;                                     /* 0x0C */
    int gotADDRESS2;                                 /* 0x10 */
    int gotADDRESS3;                                 /* 0x14 */
    int gotADDRESS1a;                                /* 0x18 */
} NatifyFlags;

#define NN_NTOHS(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define NN_NTOHL(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | (((x) << 24) & 0xFF000000))

extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
extern int func_0217ED54(int sock);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern int func_020923F0(const void *s1, const void *s2, unsigned long n);
extern char *func_02198850(unsigned int ip, unsigned short port, char *string);
extern unsigned int func_021988F4(void);
extern unsigned short func_02198958(int sock);
extern void func_0219898C(AddressMapping *theMap);

extern NatifyFlags g_021AE44C;
extern char g_021AE498[];
extern char g_021A59B4[];
extern char g_021A5A7C[];
extern char g_021A59CC[];
extern char g_021A59F0[];
extern char g_021A5A20[];
extern char g_021A5A50[];

int func_02198A0C(int sock, NAT *nat)
{
    int length;
    unsigned char ptype;
    NatNegPacket p;
    SOCSockAddrIn saddr;
    int saddrlen = sizeof(SOCSockAddrIn);

    if (g_021AE44C.gotERT1 && g_021AE44C.gotERT2 && g_021AE44C.gotERT3 && g_021AE44C.gotADDRESS1a &&
        g_021AE44C.gotADDRESS1b && g_021AE44C.gotADDRESS2 && g_021AE44C.gotADDRESS3)
        return 0;

    if (sock != -1 && func_0217EF50(sock)) do {
        length = func_0217EC60(sock, g_021AE498, 512, 0, &saddr, &saddrlen);
        if (length == -1) {
            func_0217D254(7, 0, 8, g_021A59B4, func_0217ED54(sock));
            break;
        }

        if (func_020923F0(g_021AE498, g_021A5A7C, 6) != 0)
            return 1;

        ptype = g_021AE498[7];
        if (length < 21)
            return 1;

        if (ptype == 2) {
            memcpy(&p, g_021AE498, 21);
            memcpy(&p.Packet.Init.localip, g_021AE498 + 15, 4);
            memcpy(&p.Packet.Init.localport, g_021AE498 + 19, 2);
            switch (p.Packet.Init.porttype) {
            case 1:
                g_021AE44C.gotERT1 = 1;
                func_0217D254(7, 0, 16, g_021A59CC, func_02198850(saddr.addr, NN_NTOHS(saddr.port), 0));
                break;
            case 2:
                nat->ipRestricted = 0;
                g_021AE44C.gotERT2 = 1;
                func_0217D254(7, 0, 16, g_021A59F0, func_02198850(saddr.addr, NN_NTOHS(saddr.port), 0));
                break;
            case 3:
                nat->portRestricted = 0;
                g_021AE44C.gotERT3 = 1;
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
                g_021AE44C.gotADDRESS1a = 1;
                break;
            case 3:
                g_021AE44C.gotADDRESS1b = 1;
                break;
            case 1:
                g_021AE44C.gotADDRESS2 = 1;
                break;
            case 2:
                g_021AE44C.gotADDRESS3 = 1;
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
