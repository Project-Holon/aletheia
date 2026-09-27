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
 *   g_021797A8                   0x021797A8  data
*/

typedef struct { void *p; unsigned short h; } S;
extern S *g_021797A8;

void DWCi_MOV_WH_SetUserGameInfo(void *p, unsigned short h)
{
	g_021797A8->p = p;
	g_021797A8->h = h;
}

