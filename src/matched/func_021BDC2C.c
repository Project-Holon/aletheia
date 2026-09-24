/*
 * function: func_021BDC2C
 * address:  0x021BDC2C
 * packet:   pkt_021BDC14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD3B4 0x021BD3B4  thumb  ov208

 * Returns the result of func_021BD3B4 on two fields while +0x10 is clear, else 0.
 */


extern int func_021BD3B4(int, int);

int func_021BDC2C(char *p)
{
    if (*(int *)(p + 0x10) == 0)
        return func_021BD3B4(*(int *)(p + 0x30),
                             *(int *)*(int **)(p + 0x7c));
    return 0;
}

