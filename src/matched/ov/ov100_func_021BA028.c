/*
 * function: IRCBATTLEMATCH_SetupDisplay, IRCBATTLEMATCH_VBlankTask
 * unit: yes
 * address: 0x021BA028
 * packet: pkt_ov100_021BA028
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: includes the eight-byte Thumb forwarding follower 0x021BA1C8.
 * symbols:
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   gIrcBattleMatchVramBanks 0x021BB6F0 data a4
 *   gIrcBattleMatchDispConfig 0x021BB6B0 data a4
 *   gIrcBattleMatchBgTemplate0 0x021BB720 data a4
 *   gIrcBattleMatchBgTemplate1 0x021BB740 data a4
 *   gIrcBattleMatchBgTemplate4 0x021BB760 data a4
 *   gIrcBattleMatchBgTemplate5 0x021BB780 data a4
 *   gIrcBattleMatchBgTemplate6 0x021BB7A0 data a4
 *   gIrcBattleMatchBgTemplate7 0x021BB7C0 data a4
 */
typedef unsigned char u8;
struct BgTemplate { unsigned int words[8]; };
extern const unsigned int gIrcBattleMatchVramBanks[],gIrcBattleMatchDispConfig[];
extern const struct BgTemplate gIrcBattleMatchBgTemplate0,gIrcBattleMatchBgTemplate1,gIrcBattleMatchBgTemplate4,gIrcBattleMatchBgTemplate5,gIrcBattleMatchBgTemplate6,gIrcBattleMatchBgTemplate7;
typedef unsigned int   u32;
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetTileEntry(int,int,int,int,u8,u8,u8);
extern void BG_SYS_PushTile(u32 index);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
void IRCBATTLEMATCH_SetupDisplay(char *a0) {
 BG_SYS_SetVramBanks((const struct DispVram *)gIrcBattleMatchVramBanks);BG_SYS_SetGraphicsMode((struct DispConfig *)gIrcBattleMatchDispConfig);
 BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);
 {struct BgTemplate t=gIrcBattleMatchBgTemplate0;BG_SYS_InitBgLayer(0,&t,0);BG_SYS_SetTileEntry(0,0,0,0,32,32,17);BG_SYS_PushTile(0);}
 {struct BgTemplate t=gIrcBattleMatchBgTemplate1;BG_SYS_InitBgLayer(1,&t,0);BG_SYS_SetTileEntry(1,0,0,0,32,32,17);BG_SYS_PushTile(1);}
 {struct BgTemplate t=gIrcBattleMatchBgTemplate4;BG_SYS_InitBgLayer(4,&t,0);BG_SYS_SetTileEntry(4,0,0,0,32,32,17);}
 {struct BgTemplate t=gIrcBattleMatchBgTemplate5;BG_SYS_InitBgLayer(5,&t,0);BG_SYS_SetTileEntry(5,0,0,0,32,32,17);BG_SYS_PushTile(5);}
 {struct BgTemplate t=gIrcBattleMatchBgTemplate6;BG_SYS_InitBgLayer(6,&t,0);BG_SYS_Init(6,0,1,0);BG_SYS_SetTileEntry(6,0,0,0,32,32,17);BG_SYS_PushTile(6);}
 {struct BgTemplate t=gIrcBattleMatchBgTemplate7;BG_SYS_InitBgLayer(7,&t,0);BG_SYS_SetTileEntry(7,0,0,0,32,32,17);BG_SYS_PushTile(7);}
}
extern void CLACT_VBlankSystem(void);
void IRCBATTLEMATCH_VBlankTask(void) { CLACT_VBlankSystem(); }
