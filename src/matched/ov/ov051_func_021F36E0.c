/*
 * unit:     yes
 * function: FIELD_GIMMICK_D06_GetStonePositions, GIMMICK49_Exit
 * address:  0x021F36E0
 * packet:   pkt_ov051_021F36E0
 * region:   ov051
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two accessors over the result of GIMMICK49_Init.
 *
 * symbols:
 *   GIMMICK49_Init  0x021F36C0  thumb  ov051
 */
#include "../include/Obj20552.h"
#include "../include/Obj20553.h"

int FIELD_GIMMICK_D06_GetStonePositions(int a)
{
    void *GIMMICK49_Init(int a);
    return ((struct Obj20552 *)((char *)GIMMICK49_Init(a)))->f8;
}

int GIMMICK49_Exit(int a)
{
    void *GIMMICK49_Init(int a);
    return ((struct Obj20553 *)((char *)GIMMICK49_Init(a)))->f4;
}
