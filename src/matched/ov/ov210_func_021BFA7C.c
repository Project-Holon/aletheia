/*
 * function: func_021BFA7C
 * address: 0x021BFA7C
 * packet: pkt_ov210_021BFA7C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 * Caller sign-extends r3 to 16 bits before EE38; existing callee uses u16.
 */
extern void func_021BEDF0(int p, int i, int v);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
void func_021BFA7C(char *p, int i, int flag)
{
    func_021BEDF0((int)p, 9, flag);
    func_021BEDF0((int)p, 11, 0);
    func_021BEDF0((int)p, 13, 0);
    if (flag == 1)
        func_021BEE38(p, 9, 0x8c, (short)(i * 40 + 20), 0);
}
