/*
 * function: func_021EF264
 * address:  0x021EF264
 * packet:   pkt_ov170_021EF264
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF0A8 0x021EF0A8 thumb
 *   d_021F0F58 0x021F0F58 data
 */

extern int func_021EF0A8(const void *tbl, unsigned n);
extern const unsigned char d_021F0F58[];

int func_021EF264(void)
{
    return func_021EF0A8(d_021F0F58, 1);
}
