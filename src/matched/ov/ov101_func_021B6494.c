/*
 * function: COMPATIBLE_IRC_SYS_SendToHandle
 * address: 0x021B6494
 * packet: pkt_ov101_021B6494
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two zero alignment bytes. Extern b/c widened because
 *       caller forwards full words without callee's u16 truncation pairs.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
#include "../include/Obj22091.h"
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int COMPATIBLE_IRC_SYS_SendToHandle(u32 p,u32 a,u32 b,u32 c) {
    if(((struct Obj22091 *)p)->f78!=0) return 1;
    return GFL_NET_SendToHandle((struct Entry *)GFL_NET_HANDLE_GetCurrentHandle(),a,b,c);
}
