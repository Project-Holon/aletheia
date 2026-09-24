/*
 * function: func_021BC99C
 * address:  0x021BC99C
 * packet:   pkt_021BC99C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Restarts the widget when its +5 counter has run out, otherwise counts it down.
 */


extern void func_02041EE4(int, int, int);

void func_021BC99C(char *p)
{
    unsigned char c;

    c = *(unsigned char *)(p + 5);
    if (c == 0) {
        func_02041EE4(*(unsigned char *)(p + 4), 1, 1);
        *(unsigned char *)(p + 5) = 4;
    } else {
        *(unsigned char *)(p + 5) = c - 1;
    }
}

