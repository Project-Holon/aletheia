/*
 * function: PARTY_SELECT_LIST_DeleteStatusIcons
 * address:  0x021CCDF8
 * packet:   pkt_ov021_021CCDF8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */
#include "../include/Obj09732.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct Obj;
extern u32 func_0201AA18(void *p);
extern void CLACT_DeleteActor(struct Obj *p);

void PARTY_SELECT_LIST_DeleteStatusIcons(u8 *p)
{
    int i;
    int n;

    n = func_0201AA18(((struct Obj09732 *)p)->f4);
    for (i = 0; i < n; i++) {
        if (*(void **)(p + i * 4 + 0x4c))
            CLACT_DeleteActor(*(void **)(p + i * 4 + 0x4c));
    }
    if (((struct Obj09732 *)p)->f8) {
        n = func_0201AA18(((struct Obj09732 *)p)->f8);
        for (i = 0; i < n; i++) {
            if (*(void **)(p + i * 4 + 0x64))
                CLACT_DeleteActor(*(void **)(p + i * 4 + 0x64));
        }
    }
}
