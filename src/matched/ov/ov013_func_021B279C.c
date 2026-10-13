/*
 * function: VCT_SESSION_GetEventCode
 * address:  0x021B279C
 * packet:   pkt_ov013_021B279C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctGroupEventCodes  0x021B3AF0  data  ov013  a1
 *   gVctPeerEventCodes  0x021B3AF5  data  ov013  a1
 */

typedef unsigned char u8;

typedef struct Q {
    int f0;
    u8 b4;
    u8 b5;
    u8 pad[2];
    int f8;
    int fC;
} Q;

extern u8 gVctGroupEventCodes[];
extern u8 gVctPeerEventCodes[];

int VCT_SESSION_GetEventCode(u8 *o, Q *q)
{
    q->b5 = o[0xb];
    if (o[4] == 0xff) {
        if (o[6] == 0) {
            q->f8 = (q->b4 != 0) ? (1 << q->b4) : 1;
        }
        return gVctGroupEventCodes[o[6]];
    }
    if (o[4] == 0) {
        if (o[6] == 0) {
            if (q->fC == 1) {
                q->f8 = (q->b4 != 0) ? (1 << q->b4) : 1;
                return 7;
            }
            if (q->fC == 5)
                return 9;
            return 12;
        }
        return gVctPeerEventCodes[o[6]];
    }
    return 12;
}
