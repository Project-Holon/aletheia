/*
 * function: func_021842A4
 * address: 0x021842A4
 * packet: pkt_ov023_021842A4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02186988 0x02186988 thumb ov023
 */
extern void func_02186988(char *src, char *dst, int index);
void func_021842A4(int index, int unused, char *src, char *p)
{
    if (index != 0)
        func_02186988(src, p + 0x928c, index);
}
