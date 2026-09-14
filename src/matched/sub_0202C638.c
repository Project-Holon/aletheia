/*
 * unit:     no
 * function: sub_0202C638
 * address:  0x0202C638
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202C5CC  0x0202C5CC  thumb
 *   sub_0202C5E0  0x0202C5E0  thumb
 *   sub_0202C6BC  0x0202C6BC  thumb
 *
 * Advances the saturating counter of src/matched/unit_0202C5CC.c and, once
 * it has caught up with its limit, resets the window's state to 0. One of
 * the two case bodies sub_0202C5F0's switch dispatches to.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C638.c \
 *       --func sub_0202C638 --addr 0x0202C638 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void sub_0202C5CC(void *p);
extern u32 sub_0202C5E0(void *p);
extern u32 sub_0202C6BC(void *p, u32 v);

u32 sub_0202C638(void *p)
{
    sub_0202C5CC(p);
    if (sub_0202C5E0(p) == 1) {
        sub_0202C6BC(p, 0);
    }
}
