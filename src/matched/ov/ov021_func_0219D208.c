/*
 * function: func_0219D208
 * address:  0x0219D208
 * packet:   pkt_ov021_0219D208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219C880  0x0219C880  thumb  ov021
 *   func_02050468  0x02050468  arm
 */

extern int func_0216D67C(int);
extern int *func_0216D520(int);
extern int func_0216D7A8(int, int);
extern unsigned short func_0216D598(int);
extern void func_0216E204(int, unsigned int);
extern int func_0219CBD4(int *, unsigned int, unsigned short *, unsigned short *);
extern void func_0219C880(int *, int, unsigned int, unsigned int);
extern void func_02050468(int, unsigned int, int);

void func_0219D208(int a, unsigned int id)
{
    int *ctx;
    int i;
    unsigned char *r;
    unsigned short h;
    unsigned short v[2];

    ctx = func_0216D520(func_0216D67C(a));
    r = (unsigned char *)ctx[8];
    func_0219CBD4(ctx, id, &v[1], &v[0]);
    if (v[1] != 0xFFFF && !(v[0] & 2)) {
        func_0216E204(a, id);
        return;
    }
    i = 0;
    h = func_0216D7A8(a, 0);
    if (h == 0xFFFF) {
        func_0216E204(a, id);
        return;
    }
    for (; i < 4; i++) {
        if (*(int *)r == 0) {
            break;
        }
    }
    if (i >= 4) {
        func_0216E204(a, id);
        return;
    }
    *(int *)r = a;
    *(unsigned short *)(r + 4) = h;
    *(unsigned short *)(r + 6) = func_0216D598(a);
    *(unsigned short *)(r + 8) = id;
    func_0216E204(a, id);
    i = 0;
    if (func_0216D7A8(a, 0) != 0xFFFF) {
        func_0219C880(ctx, a, *(unsigned short *)(r + 4), *(unsigned short *)(r + 6));
        func_02050468(ctx[1], *(unsigned short *)(r + 4), 1);
        *(int *)r = i;
    }
}
