/*
 * function: SYMBOL_MAP_DeleteLinkRecord
 * address:  0x021666A4
 * packet:   pkt_021666A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj12051.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020307B0();

void SYMBOL_MAP_DeleteLinkRecord(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12051 *)((char *)t4))->f0;
    if (a0 == 0) goto loc_021666B6;
loc_021666AE:
    a0 = func_020307B0(a0);
loc_021666B2:
a0 = 0;
((struct Obj12051 *)((char *)t4))->f0 = a0;
loc_021666B6:
    return;}
