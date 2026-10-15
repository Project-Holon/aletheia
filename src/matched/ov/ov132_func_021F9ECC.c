/*
 * function: STA_ACT_EFFECT_Update
 * address: 0x021F9ECC
 * packet: pkt_ov132_021F9ECC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_UpdateAllSystems 0x02051574 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int PARTICLE_UpdateAllSystems(void);
int STA_ACT_EFFECT_Update(u8 *a0) { return PARTICLE_UpdateAllSystems(); }
