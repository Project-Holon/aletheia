/*
 * function: NNSi_G3dTexMtxTrans
 * address:  0x02071180
 * packet:   pkt_02071104
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled leaf of the 0x02071104 family (saves no lr): the unit-scale
 * translate-only constructor. f00/f14 take the 0x1000 unit scale, f04/f10
 * are zero, and f30/f34 are the plain `-(f24 * f2c) << 4` form.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell: the image materialises
 * the zero LATE, `mov ip, #0` (`00 c0 a0 e3`) at 0x0207118C, AFTER the
 * `str r2, [r0]` at 0x02071184, so the f00 and f04 stores stay separate.
 * 1.1p1 -O4,p hoists the zero above the f00 store and merges the pair
 * into one `stm r0, {r2, ip}`, giving 68 bytes against the image 72 with
 * the whole body shifted by four (57 concrete bytes out). Under the pin
 * the same C is 72 bytes, 0 mismatches. Same stall as the 0x02072320
 * near miss recorded in docs/notes/pkt_02071DD4.c.txt.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef int            s32;

struct SRC {
    u8  pad_00[0x18];
    s32 f18;
    s32 f1c;
    s16 f20;
    s16 f22;
    s32 f24;
    s32 f28;
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

void NNSi_G3dTexMtxTrans(struct DST *d, struct SRC *s)
{
    s32 t;

    d->f00 = 0x1000;
    d->f14 = 0x1000;
    d->f04 = 0;

    t = s->f24 * (s32)s->f2c;
    d->f30 = (0 - t) << 4;

    t = s->f28 * (s32)s->f2e;
    d->f34 = t << 4;

    d->f10 = 0;
}
