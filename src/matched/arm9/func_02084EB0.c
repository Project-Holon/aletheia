/*
 * function: OS_ReadOwnerOfLockWord
 * address:  0x02084EB0
 * packet:   pkt_02084EB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16691.h"

unsigned short OS_ReadOwnerOfLockWord(char *p)
{
    return ((struct Obj16691 *)p)->f4;
}
