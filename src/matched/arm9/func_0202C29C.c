/*
 * function: func_0202C29C
 * address:  0x0202C29C
 * packet:   pkt_0202C268
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Looks the caller's second argument up with func_0202C268; if the result
 * differs from the object's current +0xc field, installs it there and reports
 * success.  Unlabelled in the listing and absent from the worklist; filed from
 * the bytes.
 *
 * symbols:
 *   sub_0202C24C   0x0202C24C  thumb
 *   func_0202C268  0x0202C268  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C29C.c \
 *       --func func_0202C29C --addr 0x0202C29C --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32 sub_0202C24C(u32 *p);
extern u32 func_0202C268(u32 *p, u32 v);

u32 func_0202C29C(u32 *p, u32 v)
{
    u32 f = sub_0202C24C(p);
    u32 x = func_0202C268(p, v);

    if (f == x) {
        return 0;
    }
    p[3] = x;
    return 1;
}
