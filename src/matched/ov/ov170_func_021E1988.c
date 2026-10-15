/*
 * function: BOX2_SEQ_StateExitBox
 * address: 0x021E1988
 * packet: pkt_ov170_021E1988
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb ov170
 *   BOX2_MAIN_PlaceMonSceneFromBox 0x021DEA3C thumb ov170
 *   BOX2_MAIN_IsSwapScene 0x021DEAFC thumb ov170
 */
#include "../include/Obj08237.h"
#include "../include/Obj10653.h"
typedef unsigned int   u32;
extern u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);
extern void BOX2_MAIN_PlaceMonSceneFromBox(int a, int b, int c, int d);
extern int BOX2_MAIN_IsSwapScene(int a);
int BOX2_SEQ_StateExitBox(unsigned char *p)
{
    char *w = *(char * *)&((struct Obj10653 *)p)->f2C;
    char *b = w + 0x58;
    switch (((struct Obj08237 *)b)->fC) {
    case 0:
        if (!BOX2_SEQ_IsActorAnimActive(w, 10)) {
            unsigned old = p[0x16];
            p[0x16] = **(unsigned short * *)&((struct Obj08237 *)b)->f8;
            BOX2_MAIN_PlaceMonSceneFromBox((int)p, old, old, 1);
            ((struct Obj08237 *)b)->fC = 1;
        }
        break;
    case 1:
        if (!BOX2_MAIN_IsSwapScene((int)p)) {
            ((struct Obj08237 *)b)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}
