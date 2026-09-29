/*
 * function: func_021B279C
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
 *   d_021B3AF0  0x021B3AF0  data  ov013  a1
 *   d_021B3AF5  0x021B3AF5  data  ov013  a1
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

extern u8 d_021B3AF0[];
extern u8 d_021B3AF5[];

int func_021B279C(u8 *o, Q *q)
{
    q->b5 = o[0xb];
    if (o[4] == 0xff) {
        if (o[6] == 0) {
            q->f8 = (q->b4 != 0) ? (1 << q->b4) : 1;
        }
        return d_021B3AF0[o[6]];
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
        return d_021B3AF5[o[6]];
    }
    return 12;
}
