/*
 * function: func_021C70DC
 * address:  0x021C70DC
 * packet:   pkt_ov021_021C70DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   _ffixu         0x0209C4C8  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _fdiv          0x0209CE10  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef float f32;

typedef struct {
    u32 w0;
    void *obj;
    u32 mode;
    u16 hc;
    u16 cnt;
    u16 max;
    u16 pad;
    u32 from;
    u32 to;
} Work;

extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u16 v);

void func_021C70DC(Work *w)
{
    u16 max;
    void *o;
    f32 t;
    f32 s;
    u16 v;
    u32 save;

    max = w->max;
    o = w->obj;
    w->cnt++;
    if (w->cnt > max)
        return;
    t = (f32)w->cnt / (f32)max;
    s = (3.0f + -2.0f * t) * (t * t);
    v = (u16)((1.0f - s) * (f32)w->from + s * (f32)w->to);
    save = func_0218E138(o);
    func_0218E13C(o, 0);
    switch (w->mode) {
    case 0:
        func_0218ED48(o, v);
        break;
    case 1:
        func_0218ED34(o, v);
        break;
    }
    func_0218E13C(o, save);
}
