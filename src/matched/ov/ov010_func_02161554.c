/*
 * function: func_02161554
 * address:  0x02161554
 * packet:   pkt_ov010_02161554
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0201B2B0  0x0201B2B0  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[0x18];
    u32 **f18;          /* 0x18 */
    u8 pad1c[0x68 - 0x1C];
    u32 f68;            /* 0x68 */
} Ctx;

typedef struct Src {
    u8 pad00[0x3C];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
} Src;

typedef struct Rec {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u16 f08;            /* 0x08 */
    u8 f0a;             /* 0x0A */
    u8 f0b;             /* 0x0B */
    u32 f0c;            /* 0x0C */
    u32 f10;            /* 0x10 */
} Rec;

extern const char d_02172978[];

extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *a, u32 b);
extern u16 *func_020127A4(void *sv);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

Rec *func_02161554(Ctx *c, int a1, int mode, const Src *src)
{
    Rec *r;
    void *sv;
    void *t;
    void *k;
    u32 out;
    u32 res;
    u8 x;

    sv = func_020120F4((const struct Ctx *)(*c->f18));
    r = 0;
    if (mode == 0) {
        t = func_02012934(sv);
        if (src->f40 == 8) {
            c->f68 = 3;
            k = func_0201AB28(t, src->f3c);
            x = func_02012984(sv);
            res = func_0201B2B0(t, k, 3, src->f44, x, &out, 4);
        } else {
            c->f68 = 4;
            k = func_0201AB28(t, src->f3c);
            res = func_0201B2B0(t, k, 0, *func_020127A4(sv), func_02012984(sv), &out, 4);
        }
        r = func_02030734(4, 0x14, 0, d_02172978, 0x868);
        r->f00 = sv;
        r->f04 = t;
        r->f08 = res;
        r->f0a = src->f3c;
        r->f0b = out;
        r->f0c = 1;
        r->f10 = 1;
    }
    return r;
}
