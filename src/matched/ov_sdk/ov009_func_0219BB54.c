/*
 * function: handle_public_address
 * address:  0x0219BB54
 * packet:   pkt_ov009_0219BB54
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      handle_public_address (qr2.o)
 *
 * symbols:
 *   func_0208CF34  0x0208CF34  arm
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   g_021A769C  0x021A769C  data
 *   g_021A76A8  0x021A76A8  data
 */

typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct qr2_implementation_s {
    unsigned char pad0[0xA8];
    void (*publicAddressCallback)(unsigned int ip, unsigned short port, void *userdata);
    unsigned char padAC[0x60];
    unsigned int publicip;
    unsigned short publicport;
    unsigned char pad112[2];
    void *userdata;
} qr2_implementation_s;

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

extern char g_021A769C[];
extern char g_021A76A8[];
extern int func_0208CF34(char *src, char *fmt, ...);
extern char *func_0215FA9C(SOCInAddr in);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);

void handle_public_address(qr2_implementation_s *qrec, char *buffer)
{
    unsigned int ip;
    unsigned int portTemp;
    unsigned short port;
    SOCInAddr addr;

    func_0208CF34(buffer, g_021A769C, &ip, &portTemp);
    port = (unsigned short)portTemp;
    ip = SWAP32(ip);
    if (ip == 0 || port == 0)
        return;
    addr.addr = ip;
    gsDebugFormat(3, 0, 8, g_021A76A8, func_0215FA9C(addr), port);
    if (qrec->publicip == ip && qrec->publicport == port)
        return;
    qrec->publicip = ip;
    qrec->publicport = port;
    qrec->publicAddressCallback(ip, port, qrec->userdata);
}
