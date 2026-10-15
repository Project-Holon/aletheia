/*
 * function: UN_SELECT_ContainsItem
 * address:  0x021BA75C
 * packet:   pkt_021BA75C
 * region:   ov218
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int UN_SELECT_ContainsItem(char *p, int v)
{
    int i;
    for (i = 0; i < 0x14; i++)
    {
        if (v == *(int *)(p + 0x2dc + i * 4))
        {
            return 1;
        }
    }
    return 0;
}
