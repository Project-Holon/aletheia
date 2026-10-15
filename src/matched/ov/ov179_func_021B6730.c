/*
 * function: CDEMO_SCENE_CmdStartWipe0
 * address:  0x021B6730
 * packet:   pkt_021B6730
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CDEMO_WIPE_StartFadeOut  0x021B6290  thumb  ov179
 */
#include "../include/Obj14389.h"

typedef unsigned int   u32;
extern void CDEMO_WIPE_StartFadeOut(char *p, u32 a, u32 b, u32 c);

int CDEMO_SCENE_CmdStartWipe0(int a, int *q)
{
    CDEMO_WIPE_StartFadeOut((char *)a, ((struct Obj14389 *)q)->f4, ((struct Obj14389 *)q)->f8, 5);
    return 1;
}
