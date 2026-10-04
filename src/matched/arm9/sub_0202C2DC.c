/*
 * function: sub_0202C2DC
 * address:  0x0202C2DC
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * unit:     no
 * status:   EXACT
 *
 * symbols:
 *   sub_0202C24C  0x0202C24C  thumb
 *   sub_0202C338  0x0202C338  thumb
 *
 * The same shape as src/matched/sub_0202C2C0.c: not a guard on `p`, but
 * on the *result* of sub_0202C24C(p) (EXACT, src/matched/unit_0202C244.c),
 * which is forwarded unchanged as sub_0202C338's own argument so the
 * value stays in r0 across the branch. sub_0202C338 is one of the nine
 * pool-word-and-bx trampolines of src/matched/unit_0202C318.c. Every
 * concrete byte matches.
 *
 * What closed it: sub_0202C338 is called by exactly this one `bl` in the
 * whole ROM, so no cut can give the site an outside witness. It is a
 * member function of src/matched/unit_0202C318.c, which has now promoted
 * out of src/pending/ and is EXACT, so the `matched` class witnesses the
 * address (docs/MATCHING.md, "The matched class").
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C2DC.c \
 *       --func sub_0202C2DC --addr 0x0202C2DC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Obj0202C244;
extern u32 sub_0202C24C(struct Obj0202C244 *p);
extern u32 sub_0202C338(void *p);

void sub_0202C2DC(void *p)
{
    u32 v = sub_0202C24C(p);

    if (v != 0) {
        sub_0202C338((void *)v);
    }
}
