/*
 * function: func_02173B20
 * address: 0x02173B20
 * packet: pkt_ov011_02173B20
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021754E8 0x021754E8 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
void func_021754E8(u8 *p, int a, int b, int c);

void func_02173B20(int a, int b, u8 *c, u8 *d)
{
    if (d[0x154] == a && d[0x158] == c[0]) func_021754E8((u8 *)((int)d), a, 3, c[0]);
}
