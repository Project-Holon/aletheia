/*
 * function: IRC_RHYTHM_ExitActorSystem
 * address: 0x021B7CA4
 * packet: pkt_ov104_021B7CA4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 102 code bytes then two zero alignment bytes before 021B7D0C.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *,int,int);
void IRC_RHYTHM_ExitActorSystem(void **p) { int i; for(i=0;i<35;i++) if(p[i+10]) CLACT_DeleteActor(p[i+10]); CLACT_ReleasePalette((u32)p[1]); CLACT_ReleaseCharacter((u32)p[2]); CLACT_ReleaseCellAnim((u32)p[3]); CLACT_ReleasePalette((u32)p[4]); CLACT_ReleaseCharacter((u32)p[5]); CLACT_ReleaseCellAnim((u32)p[6]); CLACT_ReleasePalette((u32)p[7]); CLACT_ReleaseCharacter((u32)p[8]); CLACT_ReleaseCellAnim((u32)p[9]); CLACT_DeleteUnit(p[0]); CLACT_ExitSystem(); MI_CpuFill8(p,0,0xb4); }
