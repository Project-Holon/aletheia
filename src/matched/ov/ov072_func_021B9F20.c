/*
 * function: TOWNMAP_BackButtonFree
 * address: 0x021B9F20
 * packet: pkt_ov072_021B9F20
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void TOUCHBAR_Delete(unsigned char *);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void MI_CpuFill8(void *,int,int);
void TOWNMAP_BackButtonFree(unsigned *p) {
    TOUCHBAR_Delete((unsigned char *)p[3]);
    CLACT_DeleteActor((struct Obj *)p[5]); CLACT_ReleaseCellAnim(p[2]);
    CLACT_ReleaseCharacter(p[1]); CLACT_ReleasePalette(p[0]);
    MI_CpuFill8(p,0,32);
}
