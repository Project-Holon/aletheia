/*
 * function: func_02173AB4
 * address: 0x02173AB4
 * packet: pkt_ov011_02173AB4
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
void func_021754E8(int a, int b, int c, int d);

void func_02173AB4(int a, int b, u8 *c, u8 *d)
{
    u8 v;
    v = c[1];
    if (v == d[0x159]) func_021754E8((int)d, a, c[0], v);
    else (d + a)[0x948] = v;
}
