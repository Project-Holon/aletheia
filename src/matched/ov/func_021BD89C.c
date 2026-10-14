/*
 * function: ZKND_TBAR_PlayButtonAnim
 * address:  0x021BD89C
 * packet:   pkt_021BD89C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKND_TBAR_GetButtonSound 0x021BD868  thumb  ov208
 *   ZKND_TBAR_SetAnimByState 0x021BD848  thumb  ov208
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9

 * Swaps in the cleared state flag and frees the handle at +0x30.
 */
#include "../include/Obj12118.h"


typedef unsigned int   u32;
extern int ZKND_TBAR_GetButtonSound(const void *p);
extern void ZKND_TBAR_SetAnimByState(char *, int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void ZKND_TBAR_PlayButtonAnim(char *p)
{
    int f = ZKND_TBAR_GetButtonSound(p) == 0;

    ZKND_TBAR_SetAnimByState(p, f);
    if (((struct Obj12118 *)p)->f30 != 0)
        GFL_USE_PlaySeDefaultVolume(((struct Obj12118 *)p)->f30);
}

