/*
 * unit:     no
 * address:  0x020314DC
 * packet:   pkt_02031324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020314DC
 *
 * A four-field constructor: marks the object valid (+0x10 = 1) and stores
 * the three remaining arguments at +0x14, +0x18 and +0x1c. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020314DC.c \
 *       --func sub_020314DC --addr 0x020314DC --cc 1.1p1
 */

typedef unsigned int u32;

struct S020314DC {
    char pad[0x10];
    u32  field10;
    u32  field14;
    u32  field18;
    u32  field1c;
};

void sub_020314DC(struct S020314DC *p, u32 a, u32 b, u32 c)
{
    p->field10 = 1;
    p->field14 = a;
    p->field18 = b;
    p->field1c = c;
}
