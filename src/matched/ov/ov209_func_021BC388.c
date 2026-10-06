/*
 * function: func_021BC388
 * address: 0x021BC388
 * packet: pkt_ov209_021BC388
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   data_021BE804 0x021BE804 data a4
 *   data_021BE894 0x021BE894 data a4
 *   data_021BE874 0x021BE874 data a4
 *   data_021BE814 0x021BE814 data a4
 *   data_021BE8F4 0x021BE8F4 data a4
 *   data_021BE8B4 0x021BE8B4 data a4
 *   data_021BE854 0x021BE854 data a4
 *   data_021BE8D4 0x021BE8D4 data a4
 *   data_021BE834 0x021BE834 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Display {u32 w[4];};
struct BgTemplate {u32 w[8];};
extern const struct Display data_021BE804;
extern const struct BgTemplate data_021BE894,data_021BE874,data_021BE814,data_021BE8F4,data_021BE8B4,data_021BE854,data_021BE8D4,data_021BE834;
extern void func_0203F8F4(u16);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
typedef unsigned char  u8;
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041B6C(u32);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
void func_021BC388(void)
{
    struct Display display;
    struct BgTemplate b0,b1,b2,b3,b4,b5,b6,b7;
    func_0203F8F4(107);
    display=data_021BE804;func_0203FC28((struct DispConfig *)(&display));
    b0=data_021BE894;func_0203FCA0(0,&b0,0);
    func_020414EC(0);func_02040B94(0,32,0,107);func_02041B6C(0);
    b1=data_021BE874;func_0203FCA0(1,&b1,0);
    b2=data_021BE814;func_0203FCA0(2,&b2,0);
    func_020414EC(2);func_02041B6C(2);
    b3=data_021BE8F4;func_0203FCA0(3,&b3,0);
    b4=data_021BE8B4;func_0203FCA0(4,&b4,0);
    func_020414EC(4);func_02040B94(4,32,0,107);func_02041B6C(4);
    b5=data_021BE854;func_0203FCA0(5,&b5,0);
    b6=data_021BE8D4;func_0203FCA0(6,&b6,0);
    func_020414EC(6);func_02041B6C(6);
    b7=data_021BE834;func_0203FCA0(7,&b7,0);
    func_020434DC(15,1);func_02043598(15,1);
}
