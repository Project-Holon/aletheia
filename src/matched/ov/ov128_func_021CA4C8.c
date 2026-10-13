/*
 * function: func_021CA4C8
 * address:  0x021CA4C8
 * packet:   pkt_021CA4C8
 * region:   ov128
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */

typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void func_021CA4C8(int *p)
{
    CLACT_ReleaseCharacter(p[95]);
    CLACT_ReleasePalette(p[96]);
    CLACT_ReleaseCellAnim(p[97]);
    CLACT_DeleteActor((struct Obj *)p[94]);
}
