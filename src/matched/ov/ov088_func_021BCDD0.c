/*
 * function: func_021BCDD0
 * address:  0x021BCDD0
 * packet:   pkt_ov088_021BCDD0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 *
 * symbols:
 *   func_021BD188  0x021BD188  thumb  ov088
 *   func_021BD1EC  0x021BD1EC  thumb  ov088
 */

extern int func_021BD188(void *);
extern void func_021BD1EC(void *);

void func_021BCDD0(void *p, int *st)
{
    if (func_021BD188(p) == 0) {
        func_021BD1EC(p);
        *st = 3;
    }
}
