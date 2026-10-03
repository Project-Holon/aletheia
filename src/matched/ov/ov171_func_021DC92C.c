/*
 * function: func_021DC92C
 * address: 0x021DC92C
 * packet: pkt_ov171_021DC92C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021DEA50 0x021DEA50 data a4
 *   d_021DEAC0 0x021DEAC0 data a4
 *   d_021DEAA0 0x021DEAA0 data a4
 *   d_021DEB00 0x021DEB00 data a4
 *   d_021DEA60 0x021DEA60 data a4
 *   d_021DEA80 0x021DEA80 data a4
 *   d_021DEAE0 0x021DEAE0 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct DispConfig {u32 w[4];};
struct BgTemplate {u32 w[8];};
extern const struct DispConfig d_021DEA50;
extern const struct BgTemplate d_021DEAC0,d_021DEAA0,d_021DEB00,d_021DEA60,d_021DEA80,d_021DEAE0;
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
void func_021DC92C(void)
{
    struct DispConfig d;
    struct BgTemplate a,b,c,e,f,g;
    func_0203F8F4(140);
    d=d_021DEA50;func_0203FC28(&d);
    a=d_021DEAC0;func_0203FCA0(0,&a,0);
    b=d_021DEAA0;func_0203FCA0(1,&b,0);
    c=d_021DEB00;func_0203FCA0(2,&c,0);
    e=d_021DEA60;func_0203FCA0(3,&e,0);
    f=d_021DEA80;func_0203FCA0(4,&f,0);
    g=d_021DEAE0;func_0203FCA0(5,&g,0);
    func_020434DC(13,1);func_02043598(3,1);
}
