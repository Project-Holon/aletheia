/*
 * function: func_02186860
 * address: 0x02186860
 * packet: pkt_ov023_02186860
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
void func_02186860(char *p, int x, unsigned char y)
{
    if (*(int *)(p + 0x9270) == 0) {
        *(int *)(p + 0x9270) = x;
        *(unsigned char *)(p + 0x9274) = y;
    }
}
