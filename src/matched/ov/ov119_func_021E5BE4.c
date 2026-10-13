/*
 * function: func_021E5BE4
 * address:  0x021E5BE4
 * packet:   pkt_ov119_021E5BE4
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 */
#include "../include/Obj00001.h"

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);

void func_021E5BE4(int a)
{
    if (((struct Obj00001 *)a)->fF08 != 0)
        CLACT_DeleteActor((struct Obj *)(((struct Obj00001 *)a)->fF08));
    if (((struct Obj00001 *)a)->fF0C != 0)
        CLACT_DeleteActor((struct Obj *)(((struct Obj00001 *)a)->fF0C));
    if (((struct Obj00001 *)a)->fF10 != 0)
        CLACT_DeleteActor((struct Obj *)(((struct Obj00001 *)a)->fF10));
    if (((struct Obj00001 *)a)->fF14 != 0)
        CLACT_DeleteActor((struct Obj *)(((struct Obj00001 *)a)->fF14));
    ((struct Obj00001 *)a)->fF08 = 0;
    ((struct Obj00001 *)a)->fF0C = 0;
    ((struct Obj00001 *)a)->fF10 = 0;
    ((struct Obj00001 *)a)->fF14 = 0;
    if (((struct Obj00001 *)a)->f89C != 0)
        CLACT_ReleaseCharacter(((struct Obj00001 *)a)->f89C);
    if (((struct Obj00001 *)a)->f8A0 != 0)
        CLACT_ReleaseCharacter(((struct Obj00001 *)a)->f8A0);
    ((struct Obj00001 *)a)->f89C = 0;
    ((struct Obj00001 *)a)->f8A0 = 0;
}
