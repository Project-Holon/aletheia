/*
 * function: func_021F44D8
 * address:  0x021F44D8
 * packet:   pkt_ov048_021F44D8
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F44B8  0x021F44B8  thumb  ov048
 *   func_021F4590  0x021F4590  thumb  ov048
 *   func_021F45F0  0x021F45F0  thumb  ov048
 *   func_02188C70  0x02188C70  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 h[4];
    u8  b[4];
} Slots;

extern void func_021F44B8(Slots *);
extern void func_021F4590(int *, Slots *);
extern void func_021F45F0(int *a, void *b);
extern int func_02188C70(int *p, int b);

void func_021F44D8(int *p, Slots *q)
{
    Slots s2;
    Slots s1;
    int n, j, k;

    n = 0;
    func_021F44B8(q);
    func_021F4590(p, &s2);
    func_021F45F0(p, &s1);
    for (j = 0; j < 4; j++) {
        if (s1.h[j] == 0x1AB)
            break;
        if (s1.b[j] == 0xFFFF)
            break;
        if (n >= 2)
            break;
        q->h[n] = s1.h[j];
        q->b[n] = s1.b[j];
        n++;
    }
    for (j = 0; j < 4; j++) {
        if (s2.h[j] == 0x1AB)
            break;
        if (s2.b[j] == 0xFFFF)
            break;
        if (n >= 2)
            break;
        q->h[n] = s2.h[j];
        q->b[n] = s2.b[j];
        n++;
    }
    if (n == 0) {
        int *r = (int *)p[7];

        q->h[0] = r[0x64 / 4];
        q->h[1] = r[0x68 / 4];
        q->h[2] = r[0x6c / 4];
        q->h[3] = r[0x70 / 4];
    }
    for (k = 0; k < 4; k++)
        q->b[k] = func_02188C70((int *)p[1], q->h[k]);
}
