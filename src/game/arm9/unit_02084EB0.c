/*
 * file:     unit_02084EB0.c
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
#include "../../matched/include/Obj16691.h"

unsigned short OS_ReadOwnerOfLockWord(char *lock)
{
    return ((struct Obj16691 *)lock)->f4;
}
