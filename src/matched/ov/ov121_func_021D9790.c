/*
 * function: MYSTERY_GRAPHIC_StopRender
 * address: 0x021D9790
 * packet: pkt_ov121_021D9790
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   MYSTERY_GRAPHIC_ExitCamera 0x021D9960 thumb ov121
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   d_021DF598 0x021DF598 data a4
 */
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void PARTICLE_ExitManager(void);
extern void MYSTERY_GRAPHIC_ExitCamera(char *p);
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern const unsigned d_021DF598[];
void MYSTERY_GRAPHIC_StopRender(char *p) { func_02040588(0,0);PARTICLE_ExitManager();MYSTERY_GRAPHIC_ExitCamera(p+12);BG_SYS_SetGraphicsMode((struct DispConfig *)d_021DF598); }
