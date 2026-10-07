/*
 * file:     unit_02062BAC_p02.c
 * unit:     yes
 * function: func_02062D08, func_02062D40
 * address:  0x02062D08
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj07015.h"
#include "../../matched/include/Obj11525.h"
#include "../../matched/include/Obj16406.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

struct CellAnim {
    u32 unk00;
    void **sequence;
};

int func_02062D08(void *p, u32 i);


int func_02062D08(void *p, u32 i)
{
    u8 *s = (u8 *)p;
    u8 *t = *(u8 * *)&((struct Obj07015 *)s)->f1C;
    u8 *e;

    if (i < ((struct Obj11525 *)t)->f0) {
        e = *(u8 * *)&((struct Obj11525 *)t)->fC + i * 8;
        *(u8 * *)&((struct Obj07015 *)s)->f0 = e;
        if (((struct Obj16406 *)e)->f4 != 0) {
            *(u8 * *)&((struct Obj07015 *)s)->f4 = e;
        }
        return 1;
    }
    return 0;
}


/*
 * *
 * Returns the cell-animation's current animation-sequence record: the sequence
 * pointer array member at +0x04 of the animation state, dereferenced once. The
 * value it yields is the 16-byte NANR sequence record the multi-cell node's
 * own sequence index selected.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062D40.c  *       --func func_02062D40 --addr 0x02062D40 --cc 1.1p1
 */
void *func_02062D40(struct CellAnim *anim)
{
    return *anim->sequence;
}
