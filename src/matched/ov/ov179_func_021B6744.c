/*
 * function: CDEMO_SCENE_CmdStartWipe1
 * address:  0x021B6744
 * packet:   pkt_ov179_021B6744
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CDEMO_WIPE_StartFadeIn  0x021B62B8  thumb  ov179
 */
#include "../include/Obj14390.h"

typedef unsigned int   u32;
extern void CDEMO_WIPE_StartFadeIn(char *p, u32 a, u32 b, u32 c);

int CDEMO_SCENE_CmdStartWipe1(int a, int *q)
{
    CDEMO_WIPE_StartFadeIn((char *)a, ((struct Obj14390 *)q)->f4, ((struct Obj14390 *)q)->f8, 5);
    return 1;
}
