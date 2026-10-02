/*
 * unit: yes
 * function: func_021DD08C, func_021DD098
 * address: 0x021DD08C
 * packet: pkt_ov093_021DD08C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD19C 0x021DD19C thumb ov093
 *   d_021F1AEC 0x021F1AEC data a4
 */
extern void func_021DD19C(void *, unsigned char *, int, int);
extern const unsigned char d_021F1AEC[];
void func_021DD08C(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 2);
}
const void *func_021DD098(int *p)
{
    *p = 5;
    return d_021F1AEC;
}
