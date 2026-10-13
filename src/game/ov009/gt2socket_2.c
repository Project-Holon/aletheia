/*
 * file:     gt2socket_2.c
 * function: gti2SetConnectAttemptCallback
 * address:  0x02198020
 * packet:   pkt_ov009_02198020
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

#include "gt2main_2_types.h"

void gti2SetConnectAttemptCallback(GTI2Socket *socket, void *connectAttemptCallback)
{
    socket->connectAttemptCallback = connectAttemptCallback;
}
