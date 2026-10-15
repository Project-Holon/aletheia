/*
 * function: POKE_SUMMARY_ANIM_ShowTextKind4
 * address:  0x021B7618
 * packet:   pkt_021B7618
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
#include "../include/Obj14318.h"

typedef unsigned int   u32;
extern void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 kind);

int POKE_SUMMARY_ANIM_ShowTextKind4(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 4);
    ((struct Obj14318 *)p)->f1BA = 2;
    ((struct Obj14318 *)p)->f1B0 = 3;
    return 2;
}
