/*
 * function: CDEMO_SCENE_CmdStartWipe2
 * address:  0x021B6758
 * packet:   pkt_021B6758
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CDEMO_WIPE_StartFadeOutWhite  0x021B62E0  thumb  ov179
 */
#include "../include/Obj14391.h"

typedef unsigned int   u32;
extern void CDEMO_WIPE_StartFadeOutWhite(char *p, u32 a, u32 b, u32 c);

int CDEMO_SCENE_CmdStartWipe2(int a, int *q)
{
    CDEMO_WIPE_StartFadeOutWhite((char *)a, ((struct Obj14391 *)q)->f4, ((struct Obj14391 *)q)->f8, 5);
    return 1;
}
