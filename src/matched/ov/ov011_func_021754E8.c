/*
 * function: func_021754E8
 * address: 0x021754E8
 * packet: pkt_ov011_021754E8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void func_021754E8(u8 *p, int a, int b, int c)
{
    if (p[0x154] == a && p[0x158] == c) {
        p[0x155] = a;
        p[0x157] = b;
    }
}
