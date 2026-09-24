/*
 * function: func_021BD07C
 * address:  0x021BD07C
 * packet:   pkt_021BD07C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 *
 * Calls the ARM9 functions at 0x0204B1CC and 0x0204A5AC, then 0x02082BCC(p, 0, 4).
 */

extern void func_0204B1CC(int);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *, int, int);

void func_021BD07C(char *p)
{
    func_0204B1CC(*(int *)p);
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}
