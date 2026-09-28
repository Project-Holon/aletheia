/*
 * function: func_021ECB74
 * address:  0x021ECB74
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ECA6C  0x021ECA6C  thumb  ov170
 *
 * One range call with the selector pair fixed.
 */



extern void func_021ECA6C(char *, int, int, int, int);
void func_021ECB74(char *a, int b)
{
    func_021ECA6C(a, 1, b, b + 1, 1);
}
