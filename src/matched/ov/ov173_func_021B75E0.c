/*
 * function: POKE_SUMMARY_ANIM_ShowTextKind7
 * address:  0x021B75E0
 * packet:   pkt_021B75E0
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_SUMMARY_MAIN_StartTextStream  0x021B7460  thumb  ov173
 */
#include "../include/Obj14316.h"

typedef unsigned int   u32;
extern void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 kind);

int POKE_SUMMARY_ANIM_ShowTextKind7(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 7);
    ((struct Obj14316 *)p)->f1BA = 3;
    ((struct Obj14316 *)p)->f1B0 = 3;
    return 2;
}
