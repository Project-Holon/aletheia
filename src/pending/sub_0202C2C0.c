/*
 * function: sub_0202C2C0
 * address:  0x0202C2C0
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   sub_0202C24C  0x0202C24C  thumb
 *   sub_0202C358  0x0202C358  thumb
 *
 * Not a guard on `p`: it is the *result* of sub_0202C24C(p) (EXACT,
 * src/matched/unit_0202C244.c) that is tested and, unchanged, forwarded
 * as sub_0202C358's own argument, which is what keeps the value in r0
 * across the branch with no extra register. sub_0202C358 is one of the
 * nine pool-word-and-bx trampolines of src/pending/unit_0202C318.c.
 * Every concrete byte matches.
 *
 * sub_0202C358 is called by exactly this one `bl` in the whole ROM, so
 * its relocation stays unresolved under the honesty rule, and it is not
 * (yet) covered by the `matched` class because src/pending/unit_0202C318.c
 * itself only reaches MATCH. Closes together with that file.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0202C2C0.c \
 *       --func sub_0202C2C0 --addr 0x0202C2C0 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202C24C(void *p);
extern void sub_0202C358(u32 v);

void sub_0202C2C0(void *p)
{
    u32 v = sub_0202C24C(p);

    if (v != 0) {
        sub_0202C358(v);
    }
}
