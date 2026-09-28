/*
 * function: func_021BCF58
 * address:  0x021BCF58
 * packet:   pkt_021BCF18
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD0AC 0x021BD0AC  thumb  ov208
 *
 * Lazy setup: sets the flag at +0x10 and initialises the sub-object at +8.
 * The second argument is only forwarded to func_021BD0AC, which is why the
 * compiler parks the flag temp in r2 rather than r1.
 */

extern void func_021BD0AC(char *, int);

void func_021BCF58(char *p, int x)
{
    if (*(int *)(p + 0x10) == 0) {
        *(int *)(p + 0x10) = 1;
        func_021BD0AC(p + 8, x);
    }
}
