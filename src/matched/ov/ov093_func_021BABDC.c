/*
 * function: BTL_SERVER_GetFinalData
 * address: 0x021BABDC
 * packet: pkt_ov093_021BABDC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj21026.h"

typedef struct { unsigned int a, b; } Pair;
void BTL_SERVER_GetFinalData(char *p, Pair *out)
{
 *out = **(Pair * *)&((struct Obj21026 *)p)->fB0;
}
