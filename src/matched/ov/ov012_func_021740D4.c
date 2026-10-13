/*
 * function: UNION_COMMAND_RecvAppNotice
 * address: 0x021740D4
 * packet: pkt_ov012_021740D4
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Extent follower 0217410C is this lane's corrected-entry file, kept separate.
 * UNION_APP_OnMemberDropped receives both original loaded arguments despite its empty body.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_02034714 0x02034714 arm
 *   UNION_APP_OnMemberDropped 0x021840A4 thumb ov022
 *   d_02175624 0x02175624 data a1
 */
#include "../include/Obj12450.h"
typedef unsigned char u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void UNION_APP_OnMemberDropped(int, u8);
extern u8 d_02175624[];
void UNION_COMMAND_RecvAppNotice(int a, int x, u8 *b, u8 *p)
{
    if (a != GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {
        if (((struct Obj12450 *)p)->f3528 == 0) {
            func_02034714((const char *)d_02175624, 0, (const char *)d_02175624);
            return;
        }
        UNION_APP_OnMemberDropped(((struct Obj12450 *)p)->f3528, *b);
    }
}
