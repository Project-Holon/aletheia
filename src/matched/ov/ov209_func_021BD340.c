/*
 * function: ZUKAN_LIST_StateSelectSpecies
 * address:  0x021BD340
 * packet:   pkt_ov209_021BD340
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_LIST_StoreLastViewedSpecies 0x021BD314 thumb
 */
#include "../include/Obj00088.h"

extern void ZUKAN_LIST_StoreLastViewedSpecies(char *p, int i);

int ZUKAN_LIST_StateSelectSpecies(char *a, int arg)
{
    ZUKAN_LIST_StoreLastViewedSpecies(a, arg);
    *(int *)(*(int *)&((struct Obj00088 *)a)->f0 + 0x10) = 3;
    return 7;
}