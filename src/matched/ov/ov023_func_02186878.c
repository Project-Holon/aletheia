/*
 * function: func_02186878
 * address: 0x02186878
 * packet: pkt_ov023_02186878
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
int func_02186878(char *p)
{
    int i = *(int *)(p + 0xBBC) - 1;
    if (i < 0) i = 99;
    return i;
}
