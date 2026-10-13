/*
 * function: PARTY_SELECT_LIST_DeleteMonIcons
 * address:  0x021CCB98
 * packet:   pkt_ov021_021CCB98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */
#include "../include/Obj09731.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct Obj;
extern u32 POKEPARTY_GetCount(void *p);
extern void CLACT_DeleteActor(struct Obj *p);

void PARTY_SELECT_LIST_DeleteMonIcons(u8 *p)
{
    int i;
    int n;

    n = POKEPARTY_GetCount(((struct Obj09731 *)p)->f4);
    for (i = 0; i < n; i++)
        CLACT_DeleteActor(*(void **)(p + i * 4 + 0x1c));
    if (((struct Obj09731 *)p)->f8) {
        n = POKEPARTY_GetCount(((struct Obj09731 *)p)->f8);
        for (i = 0; i < n; i++)
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x34));
    }
}
