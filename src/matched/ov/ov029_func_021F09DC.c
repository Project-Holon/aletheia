/*
 * function: func_021F09DC
 * address: 0x021F09DC
 * packet: pkt_ov029_021F09DC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
int func_021F09DC(unsigned char *p, int i, int v, int a, int b, int j)
{
    if (a == b && i == j) {
        *(unsigned short *)(p + i * 2 + 0x26c) = v;
        *(p + i + 0x44a) = a;
        return 1;
    }
    return 0;
}
