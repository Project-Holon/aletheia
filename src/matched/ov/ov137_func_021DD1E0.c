/*
 * function: func_021DD1E0
 * address: 0x021DD1E0
 * packet: pkt_ov137_021DD1E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_0203FC28 0x0203FC28 arm
 * func_0203FCA0 0x0203FCA0 arm
 * func_020414EC 0x020414EC arm
 * func_02040B94 0x02040B94 arm
 * d_021E1B70 0x021E1B70 data a4
 * d_021E1BE0 0x021E1BE0 data a4
 * d_021E1B80 0x021E1B80 data a4
 * d_021E1BA0 0x021E1BA0 data a4
 * d_021E1BC0 0x021E1BC0 data a4
 * d_021E1C00 0x021E1C00 data a4
 */
typedef unsigned int u32;
struct DispConfig { u32 w[4]; };
struct BgTemplate { u32 w[8]; };
extern const struct DispConfig d_021E1B70;
extern const struct BgTemplate d_021E1BE0,d_021E1B80,d_021E1BA0,d_021E1BC0,d_021E1C00;
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040B94(u32,u32,u32,u32);
void func_021DD1E0(void)
{
    struct DispConfig d;
    struct BgTemplate a,b,c,e,f;
    d=d_021E1B70;
    func_0203FC28(&d);
    a=d_021E1BE0;
    func_0203FCA0(4,&a,0); func_020414EC(4);
    b=d_021E1B80;
    func_0203FCA0(5,&b,0); func_020414EC(5);
    c=d_021E1BA0;
    func_0203FCA0(6,&c,0); func_02040B94(4,32,0,114);
    e=d_021E1BC0;
    func_0203FCA0(0,&e,0); func_020414EC(0);
    f=d_021E1C00;
    func_0203FCA0(1,&f,0); func_02040B94(0,32,0,114);
}
