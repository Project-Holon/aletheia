/*
 * function: func_0217FAE0
 * address:  0x0217FAE0
 * packet:   pkt_ov018_0217FAE0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * What closed it: the store through `out` is written in each arm of the
 * if/else (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md)
 * rather than once after it through a shared `v`; the single store made
 * `v` live across the join and coloured out/q/temp as r6/r4/r5 instead of
 * r5/r6/r4 (docs/notes/pkt_ov018_0217FAE0.c.txt has the earlier miss).
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

u16 *func_02159AE8(void *, int);
int func_0215A5DC(int);
int func_02012138(int);
int func_020120F4(int);
int func_0215841C(int);
int func_02012B58(int);

int func_0217FAE0(void *unused, int a)
{
    u16 *out;
    int t;
    int q;
    int v;

    out = func_02159AE8(unused, a);
    t = func_0215A5DC(a);
    func_02012138(t);
    q = func_020120F4(t);
    if (func_0215841C(q) == func_02012B58(q)) {
        *out = 0;
    } else {
        v = func_0215841C(q) - func_02012B58(q);
        if (v < 0) {
            v += 3;
        }
        *out = v;
    }
    return 0;
}
