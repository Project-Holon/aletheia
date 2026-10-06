/*
 * function: func_0216DB80
 * address: 0x0216DB80
 * packet: pkt_ov010_0216DB80
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

extern unsigned int *func_0216D548(unsigned int *p, unsigned int v);
typedef unsigned int   u32;
extern u32 *func_0216D550(u32 *p, u32 v);
void func_0216DB80(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D548(p, 32);
    else func_0216D550(p, 32);
}
