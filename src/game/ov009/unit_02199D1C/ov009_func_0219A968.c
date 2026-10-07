/*
 * function: func_0219A968
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
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0219972C  0x0219972C  arm  ov009
 *   g_021A6450  0x021A6450  data
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

extern char g_021A6450[];
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern unsigned int func_0217F264(void);
extern void func_0219972C(NATNegotiator *neg);

void func_0219A968(NATNegotiator *neg, NatNegPacket *p)
{
    func_0217D254(7, 0, 8, g_021A6450, p->porttype);
    if (neg->initAckSent != 1) {
        neg->initAckSent = 1;
        neg->callback(1, neg->userdata);
        neg->timeout = func_0217F264() + 10000;
        neg->retryCount = 0;
        neg->retryTime = 12;
    }
    switch (p->porttype) {
    case 0:
    case 1:
        return;
    case 2:
        func_0219972C(neg);
        break;
    }
}
