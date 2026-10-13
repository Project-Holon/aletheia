/*
 * function: func_021BD9B4
 * address: 0x021BD9B4
 * packet: pkt_ov099_021BD9B4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
#include "../include/Obj22043.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 func_02039CB4(struct Link *, u32, u32);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int func_021BD9B4(char *p, int v)
{
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10) != 0) {
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa05, 1, (u32)(p + 0x1353)) != 0) {
            ((struct Obj22043 *)p)->f1CC = 0x48;
        }
    }
    return v;
}
