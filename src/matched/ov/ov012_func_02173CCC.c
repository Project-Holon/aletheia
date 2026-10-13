/*
 * function: UNION_COMMAND_RecvAppEntry
 * address:  0x02173CCC
 * packet:   pkt_ov012_02173CCC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   UNION_APP_TryAcceptMember  0x02183BE8  thumb  ov022
 */
#include "../include/Obj05918.h"

typedef unsigned char u8;

typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int UNION_APP_TryAcceptMember(u8 *s, int i);

void UNION_COMMAND_RecvAppEntry(int a, int x, int y, u8 *p)
{
    if (((struct Obj05918 *)p)->f3528 == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        p[0x282D] |= (u8)(1 << a);
        return;
    }
    if (UNION_APP_TryAcceptMember((u8 *)(((struct Obj05918 *)p)->f3528), (u8)a) == 1) {
        p[0x282C] |= (u8)(1 << a);
        return;
    }
    p[0x282D] |= (u8)(1 << a);
}
