/*
 * function: alarmCallback
 * address:  0x021B84D0
 * packet:   pkt_ov016_021B84D0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OS_SendMessage               0x02085DBC  arm
 *   g_021DCE40                   0x021DCE40  data
*/

#include "../include/G_OSMessageQueue.h"

extern int OS_SendMessage(struct OSMessageQueue *mq, void *msg, long flags);
extern struct OSMessageQueue g_021DCE40;

void alarmCallback(void *event)
{
    OS_SendMessage(&g_021DCE40, event, 0);
}
