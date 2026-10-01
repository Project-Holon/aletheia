/*
 * function: func_021D8F0C
 * address: 0x021D8F0C
 * packet: pkt_ov131_021D8F0C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */

void func_021D8F0C(void *unused, unsigned char *p, int delta)
{
    int max = (p[0x10] - 6) * 24;
    unsigned int old;
    if (max < 0) max = 0;
    if (delta > 24) delta = 24;
    if (delta < -24) delta = -24;
    old = *(unsigned int *)(p + 0x14);
    if ((short)old + delta < 0) *(unsigned int *)(p + 0x14) = 0;
    else if (old + delta > (unsigned int)max) *(unsigned int *)(p + 0x14) = max;
    else *(unsigned int *)(p + 0x14) = old + delta;
    if (delta != 0) *(unsigned int *)(p + 0xc) = 1;
}
