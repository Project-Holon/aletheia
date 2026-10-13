/*
 * function: NNS_G2dTickCellAnimation
 * address:  0x02064364
 * packet:   pkt_02064364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062D4C  0x02062D4C  arm
 *   NNSi_G2dRefreshCellAnimation  0x0206419C  arm
 *
 * Advances one multi-cell node's cell animation by a fx32 tick and, only if
 * that actually changed the displayed frame, marks the node's OAM cache dirty
 * through NNSi_G2dRefreshCellAnimation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dTickCellAnimation.c  *       --func NNS_G2dTickCellAnimation --addr 0x02064364 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellAnim;

extern s32  func_02062D4C(struct CellAnim *anim, s32 frames);
extern void NNSi_G2dRefreshCellAnimation(char *self);

void NNS_G2dTickCellAnimation(struct CellAnim *anim, s32 frames)
{
    if (func_02062D4C(anim, frames) != 0) {
        NNSi_G2dRefreshCellAnimation((char *)anim);
    }
}
