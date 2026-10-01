/*
 * function: func_021A55DC
 * address:  0x021A55DC
 * packet:   pkt_ov021_021A55DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB404  0x021AB404  thumb  ov021
 *   func_021AB410  0x021AB410  thumb  ov021
 */

int func_021AB404(int a);
int func_021AB410(int a);

int func_021A55DC(int a)
{
    if (func_021AB404(a) == 1 || func_021AB410(a) == 1)
        return 1;
    return 0;
}
