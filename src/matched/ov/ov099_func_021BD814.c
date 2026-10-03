/*
 * function: func_021BD814
 * address: 0x021BD814
 * packet: pkt_ov099_021BD814
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0203D7B0(int);
extern void func_0203D7BC(int);
int func_021BD814(char *p, int v)
{
    int zero = 0;
    func_0203D7B0(zero);
    func_0203D7BC(zero);
    *(u32 *)(p + 0x1e0) = zero;
    *(u32 *)(p + 0x1cc) = 0x91;
    return v;
}
