/*
 * unit:     no
 * function: func_0202C5C4
 * address:  0x0202C5C4
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An unlabelled leaf, six bytes padded to eight, sitting between
 * sub_0202C5B4's trailing padding and func_0202C5CC's label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md): a plain
 * two-field setter with no prologue at all, reached only through
 * sub_0202C550's pool-word-and-bx tail call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C5C4.c \
 *       --func func_0202C5C4 --addr 0x0202C5C4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Obj0202C5C4 {
    u8 pad[6];
    u16 unk06;
    u16 unk08;
};

void func_0202C5C4(struct Obj0202C5C4 *p, u16 a, u16 b)
{
    p->unk06 = a;
    p->unk08 = b;
}
