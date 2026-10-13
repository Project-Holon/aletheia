/*
 * function: CLACT_GetActorAnimSeqCount
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
 *    CLACT_GetAnimObject   0x0204D444  arm
 *   sub_02062F1C   0x02062F1C  arm
 *
 * Hand the record CLACT_GetAnimObject returns for the sub-object at +0x68
 * straight to sub_02062F1C: a plain forwarding call whose argument is
 * already in r0
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * sub_02062F1C is the one call this family makes outside the 0x0204Cxxx
 * / 0x0204Dxxx layer.
 *
 * Byte-correct, capped at MATCH: 0x02062F1C is called from this one site
 * and nowhere else in the image.  CLACT_GetAnimObject resolves fine (label).
 * It unsticks when 0x02062F1C is itself decompiled to EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorAnimSeqCount.c  *       --func CLACT_GetActorAnimSeqCount --addr 0x0204B918 --cc 1.1p1 --arm
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

extern struct Node *CLACT_GetAnimObject(struct Obj *o);
extern u16 sub_02062F1C(const struct Node *n);

u16 CLACT_GetActorAnimSeqCount(struct Obj *p)
{
    return sub_02062F1C(CLACT_GetAnimObject((struct Obj *)(&p->unk_68)));
}
