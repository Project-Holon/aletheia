/*
 * function: func_021F58C0
 * address:  0x021F58C0
 * packet:   pkt_021F58C0
 * region:   ov082
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../fld_faceup_types.h"

void func_021F58C0(FaceupAnim *anim)
{
    anim->idle = 1;
    anim->uploadPending = 0;
    anim->delay = 0;
    anim->delayReload = 0;
    anim->frame = 0;
}
