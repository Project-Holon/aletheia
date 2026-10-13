/*
 * function: FLD_EXP_OBJ_GetAnime
 * address:  0x021BE674
 * packet:   pkt_ov021_021BE674
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb
 */
#include "../include/Obj12904.h"

typedef unsigned short u16;

void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k)
{
    char *e = base + i * 16;
    struct S {
        int n;
        char *arr;
    };
    char *arr;

    if (((struct Obj12904 *)e)->f8 == 0) {
        return 0;
    }
    if (j >= ((struct Obj12904 *)e)->f16) {
        return 0;
    }
    arr = (*(struct S **)(e + 0x10))[j].arr;
    if (k >= (*(struct S **)(e + 0x10))[j].n) {
        return 0;
    }
    return arr + k * 16;
}
