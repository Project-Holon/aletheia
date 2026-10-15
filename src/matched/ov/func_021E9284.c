/*
 * function: BOX2_SEQ_StatePlayCry
 * address:  0x021E9284
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_PlayMonCry  0x021DE898  thumb  ov170
 *   BOX2_SEQ_StartWipeBlack  0x021E8F90  thumb  ov170
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *
 * Set the id, re-key the queue, store 0x69 as the frame, then
 *   arm the flag.
 */
#include "../include/Obj18472.h"


typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BOX2_MAIN_PlayMonCry(int *q);
extern int BOX2_SEQ_StartWipeBlack(void *p, int a);
int BOX2_SEQ_StatePlayCry(char *p)
{
    GFL_USE_PlaySeDefaultVolume(0x55D);
    BOX2_MAIN_PlayMonCry((int *)p);
    ((struct Obj18472 *)p)->f28 = 0x69;
    return BOX2_SEQ_StartWipeBlack(p, 1);
}
