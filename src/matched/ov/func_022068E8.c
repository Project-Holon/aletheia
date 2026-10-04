/*
 * function: func_022068E8
 * address:  0x022068E8
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022068E8   0x022068E8  thumb
 *   func_0220687C 0x0220687C thumb ov094

 *
 * lane O10 candidate
 */

extern void func_0220687C(char *p, void *q);

void func_022068E8(char *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        int v = *(int *)(p + 8 + i * 4);

        if (v != 0)
            func_0220687C(p, (void *)v);
    }
}

