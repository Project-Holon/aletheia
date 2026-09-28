/*
 * unit:     no
 * function: func_0203F034
 * address:  0x0203F034
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469F8  0x021469F8  data
 *
 * Mersenne Twister (MT19937) seeding: 624 words at offset 0 of the block
 * behind 0x021469F8, with the generator index at +0x9c0.  Every step
 * re-reads both the global pointer and the index out of memory, so the
 * index is a real field and not a local; the multiply-accumulate is one
 * `mla` because the index is the addend.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F034.c \
 *       --func func_0203F034 --addr 0x0203F034 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef signed int   s32;

struct Mt {
    u32 mt[624];
    s32 index;
};

extern struct Mt *g_021469F8;

void func_0203F034(u32 seed)
{
    g_021469F8->mt[0] = seed;
    for (g_021469F8->index = 1; g_021469F8->index < 624;
         g_021469F8->index++) {
        u32 prev = g_021469F8->mt[g_021469F8->index - 1];

        g_021469F8->mt[g_021469F8->index] =
            (prev ^ (prev >> 30)) * 0x6c078965 + g_021469F8->index;
    }
}
