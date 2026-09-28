/*
 * function: func_021FFF0C
 * address:  0x021FFF0C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFF0C   0x021FFF0C  thumb
 *   func_022019F4 0x022019F4 thumb ov094

 *
 * lane O10 candidate
 */

extern int func_022019F4(char *p, int key);

int func_021FFF0C(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (*(int *)(e + 8) == 0)
        return 0;
    return *(unsigned short *)(e + 0x40);
}

