/*
 * function: func_021FE4D0
 * address:  0x021FE4D0
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FE4D0   0x021FE4D0  thumb
 *   BODY

 *
 * lane O10 candidate
 */

int func_021FE4D0(char *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(int *)(p + 0x26c + i * 4) == -1)
            break;
    }
    if (i == 6)
        i = 0;
    return i;
}

