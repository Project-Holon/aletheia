/*
 * function: func_021C1FC4
 * address:  0x021C1FC4
 * packet:   pkt_021C1FC4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C1920 0x021C1920  thumb  ov208
 *
 * Dispatches on the word at +0x6C: state 0 hands a 3, state 5 hands an 8 to func_021C1920.
 */

extern void func_021C1920(void *, void *, int, int);

void func_021C1FC4(void *a, char *b, int c)
{
    int s = *(int *)(b + 0x6c);

    if (s == 0) {
        func_021C1920(a, b, c, 3);
        return;
    }
    if (s == 5) {
        func_021C1920(a, b, c, 8);
    }
}
