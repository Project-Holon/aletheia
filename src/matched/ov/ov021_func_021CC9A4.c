/*
 * function: PARTY_SELECT_LIST_FreeMonIconResources
 * address:  0x021CC9A4
 * packet:   pkt_ov021_021CC9A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 */
#include "../include/Obj06097.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0201AA18(void *p);
extern void CLACT_ReleaseCharacter(u32 v);
extern void CLACT_ReleaseCellAnim(u32 v);
extern void CLACT_ReleasePalette(u32 v);

void PARTY_SELECT_LIST_FreeMonIconResources(u8 *p)
{
    int i;
    int n;

    if (((struct Obj06097 *)p)->f8) {
        n = func_0201AA18(((struct Obj06097 *)p)->f8);
        for (i = 0; i < n; i++)
            CLACT_ReleaseCharacter(*(u16 *)(p + i * 2 + 0x8c));
    }
    n = func_0201AA18(((struct Obj06097 *)p)->f4);
    for (i = 0; i < n; i++)
        CLACT_ReleaseCharacter(*(u16 *)(p + i * 2 + 0x80));
    CLACT_ReleaseCellAnim(((struct Obj06097 *)p)->f7E);
    CLACT_ReleasePalette(((struct Obj06097 *)p)->f7C);
}
