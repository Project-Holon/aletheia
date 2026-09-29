/*
 * function: func_02206864
 * address:  0x02206864
 * packet:   pkt_ov094_02206864
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * lane S13 leaf of func_0220687C
 */

int func_02206864(char *p, int v)
{
    int i;
    int x;

    for (i = 0; i < 8; i++) {
        x = *(int *)(p + i * 4 + 8);
        if (x == v)
            break;
    }
    return i;
}
