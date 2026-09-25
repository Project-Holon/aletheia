/*
 * function: func_021BA780
 * address:  0x021BA780
 * packet:   pkt_021BA780
 * region:   ov218
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 */

extern int tbl_021BAC80[];

unsigned int func_021BA780(int v)
{
    int i;
    for (i = 0; i < 0x82; i++)
    {
        if (v == tbl_021BAC80[i])
        {
            break;
        }
    }
    if (i >= 0x82)
    {
        return 0xffff;
    }
    return i;
}
