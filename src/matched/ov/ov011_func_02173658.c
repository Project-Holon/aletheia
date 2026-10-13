/*
 * function: INTRUDE_COMM_AgeFoundList
 * address:  0x02173658
 * packet:   pkt_ov011_02173658
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;

void INTRUDE_COMM_AgeFoundList(u8 *o)
{
    int i;

    if (o[0x925] != 0) {
        o[0x926] = o[0x926] + 1;
        if (o[0x926] > 0x96) {
            for (i = 0; i < o[0x925]; i++)
                *(int *)(o + 0x930 + i * 4) = 0;
            o[0x926] = 0;
            o[0x925] = 0;
        }
    }
}
