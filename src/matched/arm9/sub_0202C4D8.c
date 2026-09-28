/*
 * unit:     no
 * function: sub_0202C4D8
 * address:  0x0202C4D8
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202C4CC  0x0202C4CC  thumb
 *   sub_0202C4D0  0x0202C4D0  thumb
 *
 * One of the eight open trampoline targets of src/pending/unit_0202C318.c
 * (reached through sub_0202C348's pool-word-and-bx tail call). Linear
 * search of the u16 array src/matched/unit_0202C4CC.c's sub_0202C4D0
 * indexes, bounded by the count sub_0202C4CC reads off the same object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C4D8.c \
 *       --func sub_0202C4D8 --addr 0x0202C4D8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202C4CC(void *p);
extern u32 sub_0202C4D0(void *p, u32 idx);

u32 sub_0202C4D8(void *a, u32 b)
{
    int count = sub_0202C4CC(a);
    int i;

    for (i = 0; i < count; i++) {
        if (b == sub_0202C4D0(a, i)) {
            return 1;
        }
    }
    return 0;
}
