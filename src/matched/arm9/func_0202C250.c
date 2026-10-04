/*
 * function: func_0202C250
 * address:  0x0202C250
 * packet:   pkt_0202C250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the object's +0xc field is set, hands that field (not the object) to
 * sub_0202C348 together with the caller's second argument.  Unlabelled in the
 * listing and absent from the worklist; filed from the bytes.
 *
 * symbols:
 *   sub_0202C24C  0x0202C24C  thumb
 *   sub_0202C348  0x0202C348  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C250.c \
 *       --func func_0202C250 --addr 0x0202C250 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32 sub_0202C24C(u32 *p);
extern u32 sub_0202C348(void *a, void *b);

u32 func_0202C250(u32 *p, u32 v)
{
    u32 f = sub_0202C24C(p);

    if (f == 0) {
        return 0;
    }
    return sub_0202C348((void *)f, (void *)v);
}
