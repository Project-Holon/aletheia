/*
 * function: func_021EE200
 * address:  0x021EE200
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
 * Walk 9 8-byte records releasing both words of each, then the
 *   head.
 */


extern void func_0202570C(int);
extern void func_020437AC(int);
extern void func_02025588(int);
void func_021EE200(char *p)
{
    unsigned i;
    for (i = 0; i < 9; i++) {
        func_0202570C(*(int *)(p + i * 8 + 4));
        func_020437AC(*(int *)(p + i * 8 + 8));
    }
    func_02025588(*(int *)p);
}
