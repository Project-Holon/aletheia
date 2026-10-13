/*
 * function: func_021BE420
 * address:  0x021BE420
 * packet:   pkt_021BE420
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   func_020061F8 0x020061F8 thumb
 */

extern int GFL_USE_GetSeSlot(unsigned int);
extern void func_020061F8(int);

int func_021BE420(int a, int b, int *p)
{
    func_020061F8(GFL_USE_GetSeSlot(*p));
    return 1;
}
