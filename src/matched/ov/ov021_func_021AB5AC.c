/*
 * function: func_021AB5AC
 * address:  0x021AB5AC
 * packet:   pkt_ov021_021AB5AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB0F8  0x021AB0F8  thumb
 *   func_021AB11C  0x021AB11C  thumb
 *   func_021AB2E8  0x021AB2E8  thumb
 */

extern unsigned short func_021AB0F0(unsigned long attr);
extern unsigned short func_021AB0F8(unsigned long attr);
extern int func_021AB11C(unsigned long attr);
extern int func_021AB2E8(int id);

int func_021AB5AC(unsigned long a, unsigned long b)
{
    unsigned short lo = func_021AB0F8(b);
    unsigned short hi = func_021AB0F0(b);

    if (func_021AB11C(a))
        return 0;
    if (((lo & 2) && !func_021AB11C(b)) || func_021AB2E8(hi))
        return 1;
    return 0;
}
