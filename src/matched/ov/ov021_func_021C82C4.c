/*
 * function: func_021C82C4
 * address:  0x021C82C4
 * packet:   pkt_ov021_021C82C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback armed by func_021C8268 (0x30-byte context). Case 8 is an
 * if/else with func_02012374 written in both arms (its `beq` over `b`);
 * spelled as `if (v == 0) v = ...; func_02012374(a, v);` the call merges
 * with case 3's and every `(*st)++` moves off case 0's copy.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218F818  0x0218F818  thumb  ov021
 *   func_0218F848  0x0218F848  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218F900  0x0218F900  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_021BEA30  0x021BEA30  thumb  ov021
 *   func_021854CC  0x021854CC  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_02043658  0x02043658  arm
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02043534  0x02043534  arm
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_021C85CC  0x021C85CC  thumb  ov021
 *   func_021BC578  0x021BC578  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct Buf24 {
    u32 w[6];
} Buf24;

typedef struct Param {
    u32 pad0[3];
    VecFx32 pos;
    u32 f18;
    u32 f1c;
    u32 f20;
    u16 h24;
    u16 h26;
    u32 f28;
    u16 h2c;
    u16 pad2e;
    Buf24 buf;
} Param;

typedef struct Ctx {
    void *w0;
    u32 f04;
    u32 f08;
    u8 f0c[0x28 - 0x0c];
    u32 f28;
    u32 f2c;
} Ctx;

extern void *func_0201210C(void *p);
extern u32 func_02188C58(void *p);
extern void *func_02189A00(u8 *p);
extern u32 func_02188C5C(u8 *p);
extern void func_0218F1AC(u32 a, u32 b);
extern u32 func_0218EC5C(u32 a);
extern void func_0218F0A8(u32 a);
extern int func_0218F0E8(u32 a);
extern void func_021BB260(u32 a, u32 b);
extern void func_0218EC54(u32 a);
extern void func_0218F818(u32 a);
extern void func_0218F848(u32 a);
extern void *func_02188CB4(u8 *p);
extern void func_021A3038(u8 *a, VecFx32 *out);
extern void func_0218F900(u32 h, Param *p, int n);
extern int func_0218FE50(u32 a);
extern void *func_02188C7C(u8 *p);
extern void func_0216D9A0(void *map);
extern u32 func_021C1CB0(u32 a, char *b, u8 c);
extern void func_02012374(u32 a, u32 b);
extern void func_0216D9E4(void *c);
extern void *func_021A3074(u8 *p);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void func_0218F878(u32 a);
extern u32 func_021BEA30(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021854CC(void *p, u32 u, u16 u2, void *src, u16 h);
extern u32 func_02188D20(u8 *p);
extern void func_021BC5BC(u32 a);
extern void *func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(void *);
extern void func_02188DB0(u8 *a);
extern void func_0216D5E0(u32 o, u32 b);
extern u32 func_020122C0(void *a, u32 b, void *c, u32 d);
extern void func_021C85CC(void);
extern void func_021BC578(u32 a, u32 b);
extern void func_0218F9C4(u32 h, Buf24 *src, u16 v);
extern void func_0218EC30(u32 a, u32 b);
extern void func_0218F05C(u32 a);

int func_021C82C4(u32 a, int *st, Ctx *c)
{
    void *sys;
    u32 h;
    void *y;
    u32 x;
    u32 v;
    void *o;
    void *t;
    Param p1;
    Param p2;
    VecFx32 v1;
    VecFx32 v2;
    Buf24 buf;

    sys = func_0201210C(c->w0);
    h = func_02188C58(sys);
    y = func_02189A00(sys);
    x = func_02188C5C(sys);
    switch (*st) {
    case 0:
        func_0218F1AC(h, 0);
        c->f04 = func_0218EC5C(h);
        func_0218F0A8(h);
        (*st)++;
        break;
    case 1:
        if (c->f04 != 0 && func_0218F0E8(h) != 0)
            break;
        func_021BB260(x, 0);
        func_0218EC54(h);
        func_0218F818(h);
        func_021A3038(func_02188CB4(sys), &v1);
        p1.h24 = 0x25d8;
        p1.h26 = 0;
        p1.f28 = 0xed000;
        p1.f18 = 0;
        p1.f1c = 0x4000;
        p1.f20 = 0;
        p1.pos = v1;
        p1.h2c = 0xe38;
        p1.buf.w[0] = 1;
        p1.buf.w[1] = 1;
        p1.buf.w[2] = 0;
        p1.buf.w[3] = 1;
        p1.buf.w[4] = 1;
        p1.buf.w[5] = 1;
        func_0218F900(h, &p1, 10);
        (*st)++;
    case 2:
        if (func_0218FE50(h) != 0)
            break;
        func_0216D9A0(func_02188C7C(sys));
        v = func_021C1CB0((u32)c->w0, y, c->f28);
        if (v != 0)
            func_02012374(a, v);
        (*st)++;
        break;
    case 3:
        func_0216D9E4(func_02188C7C(sys));
        func_0216DAC8(func_021A3074(func_02188CB4(sys)), 1);
        func_0218F878(h);
        func_02012374(a, func_021BEA30((u32)c->w0, (u32)sys, 0, 0));
        (*st)++;
        break;
    case 4:
        func_02012374(a, func_021854CC(c->w0, (u32)sys, c->f08, c->f0c, 1));
        (*st)++;
        break;
    case 5:
        func_021BC5BC(func_02188D20(sys));
        c->f04 = func_0218EC5C(h);
        func_0218F0A8(h);
        (*st)++;
        break;
    case 6:
        if (c->f04 != 0 && func_0218F0E8(h) != 0)
            break;
        func_021BB260(x, 0);
        func_0218EC54(h);
        func_0218F848(h);
        func_0218F1AC(h, 0);
        func_021A3038(func_02188CB4(sys), &v2);
        p2.h24 = 0x25d8;
        p2.h26 = 0;
        p2.f28 = 0xed000;
        p2.f18 = 0;
        p2.f1c = 0x4000;
        p2.f20 = 0;
        p2.pos = v2;
        p2.h2c = 0xe38;
        p2.buf.w[0] = 1;
        p2.buf.w[1] = 1;
        p2.buf.w[2] = 0;
        p2.buf.w[3] = 1;
        p2.buf.w[4] = 1;
        p2.buf.w[5] = 1;
        func_0218F900(h, &p2, 1);
        (*st)++;
    case 7:
        if (func_0218FE50(h) != 0)
            break;
        func_0216DAC8(func_021A3074(func_02188CB4(sys)), 1);
        t = func_02043658();
        func_02188DA0();
        func_02043534(t);
        func_02188DB0(sys);
        (*st)++;
        break;
    case 8:
        func_0216D9A0(func_02188C7C(sys));
        v = func_021C1CB0((u32)c->w0, y, c->f2c);
        if (v != 0) {
            func_02012374(a, v);
        } else {
            o = func_021A3074(func_02188CB4(sys));
            func_0216DAC8(o, 0);
            func_0216D5E0((u32)o, 1);
            func_02012374(a, func_020122C0(c->w0, a, func_021C85CC, 0));
        }
        (*st)++;
        break;
    case 9:
        func_0216D9E4(func_02188C7C(sys));
        func_021BC578(func_02188D20(sys), c->f08);
        buf.w[0] = 1;
        buf.w[1] = 1;
        buf.w[2] = 0;
        buf.w[3] = 1;
        buf.w[4] = 1;
        buf.w[5] = 1;
        func_0218F9C4(h, &buf, 10);
        (*st)++;
    case 10:
        if (func_0218FE50(h) != 0)
            break;
        if (c->f04 != 0)
            func_0218EC30(h, c->f04);
        func_0218F05C(h);
        func_021BB260(x, 1);
        func_0218F878(h);
        func_0218F1AC(h, 1);
        return 1;
    }
    return 0;
}
