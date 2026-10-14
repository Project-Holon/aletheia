/*
 * function: GURU2_MAIN_SetupBg
 * address: 0x021DFB60
 * packet: pkt_ov137_021DFB60
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021DFB6E reads and 021DFB76 writes hardware register 04000304
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   gGuru2GameDispConfig 0x021E202C data a4
 *   gGuru2GameBg1Template 0x021E204C data a4
 *   gGuru2GameBg2Template 0x021E206C data a4
 *   gGuru2GameBg3Template 0x021E208C data a4
 *   gGuru2GameBg6Template 0x021E20AC data a4
 *   gGuru2GameBg7Template 0x021E20CC data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct DispConfig {u32 w[4];};
struct BgTemplate {u32 w[8];};
extern const struct DispConfig gGuru2GameDispConfig;
extern const struct BgTemplate gGuru2GameBg1Template,gGuru2GameBg2Template,gGuru2GameBg3Template,gGuru2GameBg6Template,gGuru2GameBg7Template;
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
typedef unsigned char  u8;
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
void GURU2_MAIN_SetupBg(char *a0)
{
    func_0203F8F4(114);
    *(volatile u16 *)0x04000304 |= 0x8000;
    {struct DispConfig t=gGuru2GameDispConfig; func_0203FC28(&t);}
    {struct BgTemplate t=gGuru2GameBg1Template; func_0203FCA0(1,&t,0); func_020414EC(1); func_02040B94(1,32,0,114);}
    {struct BgTemplate t=gGuru2GameBg2Template; func_0203FCA0(2,&t,0); func_020414EC(2);}
    {struct BgTemplate t=gGuru2GameBg3Template; func_0203FCA0(3,&t,0); func_020414EC(3);}
    {struct BgTemplate t=gGuru2GameBg6Template; func_0203FCA0(6,&t,0); func_020414EC(6);}
    {struct BgTemplate t=gGuru2GameBg7Template; func_0203FCA0(7,&t,0); func_020414EC(7);}
}
