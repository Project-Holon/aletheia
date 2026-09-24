/*
 * function: func_0220684C
 * address:  0x0220684C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220684C   0x0220684C  thumb
 *   func_022068C4 0x022068C4 thumb ov094

 *
 * lane O10 candidate
 */

extern int func_022068C4(char *p);

void func_0220684C(char *p, int a, int b)
{
    int i = func_022068C4(p);

    *(int *)(p + i * 4 + 8) = a;
    *(int *)(p + i * 4 + 0x28) = b;
}

