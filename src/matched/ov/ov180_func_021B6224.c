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
 *   func_0203FC28 0x0203FC28 arm
 *   func_02040EBC 0x02040EBC arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct DispConfig {u32 a,b,c,d;};
extern const struct DispConfig gHallOfFameDisplayConfig;
extern void func_0203FC28(struct DispConfig *);
extern void func_02040EBC(u32,u32);
void HALL_OF_FAME_SetupDisplay(void) {struct DispConfig cfg; cfg=gHallOfFameDisplayConfig; func_0203FC28(&cfg); func_02040EBC(0,0); func_02040EBC(4,0);}
