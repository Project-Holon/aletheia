/*
 * function: func_02161950
 * address: 0x02161950
 * packet: pkt_ov010_02161950
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
void func_02161950(char *p)
{
    int i = 0;
    int zero = i;
    for (; i < 8; i++)
        *(int *)(p + 0x14 + i * 4) = zero;
}
