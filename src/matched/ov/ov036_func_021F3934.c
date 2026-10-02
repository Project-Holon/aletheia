/*
 * function: func_021F3934
 * address: 0x021F3934
 * packet: pkt_ov036_021F3934
 * region: ov036
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
int func_021F3934(u8 *p, int v)
{
    int i;
    for (i = 0; i < 15; i++) {
        if (p[i] == v) return i;
    }
    return -1;
}
