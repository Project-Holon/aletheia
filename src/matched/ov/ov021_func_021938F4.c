/*
 * function: func_021938F4
 * address:  0x021938F4
 * packet:   pkt_021938F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02193D08  0x02193D08  thumb  ov021
 *
 * Unblocked by matching the leaf at 0x02193D08 in ov021; the tail-call site
 * now resolves via `matched`.
 */

int func_02193D08(unsigned char *p);

int func_021938F4(unsigned char *p)
{
    return func_02193D08(p);
}
