/*
 * function: STARTMENU_DeleteActors
 * address:  0x021BB328
 * packet:   pkt_ov088_021BB328
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 */
#include "../include/Obj20817.h"

struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ExitSystem(void);

void STARTMENU_DeleteActors(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        CLACT_DeleteActor(*(void **)(p + 0x1c + i * 4));
    CLACT_DeleteUnit(((struct Obj20817 *)p)->f18);
    for (i = 0; i < 3; i++)
        CLACT_ReleaseCharacter((u32)(*(void **)(p + 0x34 + i * 4)));
    for (i = 0; i < 3; i++)
        CLACT_ReleasePalette((u32)(*(void **)(p + 0x40 + i * 4)));
    for (i = 0; i < 3; i++)
        CLACT_ReleaseCellAnim((u32)(*(void **)(p + 0x4c + i * 4)));
    CLACT_ExitSystem();
}
