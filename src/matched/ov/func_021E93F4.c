/*
 * function: BOX2_SEQ_SaveMenuPosAndExit
 * address:  0x021E93F4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_MAIN_PlayMonCry  0x021DE898  thumb  ov170
 *   BOX2_SEQ_StartWipeBlack  0x021E8F90  thumb  ov170
 *
 * candidate BOX2_SEQ_SaveMenuPosAndExit: copy two bytes into a sub object
 */
#include "../include/Obj05869.h"


extern void BOX2_MAIN_PlayMonCry(int *q);
extern int BOX2_SEQ_StartWipeBlack(void *p, int a);
void BOX2_SEQ_SaveMenuPosAndExit(char *p)
{
    BOX2_MAIN_PlayMonCry((int *)((int)p));
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2a) = ((struct Obj05869 *)p)->f14;
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2b) = ((struct Obj05869 *)p)->f16;
    ((struct Obj05869 *)p)->f28 = 0x69;
    BOX2_SEQ_StartWipeBlack((void *)((int)p), 1);
}

