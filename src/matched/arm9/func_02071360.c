/*
 * function: NNSi_G3dTexMtxScale4x4
 * address:  0x02071360
 * packet:   pkt_02071360
 * region:   arm9
 * isa:      arm
 * status:   EXACT
 *
 * The 68-byte member of the cluster_02071360 constructor family: copies
 * the source's f18/f1c straight into the destination's diagonal slots
 * f00/f14, zeroes f04/f10/f30 and derives f34 from f1c and the angle
 * halfword f2e.
 *
 * The f34 term is the whole difficulty.  The image forms it as
 * `lsl r1, r2, #1; rsb r1, r1, #0; add r1, r1, #0x2000; mul; lsl #3`,
 * i.e. -(2*f1c) + 0x2000 with the constant added LAST.  Every factored
 * spelling folds it: `(0x1000 - f1c) * f2e * 16` is 60 bytes (rsb #0x1000,
 * lsl #4), `(0x2000 - f1c * 2) * f2e * 8` is 64 (rsb #0x2000).  Only the
 * doubled operand written out twice, `0x1000 - f1c + 0x1000 - f1c` (a
 * macro argument expanded twice, by the look of it), keeps the negate and
 * the separate add.
 *
 * Front end: NOT pinned.  EXACT under both dsi/1.1p1 and ../2.0/sp2 with
 * the same C (the zero is materialised early, at +0x04, in the image, so
 * there is no "kept constants" tell for 2.0 to bite on); filed under the
 * project default.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G3dTexMtxScale4x4.c \
 *       --func NNSi_G3dTexMtxScale4x4 --addr 0x02071360 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef int            s32;

struct SRC {
    u8  pad_00[0x18];
    s32 f18;
    s32 f1c;
    u8  pad_20[0xe];
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

void NNSi_G3dTexMtxScale4x4(struct DST *d, struct SRC *s)
{
    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;
    d->f30 = 0;
    d->f34 = (0x1000 - s->f1c + 0x1000 - s->f1c) * s->f2e * 8;
    d->f10 = 0;
}
