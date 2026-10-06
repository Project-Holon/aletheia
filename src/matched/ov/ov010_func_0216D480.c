/*
 * function: func_0216D480
 * address: 0x0216D480
 * packet: pkt_ov010_0216D480
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D57C 0x0216D57C thumb ov010
 *   func_0216D570 0x0216D570 thumb ov010
 */

typedef unsigned int   u32;
extern u32 func_0216D57C(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
int func_0216D480(char *p)
{
    if (func_0216D57C(p, 0x200) == 0) return 1;
    if (func_0216D57C(p, 0x400) == 0) return 0;
    func_0216D570(p, 0x600);
    return 1;
}
