/*
 * function: func_021B6704
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
 * split: scratch tu --suggest-split confirms no viable partition; ARM9 belongs to Ilias.
 * note 2026-10-05: the blocker leaf is now filed as src/matched/arm9/func_0204EA4C.c (EXACT, the
 * snippet above, verified). This file stays MATCH until the integrator regenerates the manifest
 * so the witness resolves; then it is EXACT with no change to the C.
 *
 * symbols:
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_0204EA38 0x0204EA38 arm
 *   func_021B6844 0x021B6844 thumb ov180
 *   func_02050BE8 0x02050BE8 arm
 *   func_02047970 0x02047970 arm
 *   func_0204EA4C 0x0204EA4C arm
 */
extern void func_02047964(void); extern void func_020479D8(void); extern unsigned func_0204EA38(void);
extern void func_021B6844(char *,void *,int); extern void func_02050BE8(void); extern void func_02047970(void); extern void func_0204EA4C(void);
void func_021B6704(char *p) {
 func_02047964(); func_020479D8();
 if(func_0204EA38()==1) { func_021B6844(p,*(void **)(p+0x28),1); func_021B6844(p,*(void **)(p+0x2C),1); }
 else { func_021B6844(p,*(void **)(p+0x28),0); func_021B6844(p,*(void **)(p+0x2C),0); }
 func_02050BE8(); func_02047970(); func_0204EA4C();
}
