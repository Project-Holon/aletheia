/*
 * function: func_0216D208
 * address: 0x0216D208
 * packet: pkt_ov010_0216D208
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D5D4 0x0216D5D4 thumb ov010
 *   func_0216D5D8 0x0216D5D8 thumb ov010
 *   func_0216D600 0x0216D600 thumb ov010
 */

typedef unsigned short u16;
extern int func_0216D5D4(void *p);
extern void func_0216D5D8(void *p, u16 v);
extern void func_0216D600(void *p, u16 v);
void func_0216D208(void *p)
{
    func_0216D5D8(p, func_0216D5D4(p));
    func_0216D600(p, func_0216D5D4(p));
}
