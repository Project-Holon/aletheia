/*
 * function: BSUBWAY_RECORD_LIST_DeleteActors
 * address:  0x021B9BF0
 * packet:   pkt_ov069_021B9BF0
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 */
#include "../include/Obj01132.h"

typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);

void BSUBWAY_RECORD_LIST_DeleteActors(char *p)
{
    CLACT_ReleaseCharacter(((struct Obj01132 *)p)->f144);
    CLACT_ReleasePalette(((struct Obj01132 *)p)->f140);
    CLACT_ReleaseCellAnim(((struct Obj01132 *)p)->f148);
    CLACT_ReleaseCharacter(((struct Obj01132 *)p)->f138);
    CLACT_ReleasePalette(((struct Obj01132 *)p)->f134);
    CLACT_ReleaseCellAnim(((struct Obj01132 *)p)->f13C);
    CLACT_DeleteUnit((struct Bank *)(((struct Obj01132 *)p)->f120));
    CLACT_DeleteUnit((struct Bank *)(((struct Obj01132 *)p)->f11C));
    CLACT_ExitSystem();
}
