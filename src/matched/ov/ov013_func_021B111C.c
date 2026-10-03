/*
 * function: func_021B111C
 * address:  0x021B111C
 * packet:   pkt_ov013_021B111C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The three sample converters are passed q->fC as a fourth argument: the
 * original keeps the format in r3 across the argument set-up of all three
 * calls, which only a live fourth argument reproduces (a plain local or
 * the bare field lands in r0).
 *
 * symbols:
 *   func_021B1488  0x021B1488  arm  ov013
 *   func_021B1498  0x021B1498  arm  ov013
 *   func_021B14A8  0x021B14A8  arm  ov013
 *   func_021B043C  0x021B043C  arm  ov013
 *   func_021B1634  0x021B1634  arm  ov013
 *   func_021B16B4  0x021B16B4  arm  ov013
 *   func_021B14F8  0x021B14F8  arm  ov013
 *   func_021B1810  0x021B1810  arm  ov013
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Voice {
    u32 f0;
    u32 f4;
    u32 f8;
    int fC;
    u8 f10;
    u8 f11;
    u8 pad12[2];
    u32 f14;
    u32 f18;
    u8 buf[0x474 - 0x1c];
    void *f474;
} Voice;

extern Voice *func_021B1488(void);
struct AdpcmState;
extern int func_021B1498(unsigned int i);
extern Voice *func_021B14A8(u8 id);
extern void func_021B043C(struct AdpcmState *hdr, void *dst, int n, int mode);
extern void func_021B1634(void *src, void *dst, u32 n, int fmt);
extern void func_021B16B4(void *src, void *dst, u32 n, int fmt);
extern void func_021B14F8(Voice *v);
extern int func_021B1810(Voice *v, u32 idx);
extern void func_021B2FE4(void *p);
extern int func_02087988(void);
extern void func_0208799C(int);

int func_021B111C(void)
{
    Voice *v;
    int i;
    int n;
    u8 id;
    int irq;
    Voice *q;
    int fmt;

    v = func_021B1488();
    if (v == 0)
        return 0;

    irq = func_02087988();
    id = v->f11;
    n = func_021B1498(id);
    for (i = 0; i < n; i++) {
        q = func_021B14A8(id);
        fmt = q->fC;
        if (fmt >= 2)
            func_021B043C(q->f474, q->buf, q->f14, fmt);
        else if (fmt == 1)
            func_021B1634(q->f474, q->buf, q->f14, fmt);
        else
            func_021B16B4(q->f474, q->buf, q->f14, fmt);
        q->f474 = q->buf;
        func_021B14F8(q);
        if (func_021B1810(q, q->f11) < 0)
            func_021B2FE4(q);
    }
    func_0208799C(irq);
    return n;
}
