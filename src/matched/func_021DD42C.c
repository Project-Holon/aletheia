/*
 * function: func_021DD42C
 * address:  0x021DD42C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Walk the p+8 object's entries from tag-0x1e to the current
 *   count, re-reading the count each step.
 */


extern int func_0201AA18(int);
extern void func_0201AB8C(int, int, int, int);
void func_021DD42C(int *p, unsigned char *a)
{
    unsigned i = *(unsigned short *)(a + 4) - 0x1e;
    while (i < func_0201AA18(*(int *)(*p + 8)) - 1) {
        func_0201AB8C(*(int *)(*p + 8), i, i + 1, 0x4c);
        i++;
    }
}
