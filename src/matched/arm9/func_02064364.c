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
 *   NNS_G2dTickAnimCtrl  0x02062D4C  arm
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

extern s32  NNS_G2dTickAnimCtrl(struct CellAnim *anim, s32 frames);
extern void NNSi_G2dRefreshCellAnimation(char *self);

void NNS_G2dTickCellAnimation(struct CellAnim *anim, s32 frames)
{
    if (NNS_G2dTickAnimCtrl(anim, frames) != 0) {
        NNSi_G2dRefreshCellAnimation((char *)anim);
    }
}
