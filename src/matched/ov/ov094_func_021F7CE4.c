/*
 * function: func_021F7CE4
 * address:  0x021F7CE4
 * packet:   pkt_ov094_021F7CE4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs func_021F7A28 with code 0x23b, then func_021F8AE8 with 0.
 *
 * symbols:
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   func_021F8AE8 0x021F8AE8 thumb ov094
 */
extern void func_021F7A28(int, int);
extern void func_021F8AE8(int, int);

void func_021F7CE4(int a)
{
    func_021F7A28(a, 0x23b);
    func_021F8AE8(a, 0);
}
