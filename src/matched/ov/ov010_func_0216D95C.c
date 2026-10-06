/*
 * function: func_0216D95C
 * address: 0x0216D95C
 * packet: pkt_ov010_0216D95C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0216D4DC 0x0216D4DC thumb ov010
 *   func_0216D4E4 0x0216D4E4 thumb ov010
 */

extern int func_0216D4DC(int a0, int a1, int a2);
extern void func_0216D4E4(unsigned int *p, unsigned int v);
void func_0216D95C(unsigned int *p, unsigned int v, int a2)
{
    if (v == 1) func_0216D4DC((int)p, 1, a2);
    else func_0216D4E4(p, 1);
}
