/*
 * function: func_0202C29C
 * address:  0x0202C29C
 * packet:   pkt_0202C268
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Closed: func_0202C268 became an EXACT manifest entry (pkt_0202C268), so the `matched` class attests its call at 0x0202C2A2.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0202C24C(u8 *p);
extern u32 func_0202C268(void *p, u32 v);

u32 func_0202C29C(u8 *p, u32 v)
{
    u32 r = func_0202C24C(p);
    u32 s = func_0202C268(p, v);

    if (r == s) {
        return 0;
    }
    *(u32 *)(p + 0xc) = s;
    return 1;
}
