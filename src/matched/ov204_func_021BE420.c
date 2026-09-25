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
 *   func_02006148 0x02006148 thumb
 *   func_020061F8 0x020061F8 thumb
 */

extern void func_02006148(int);
extern void func_020061F8(void);

int func_021BE420(int a, int b, int *p)
{
    func_02006148(*p);
    func_020061F8();
    return 1;
}
