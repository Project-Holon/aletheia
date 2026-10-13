/*
 * function: CLACT_SetActorAnimFrame
 * address:  0x0204B8C4
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *    CLACT_SetAnimFrame   0x0204D3A0  arm
 *
 * Forward the sub-object embedded at +0x68 of the 0x0204Bxxx object to
 * CLACT_SetAnimFrame.  A pool word and a `bx ip`, never a displacement branch,
 * because each function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Byte-correct, capped at MATCH: 0x0204D3A0 has zero branch witnesses
 * anywhere in the image outside this ABS32 pool word, so the tail-call
 * target cannot be attested.  It unsticks when 0x0204D3A0 is itself
 * decompiled to EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorAnimFrame.c  *       --func CLACT_SetActorAnimFrame --addr 0x0204B8C4 --cc 1.1p1 --arm
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

extern void CLACT_SetAnimFrame(struct Obj *o, u32 value);

void CLACT_SetActorAnimFrame(struct Obj *p, u32 value)
{
    CLACT_SetAnimFrame((struct Obj *)(&p->unk_68), value);
}
