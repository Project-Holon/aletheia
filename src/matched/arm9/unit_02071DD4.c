/*
 * unit:     yes
 * function: func_02071DD4
 * address:  0x02071DD4
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two functions of the 0x02071CDC constructor family, 296 bytes:
 * 0x02071DD4 (the s16-only variant, 216 B) and the UNLABELLED leaf at
 * 0x02071EAC (80 B), which saves no lr and so never gets a func_ label -
 * folding it in here is what turns the lead function's EXACT* into EXACT.
 *
 * ONE operand-order tell decides the lead function's f30/f34 pair. In f30
 * the `<<15` term is written LAST (`(m >> 8) + (f2c << 15)`); in f34 it is
 * written FIRST (`(f2e << 15) + (m >> 8)`). Spelled the other way round the
 * instruction sequence is identical but the allocator names r3/r4/r2 for
 * the three loads where the image names r2/r3/ip: 9 concrete bytes out,
 * unreachable by any local-binding or statement-splitting spelling (six
 * measured).
 *
 * The third leaf of the file, at 0x02071EFC (36 B, the pure-identity
 * version), is NOT in this unit: 1.1p1 -O4,p hoists `mov r1, #0` ahead of
 * `mov r2, #0x1000` where the image materialises 0x1000 first, a stable
 * 3-instruction scheduling swap that survived eight store-order and
 * constant-binding spellings. See docs/notes/func_02071EFC.c.txt.
 *
 * symbols:
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;
typedef int            s32;
typedef long long      s64;

struct SRC {
    u8  pad_00[0x18];
    s32 f18;
    s32 f1c;
    s16 f20;
    s16 f22;
    u8  pad_24[8];
    u16 f2c;
    u16 f2e;
};

struct DST {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

extern void func_0207C930(u32 numer, u32 denom);
extern u32 func_0207C86C(void);

void func_02071DD4(struct DST *d, struct SRC *s)
{
    s32 e12, f12;
    s32 t;
    s32 ne, nf, a, b;
    s64 m;

    e12 = (s32)((u32)s->f2c << 12);
    f12 = (s32)((u32)s->f2e << 12);

    func_0207C930(f12, e12);

    d->f00 = s->f22;
    d->f14 = s->f22;

    t = func_0207C86C();
    d->f04 = (s->f20 * t) >> 12;

    func_0207C930(e12, f12);

    ne = 0 - (s32)s->f2c;
    nf = 0 - (s32)s->f2e;

    m = (s64)s->f22 * (ne << 11) - (s64)s->f20 * (nf << 11);
    d->f30 = (s32)(m >> 8) + ((s32)s->f2c << 15);

    m = (s64)s->f20 * (ne << 11) + (s64)s->f22 * (nf << 11);
    d->f34 = ((s32)s->f2e << 15) + (s32)(m >> 8);

    t = func_0207C86C();
    d->f10 = ((0 - (s32)s->f20) * t) >> 12;
}

void func_02071EAC(struct DST *d, struct SRC *s)
{
    s32 a, b;

    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;

    a = 0x1000 - s->f18;
    d->f30 = (a * (s32)s->f2c) << 3;

    b = 0x1000 - s->f1c;
    d->f34 = (b * (s32)s->f2e) << 3;

    d->f10 = 0;
}

