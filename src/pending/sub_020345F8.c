/*
 * function: sub_020345F8
 * address:  0x020345F8
 * packet:   pkt_020345F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_Table1  0x020A07A0  data
 *   g_Table2  0x020A07A4  data
 *
 * A five-entry linear search over g_Table1 keyed by the argument,
 * returning the matching entry of g_Table2 or a default of 0x20.
 *
 * Every concrete byte matches; neither table is referenced by any other
 * pool word or ABS32 site anywhere else in the ARM9 image, so both stay
 * unresolved under the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020345F8.c \
 *       --func sub_020345F8 --addr 0x020345F8 --cc 1.1p1
 */

typedef unsigned int u32;

struct Entry8 {
    u32 key;
    u32 pad;
};

extern const struct Entry8 g_Table1[5];
extern const struct Entry8 g_Table2[5];

u32 sub_020345F8(u32 key)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        if (g_Table1[i].key == key) {
            return g_Table2[i].key;
        }
    }
    return 0x20;
}
