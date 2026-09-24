/*
 * function: func_022019F4
 * address:  0x022019F4
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022019F4   0x022019F4  thumb
 *   BODY

 *
 * lane O10 candidate
 */

int func_022019F4(char *p, int key)
{
    int i;

    for (i = 0; i < 14; i++) {
        char *e = p + i * 0x5c;

        if (*(int *)(e + 8) != 0 && key == *(int *)(e + 0x50))
            return i;
    }
    return -1;
}

