/*
 * function: NNS_G2dSetCellAnimationCurrentFrame
 * address:  0x02064384
 * packet:   pkt_02064364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062F00  0x02062F00  arm
 *   NNSi_G2dRefreshCellAnimation  0x0206419C  arm
 *
 * The single-step form of NNS_G2dTickCellAnimation: steps the node's cell animation by
 * one frame instead of by a tick, and marks the cache dirty if it moved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dSetCellAnimationCurrentFrame.c  *       --func NNS_G2dSetCellAnimationCurrentFrame --addr 0x02064384 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct CellAnim;

extern int func_02062F00(void *s, u32 i);
extern void NNSi_G2dRefreshCellAnimation(char *self);

void NNS_G2dSetCellAnimationCurrentFrame(struct CellAnim *anim, u32 i)
{
    if (func_02062F00(anim, i) != 0) {
        NNSi_G2dRefreshCellAnimation((char *)anim);
    }
}
