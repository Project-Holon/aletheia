/*
 * function: func_021751A8
 * address: 0x021751A8
 * packet: pkt_ov011_021751A8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_02012B58 0x02012B58 thumb
 */
typedef unsigned char u8;
extern int func_02026478(int);
extern int func_02012B58(int);
int func_021751A8(u8 *p, int index)
{
    int value;
    if (index >= p[0x902]) return 0;
    value = index - func_02012B58(func_02026478(*(int *)(p + 4)));
    if (value < 0) value += p[0x902];
    return value;
}
