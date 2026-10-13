/*
 * function: func_021B891C
 * address: 0x021B891C
 * packet: pkt_ov172_021B891C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
#include "../include/Obj24084.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32, u32, u32, u32, u32, u32, u32, u32);
int func_021B891C(void *a, char *q, u16 *p)
{
    u32 entry;
    int r;
    entry = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    r = GFL_NET_SendData(entry, 255, 0x2001, *p + 8, (u32)p, 1, 0, 1);
    if (r != 0)
        ((struct Obj24084 *)q)->f194 = 1;
    return r;
}
