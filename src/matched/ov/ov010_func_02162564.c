/*
 * function: EVENTDATA_SYSTEM_SearchConnectIdByGridPos
 * address: 0x02162564
 * packet: pkt_ov010_02162564
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: same shape as EVENTDATA_SYSTEM_SearchConnectIdByRailLocation with the callee EVENTDATA_SYSTEM_IsConnectGridHit.
 * symbols:
 *   EVENTDATA_SYSTEM_IsConnectGridHit 0x02162D2C thumb ov010
 */
#include "../include/Obj12338.h"
typedef unsigned short u16;
struct Box; struct Q;
extern int EVENTDATA_SYSTEM_IsConnectGridHit(const struct Box *b, const int *pos);
int EVENTDATA_SYSTEM_SearchConnectIdByGridPos(char *p, struct Q *q) { int i; char *r; i=0; r=*(char * *)&((struct Obj12338 *)p)->f24; for(;i<((struct Obj12338 *)p)->f16;i++,r+=20) { if(EVENTDATA_SYSTEM_IsConnectGridHit((struct Box *)r,(const int *)q)) return i; } return 0xffff; }
