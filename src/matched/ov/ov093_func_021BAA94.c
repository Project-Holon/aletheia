/*
 * function: BTL_SERVER_SetClientAdapter
 * address: 0x021BAA94
 * packet: pkt_ov093_021BAA94
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SERVER_SetClientAdapterSlot 0x021BB840 thumb ov093
 *   BTL_SERVER_SetClientParty 0x021BB848 thumb ov093
 */
#include "../include/Obj21023.h"

typedef unsigned char u8;
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
struct Q4;
extern void BTL_SERVER_SetClientAdapterSlot(struct Q4 *p, int a, int b, int c);
extern void BTL_SERVER_SetClientParty(u8 *p, void *q, u8 v);
void BTL_SERVER_SetClientAdapter(char *p, int b, u8 c, u8 d)
{
 char *x;
 unsigned int q;
 unsigned int off;
 x = BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj21023 *)p)->f10, c);
 q = (unsigned int)p + 0x14U;
 off = (unsigned int)c * 12U;
 BTL_SERVER_SetClientAdapterSlot((struct Q4 *)(q + off), c, b, 1);
 BTL_SERVER_SetClientParty((u8 *)(q + off), x, d);
}
