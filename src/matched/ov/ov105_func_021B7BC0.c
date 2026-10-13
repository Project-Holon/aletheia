/*
 * function: IRC_RESULT_ExitActorSystem
 * address: 0x021B7BC0
 * packet: pkt_ov105_021B7BC0
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes after the return, before 021B7C04.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *,int,int);
void IRC_RESULT_ExitActorSystem(void **p) {
 int i;
 for(i=0;i<38;i++) if(p[i+4]) CLACT_DeleteActor(p[i+4]);
 CLACT_ReleasePalette((u32)p[1]); CLACT_ReleaseCharacter((u32)p[2]); CLACT_ReleaseCellAnim((u32)p[3]);
 CLACT_DeleteUnit(p[0]); CLACT_ExitSystem(); MI_CpuFill8(p,0,0xa8);
}
