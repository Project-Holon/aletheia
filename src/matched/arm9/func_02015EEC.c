/*
 * function: MCSS_GetAnimSeqNum
 * address:  0x02015EEC
 * packet:   pkt_02015EEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj15665.h"
typedef unsigned short u16;

u16 MCSS_GetAnimSeqNum(char *p)
{
    return **(u16 * *)&((struct Obj15665 *)p)->f28;
}
