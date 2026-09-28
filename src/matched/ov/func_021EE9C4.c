/*
 * function: func_021EE9C4
 * address:  0x021EE9C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE754  0x021EE754  thumb  ov170
 *   func_021EEF74  0x021EEF74  thumb  ov170
 *   func_021DC9B4  0x021DC9B4  thumb  ov170
 *
 * Twin of func_021EE7C4 with the same selector and target word.
 */


extern void func_021EE754(char *, int, int);
extern void func_021EEF74(int, int, int);
extern void func_021DC9B4(int, int);
void func_021EE9C4(char *p, int a, int b)
{
    func_021EE754(p, a, b);
    func_021EEF74(*(int *)(p + 0x2c), a, b);
    func_021DC9B4(*(int *)(p + 0x2c), 0x021E066D);
    *(int *)(*(int *)(p + 0x2c) + 0xA168) = a;
}
