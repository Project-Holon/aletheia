/*
 * function: func_021DCE24
 * address:  0x021DCE24
 * packet:   pkt_021DCE24
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203C9AC  0x0203C9AC  arm
 *
 * Set the word at +0 and mark the object armed at +0x1c, then start the
 * 0x3f7 service with a zeroed first three arguments.
 */

extern void func_0203C9AC(int, int, int, int);

void func_021DCE24(char *p, int v)
{
    *(int *)p = v;
    *(int *)(p + 0x1c) = 1;
    func_0203C9AC(0, 0, 0, 0x3f7);
}

