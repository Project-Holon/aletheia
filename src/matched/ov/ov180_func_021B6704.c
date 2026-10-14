/*
 * function: HALL_OF_FAME_DrawParticles
 * address: 0x021B6704
 * packet: pkt_ov180_021B6704
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 func_0204EA4C lacks an external attested witness; scratch one EXACT, 24 bytes.
 *   symbols: g_02146A80 0x02146A80 data a4
 *   extern char *g_02146A80;
 *   void func_0204EA4C(void) { *(int *)(g_02146A80+8)=1; }
 * split: scratch tu --suggest-split confirms no viable partition; ARM9 belongs to the integrator.
 * note 2026-10-05: the blocker leaf is now filed as src/matched/arm9/func_0204EA4C.c (EXACT, the
 * snippet above, verified). This file stays MATCH until the integrator regenerates the manifest
 * so the witness resolves; then it is EXACT with no change to the C.
 *
 * symbols:
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   func_0204EA38 0x0204EA38 arm
 *   HALL_OF_FAME_SetParticleCamera 0x021B6844 thumb ov180
 *   PARTICLE_Main 0x02050BE8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   func_0204EA4C 0x0204EA4C arm
 */
extern void G3D_SYSTEM_DrawStart(void); extern void G3D_SYSTEM_ApplyLookAt(void); extern unsigned func_0204EA38(void);
extern void HALL_OF_FAME_SetParticleCamera(char *,void *,int); extern void PARTICLE_Main(void); extern void G3D_SYSTEM_DrawEnd(void); extern void func_0204EA4C(void);
void HALL_OF_FAME_DrawParticles(char *p) {
 G3D_SYSTEM_DrawStart(); G3D_SYSTEM_ApplyLookAt();
 if(func_0204EA38()==1) { HALL_OF_FAME_SetParticleCamera(p,*(void **)(p+0x28),1); HALL_OF_FAME_SetParticleCamera(p,*(void **)(p+0x2C),1); }
 else { HALL_OF_FAME_SetParticleCamera(p,*(void **)(p+0x28),0); HALL_OF_FAME_SetParticleCamera(p,*(void **)(p+0x2C),0); }
 PARTICLE_Main(); G3D_SYSTEM_DrawEnd(); func_0204EA4C();
}
