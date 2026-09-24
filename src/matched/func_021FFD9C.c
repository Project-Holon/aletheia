/*
 * function: func_021FFD9C
 * address:  0x021FFD9C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFD9C   0x021FFD9C  thumb
 *   func_022019F4 0x022019F4 thumb ov094

 *
 * lane O10 candidate
 */

extern int func_022019F4(char *p, int key);

int func_021FFD9C(char *p, int key)
{
    if (func_022019F4(p, key) != -1)
        return 1;
    return 0;
}

