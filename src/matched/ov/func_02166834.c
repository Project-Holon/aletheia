/*
 * function: SYMBOL_MAP_GetSyncBlockHeader
 * address:  0x02166834
 * packet:   pkt_02166834
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int SYMBOL_MAP_GetSyncBlockHeader(int a0, int a1)
{

    if (a1 == 0) goto loc_02166842;
loc_02166838:
    if (a1 == 1) goto loc_02166846;
loc_0216683C:
    if (a1 == 2) goto loc_0216684A;
loc_02166840:
    goto loc_0216684E;
loc_02166842:
a0 = *(u8 *)((char *)a0 + 1);
    return a0;
loc_02166846:
a0 = *(u8 *)&((struct Obj00005 *)((char *)a0))->f0;
    return a0;
loc_0216684A:
a0 = *(u8 *)((char *)a0 + 2);
    return a0;
loc_0216684E:
a0 = 0;
    return a0;}
