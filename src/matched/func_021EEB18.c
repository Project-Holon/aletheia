/*
 * function: func_021EEB18
 * address:  0x021EEB18
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

extern void func_021EEF74(void *);
extern void func_021DC9B4(void *, void *);
extern void func_021E066C(void);

void func_021EEB18(char *p)
{
    func_021EEF74(*(void **)(p + 0x2c));
    func_021DC9B4(*(void **)(p + 0x2c), (void *)&func_021E066C);
}

