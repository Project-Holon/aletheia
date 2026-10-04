/*
 * function: func_021EE43C
 * address:  0x021EE43C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEF74  0x021EEF74  thumb  ov170
 *   func_021DC9B4  0x021DC9B4  thumb  ov170
 *   func_021E066C  0x021E066C  thumb  ov170
 *
 * Release the child at +0x2c and reset its field +0x5c to the handler.
 */

extern void func_021EEF74(char *q, int a, int b);
extern void func_021DC9B4(char *p, int v);
extern int func_021E066C(char *p);

void func_021EE43C(char *p, int a, int b)
{
    func_021EEF74(*(char **)(p + 0x2c), a, b);
    func_021DC9B4(*(void **)(p + 0x2c), (int)((void *)&func_021E066C));
}

