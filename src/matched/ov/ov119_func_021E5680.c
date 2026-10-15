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
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   gSubBgTemplate4 0x021E7EE4 data a4
 *   gSubBgTemplate5 0x021E7F04 data a4
 *   gSubBgTemplate7 0x021E7F64 data a4
 *   gSubBgTemplate6 0x021E7E04 data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;
extern const BgTemplate gSubBgTemplate4,gSubBgTemplate5,gSubBgTemplate7,gSubBgTemplate6;
extern void BG_SYS_InitBgLayer(u32,const BgTemplate *,u32);
extern void BG_SYS_Init(u32,u32,u32,u32),BG_SYS_SetTileEntry(u32,int,int,int,u8,u8,u8),BG_SYS_PushTile(u32);
void POKETRADE_2D_SetupSubBgs(char *p)
{
 BgTemplate a,b,c,d;
 a=gSubBgTemplate4;BG_SYS_InitBgLayer(4,&a,0);BG_SYS_SetTileEntry(4,0,0,0,32,24,17);
 b=gSubBgTemplate5;BG_SYS_InitBgLayer(5,&b,0);BG_SYS_Init(5,0,1,0);BG_SYS_SetTileEntry(5,0,0,0,32,24,17);BG_SYS_PushTile(5);
 c=gSubBgTemplate7;BG_SYS_InitBgLayer(7,&c,0);BG_SYS_SetTileEntry(7,0,0,0,64,24,17);BG_SYS_PushTile(7);
 d=gSubBgTemplate6;BG_SYS_InitBgLayer(6,&d,0);BG_SYS_Init(6,0,1,0);BG_SYS_SetTileEntry(6,0,0,0,32,24,17);BG_SYS_PushTile(6);
 p[0x11eb]=1;
}
