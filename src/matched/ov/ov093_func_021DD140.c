/*
 * unit: yes
 * function: func_021DD140, func_021DD14C
 * address: 0x021DD140
 * packet: pkt_ov093_021DD140
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD19C 0x021DD19C thumb ov093
 *   d_021F1B8C 0x021F1B8C data a4
 */
extern void func_021DD19C(void *, unsigned char *, int, int);
extern const unsigned char d_021F1B8C[];
void func_021DD140(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 37);
}
const void *func_021DD14C(int *p)
{
    *p = 5;
    return d_021F1B8C;
}
