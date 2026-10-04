/*
 * function: func_021C1A98
 * address:  0x021C1A98
 * packet:   pkt_ov021_021C1A98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads a resource with the owner's heap id (tail call).
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0205121C(u32 a, u32 b, u32 c);

void *func_021C1A98(u16 *p, u32 a, u32 b)
{
    return (void *)func_0205121C(a, b, p[2]);
}
