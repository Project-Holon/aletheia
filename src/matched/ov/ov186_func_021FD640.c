/*
 * function: func_021FD640
 * address: 0x021FD640
 * packet: pkt_ov186_021FD640
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_021FC734 0x021FC734 thumb ov186
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020307B0 0x020307B0 arm
 *   func_020409B4 0x020409B4 arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void PMS_DRAW_Delete(struct Obj *p);
extern void func_021FBDA4(int a, unsigned mode);
extern u32 func_020307B0(void *p);
extern void func_020409B4(u32 index);
void func_021FD640(int *p)
{
    int i;
    if(p[10]) {CLACT_DeleteActor((struct Obj *)p[10]);CLACT_ReleasePalette(p[14]);CLACT_ReleaseCharacter(p[15]);CLACT_ReleaseCellAnim(p[16]);}
    if(p[9]) {CLACT_DeleteActor((struct Obj *)p[9]);CLACT_ReleasePalette(p[11]);CLACT_ReleaseCharacter(p[12]);CLACT_ReleaseCellAnim(p[13]);}
    for(i=0;i<7;i++) if(p[i]) {func_021FC734((void *)p[i]);p[i]=0;}
    PMS_DRAW_Delete((struct Obj *)p[8]);func_021FBDA4(p[7],8);func_020307B0(p);func_020409B4(1);
}
