/*
 * function: func_021F821C
 * address:  0x021F821C
 * packet:   pkt_ov094_021F821C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwards three arguments to func_02208958 with the handle at 0x1a4 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_02208958 0x02208958 thumb ov094
 */
extern char *d_0220AF20;
extern void func_02208958(void *, int, int, int);

void func_021F821C(int a, int b, int c)
{
    func_02208958(*(void **)(d_0220AF20 + 0x1a4), a, b, c);
}
