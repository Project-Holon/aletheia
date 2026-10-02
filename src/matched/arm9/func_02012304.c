/*
 * function: func_02012304
 * address:  0x02012304
 * packet:   pkt_02012304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Virtual call: the target is the object's own word at +4, the first argument is
 * the object, the second is the object + 8, the third is the object's word at
 * +0xc.  The call is a register `blx r3`, so there is no relocation to attest
 * and the file is EXACT up to the two bytes of section padding after the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012304.c \
 *       --func func_02012304 --addr 0x02012304 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

typedef int (*Fn02012304)(void *self, void *arg, u32 n);

struct S02012304 {
    unsigned char pad[4];
    Fn02012304 f04;
    unsigned char pad2[4];
    u32 f0c;
};

int func_02012304(struct S02012304 *o)
{
    return o->f04(o, (unsigned char *)o + 8, o->f0c);
}
