/*
 * function: ProcessPreinitAckPacket
 * address:  0x0219A968
 * packet:   pkt_ov009_0219A968
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessPreinitAckPacket (natneg.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   SendInitPackets  0x0219972C  arm  ov009
 *   gNatNegPreinitAckFmt  0x021A6450  data
 */

typedef struct _NATNegotiator {
    unsigned char pad0[0xC];
    void (*callback)(int state, void *userdata);
    unsigned char pad10[4];
    void *userdata;
    unsigned char pad18[4];
    int initAckSent;
    unsigned char pad20[0x10];
    int retryCount;
    int retryTime;
    unsigned int timeout;
} NATNegotiator;

typedef struct _NatNegPacket {
    unsigned char pad0[0xD];
    unsigned char porttype;
} NatNegPacket;

extern char gNatNegPreinitAckFmt[];
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern unsigned int current_time(void);
extern void SendInitPackets(NATNegotiator *neg);

void ProcessPreinitAckPacket(NATNegotiator *neg, NatNegPacket *p)
{
    func_0217D254(7, 0, 8, gNatNegPreinitAckFmt, p->porttype);
    if (neg->initAckSent != 1) {
        neg->initAckSent = 1;
        neg->callback(1, neg->userdata);
        neg->timeout = current_time() + 10000;
        neg->retryCount = 0;
        neg->retryTime = 12;
    }
    switch (p->porttype) {
    case 0:
    case 1:
        return;
    case 2:
        SendInitPackets(neg);
        break;
    }
}
