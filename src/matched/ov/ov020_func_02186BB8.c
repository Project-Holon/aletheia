/*
 * function: func_02186BB8
 * address: 0x02186BB8
 * packet: pkt_ov020_02186BB8
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
int func_02186BB8(u8 *p, int delta)
{
    int ret;
    int sum;
    ret = 0;
    sum = p[2] + delta;
    if (sum > 100) p[2] = 100;
    else if (sum < 0) { p[2] = 0; ret = 1; }
    else p[2] += (u8)delta;
    return ret;
}
