/*
 * function: func_021BE0D4
 * address:  0x021BE0D4
 * packet:   pkt_ov172_021BE0D4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Field setter, u32 at +0x2c (unlabelled; follows the getter func_021BE0D0).
 */

typedef unsigned long u32;

void func_021BE0D4(void *p, u32 v)
{
    *(u32 *)((char *)p + 0x2c) = v;
}
