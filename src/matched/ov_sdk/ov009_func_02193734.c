/*
 * function: gpiSetErrorString
 * address:  0x02193734
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the word the pointer holds, with the constant third argument 0x100.
 *
 * symbols:
 *   strzcpy  0x0219327C  arm  ov009
 */

extern void strzcpy(char *p, int b, int n);

void gpiSetErrorString(int *p, int b)
{
    strzcpy((char *)(*p), b, 0x100);
}

