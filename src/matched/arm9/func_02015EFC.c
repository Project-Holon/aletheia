/*
 * function: func_02015EFC
 * address:  0x02015EFC
 * packet:   pkt_02015EFC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj15669.h"
typedef unsigned char u8;

u8 func_02015EFC(char *p, u8 i)
{
    return (*(u8 * *)&((struct Obj15669 *)p)->f30 + i)[2];
}
