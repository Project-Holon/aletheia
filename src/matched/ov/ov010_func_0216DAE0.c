/*
 * function: func_0216DAE0
 * address: 0x0216DAE0
 * packet: pkt_ov010_0216DAE0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0216D548 0x0216D548 thumb ov010
 *   func_0216D550 0x0216D550 thumb ov010
 */

extern void func_0216D548(unsigned int *p, unsigned int v);
extern void func_0216D550(unsigned int *p, unsigned int v);
void func_0216DAE0(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D550(p, 128);
    else func_0216D548(p, 128);
}
