/*
 * function: func_0220793C
 * address:  0x0220793C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220793C   0x0220793C  thumb
 *   func_02208D38 0x02208D38 thumb ov094

 *
 * lane O10 candidate
 */

extern unsigned int func_02208D38(int a, int b, int c);

void func_0220793C(char *p)
{
    int a = *(int *)(p + 0x48);
    int b = *(int *)(p + 0x4c);

    if (b < 0x30)
        *(int *)(p + 0x78) = func_02208D38(a << 8, b, 0x30) >> 8;
    else
        *(int *)(p + 0x78) = func_02208D38(a, b, 0x30);
}

