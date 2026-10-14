/*
 * function: ZKND_TBAR_PlayCancelAnim
 * address:  0x021BD880
 * packet:   pkt_021BD880
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Re-verified 2026-09-27 (DIFF fixer lane): the +8 store in the image is a
 * full word, `str r1,[r4,#8]`, not `strh`: the zero-extended u16 is written
 * through an int lvalue.  With `*(int *)(p + 8) = h;` the whole function
 * reproduces, including `ldrh r1,[r4,#0x28]; ldr r0,[r4]; str r1,[r4,#8]`.
 * EXACT*: the inferred extent runs 2 bytes past `pop` (an unlabelled
 * follower/alignment word), never a byte difference.
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   (none)
 */
#include "../include/Obj05866.h"


typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void ZKND_TBAR_PlayCancelAnim(char *p)
{
    unsigned short h = ((struct Obj05866 *)p)->f28;
    int v = ((struct Obj05866 *)p)->f0;

    ((struct Obj05866 *)p)->f8 = h;
    CLACT_SetActorAnimSeq((struct Obj *)v, h);
    if (((struct Obj05866 *)p)->f30 != 0)
        GFL_USE_PlaySeDefaultVolume(((struct Obj05866 *)p)->f30);
}
