/*
 * function: func_021FD1A8
 * address:  0x021FD1A8
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD1A8   0x021FD1A8  thumb
 *
 * lane O10 candidate
 */

int func_021FD1A8(char *p, int v)
{
    int i;

    for (i = 0; i < 16; i++) {
        if (*(int *)(p + 0x4c + i * 4) == v)
            break;
    }
    return i;
}

