/*
 * function: ISS_SWITCH_SYS_IsActiveSetZone
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
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_IsActiveSetZone.c \
 *       --func ISS_SWITCH_SYS_IsActiveSetZone --addr 0x0202C250 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

struct Obj0202C244;
extern u32 sub_0202C24C(struct Obj0202C244 *p);
extern u32 sub_0202C348(void *a, void *b);

u32 ISS_SWITCH_SYS_IsActiveSetZone(u32 *p, u32 v)
{
    u32 f = sub_0202C24C((struct Obj0202C244 *)p);

    if (f == 0) {
        return 0;
    }
    return sub_0202C348((void *)f, (void *)v);
}
