/*
 * function: func_021759B0
 * address: 0x021759B0
 * packet: pkt_ov011_021759B0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02175B34 0x02175B34 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_02175B34(u8 *p);
void func_021759B0(u8 *p)
{
    u8 *q = func_02175B34(p);
    if (q != 0) *(u16 *)(q + 0x30) = 0;
}
