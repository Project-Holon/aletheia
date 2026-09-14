/*
 * function: func_02063018
 * address:  0x02063018
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * The variant of func_02063000 that pins the kind word at +0x20 to 2 and takes
 * the u16 tag as an argument instead of clearing it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02063018.c  *       --func func_02063018 --addr 0x02063018 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellAnim {
    u8 pad00[0x20];
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u16 unk2C;
};

void func_02063018(struct CellAnim *anim, u32 a, u32 b, u16 tag)
{
    anim->unk20 = 2;
    anim->unk28 = b;
    anim->unk24 = a;
    anim->unk2C = tag;
}
