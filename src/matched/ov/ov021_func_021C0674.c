/*
 * function: func_021C0674
 * address:  0x021C0674
 * packet:   pkt_ov021_021C0674
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Frees the sub-object at +4, then the object (EXACT*: trailing pad).
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021C0674(void **p)
{
    func_020307B0(p[1]);
    func_020307B0(p);
}
