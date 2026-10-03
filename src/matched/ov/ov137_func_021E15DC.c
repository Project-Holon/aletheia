/*
 * function: func_021E15DC
 * address: 0x021E15DC
 * packet: pkt_ov137_021E15DC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;

void func_021E15DC(int *p, int v)
{
    *p += v;
    while (*p < 0) *p += 0x168000;
    *p %= 0x168000;
}
