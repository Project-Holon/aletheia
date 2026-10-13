/*
 * function: UNION_COMMAND_RecvAppLeaveData
 * address:  0x0217403C
 * packet:   pkt_ov012_0217403C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   func_02034714  0x02034714  arm
 *   UNION_APP_SetMemberEntry  0x02183FB8  thumb  ov022
 *   UNION_APP_QueueJoinConfirm  0x02184060  thumb  ov022
 */
#include "../include/Obj09365.h"

typedef unsigned char u8;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_GetHandleNetID(struct Link *p);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void UNION_APP_SetMemberEntry(int o, void *p, u8 i, int y);
extern void UNION_APP_QueueJoinConfirm(u8 *s, int i);

void UNION_COMMAND_RecvAppLeaveData(int a, int x, int y, u8 *p)
{
    if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
        if (((struct Obj09365 *)p)->f3528 == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
        UNION_APP_SetMemberEntry(((struct Obj09365 *)p)->f3528, p, (u8)a, y);
        UNION_APP_QueueJoinConfirm((u8 *)(((struct Obj09365 *)p)->f3528), (u8)a);
    }
}
