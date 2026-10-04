/*
 * function: func_021C96CC
 * address: 0x021C96CC
 * packet: pkt_ov114_021C96CC
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D3EFC 0x021D3EFC data a4
 *   d_021D4084 0x021D4084 data a4
 *   d_021CF6D4 0x021CF6D4 data a4
 *   d_021CF770 0x021CF770 data a4
 *   d_021D4098 0x021D4098 data a4
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 */
extern void *d_021D3EFC;
extern unsigned d_021D4084[], d_021CF6D4[], d_021CF770[], d_021D4098[];
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
void func_021C96CC(void)
{
    func_021C9EE4((int)d_021D3EFC, (char *)d_021CF6D4);
    if (func_021CA470(d_021CF770, d_021D4084[2], d_021D4098, 0, 0) == 0) {
        d_021D4084[0] = 8;
        return;
    }
    d_021D4084[0] = 12;
    d_021D4084[1] = -5;
    func_021CA1B4();
}
