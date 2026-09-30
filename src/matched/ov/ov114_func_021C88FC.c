/*
 * function: func_021C88FC
 * address: 0x021C88FC
 * packet: pkt_ov114_021C88FC
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 * d_021D3D28 0x021D3D28 data a4
 * d_021D3D2C 0x021D3D2C data a4
 * d_021CF538 0x021CF538 data a4
 * d_021CF5F4 0x021CF5F4 data a4
 * d_021D3D40 0x021D3D40 data a4
 * func_021C9EE4 0x021C9EE4 arm ov114
 * func_021CA470 0x021CA470 arm ov114
 * func_021CA1B4 0x021CA1B4 arm ov114
 */
extern unsigned int *d_021D3D28;
extern unsigned int d_021D3D2C[], d_021CF538[], d_021CF5F4[], d_021D3D40[];
extern void func_021C9EE4(void *, void *);
extern int func_021CA470(void *, unsigned int, void *, unsigned int, unsigned int);
extern void func_021CA1B4(void);
void func_021C88FC(void)
{
    func_021C9EE4(d_021D3D28, d_021CF538);
    if (func_021CA470(d_021CF5F4, d_021D3D2C[2], d_021D3D40, 0x1b0, 0) == 0) {
        d_021D3D2C[0] = 10;
        return;
    }
    d_021D3D2C[0] = 0x18;
    d_021D3D2C[1] = -13;
    func_021CA1B4();
}
