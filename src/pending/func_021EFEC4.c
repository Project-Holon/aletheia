/*
 * function: func_021EFEC4
 * address:  0x021EFEC4
 * packet:   pkt_021EFEC4
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  tail-call target 0x021EFEC0 is unlabelled (leaf) in this
 *           function's own overlay ov030; 10 overlays overlap the address
 *           and none resolves without an invented region hint. Byte-correct.
 *
 * symbols:
 *   func_021EFEC4 0x021EFEC4 thumb
 *   func_021EFEC0 0x021EFEC0 thumb
 */

extern void func_021EFEC0(void);

void func_021EFEC4(void)
{
    func_021EFEC0();
}
