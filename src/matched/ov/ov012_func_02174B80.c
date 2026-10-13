/*
 * function: COLOSSEUM_RecvPlayerEntry
 * address: 0x02174B80
 * packet: pkt_ov012_02174B80
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj19276.h"
#include "../include/Obj19277.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void func_02082D44(void *,void *,u32);
void COLOSSEUM_RecvPlayerEntry(u32 a, u32 b, void *c, u8 *d)
{
    u8 *w = *(u8 * *)&((struct Obj19276 *)d)->f355C;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()))) return;
    if (w == 0 || ((struct Obj19277 *)w)->f0 == 0) return;
    func_02082D44(c, w + 0x18 + a * 44, b);
}
