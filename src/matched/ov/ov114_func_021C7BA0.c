/*
 * function: func_021C7BA0
 * address: 0x021C7BA0
 * packet: pkt_ov114_021C7BA0
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 * d_021D3D2C 0x021D3D2C data a4
 * d_021D3D28 0x021D3D28 data a4
 */
extern unsigned int d_021D3D2C[], d_021D3D28;
void func_021C7BA0(unsigned int a, unsigned int b, unsigned int c, int d)
{
    d_021D3D2C[0] = 1;
    d_021D3D2C[1] = 0;
    d_021D3D2C[2] = a;
    d_021D3D2C[3] = b;
    d_021D3D2C[4] = c;
    switch (d) {
    case 0: d_021D3D28 = 0; break;
    case 1: d_021D3D28 = 1; break;
    case 2: d_021D3D28 = 2; break;
    default: d_021D3D28 = 1; break;
    }
}
