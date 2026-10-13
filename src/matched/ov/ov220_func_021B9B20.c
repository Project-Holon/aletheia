/*
 * function: func_021B9B20
 * address: 0x021B9B20
 * packet: pkt_ov220_021B9B20
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 66-byte body, then zero alignment at 021B9B62..021B9B64.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
typedef unsigned char u8;
typedef struct {unsigned a,b,c;} Row;
typedef struct {char pad0[24];u8 count;char pad19[3];Row rows[4];void *objects[4];} Context;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(unsigned),CLACT_ReleaseCharacter(unsigned),CLACT_ReleasePalette(unsigned);
void func_021B9B20(Context *p)
{
    u8 i;
    for(i=0;i<p->count;i++) {
        CLACT_DeleteActor(p->objects[i]);
        CLACT_ReleaseCellAnim(p->rows[i].c);
        CLACT_ReleaseCharacter(p->rows[i].a);
        if(i==0) CLACT_ReleasePalette(p->rows[i].b);
    }
}
