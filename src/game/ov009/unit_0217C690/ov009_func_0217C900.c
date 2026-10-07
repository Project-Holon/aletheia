/*
 * function: func_0217C900
 * address:  0x0217C900
 * packet:   pkt_ov009_0217C900
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GSIAvailableCheckThink (libdwcgscommon.TWL.HYB.a(gsavailable.o))
 *
 * symbols:
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   func_0217C848  0x0217C848  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217C704  0x0217C704  arm  ov009
 *   g_021ACF7C  0x021ACF7C  data
 *   g_021ACEF8  0x021ACEF8  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8  len;
    u8  family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

typedef struct {
    int sock;
    SOCSockAddrIn address;
    char packet[64];
    int packetLen;
    unsigned int sendTime;
    int retryCount;
} AvailableCheck;

extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, void *addr, int *fromlen);
struct SOCSockAddrIn;
extern int func_0217C848(char *packet, int len, struct SOCSockAddrIn *address, int *disabledservices);
extern int func_0217EB2C(int sock);
extern unsigned int func_0217F264(void);
extern void func_0217C704(void);
extern AvailableCheck g_021ACF7C;
extern int g_021ACEF8;

int func_0217C900(void)
{
    char packet[64];
    SOCSockAddrIn address;
    int len = sizeof(address);
    int rcode;
    int disabledservices;

    if (g_021ACF7C.sock == -1) {
        g_021ACEF8 = 1;
        return 1;
    }
    if (func_0217EF50(g_021ACF7C.sock)) {
        rcode = func_0217EC60(g_021ACF7C.sock, packet, 64, 0, &address, &len);
        if (func_0217C848(packet, rcode, (struct SOCSockAddrIn *)(&address), &disabledservices) == 0) {
            func_0217EB2C(g_021ACF7C.sock);
            if (disabledservices & 1) {
                g_021ACEF8 = 2;
                return 2;
            } else if (disabledservices & 2) {
                g_021ACEF8 = 3;
                return 3;
            } else {
                g_021ACEF8 = 1;
                return 1;
            }
        }
    }
    if (func_0217F264() > g_021ACF7C.sendTime + 2000) {
        if (g_021ACF7C.retryCount == 1) {
            func_0217EB2C(g_021ACF7C.sock);
            g_021ACEF8 = 1;
            return 1;
        }
        func_0217C704();
        g_021ACF7C.retryCount++;
    }
    return 0;
}
