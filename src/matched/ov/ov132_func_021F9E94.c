/*
 * function: STA_ACT_EFFECT_Delete
 * address: 0x021F9E94
 * packet: pkt_ov132_021F9E94
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the load uses p+index*0x4848+4, while the outgoing pointer uses p+4+index*0x4848; the latter keeps p+4 hoisted in r6. Using the load's grouping for both gave 49 concrete byte differences.
 * symbols:
 *   STA_ACT_EFFECT_KillSystem 0x021F9F58 thumb ov132
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void STA_ACT_EFFECT_KillSystem(u8 *,u8 *);
extern void PARTICLE_ExitManager(void);
extern u32 func_020307B0(void *p);
void STA_ACT_EFFECT_Delete(u8 *p) { u8 i; for(i=0;i<8;i++) { if(*(u32 *)(p+i*0x4848+4)==1) STA_ACT_EFFECT_KillSystem(p,p+4+i*0x4848); } PARTICLE_ExitManager(); func_020307B0(p); }
