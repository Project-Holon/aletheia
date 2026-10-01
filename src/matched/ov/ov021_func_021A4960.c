/*
 * function: func_021A4960
 * address:  0x021A4960
 * packet:   pkt_ov021_021A4960
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB140  0x021AB140  thumb  ov021
 *   func_021AB404  0x021AB404  thumb  ov021
 *   func_021AB410  0x021AB410  thumb  ov021
 *   func_021AB328  0x021AB328  thumb  ov021
 */

int func_021AB140(int a);
int func_021AB404(int a);
int func_021AB410(int a);
int func_021AB328(int a);

int func_021A4960(int a)
{
    if (func_021AB140(a) != 0 || func_021AB404(a) != 0 || func_021AB410(a) != 0 || func_021AB328(a) != 0)
        return 1;
    return 0;
}
