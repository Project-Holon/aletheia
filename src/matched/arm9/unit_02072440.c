/*
 * unit:     yes
 * function: NNSi_G3dTexMtxRot_Max
 * address:  0x02072440
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two functions of the 0x02071CDC constructor family, 228 bytes: the
 * all-s16 variant at 0x02072440 (164 B, no smull anywhere - every term is
 * a plain `ldrsh` times an `ldrh`) and the UNLABELLED leaf at 0x020724E4
 * (64 B), which saves no lr and so never gets a func_ label. Folding the
 * follower in here is what turns the lead function's EXACT* into EXACT.
 *
 * The third leaf of the file, the pure-identity writer at 0x02072524
 * (36 B, byte-identical to the one at 0x02071EFC), is NOT in this unit:
 * 1.1p1 -O4,p hoists `mov r1, #0` ahead of `mov r2, #0x1000` where the
 * image materialises 0x1000 first. Nine store-order and constant-binding
 * spellings all give the same 3-instruction swap; see
 * docs/notes/NNSi_G3dTexMtxIdentity2.c.txt.
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

void NNSi_G3dTexMtxRot_Max(struct DST *d, struct SRC *s)
{
    s32 e12, f12, t;

    e12 = (s32)((u32)s->f2c << 12);
    f12 = (s32)((u32)s->f2e << 12);

    func_0207C930(f12, e12);

    d->f00 = s->f22;
    d->f14 = s->f22;

    t = func_0207C86C();
    d->f04 = (s->f20 * t) >> 12;

    func_0207C930(e12, f12);

    d->f30 = ((s32)s->f2c * s->f20) << 4;
    d->f34 = ((0 - (s32)s->f2e) * (s->f22 - 0x1000)) << 4;

    t = func_0207C86C();
    d->f10 = ((0 - (s32)s->f20) * t) >> 12;
}

void NNSi_G3dTexMtxScale_Max(struct DST *d, struct SRC *s)
{
    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;
    d->f30 = 0;
    d->f34 = ((0 - (s32)s->f2e) * (s->f1c - 0x1000)) << 4;
    d->f10 = 0;
}
