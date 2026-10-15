/*
 * function: POKE_SUMMARY_ANIM_ShowTextKind8
 * address:  0x021B75FC
 * packet:   pkt_021B75FC
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
#include "../include/Obj14317.h"

typedef unsigned int   u32;
extern void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 kind);

int POKE_SUMMARY_ANIM_ShowTextKind8(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 8);
    ((struct Obj14317 *)p)->f1B0 = 8;
    *(unsigned char *)(((struct Obj14317 *)p)->f0 + 0x1a) = 1;
    return 2;
}
