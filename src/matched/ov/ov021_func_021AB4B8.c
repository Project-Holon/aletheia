/*
 * function: func_021AB4B8
 * address:  0x021AB4B8
 * packet:   pkt_ov021_021AB4B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB140  0x021AB140  thumb
 *   func_021AB404  0x021AB404  thumb
 *   func_021AB410  0x021AB410  thumb
 *   func_021AB328  0x021AB328  thumb
 */

extern int func_021AB140(int id);
extern int func_021AB404(int id);
extern int func_021AB410(int id);
extern int func_021AB328(int id);

int func_021AB4B8(int id)
{
    if (func_021AB140(id) || func_021AB404(id) || func_021AB410(id) || func_021AB328(id))
        return 1;
    return 0;
}
