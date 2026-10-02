/*
 * function: func_021BA350
 * address: 0x021BA350
 * packet: pkt_ov069_021BA350
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
void func_021BA350(char *p)
{
    *(unsigned short *)(p + 0x160) = 0;
    *(unsigned short *)(p + 0x162) = *(int *)(p + 0x164) / 10;
    if (*(int *)(p + 0x164) % 10 != 0)
        (*(unsigned short *)(p + 0x162))++;
}
