/*
 * function: STA_ACT_EFFECT_Draw
 * address: 0x021F9ED4
 * packet: pkt_ov132_021F9ED4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_DrawAllSystems 0x02051534 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int PARTICLE_DrawAllSystems(void);
int STA_ACT_EFFECT_Draw(u8 *a0) { return PARTICLE_DrawAllSystems(); }
