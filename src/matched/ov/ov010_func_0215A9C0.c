/*
 * function: func_0215A9C0
 * address:  0x0215A9C0
 * packet:   pkt_ov010_0215A9C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02020D0C  0x02020D0C  thumb
 *   func_020202EC  0x020202EC  thumb
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_02191184  0x02191184  thumb  ov021
 */

typedef struct {
    char pad[0x20];
    int k[8];
} Q;

extern int func_02020D0C(int);
extern void func_020202EC(int, unsigned short *);
extern int func_02159190(int);
extern int func_0215A61C(int);
extern void func_02191164(void);
extern void func_02191184(int, int, int, int);

void func_0215A9C0(int a)
{
    unsigned short h = 0;
    int r = func_02020D0C(a);
    Q *q = (Q *)(*(char **)(r + 0x20) + 0x34);

    func_020202EC(a, &h);
    if (q->k[h] != 0) {
        if (func_02159190(1) != 0) {
            int t = func_0215A61C(r);
            func_02191164();
            func_02191184(t, 0, 0, q->k[h]);
        } else if (func_02159190(2) == 0) {
            func_02159190(3);
        }
    }
}
