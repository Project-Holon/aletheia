/*
 * function: func_021A356C
 * address:  0x021A356C
 * packet:   pkt_ov021_021A356C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A575C  0x021A575C  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 func_02188CFC(u8 *p);
void func_021A575C(u32 *x);

void func_021A356C(void **p)
{
    if (func_02188CFC(p[0]) == 0)
        func_021A575C(p[2]);
}
