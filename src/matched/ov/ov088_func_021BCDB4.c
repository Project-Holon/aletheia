/*
 * function: func_021BCDB4
 * address:  0x021BCDB4
 * packet:   pkt_ov088_021BCDB4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_021BD118  0x021BD118  thumb  ov088
 */

extern int func_020221A4(void);
extern void func_021BD118(void *, int);

void func_021BCDB4(void *p, int *st)
{
    if (func_020221A4() == 1) {
        func_021BD118(p, 0);
        *st = 2;
    }
}
