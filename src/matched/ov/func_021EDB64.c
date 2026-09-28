/*
 * function: func_021EDB64
 * address:  0x021EDB64
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Detach slot i then hand the a*0x400 span of the 0x3E70 pool to
 *   the 0x400/0/0 emitter.
 */


extern int func_0204B7F0(int);
extern void func_0204AA94(int, int, int, int, int);
void func_021EDB64(char *p, int a, int i)
{
    int q = *(int *)(p + 0x2c);
    int x = func_0204B7F0(*(int *)(q + i * 4 + 0x9E74));
    func_0204AA94(x, q + 0x3E70 + a * 0x400, 0x400, 0, 0);
}
