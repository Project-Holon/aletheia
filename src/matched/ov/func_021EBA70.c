/*
 * function: BOX2_SEQ_HideWindowObject
 * address:  0x021EBA70
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb  ov170
 *
 * Forward the i-th entry word with flag 0.
 */

extern void func_0201F7A8(void *, int);

void BOX2_SEQ_HideWindowObject(char *p, int i)
{
    func_0201F7A8(*(void **)(p + i * 8 + 0x94), 0);
}

