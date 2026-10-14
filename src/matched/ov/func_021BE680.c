/*
 * function: ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources
 * address:  0x021BE680
 * packet:   pkt_021BE4DC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKND_TBAR_DeleteButtonList 0x021BD208  thumb  ov208
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9

 * Frees the three allocations at +0x5C..+0x64 and clears +0x30.
 */
#include "../include/Obj01081.h"


struct Ov208Mgr;
extern void ZKND_TBAR_DeleteButtonList(struct Ov208Mgr *m);
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);

void ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources(char *p)
{
    if (*(int *)&((struct Obj01081 *)p)->f30 != 0) {
        ZKND_TBAR_DeleteButtonList((struct Ov208Mgr *)(*(int *)&((struct Obj01081 *)p)->f30));
        CLACT_ReleasePalette(((struct Obj01081 *)p)->f5C);
        CLACT_ReleaseCharacter(((struct Obj01081 *)p)->f60);
        CLACT_ReleaseCellAnim(((struct Obj01081 *)p)->f64);
    }
    *(int *)&((struct Obj01081 *)p)->f30 = 0;
}

