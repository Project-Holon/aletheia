/*
 * function: POKETRADE_2D_SetupSubBgs
 * address: 0x021E5680
 * packet: pkt_ov119_021E5680
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
 *   d_021E7EE4 0x021E7EE4 data a4
 *   d_021E7F04 0x021E7F04 data a4
 *   d_021E7F64 0x021E7F64 data a4
 *   d_021E7E04 0x021E7E04 data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;
extern const BgTemplate d_021E7EE4,d_021E7F04,d_021E7F64,d_021E7E04;
extern void func_0203FCA0(u32,const BgTemplate *,u32);
extern void func_02040C14(u32,u32,u32,u32),func_02041300(u32,int,int,int,u8,u8,u8),func_020409B4(u32);
void POKETRADE_2D_SetupSubBgs(char *p)
{
 BgTemplate a,b,c,d;
 a=d_021E7EE4;func_0203FCA0(4,&a,0);func_02041300(4,0,0,0,32,24,17);
 b=d_021E7F04;func_0203FCA0(5,&b,0);func_02040C14(5,0,1,0);func_02041300(5,0,0,0,32,24,17);func_020409B4(5);
 c=d_021E7F64;func_0203FCA0(7,&c,0);func_02041300(7,0,0,0,64,24,17);func_020409B4(7);
 d=d_021E7E04;func_0203FCA0(6,&d,0);func_02040C14(6,0,1,0);func_02041300(6,0,0,0,32,24,17);func_020409B4(6);
 p[0x11eb]=1;
}
