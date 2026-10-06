/*
 * function: func_021B64D0
 * address: 0x021B64D0
 * packet: pkt_ov173_021B64D0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040588 0x02040588 arm
 *   func_02040B94 0x02040B94 arm
 *   d_021B8280 0x021B8280 data a4
 *   d_021B82F0 0x021B82F0 data a4
 *   d_021B8330 0x021B8330 data a4
 *   d_021B8290 0x021B8290 data a4
 *   d_021B82B0 0x021B82B0 data a4
 *   d_021B82D0 0x021B82D0 data a4
 *   d_021B8310 0x021B8310 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct DispConfig {u32 unk_00,unk_04,unk_08,unk_0c;};
struct BgTemplate {u32 unk_00,unk_04,bufSize,unk_0c;u8 unk_10,unk_11,unk_12,unk_13;u32 unk_14;u8 unk_18,unk_19,unk_1a,unk_1b;u32 unk_1c;};
extern const struct DispConfig d_021B8280;
extern const struct BgTemplate d_021B82F0,d_021B8330,d_021B8290,d_021B82B0,d_021B82D0,d_021B8310;
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040588(u32,u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
void func_021B64D0(void)
{
    struct DispConfig cfg;
    struct BgTemplate a,b,c,d,e,f;
    func_0203F8F4(79);func_02045088(79);
    cfg=d_021B8280;func_0203FC28(&cfg);
    a=d_021B82F0;func_0203FCA0(2,&a,0);func_020414EC(2);
    b=d_021B8330;func_0203FCA0(3,&b,0);func_020414EC(3);
    c=d_021B8290;func_0203FCA0(4,&c,0);func_020414EC(4);
    d=d_021B82B0;func_0203FCA0(6,&d,0);func_020414EC(6);
    e=d_021B82D0;func_0203FCA0(5,&e,0);func_020414EC(5);
    f=d_021B8310;func_0203FCA0(7,&f,0);func_020414EC(7);
    func_02040588(2,1);func_02040588(3,1);func_02040588(4,1);
    func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    func_02040B94(2,32,0,79);func_02040B94(4,32,0,79);
    func_02040B94(5,32,0,79);func_02040B94(2,32,0,79);func_02040B94(4,32,0,79);
    *(u16 *)0x04000050=0;*(u16 *)0x04001050=0;
}
