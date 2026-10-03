/*
 * function: func_022104EC
 * address: 0x022104EC
 * packet: pkt_ov198_022104EC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FC6C 0x0203FC6C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   sub_02041B6C 0x02041B6C arm
 *   sub_02043598 0x02043598 arm
 *   d_02212144 0x02212144 data a4
 *   d_02212174 0x02212174 data a4
 *   d_022121B4 0x022121B4 data a4
 *   d_02212154 0x02212154 data a4
 *   d_02212194 0x02212194 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct BgVramReq {u32 unk00,unk04,unk08,unk0c;};
struct BgTemplate {
    u32 unk00,unk04,bufSize,unk0c;
    u8 unk10,unk11,unk12,unk13;
    u32 unk14;
    u8 unk18,unk19,unk1a,unk1b;
    u32 unk1c;
};
extern const struct BgVramReq d_02212144;
extern const struct BgTemplate d_02212174,d_022121B4,d_02212154,d_02212194;
extern void func_0203FC6C(const struct BgVramReq *,u32);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040B94(u32,u32,u32,u32);
extern void sub_02041B6C(u32);
extern void sub_02043598(u32,u32);
void func_022104EC(u8 *p)
{
    struct BgVramReq req=d_02212144;
    struct BgTemplate cfg7,cfg6,cfg5,cfg4;
    func_0203FC6C(&req,1);
    cfg7=d_02212174;
    func_0203FCA0(7,&cfg7,0);
    cfg6=d_022121B4;
    func_0203FCA0(6,&cfg6,0);
    cfg5=d_02212154;
    func_0203FCA0(5,&cfg5,0);
    func_020414EC(5);
    cfg4=d_02212194;
    func_0203FCA0(4,&cfg4,0);
    func_020414EC(4);
    func_02040B94(5,32,0,*(u16 *)(*(u8 **)p+0x10));
    func_02040B94(4,32,0,*(u16 *)(*(u8 **)p+0x10));
    sub_02041B6C(5);
    sub_02041B6C(4);
    sub_02043598(15,1);
}
