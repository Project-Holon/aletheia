/*
 * function: func_02063030
 * address:  0x02063030
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * Returns true when the cell this animation is currently on is one of the two
 * "has a bounding box" cell kinds (attribute 2 or 4). The attribute comes from
 * the animation's own override word at +0x18 when that is non-zero, otherwise
 * from the bound cell data bank's +0x08 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02063030.c  *       --func func_02063030 --addr 0x02063030 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellBank {
    u32 unk00;
    u32 unk04;
    u32 attr;
};

struct CellAnim {
    u8 pad00[0x18];
    u32 attrOverride;
    struct CellBank *bank;
};

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
