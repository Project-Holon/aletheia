/*
 * unit: yes
 * function: func_021DD11C, func_021DD128
 * address: 0x021DD11C
 * packet: pkt_ov093_021DD11C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD19C 0x021DD19C thumb ov093
 *   d_021F1B64 0x021F1B64 data a4
 */
extern void func_021DD19C(void *, unsigned char *, int, int);
extern const unsigned char d_021F1B64[];
void func_021DD11C(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 5);
}
const void *func_021DD128(int *p)
{
    *p = 5;
    return d_021F1B64;
}
