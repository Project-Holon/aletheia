/*
 * function: func_021F64D0
 * address:  0x021F64D0
 * packet:   pkt_021F64D0
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F661C 0x021F661C thumb
 *   func_021F65B4 0x021F65B4 thumb
 */

extern void func_021F661C(void *);
extern void func_021F65B4(void *);

void func_021F64D0(char *a)
{
    func_021F661C(a + 4);
    func_021F65B4(a);
}