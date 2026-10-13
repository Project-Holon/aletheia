/*
 * function: FS_GetFileImageTop
 * address:  0x0207A7BC
 * packet:   pkt_0207A7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj02340.h"

void *FS_GetFileImageTop(char *p)
{
    return ((struct Obj02340 *)p)->f24;
}
