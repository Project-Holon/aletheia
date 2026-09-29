/*
 * function: func_0216E290
 * address:  0x0216E290
 * packet:   pkt_ov010_0216E290
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Forwards the pointer at +0x14 to the arm9 routine at 0x02049238.
 *
 * symbols:
 *   func_02049238  0x02049238  arm
 */

extern void func_02049238(void *p);

void func_0216E290(char *p)
{
    func_02049238(*(void **)(p + 0x14));
}
