/*
 * function: func_021DD21C
 * address: 0x021DD21C
 * packet: pkt_ov119_021DD21C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
int func_021DD21C(char *p)
{
    int i, n = 0;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 4 + 0xFA4) != -1 && *(int *)(p + i * 4 + 0xFBC) != -1)
            n++;
    }
    return n;
}
