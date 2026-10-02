/*
 * function: func_02183F88
 * address:  0x02183F88
 * packet:   pkt_ov022_02183F88
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * leaf:     Sole game blocker of assigned ov012 caller; root claim granted.
 */

typedef unsigned char u8;
typedef unsigned int u32;

void func_02183F88(u8 *p, u8 a)
{
    p[0xC] |= (u8)(1 << a);
}
