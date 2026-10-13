/*
 * function: DWCi_MOV_WH_SetUserGameInfo
 * address:  0x02178E28
 * packet:   pkt_ov014_02178E28
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWihWork                   0x021797A8  data
*/

#include "../include/G_S.h"

typedef struct { void *p; unsigned short h; } S;
extern struct S *gWihWork;

void DWCi_MOV_WH_SetUserGameInfo(void *p, unsigned short h)
{
	gWihWork->p = p;
	gWihWork->h = h;
}

