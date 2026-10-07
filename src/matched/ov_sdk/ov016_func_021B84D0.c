/*
 * function: alarmCallback
 * address:  0x021B84D0
 * packet:   pkt_ov016_021B84D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OS_SendMessage               0x02085DBC  arm
 *   d_021DCE40                   0x021DCE40  data
*/

#include "../include/G_OSMessageQueue.h"

extern void OS_SendMessage(void);
extern struct OSMessageQueue d_021DCE40;

asm void alarmCallback(void)
{
	LDR R3, =OS_SendMessage
	ADD R1, R0, #0
	LDR R0, =0x021DCE40
	MOV R2, #0
	BX R3
}

