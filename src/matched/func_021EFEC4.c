/*
 * function: func_021EFEC4
 * address:  0x021EFEC4
 * packet:   pkt_021EFEC4
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to the unlabelled ov030 leaf func_021EFEC0; its ABS32 pool word
 * is now witnessed by the EXACT shard entry for func_021EFEC0 (matched x1).
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
