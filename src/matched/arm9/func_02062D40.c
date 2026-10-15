/*
 * function: NNSi_G2dGetCellAnimationCurrentSequence
 * address:  0x02062D40
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * Returns the cell-animation's current animation-sequence record: the sequence
 * pointer array member at +0x04 of the animation state, dereferenced once. The
 * value it yields is the 16-byte NANR sequence record the multi-cell node's
 * own sequence index selected.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dGetCellAnimationCurrentSequence.c  *       --func NNSi_G2dGetCellAnimationCurrentSequence --addr 0x02062D40 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellAnim {
    u32 unk00;
    void **sequence;
};

void *NNSi_G2dGetCellAnimationCurrentSequence(struct CellAnim *anim)
{
    return *anim->sequence;
}
