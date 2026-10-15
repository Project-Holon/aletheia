/*
 * function: GSIAvailableCheckThink
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
 *   HandlePacket  0x0217C848  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   func_0217C704  0x0217C704  arm  ov009
 *   gGsAvailableCheck  0x021ACF7C  data
 *   gGsAvailabilityState  0x021ACEF8  data
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
extern int HandlePacket(char *packet, int len, struct SOCSockAddrIn *address, int *disabledservices);
extern int closesocket(int sock);
extern unsigned int current_time(void);
extern void func_0217C704(void);
extern AvailableCheck gGsAvailableCheck;
extern int gGsAvailabilityState;

int GSIAvailableCheckThink(void)
{
    char packet[64];
    SOCSockAddrIn address;
    int len = sizeof(address);
    int rcode;
    int disabledservices;

    if (gGsAvailableCheck.sock == -1) {
        gGsAvailabilityState = 1;
        return 1;
    }
    if (func_0217EF50(gGsAvailableCheck.sock)) {
        rcode = func_0217EC60(gGsAvailableCheck.sock, packet, 64, 0, &address, &len);
        if (HandlePacket(packet, rcode, (struct SOCSockAddrIn *)(&address), &disabledservices) == 0) {
            closesocket(gGsAvailableCheck.sock);
            if (disabledservices & 1) {
                gGsAvailabilityState = 2;
                return 2;
            } else if (disabledservices & 2) {
                gGsAvailabilityState = 3;
                return 3;
            } else {
                gGsAvailabilityState = 1;
                return 1;
            }
        }
    }
    if (current_time() > gGsAvailableCheck.sendTime + 2000) {
        if (gGsAvailableCheck.retryCount == 1) {
            closesocket(gGsAvailableCheck.sock);
            gGsAvailabilityState = 1;
            return 1;
        }
        func_0217C704();
        gGsAvailableCheck.retryCount++;
    }
    return 0;
}
