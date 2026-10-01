/*
 * function: func_021A3504
 * address:  0x021A3504
 * packet:   pkt_ov021_021A3504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021AB5AC  0x021AB5AC  thumb  ov021
 */

int func_021A3098(int a);
int func_021AB5AC(int b, int c);

int func_021A3504(int a, int b, int c)
{
    int r = func_021A3098(a);

    if (r == 2 || r == 3)
        return 0;
    return func_021AB5AC(b, c);
}
