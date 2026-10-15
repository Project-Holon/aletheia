/*
 * function: NAMEIN_GRAPHIC_PickTable14
 * address: 0x021F4E98
 * packet: pkt_ov194_021F4E98
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_CopyString 0x0201F41C thumb
 */
extern void WORDSET_CopyString(const unsigned short *, unsigned short *, unsigned);
int NAMEIN_GRAPHIC_PickTable14(char *p, int index, unsigned short *table, unsigned n, unsigned char *out)
{
    unsigned char i;
    WORDSET_CopyString((const unsigned short *)(p + 0x14 + 0x18 * index), table, n);
    i = 0;
    while (i < 3 && table[i] != 0x3000) i++;
    if (out != 0) *out = i;
    return i != 0;
}
