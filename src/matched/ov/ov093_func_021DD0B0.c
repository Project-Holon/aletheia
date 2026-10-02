/*
 * unit: yes
 * function: func_021DD0B0, func_021DD0BC
 * address: 0x021DD0B0
 * packet: pkt_ov093_021DD0B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD19C 0x021DD19C thumb ov093
 *   d_021F1DE4 0x021F1DE4 data a4
 */
extern void func_021DD19C(void *, unsigned char *, int, int);
extern const unsigned char d_021F1DE4[];
void func_021DD0B0(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 4);
}
const void *func_021DD0BC(int *p)
{
    *p = 5;
    return d_021F1DE4;
}
