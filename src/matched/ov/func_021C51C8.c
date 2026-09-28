/*
 * function: func_021C51C8
 * address:  0x021C51C8
 * packet:   pkt_021C51C8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Stores the two arguments and zeroes the byte at +8 and the word at +0xC.
 */


typedef struct {
    int w0;
    int w4;
    char b8;
    char pad[3];
    int wc;
} S;

void func_021C51C8(S *p, int a, int b)
{
    p->w0 = a;
    p->w4 = b;
    p->b8 = 0;
    p->wc = 0;
}

