/*
 * unit: yes
 * function: func_021BD924, func_021BD97C
 * address: 0x021BD924
 * packet: pkt_ov099_021BD924
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BCBD8 0x021BCBD8 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
#include "../include/Obj05264.h"
#include "../include/Obj13695.h"
extern unsigned int func_021BCBD8(char *p, int m);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int func_021BD924(char *p, int v)
{
    int t;
    if (((struct Obj05264 *)p)->f1352 == 6) {
        ((struct Obj05264 *)p)->f1353 = 0x4d;
        ((struct Obj05264 *)p)->f1CC = 0x8a;
    } else {
        if (((struct Obj05264 *)p)->f135C == 3 || ((struct Obj05264 *)p)->f135C == 1) {
            t = func_021BCBD8(p, 1);
        } else {
            t = func_021BCBD8(p, 0);
        }
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa06, 4, (u32)(&t)) != 0) {
            ((struct Obj05264 *)p)->f1CC = 0x82;
        }
    }
    return v;
}
int func_021BD97C(char *p, int v)
{
    ((struct Obj13695 *)p)->f1353 = 0x5e;
    ((struct Obj13695 *)p)->f1CC = 0x8a;
    return v;
}
