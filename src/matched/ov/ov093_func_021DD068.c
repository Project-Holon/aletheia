/*
 * unit: yes
 * function: func_021DD068, func_021DD074
 * address: 0x021DD068
 * packet: pkt_ov093_021DD068
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD19C 0x021DD19C thumb ov093
 *   d_021F1AC4 0x021F1AC4 data a4
 */
extern void func_021DD19C(void *, unsigned char *, int, int);
extern const unsigned char d_021F1AC4[];
void func_021DD068(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 1);
}
const void *func_021DD074(int *p)
{
    *p = 5;
    return d_021F1AC4;
}
