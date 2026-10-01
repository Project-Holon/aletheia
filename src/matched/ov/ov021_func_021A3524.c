/*
 * function: func_021A3524
 * address:  0x021A3524
 * packet:   pkt_ov021_021A3524
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB310  0x021AB310  thumb  ov021
 */

int func_021A3098(int a);
int func_021AB11C(int b);
int func_021AB0F0(int c);
int func_021AB310(int x);

int func_021A3524(int a, int b, int c)
{
    int r = func_021A3098(a);

    if (func_021AB11C(b) != 0 || r != 2)
        return 0;
    return func_021AB310(func_021AB0F0(c));
}
