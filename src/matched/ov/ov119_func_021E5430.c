/*
 * function: POKETRADE_2D_SetupMainBgs
 * address: 0x021E5430
 * packet: pkt_ov119_021E5430
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204044C 0x0204044C arm
 *   func_02040588 0x02040588 arm
 *   func_0204047C 0x0204047C arm
 *   d_021E7F24 0x021E7F24 data a4
 *   d_021E7E84 0x021E7E84 data a4
 *   d_021E7EA4 0x021E7EA4 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;
extern const BgTemplate d_021E7F24,d_021E7E84,d_021E7EA4;
extern void func_0203FCA0(u32,const BgTemplate *,u32);
extern void func_02040C14(u32,u32,u32,u32);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void func_020409B4(u32);
extern void func_0204044C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204047C(int,u16);
void POKETRADE_2D_SetupMainBgs(void *a0)
{
 BgTemplate a,b,c;
 a=d_021E7F24;
 func_0203FCA0(3,&a,0);func_02040C14(3,0,1,0);
 func_02041300(3,0,0,0,32,24,17);func_020409B4(3);
 b=d_021E7E84;
 func_0203FCA0(2,&b,0);func_02040C14(2,0,1,0);
 func_02041300(2,0,0,0,32,24,17);func_020409B4(2);
 c=d_021E7EA4;
 func_0203FCA0(1,&c,0);
 func_02041300(1,0,0,0,32,24,17);func_020409B4(1);
 func_0204044C(0);func_02040588(0,1);func_0204047C(0,0);
}
