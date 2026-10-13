/*
 * file:     unit_02198020.c
 * function: func_02198020
 * address:  0x02198020
 * packet:   pkt_ov009_02198020
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

#include "unit_02195B20_types.h"

void func_02198020(GTI2Socket *socket, void *connectAttemptCallback)
{
    socket->connectAttemptCallback = connectAttemptCallback;
}
