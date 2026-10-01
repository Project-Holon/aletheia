/*
 * function: func_021A8AFC
 * address:  0x021A8AFC
 * packet:   pkt_ov021_021A8AFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A92A4  0x021A92A4  thumb
 *   func_02040588  0x02040588  arm
 */

extern void func_021A92A4(int a, int b);
extern void func_02040588(int a, int b);

void func_021A8AFC(int a, int b)
{
    func_021A92A4(a, 4);
    if (b != 0) {
        func_02040588(4, 0);
    }
}
