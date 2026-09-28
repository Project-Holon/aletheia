/*
 * function: func_0215A864
 * address:  0x0215A864
 * packet:   pkt_ov010_0215A864
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  byte-correct, 188/188. Three bl sites (0x02190AC4 x2, 0x02190AEC) are
 * unresolved: in ov021 both are unlabelled leaf accessors (.word runs, no
 * func_ label), in ov009 they are interior to ARM code. evidence class:
 * label / sole-ref/code refused (no traced function start).
 *
 * symbols:
 *   func_0215A5FC  0x0215A5FC  thumb  ov010
 *   func_02190ACC  0x02190ACC  thumb  ov021
 *   func_02190AC4  0x02190AC4  thumb  ov021
 *   func_02190AEC  0x02190AEC  thumb  ov021
 *   func_02190B08  0x02190B08  thumb  ov021
 *   func_02190988  0x02190988  thumb  ov021
 *   func_0215A9C0  0x0215A9C0  thumb  ov010
 *   d_02171140     0x02171140  data  ov010  a4
 */

typedef struct {
    int a0;
    int a1;
    unsigned short a2;
    unsigned short f1 : 3;
    unsigned short f2 : 4;
    int c3;
    unsigned short h8;
    unsigned short h9;
    int d5;
    int d6;
    int d7;
} L32;

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
    int pad8;
    int padc;
    int pad10;
    int pad14;
    int j;
    int k;
} Q;

extern int func_0215A5FC(void *);
extern int func_02190ACC(int, int, int, int);
extern unsigned func_02190AC4(int);
extern int func_02190AEC(int, int, int, int);
extern void func_02190B08(void *, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
extern int func_02190988(int, void *, int, void *, void *, int, int, int);
extern void func_0215A9C0(void);
extern L32 d_02171140;

void func_0215A864(int *p)
{
    int x;
    int y;
    Q *q = (Q *)(*(char **)((char *)p + 0x20) + 0x34);
    L32 l = d_02171140;
    int t = func_0215A5FC(p);
    unsigned m;
    unsigned n;

    x = func_02190ACC(t, q->j, l.h8, l.f1);
    if (q->e == 1) {
        q->a = q->a - (unsigned short)x;
    }
    n = func_02190AC4(q->j);
    m = 6;
    if (n <= 6) {
        m = n;
    }
    y = func_02190AEC(m, l.h9, l.f2, n > 6);
    func_02190B08(&l, func_02190AC4(q->j), q->a, q->b, x, y);
    q->k = func_02190988(t, &l, q->j, (void *)func_0215A9C0, p, 0, q->c, q->d);
}
