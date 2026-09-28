/*
 * function: func_021E2648
 * address:  0x021E2648
 * packet:   pkt_ov170_021E2648
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9284 0x021E9284 thumb
 *
 * State handler (table entry at 0x021EFABC) that forwards to
 * func_021E9284.
 */

extern int func_021E9284(unsigned char *p);

int func_021E2648(unsigned char *p)
{
    return func_021E9284(p);
}
