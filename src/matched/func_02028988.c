/*
 * unit:     yes
 * function: func_02028988
 * address:  0x02028988
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c.  A pure predicate over the system's mode word: nine accepted values written
 * as one disjunction so that all nine tests share the single `movs r0, #1`
 * exit (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 * The source order of the nine is the order of the nine `cmp` instructions,
 * which is not sorted.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_02028988.c  *       --addr 0x02028988 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Sys {
    u32 unk00;
    u32 unk04;
    u8  unk08[0x14];
    u32 unk1C;
    u32 unk20;
};

u32 func_02028988(struct Sys *s)
{
    u32 v = s->unk04;

    if (v == 4 || v == 3 || v == 6 || v == 7 || v == 5 || v == 8 || v == 10 ||
        v == 11 || v == 13) {
        return 1;
    }
    return 0;
}
