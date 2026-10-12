/*
 * file:     unit_02062FF0.c
 * unit:     yes
 * function: func_02062FF0, func_02063000, func_02063018, func_02063030
 * address:  0x02062FF0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02062F90  0x02062F90  arm
 */
#include "cell_anim_types.h"

struct NNSG2dAnimController;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_02062F90(struct NNSG2dAnimController *pAnimCtrl);
void func_02063000(int p0, int p1, int p2, int p3);


/*
 * Binds a cell data bank to a cell animation and restarts it. The bind is a
 * single store followed by a tail call, so it costs a pool word and a `bx`
 * rather than a branch (one section per function, no displacement branch).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062FF0.c  *       --func func_02062FF0 --addr 0x02062FF0 --cc 1.1p1
 */
void func_02062FF0(struct CellAnim *anim, void *bank)
{
    anim->bank = bank;
    func_02062F90((struct NNSG2dAnimController *)anim);
}


/* stand-in: p0 must be an int cast to the struct; a CellAnim * parameter changes the bytes */
void func_02063000(int p0, int p1, int p2, int p3)
{
    ((struct CellAnim *)p0)->unk28 = (int)p3;
    ((struct CellAnim *)p0)->unk24 = (int)p2;
    ((struct CellAnim *)p0)->unk20 = (int)p1;
    ((struct CellAnim *)p0)->unk2C = (unsigned short)0;
}


/*
 * *
 * The variant of func_02063000 that pins the kind word at +0x20 to 2 and takes
 * the u16 tag as an argument instead of clearing it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02063018.c  *       --func func_02063018 --addr 0x02063018 --cc 1.1p1
 */
void func_02063018(struct CellAnim *anim, u32 a, u32 b, u16 tag)
{
    anim->unk20 = 2;
    anim->unk28 = b;
    anim->unk24 = a;
    anim->unk2C = tag;
}


/*
 * *
 * Returns true when the cell this animation is currently on is one of the two
 * "has a bounding box" cell kinds (attribute 2 or 4). The attribute comes from
 * the animation's own override word at +0x18 when that is non-zero, otherwise
 * from the bound cell data bank's +0x08 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02063030.c  *       --func func_02063030 --addr 0x02063030 --cc 1.1p1
 */
s32 func_02063030(struct CellAnim *anim)
{
    u32 attr = anim->attrOverride;

    if (attr == 0) {
        attr = anim->bank->attr;
    }

    if (attr == 2 || attr == 4) {
        return 1;
    }

    return 0;
}
