/*
 * function: UNION_COMMAND_SendMyStatus
 * address: 0x02173B4C
 * packet: pkt_ov012_02173B4C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 * Live r0 return and narrowed third argument observed at send call;
 * matched wrapper copies fourth full-word payload unchanged.
 */
#include "../include/Obj19251.h"
#include "../include/Obj19252.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int MYSTATUS_GetSize(void);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int UNION_COMMAND_SendMyStatus(u8 *p)
{
    u32 link;
    int n;
    link = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    n = MYSTATUS_GetSize();
    return GFL_NET_SendToHandle((struct Entry *)link, (u16)0x1405, (u16)n, (u32)GAME_DATA_GetMyStatus(((struct Obj19252 *)(*(u8 * *)&((struct Obj19251 *)p)->f0))->f8));
}
