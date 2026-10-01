/*
 * function: func_021FD854
 * address: 0x021FD854
 * packet: pkt_ov186_021FD854
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Blocker leaf for ov183 021E1D48 and 021E20F8, parent cleared.
 * symbols:
 *   func_021FD71C 0x021FD71C thumb ov186
 */
extern void func_021FD71C(int);
void func_021FD854(char *p)
{
    func_021FD71C(*(int *)(p+0x10));
}
