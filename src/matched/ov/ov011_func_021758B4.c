/*
 * function: func_021758B4
 * address: 0x021758B4
 * packet: pkt_ov011_021758B4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02175894 0x02175894 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02175894(u8 *p);
int func_021758B4(u8 *p)
{
    int limit = *(u16 *)(p + 0xAA);
    int n = limit - func_02175894(p);
    if (n < 0) n = 0;
    return n;
}
