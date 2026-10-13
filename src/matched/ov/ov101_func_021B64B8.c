/*
 * function: COMPATIBLE_IRC_SYS_SendData
 * address: 0x021B64B8
 * packet: pkt_ov101_021B64B8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
#include "../include/Obj22092.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
u32 COMPATIBLE_IRC_SYS_SendData(u32 p,u32 a,u32 b,u32 c,u8 d,u32 e,u32 f,u32 g) {
    if(((struct Obj22092 *)p)->f78!=0) return 1;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),d,a,b,c,e,f,g);
}
