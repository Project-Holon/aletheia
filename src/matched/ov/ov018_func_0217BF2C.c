/*
 * function: func_0217BF2C
 * address:  0x0217BF2C
 * packet:   pkt_ov018_0217BF2C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_02182B6C     0x02182B6C  data   a4
 */

typedef unsigned short u16;

typedef struct { u16 a, b; int c; } Sub;

typedef struct {
    u16 f00, f02;
    u16 pad04[3];
    u16 f0a;
    u16 pad0c[8];
    Sub s;
} Buf;

extern void *func_02188C7C(unsigned char *p);
typedef unsigned char  u8;
extern u16 func_02188C9C(u8 *p);
extern void func_0216CE60(void *, Buf *, int);
extern const Buf d_02182B6C;

void func_0217BF2C(int a, u16 b, u16 c, int d, u16 e, u16 f, u16 g)
{
    Buf buf;
    void *h;
    int k;
    Sub *q;

    h = func_02188C7C((void *)a);
    k = func_02188C9C((u8 *)a);
    buf = d_02182B6C;
    buf.f00 = g;
    buf.f02 = e;
    buf.f0a = f;
    q = &buf.s;
    q->a = b;
    q->b = c;
    q->c = d;
    func_0216CE60(h, &buf, k);
}
