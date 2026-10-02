/*
 * function: func_021D5F4C
 * address: 0x021D5F4C
 * packet: pkt_ov123_021D5F4C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DA758 0x021DA758 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct BgTemplate {
    u32 unk00, unk04, bufSize, unk0c;
    u8 unk10, unk11, unk12, unk13;
    u32 unk14;
    u8 unk18, unk19, unk1a, unk1b;
    u32 unk1c;
};
extern const struct BgTemplate d_021DA758[7];
extern void func_0203FCA0(u32,struct BgTemplate *,u32);
extern void func_02040588(u32,u32);
extern void func_020409B4(u32);
extern void func_02040C14(u32,u32,u32,u32);
extern void func_02041300(u32,u32,u32,u32,u8,u8,u8);
void func_021D5F4C(u8 *p)
{
    struct BgTemplate b[7];
    b[6]=d_021DA758[0]; func_0203FCA0(0,&b[6],0); func_02040588(0,1); func_020409B4(0);
    b[5]=d_021DA758[1]; func_0203FCA0(1,&b[5],0); func_02040588(1,1); func_020409B4(1);
    b[4]=d_021DA758[2]; func_0203FCA0(3,&b[4],0); func_02040588(3,1); func_020409B4(3);
    b[3]=d_021DA758[3]; func_0203FCA0(4,&b[3],0); func_02040588(4,1); func_020409B4(4);
    b[2]=d_021DA758[4]; func_0203FCA0(5,&b[2],0);
    func_02040C14(5,0,1,0); func_02041300(5,0,0,0,32,32,17); func_02040588(5,1); func_020409B4(5);
    b[1]=d_021DA758[5]; func_0203FCA0(6,&b[1],0); func_02040588(6,1);
    func_02040C14(6,0,1,0); func_02041300(6,0,0,0,32,32,17); func_020409B4(6);
    b[0]=d_021DA758[6]; func_0203FCA0(7,&b[0],0); func_02040588(7,1); func_020409B4(7);
}
