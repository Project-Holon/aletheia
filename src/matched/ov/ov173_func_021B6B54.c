/*
 * function: POKE_SUMMARY_MAIN_ShowTextKind6
 * address:  0x021B6B54
 * packet:   pkt_021B6B54
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_SUMMARY_MAIN_StartTextStream  0x021B7460  thumb  ov173
 */
#include "../include/Obj24158.h"

typedef unsigned int   u32;
extern void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 kind);

int POKE_SUMMARY_MAIN_ShowTextKind6(int *p)
{
    POKE_SUMMARY_MAIN_StartTextStream((char *)p, 6);
    ((struct Obj24158 *)p)->f1B0 = 5;
    return 2;
}
