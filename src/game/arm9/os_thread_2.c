/*
 * file:     os_thread_2.c
 * function: OS_GetThreadPriority
 * address:  0x02085A30
 * packet:   pkt_02085A30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../../matched/include/Obj01024.h"

void *OS_GetThreadPriority(char *thread)
{
    return ((struct Obj01024 *)thread)->f70;
}
