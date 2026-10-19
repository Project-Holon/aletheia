/*
 * unit:     no
 * function: ISS_SWITCH_StartFadeOut
 * address:  0x0202C688
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_0202C760  0x0202C760  thumb
 *   sub_0202C6BC  0x0202C6BC  thumb
 *
 * One of the four open trampoline targets of src/pending/unit_0202C548.c
 * (reached through sub_0202C568's pool-word-and-bx tail call). The
 * complementary test to sub_0202C670: unless the state accessor already
 * reads 1, resets the object to state 3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_StartFadeOut.c \
 *       --func ISS_SWITCH_StartFadeOut --addr 0x0202C688 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202C760(void *p);
struct Obj0202C6B8;
extern struct Obj0202C6B8 *sub_0202C6BC(struct Obj0202C6B8 *p, u32 v);

u32 ISS_SWITCH_StartFadeOut(void *p)
{
    if (sub_0202C760(p) != 1) {
        sub_0202C6BC(p, 3);
    }
}
