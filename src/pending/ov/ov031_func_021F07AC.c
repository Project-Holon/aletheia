/*
 * function: func_021F07AC
 * address: 0x021F07AC
 * packet: pkt_ov031_021F07AC
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * residual: 500/500 bytes, 28 concrete mismatches, all27 sites resolved.
 * W76 final retry: eight runs. Inline paletteFlag return branch reduces29
 * to28, retained; long c, enum helper/c, long offset and wide k unchanged;
 * proven-range u16 offset expands504/DIFF459. Three later nonshrinks stop.
 * checks: 1 own 1C724(7), 2DC60(5), 413B0(6), 2DCC4(2), other own/shared
 * signatures re-read; corrected wide413B0 index and unsigned2DCC4 index
 * unchanged28; preserve narrow1C724 arguments for observed truncation;
 * 2 own0054/0680/09A0/0AA0 prove layout/byte k, no full twin;
 * 3 u32 k unchanged28 and existing const e retained; u8 k best restored;
 * 4 enum-return/flag, masked-width and shared register idioms read;
 * 5 recent directory/neighbours reviewed, pair/frame offsets agree.
 * Keep per-arm b[k] store, case0 aftercase5, w40 local before firstprint.
 * Both old types-permuter300 searches consumed, not repeated.
 * Next: inline palette-copy binding with halfword offset before flag branch.
 * 2026-10-05 (wave P6 U7): size is 500 B (lane list said 342). Residue 28 B is one
 * register swap: original k=r6, flag c=r5 (c and k*4 share r5); build k=r5, c/k*4=r6.
 * Tried: c as inline 'c = 0; if (e[0x20]) c = 2;' (29 B), no off local (39 B), k as int
 * (29 B), c declared first (29 B), each of opt_lifetimes/opt_propagation/opt_common_subs/
 * opt_dead_assignments/scheduling/peephole off (28, 364, 424, 364, 28, 28). No twin in other
 * overlays (ov029 021F07AC is a different function). Callee arities all agree with callers.
 * symbols:
 *   func_0204162C  0x0204162C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0202DCC4  0x0202DCC4  thumb
 *   func_0202DC9C  0x0202DC9C  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0202DC60  0x0202DC60  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   d_021F1040     0x021F1040  data  ov031  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct { int a, b; } Pair;

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

struct Obj {
    u32 w0;
    char pad0[0x40 - 4];
    u32 w40;
    u32 w44;
    u32 w48;
    u32 a[3];
    u32 b[3];
    struct Slot s[3];
    u32 w7c;
};

extern u16 *func_0204162C(u8 bg);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(int);
extern u32 func_0202DCC4(u32 o, u32 i);
extern void func_0202DC9C(u32 o, int i, u32 a1);
extern u32 func_02045770(u32 a);
extern void func_02043B5C(u32 v, u32 a);
extern void func_02045334(u32 a);
extern void func_0202DC60(u32 a, u32 b, const void *c, u32 d, void *e);
extern void *func_02045EC0(u32 h, u32 idx);
extern void func_02045374(u32 a);
extern int func_02045730(u32 a);
extern void func_0201C724(u32 print, u32 bmp, s16 x, s16 y, void *str, u32 font, u32 color);
extern void func_02045808(void *p);
extern void *func_020457B0(u32 size, u32 heap);
extern void func_02045924(void *dst, const void *src);
extern const Pair d_021F1040;
static inline int paletteFlag(const u8 *e)
{
    if (e[0x20] != 0) return 2;
    return 0;
}

void func_021F07AC(struct Obj *p, const u8 *e, u8 k)
{
    u16 *pal;
    int c;
    Pair t;
    void *x;
    void *buf;
    u32 q;
    int off;

    pal = func_0204162C(6);
    off = k * 0xE0;
    c = paletteFlag(e);
    func_02082D44(pal, pal + off, 0x1C0);
    func_020413B0(6, 0, k * 7, 0x20, 7, c);
    func_02041B6C(6);
    t = d_021F1040;
    if (p->b[k] == 0) {
        if (func_0202DCC4(p->w7c, k) == 1)
            func_0202DC9C(p->w7c, k, 1);
    } else if (p->b[k] == 1) {
        func_02043B5C(func_02045770(p->a[k]), 0);
        func_02045334(p->a[k]);
    }
    if (e[0x21] == 0) {
        func_0202DC60(p->w7c, p->a[k], e + 0x10, k, &t);
        p->b[k] = 0;
    } else {
        switch (e[0x21]) {
        case 1:
            x = func_02045EC0(p->w48, 6);
            break;
        case 2:
            x = func_02045EC0(p->w48, 0);
            break;
        case 3:
            x = func_02045EC0(p->w48, 1);
            break;
        case 4:
            x = func_02045EC0(p->w48, 2);
            break;
        case 5:
            x = func_02045EC0(p->w48, 3);
            break;
        case 0:
            return;
        default:
            return;
        }
        func_02045374(p->a[k]);
        func_02041B6C(func_02045730(p->a[k]));
        q = p->w40;
        func_0201C724(q, func_02045770(p->s[k].h), 0, t.b, x, p->w44, 0x440);
        p->s[k].f = 1;
        func_02045808(x);
        p->b[k] = 1;
    }
    buf = func_020457B0(8, 0x15);
    func_02045924(buf, e);
    func_0201C724(p->w40, func_02045770(p->a[k]), 0, 0, buf, p->w44, 0x440);
    func_02045808(buf);
    if (e[0x22] != 0) {
        buf = func_02045EC0(p->w48, (e[0x22] == 1) ? 4 : 5);
        func_0201C724(p->w40, func_02045770(p->a[k]), 0x74, 0, buf, p->w44, 0x440);
        func_02045808(buf);
    }
}
