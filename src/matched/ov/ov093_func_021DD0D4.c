/*
 * unit: yes
 * function: func_021DD0D4, func_021DD0E0
 * address: 0x021DD0D4
 * packet: pkt_ov093_021DD0D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD19C 0x021DD19C thumb ov093
 *   d_021F1B14 0x021F1B14 data a4
 */
extern void func_021DD19C(void *, unsigned char *, int, int);
extern const unsigned char d_021F1B14[];
void func_021DD0D4(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 3);
}
const void *func_021DD0E0(int *p)
{
    *p = 5;
    return d_021F1B14;
}
