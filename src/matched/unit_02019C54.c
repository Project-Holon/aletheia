/*
 * unit:     yes
 * address:  0x02019C54
 * packet:   pkt_02019C38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02019C54
 *
 * A one-entry memo: the (a, b) key pair at 0x02146270 and the 0x10 byte
 * object built for it at 0x02146274, rebuilt through sub_0201ADA4
 * (src/matched/unit_0201ADA4.c) only when the key changes.  func_02019C90 in
 * src/matched/unit_02019C7C.c is its only caller.
 *
 * Two things pin the source.
 *
 * The guard is one `||` expression rather than two ifs, which is what puts
 * both stores and the call in one block, per
 * docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md; and the
 * arm that falls through the first `bne` is the second half of the
 * disjunction, not the body.
 *
 * The two pool words 0x02146270 and 0x02146274 are one symbol and an addend,
 * per docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 * Declared as two symbols, 0x02146274 would need a witness of its own and the
 * only word in the image that holds it is the one under test.
 *
 * The neighbour func_02019C38 at the head of this packet is byte-correct but
 * MATCH-capped on its private table and is parked in
 * src/pending/sub_02019C38.c; this range is cut to exclude it.
 *
 * symbols:
 *   g_02146270   0x02146270  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02019C54.c \
 *       --addr 0x02019C54 --thumb
 */

typedef unsigned short u16;
typedef unsigned char  u8;
typedef unsigned int   u32;

struct Memo {
    u16 b;
    u16 a;
    u8  obj[0x10];
};

extern struct Memo g_02146270;

extern void sub_0201ADA4(u32 a, u32 b, void *dest);

void *func_02019C54(u32 a, u32 b)
{
    if (a != g_02146270.a || b != g_02146270.b) {
        g_02146270.b = (u16)b;
        g_02146270.a = (u16)a;
        sub_0201ADA4(a, b, g_02146270.obj);
    }
    return g_02146270.obj;
}
