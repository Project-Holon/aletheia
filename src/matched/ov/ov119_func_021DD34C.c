/*
 * function: func_021DD34C
 * address: 0x021DD34C
 * packet: pkt_ov119_021DD34C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
int func_021DD34C(char *p, int a, int b)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (b == *(int *)(p + i * 4 + 0xFA4) && a == *(int *)(p + i * 4 + 0xFBC))
            return i;
    }
    return -1;
}
