/*
 * function: NNS_G2dRestartCellAnimation
 * address:  0x020643A4
 * packet:   pkt_02064364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dResetCellAnimation  0x02062F90  arm
 *   NNSi_G2dRefreshCellAnimation  0x0206419C  arm
 *
 * Restarts one node's cell animation from frame 0, forces its active flag at
 * +0x0C on and marks the node's OAM cache dirty unconditionally.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dRestartCellAnimation.c  *       --func NNS_G2dRestartCellAnimation --addr 0x020643A4 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellAnim {
    u8 pad00[0xC];
    u32 active;
};

struct NNSG2dAnimController;
extern void NNS_G2dResetCellAnimation(struct NNSG2dAnimController *pAnimCtrl);
extern void NNSi_G2dRefreshCellAnimation(char *self);

void NNS_G2dRestartCellAnimation(struct CellAnim *anim)
{
    NNS_G2dResetCellAnimation((struct NNSG2dAnimController *)anim);
    anim->active = 1;
    NNSi_G2dRefreshCellAnimation((char *)anim);
}
