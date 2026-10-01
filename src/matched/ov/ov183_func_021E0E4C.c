/*
 * function: func_021E0E4C
 * address: 0x021E0E4C
 * packet: pkt_ov183_021E0E4C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
void func_021E0E4C(char *p)
{
    int i;
    for (i = 0; i < *(int *)(p + 0x23c); i++) {
        if (i >= *(int *)(p + 0x248) && i < *(int *)(p + 0x24c))
            *(int *)(p + i * 28 + 8) = 1;
        else
            *(int *)(p + i * 28 + 8) = 0;
    }
}
