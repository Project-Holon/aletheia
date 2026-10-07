/*
 * function: func_021DA610
 * address:  0x021DA610
 * packet:   pkt_021DA610
 * region:   ov129
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DA578  0x021DA578  thumb
 */

extern void func_021DA578(void *p, int a, void *b, unsigned int c);

void func_021DA610(void *p, int sel, void *b, unsigned int c)
{
    if (sel == 1) {
        func_021DA578(p, 5, b, c);
        return;
    }
    if (sel == 2)
        func_021DA578(p, 6, b, c);
}
