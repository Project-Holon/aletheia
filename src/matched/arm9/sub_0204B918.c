/*
 * function: sub_0204B918
 * address:  0x0204B918
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *    sub_0204D444   0x0204D444  arm
 *   sub_02062F1C   0x02062F1C  arm
 *
 * Hand the record sub_0204D444 returns for the sub-object at +0x68
 * straight to sub_02062F1C: a plain forwarding call whose argument is
 * already in r0
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * sub_02062F1C is the one call this family makes outside the 0x0204Cxxx
 * / 0x0204Dxxx layer.
 *
 * Byte-correct, capped at MATCH: 0x02062F1C is called from this one site
 * and nowhere else in the image.  sub_0204D444 resolves fine (label).
 * It unsticks when 0x02062F1C is itself decompiled to EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B918.c  *       --func sub_0204B918 --addr 0x0204B918 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8 unk_00[1];
};

struct Node {
    u8  pad_00[0xc];
    u32 unk_0c;
    u32 unk_10;
};

struct Obj {
    u8         pad_00[0x68];
    struct Sub unk_68;
};

extern struct Node *sub_0204D444(struct Sub *s);
extern u16 sub_02062F1C(const struct Node *n);

void sub_0204B918(struct Obj *p)
{
    sub_02062F1C(sub_0204D444(&p->unk_68));
}
