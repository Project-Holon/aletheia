/*
 * function: func_021FD19C
 * address:  0x021FD19C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FD19C   0x021FD19C  thumb
 *
 * lane O10 candidate
 */

void func_021FD19C(char *p, int i, char *q)
{
    *(int *)(p + i * 4 + 0x8c) = *(unsigned short *)(q + 8);
}

