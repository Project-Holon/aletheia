/*
 * file:     btlv_effvm_p04.c
 * unit:     yes
 * function: func_021F7208, func_021F722C
 * address:  0x021F7208
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj18557.h"

typedef struct {
    int x, y, z;
} VecFx32;

void func_021F7208(VecFx32 *a, VecFx32 *b);
int func_021F722C(char *p);


void func_021F7208(VecFx32 *a, VecFx32 *b)
{
    a->x = 0x6b33;
    a->y = 0x6b33;
    a->z = 0x114cd;
    b->x = 0;
    b->y = 0x299a;
    b->z = 0;
}


/*
 * lane O10 candidate
 */
int func_021F722C(char *p)
{
    return ((struct Obj18557 *)p)->f14 != 0;
}
