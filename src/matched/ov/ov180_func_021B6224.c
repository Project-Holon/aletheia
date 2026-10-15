/*
 * function: HALL_OF_FAME_SetupDisplay
 * address: 0x021B6224
 * packet: pkt_ov180_021B6224
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHallOfFameDisplayConfig 0x021B80D8 data a4
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct DispConfig {u32 a,b,c,d;};
extern const struct DispConfig gHallOfFameDisplayConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_LoadPlttEntry(u32,u32);
void HALL_OF_FAME_SetupDisplay(void) {struct DispConfig cfg; cfg=gHallOfFameDisplayConfig; BG_SYS_SetGraphicsMode(&cfg); BG_SYS_LoadPlttEntry(0,0); BG_SYS_LoadPlttEntry(4,0);}
