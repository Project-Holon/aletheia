/*
 * function: func_021B9B58
 * address:  0x021B9B58
 * packet:   pkt_ov114_021B9B58
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 *
 * ARM linker veneer / far tail call: ldr ip,[pc,#0]; bx ip; .word
 * 0x02086028, printed as a .word run by disasm.py at 0x021B9B58 in ov114.
 * Blocker target of func_021BEFCC (pkt_021B9500).
 */

extern void func_02086028(void);

void func_021B9B58(void)
{
    func_02086028();
}
