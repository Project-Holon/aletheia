/*
 * function: func_021BDAE8
 * address:  0x021BDAE8
 * packet:   pkt_021BDAE8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD358 0x021BD358  thumb  ov208

 * Stores the argument at +0x20 and, when +8 is set, restarts it at state 3.
 */


extern void func_021BD358(char *, int);

void func_021BDAE8(char *p, int v)
{
    *(int *)(p + 0x20) = v;
    if (*(int *)(p + 8) != 0) {
        *(int *)(p + 8) = 3;
        p[0x24] = 0;
        func_021BD358(*(char **)(p + 0x30), 0);
    }
}

