/*
 * function: sub_0204B908
 * address:  0x0204B908
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *    sub_0204D478   0x0204D478  arm
 *
 * Forward the sub-object embedded at +0x68 of the 0x0204Bxxx object to
 * sub_0204D478, as a pool-word tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Byte-correct, capped at MATCH: 0x0204D478 has zero branch witnesses
 * anywhere in the image outside this ABS32 pool word.  It unsticks when
 * 0x0204D478 is itself decompiled to EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204B908.c  *       --func sub_0204B908 --addr 0x0204B908 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8 unk_00[1];
};

struct Obj {
    u8         pad_00[0x68];
    struct Sub unk_68;
};

extern void sub_0204D478(struct Sub *s);

void sub_0204B908(struct Obj *p)
{
    sub_0204D478(&p->unk_68);
}
