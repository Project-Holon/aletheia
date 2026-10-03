/*
 * unit:     no
 * function: sub_0202C654
 * address:  0x0202C654
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
 * The complementary case body to sub_0202C638: advances the same
 * saturating counter and resets the window's state to 1 once it has
 * caught up with its limit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C654.c \
 *       --func sub_0202C654 --addr 0x0202C654 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Counter0202C5B4;
struct Obj0202C6B8;
extern void sub_0202C5CC(struct Counter0202C5B4 *p);
extern u32 sub_0202C5E0(struct Counter0202C5B4 *p);
extern void sub_0202C6BC(struct Obj0202C6B8 *p, u32 v);

u32 sub_0202C654(void *p)
{
    sub_0202C5CC(p);
    if (sub_0202C5E0(p) == 1) {
        sub_0202C6BC(p, 1);
    }
}
