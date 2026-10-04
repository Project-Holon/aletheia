/*
 * function: func_021A7258
 * address:  0x021A7258
 * packet:   pkt_ov021_021A7258
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Switches an object's model between the placed mode (0: position copied
 * in and rotation set from whole-unit sixteenths) and the attached mode,
 * then applies the shared animation settings and records the new mode.
 * d_021DDF38 is one static record: two callbacks, then at +8 the
 * parameter block func_0216E0AC takes, whose u16 at +0xA is refreshed
 * here (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-
 * by-the-load-reach.md).
 *
 * symbols:
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DC4C  0x0216DC4C  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021A368C  0x021A368C  thumb  ov021
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021BB3B8  0x021BB3B8  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218E160  0x0218E160  thumb  ov021
 *   func_021A3680  0x021A3680  thumb  ov021
 *   func_021A36A4  0x021A36A4  thumb  ov021
 *   func_021BB3AC  0x021BB3AC  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0219F0B0  0x0219F0B0  thumb  ov021
 *   d_021DDF38     0x021DDF38  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct ModelParam {
    u8 f0;
    u8 f1;
    u16 f2;
} ModelParam;

typedef struct Record {
    void *cb[2];
    ModelParam param;
} Record;

typedef struct Holder {
    int mode;
    void *f04;
} Holder;

extern Record d_021DDF38;

extern u32 func_02188C5C(u8 *p);
extern void *func_02188C58(void *o);
struct Actor;
extern void *func_021A3074(u8 *p);
extern int func_0216DC4C(void *m);
extern void func_0216D4B4(char *p);
extern u16 func_0216D598(void *m);
extern void func_021A368C(u8 *p);
extern void func_0216E0AC(void *a0, void *a1);
extern void func_0216E084(void *m, s16 x, s16 y, s16 z, u16 e);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_021A3044(void *p, const VecFx32 *v);
extern void func_021BB3B8(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0218EC60(void *y);
extern void func_0218E160(void *y);
extern void func_021A3680(void *p, VecFx32 *v);
extern u32 func_021A36A4(void *p);
extern void func_021BB3AC(void *x, u32 v);
extern void func_0218F05C(unsigned char *a);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D600(void *m, u16 e);
extern void func_0219F0B0(u32 a, u32 b, u32 c);

void func_021A7258(void *o, Holder *h, int mode, VecFx32 *pos, u16 e, u16 f, u16 g)
{
    void *x;
    void *y;
    void *m;
    VecFx32 v;

    x = (void *)func_02188C5C(o);
    y = func_02188C58(o);
    if (h->mode == mode) {
        return;
    }
    m = func_021A3074(h->f04);
    if (func_0216DC4C(m) != 0) {
        func_0216D4B4(m);
    }
    if (mode == 0) {
        v = *pos;
        d_021DDF38.param.f2 = func_0216D598(m);
        func_021A368C(h->f04);
        func_0216E0AC(m, &d_021DDF38.param);
        func_0216E084(m, (v.x >> 12) / 16, (v.y >> 12) / 16, (v.z >> 12) / 16, e);
        func_0216D88C(m, &v);
        func_021A3044(h->f04, &v);
        func_021BB3B8(x);
        func_0218E13C(y, 0);
        func_0218EC60(y);
        func_0218E160(y);
    } else {
        func_021A3680(h->f04, pos);
        func_021BB3AC(x, func_021A36A4(h->f04));
        func_0218F05C(y);
    }
    func_0216D5E0((int)m, e);
    func_0216D600(m, e);
    func_0219F0B0((u32)m, f, g);
    h->mode = mode;
}
