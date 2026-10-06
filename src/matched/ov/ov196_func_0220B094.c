/*
 * function: func_0220B094
 * address:  0x0220B094
 * packet:   pkt_0220B094
 * region:   ov196
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220B07C  0x0220B07C  thumb  ov196
 */
extern void func_0220B07C(void **p);

void func_0220B094(char *p, unsigned char *q)
{
    int i = 0;
    for (;;) {
        unsigned char c = q[i];
        if (c == 0xff)
            break;
        func_0220B07C((void **)(p + (c << 3)));
        i++;
    }
}
