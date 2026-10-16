/*
 * function: NNSi_G3dTexMtxIdentity_Max
 * address:  0x02072524
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The identity member of the 0x02071CDC constructor family, an unlabelled
 * leaf (saves no lr). The same 36-byte body appears twice in this file, at
 * 0x02072524 and 0x02072524.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md),
 * the same measurement already taken for src/matched/NNSi_G3dTexMtxIdentity.c: the
 * image materialises the unit scale FIRST, `mov r2, #0x1000`
 * (`01 2a a0 e3`) at 0x02072524 followed by `str r2, [r0]`, and only then
 * `mov r1, #0` (`00 10 a0 e3`) at 0x0207252C. dsi/1.1p1 -O4,p schedules the
 * zero first for the same 36 bytes, 9 concrete bytes out, under all ten
 * spellings measured in docs/notes/NNSi_G3dTexMtxIdentity_Max.c.txt (store order,
 * constants bound to locals, zero derived from the live 0x1000, re-read of
 * a stored field). Under the pin the same C is 36 bytes, 0 mismatches.
 */
typedef unsigned char u8;
typedef int           s32;

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

void NNSi_G3dTexMtxIdentity_Max(struct DST *d)
{
    d->f00 = 0x1000;
    d->f04 = 0;
    d->f10 = 0;
    d->f14 = 0x1000;
    d->f30 = 0;
    d->f34 = 0;
}
