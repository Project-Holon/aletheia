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
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   gMainBgTemplateC 0x021E7F24 data a4
 *   gMainBgTemplateB 0x021E7E84 data a4
 *   gMainBgTemplateA 0x021E7EA4 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;
extern const BgTemplate gMainBgTemplateC,gMainBgTemplateB,gMainBgTemplateA;
extern void BG_SYS_InitBgLayer(u32,const BgTemplate *,u32);
extern void BG_SYS_Init(u32,u32,u32,u32);
extern void BG_SYS_SetTileEntry(u32,int,int,int,u8,u8,u8);
extern void func_020409B4(u32);
extern void BG_SYS_SetLowBit(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetVisibleLayer(int,u16);
void POKETRADE_2D_SetupMainBgs(void *a0)
{
 BgTemplate a,b,c;
 a=gMainBgTemplateC;
 BG_SYS_InitBgLayer(3,&a,0);BG_SYS_Init(3,0,1,0);
 BG_SYS_SetTileEntry(3,0,0,0,32,24,17);func_020409B4(3);
 b=gMainBgTemplateB;
 BG_SYS_InitBgLayer(2,&b,0);BG_SYS_Init(2,0,1,0);
 BG_SYS_SetTileEntry(2,0,0,0,32,24,17);func_020409B4(2);
 c=gMainBgTemplateA;
 BG_SYS_InitBgLayer(1,&c,0);
 BG_SYS_SetTileEntry(1,0,0,0,32,24,17);func_020409B4(1);
 BG_SYS_SetLowBit(0);func_02040588(0,1);BG_SYS_SetVisibleLayer(0,0);
}
