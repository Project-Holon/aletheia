/*
 * function: func_021EE26C
 * address:  0x021EE26C
 * packet:   pkt_ov170_021EE26C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020258E8 0x020258E8 thumb
 *   func_0202590C 0x0202590C thumb
 *   func_021EE224 0x021EE224 thumb
 */

extern void func_020258E8(void *o, short *x, short *y);
extern void func_0202590C(void *o, short x, short y);
extern void func_021EE224(char *p, int i, int v);

void func_021EE26C(char *p, int d)
{
    unsigned i;
    short x;
    short y;
    for (i = 7; i <= 8; i++) {
        char *e = p + i * 8;
        func_020258E8(*(void **)(e + 4), &x, &y);
        func_0202590C(*(void **)(e + 4), x + d, y);
        if (x + d == -0x94 || x + d == 0xDC)
            func_021EE224(p, i, 0);
    }
}
