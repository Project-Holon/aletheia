/*
 * function: func_021BAB38
 * address:  0x021BAB38
 * packet:   pkt_ov217_021BAB38
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C2A08  0x021C2A08  thumb  ov217
 */

extern void func_021C2A08(int);

void func_021BAB38(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        func_021C2A08(*(int *)(self + i * 4 + 0x38));
    }
}
