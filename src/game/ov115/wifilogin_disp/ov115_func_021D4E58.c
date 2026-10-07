/*
 * function: func_021D4E58
 * address: 0x021D4E58
 * packet: pkt_ov115_021D4E58
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initialized wrapping base+1 temporary before the first commit, then layer assignments before the following template copies, preserves the four table/call sequences and the original register webs.
 * ABI: first argument unused; full32 base is incremented with wrapping arithmetic and passed untruncated to40C14, while template/toggle/commit/rectangle calls explicitly truncate8 in the original.
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   sub_02040588 0x02040588 arm
 *   sub_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   data_021D6364 0x021D6364 data a4
 *   data_021D64C4 0x021D64C4 data a4
 *   data_021D64A4 0x021D64A4 data a4
 *   data_021D6484 0x021D6484 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct BgTemplate {
    u32 unk_00,unk_04,bufSize,unk_0c;
    u8 unk_10,unk_11,unk_12,unk_13;
    u32 unk_14;
    u8 unk_18,unk_19,unk_1a,unk_1b;
    u32 unk_1c;
};
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void sub_020409B4(u8);
extern void func_02040C14(u32,u32,u32,u32);
extern void func_02041300(u8,int,int,int,u8,u8,u8);
extern const struct BgTemplate data_021D6364,data_021D64C4,data_021D64A4,data_021D6484;
void func_021D4E58(u32 unused,unsigned long base)
{
    struct BgTemplate a,b,c,d;
    unsigned long layer1,layer2,layer3;
    u32 tmp;
    a=data_021D6364;
    func_0203FCA0((u8)base,&a,0);
    sub_02040588(base,1);
    tmp=(u32)base+1;
    sub_020409B4(base);
    layer1=tmp;
    b=data_021D64C4;
    func_0203FCA0((u8)layer1,&b,0);
    sub_02040588(layer1,1);
    func_02040C14(layer1,0,1,0);
    func_02041300(layer1,0,0,0,32,32,17);
    sub_020409B4(layer1);
    layer2=(u32)base+2;
    c=data_021D64A4;
    func_0203FCA0((u8)layer2,&c,0);
    sub_02040588(layer2,1);
    func_02041300(layer2,0,0,0,32,32,17);
    sub_020409B4(layer2);
    layer3=(u32)base+3;
    d=data_021D6484;
    func_0203FCA0((u8)layer3,&d,0);
    sub_02040588(layer3,1);
    func_02040C14(layer3,0,1,0);
    func_02041300(layer3,0,0,0,32,32,17);
    sub_020409B4(layer3);
}
