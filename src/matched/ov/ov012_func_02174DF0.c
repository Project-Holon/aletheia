/*
 * unit: yes
 * function: COLOSSEUM_SendBattlePositions, COLOSSEUM_RecvReady
 * address: 0x02174DF0
 * packet: pkt_ov012_02174DF0
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes 020399A8's live r0 despite its filed void return.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
#include "../include/Obj19291.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int COLOSSEUM_SendBattlePositions(u32 v) { return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0x1507,4,v); }
void COLOSSEUM_RecvReady(int index,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19291 *)ctx)->f355C;
    if (p) (p+index)[0xd4] = 1;
}
