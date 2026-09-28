/*
 * function: func_02175368
 * address:  0x02175368
 * packet:   pkt_ov011_02175368
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf, seeded so that ov018 func_0217FE38 has a witness:
 * clears the four bytes at +0x15C through sub_02082BCC (fill, n bytes).
 *
 * symbols:
 *   sub_02082BCC  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

extern void sub_02082BCC(void *p, int c, unsigned int n);

void func_02175368(char *p)
{
    sub_02082BCC(p + 0x15C, 0, 4);
}
