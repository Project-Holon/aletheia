/*
 * function: func_021DFD0C
 * address:  0x021DFD0C
 * packet:   pkt_ov119_021DFD0C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02015E04  0x02015E04  thumb
 */

typedef unsigned int u32;

extern void func_02015E04(void *p);

void func_021DFD0C(char *p)
{
    func_02015E04((void *)(*(u32 *)(p + 0x844)));
    *(u32 *)(p + 0x854) = 1;
}
