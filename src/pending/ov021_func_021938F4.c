/*
 * function: func_021938F4
 * address:  0x021938F4
 * packet:   pkt_021938F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   func_02193D08  0x02193D08  thumb  ov021
 *
 * blocker: target 0x02193D08 has no witness outside the compared range
 *          (ov009/ov021 overlap; the ov021 hint does not locate a func_ label).
 */

void func_02193D08(void);

void func_021938F4(void)
{
    func_02193D08();
}
