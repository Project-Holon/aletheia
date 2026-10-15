/*
 * function: CDEMO_SCENE_RunCommands
 * address:  0x021B64B0
 * packet:   pkt_ov179_021B64B0
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CDEMO_SCENE_DispatchCommand  0x021B66DC  thumb  ov179
 */
#include "../include/Obj14388.h"
typedef unsigned int u32;

extern int CDEMO_SCENE_DispatchCommand(char *p);

u32 CDEMO_SCENE_RunCommands(char *p)
{
    do {
        if (**(int * *)&((struct Obj14388 *)p)->f601C == 20) {
            (*(unsigned char **)p)[3] = 0;
            return 1;
        }
    } while (CDEMO_SCENE_DispatchCommand(p) == 1);
    return ((struct Obj14388 *)p)->f6050;
}
