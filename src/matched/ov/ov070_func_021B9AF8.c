/*
 * function: ITEMMENU_FreeGraphics
 * address:  0x021B9AF8
 * packet:   pkt_ov070_021B9AF8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   BMP_Delete  0x020437AC  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 */
#include "../include/Obj01682.h"

struct Bank;
struct Descriptor;
struct Obj;
struct Obj020437AC;
extern unsigned int func_020452E8(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);

void ITEMMENU_FreeGraphics(char *p)
{
    int i;
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f73C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f74C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f744));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f734));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f754));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f76C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f774));
    CLACT_DeleteActor((struct Obj *)(((struct Obj01682 *)p)->f6A8));
    if (((struct Obj01682 *)p)->f6A0 != 0) {
        CLACT_DeleteActor((struct Obj *)(((struct Obj01682 *)p)->f6A0));
        CLACT_ReleaseCharacter(((struct Obj01682 *)p)->f54C);
        CLACT_ReleasePalette(((struct Obj01682 *)p)->f548);
    }
    CLACT_ReleaseCellAnim(((struct Obj01682 *)p)->f550);
    for (i = 0; i < 8; i++) {
        BMP_Delete((struct Obj020437AC *)(*(int *)(p + i * 4 + 0x614)));
    }
    CLACT_DeleteUnit((struct Bank *)(((struct Obj01682 *)p)->f69C));
    CLACT_ExitSystem();
}
