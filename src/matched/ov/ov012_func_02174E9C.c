/*
 * unit: yes
 * function: COLOSSEUM_SendCancelAck, COLOSSEUM_RecvAllReady
 * address: 0x02174E9C
 * packet: pkt_ov012_02174E9C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes 020399A8's live r0 despite its filed void return.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
#include "../include/Obj19294.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
u32 COLOSSEUM_SendCancelAck(int v) { return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),(u8)v,0x150a,0,0,1,0,0); }
void COLOSSEUM_RecvAllReady(int unused0,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19294 *)ctx)->f355C;
    if (p) p[0xcb] = 1;
}
