/*
 * function: UNION_COMMAND_RecvAppJoinData
 * address: 0x02173F54
 * packet: pkt_ov012_02173F54
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   UNION_APP_SetMemberEntry 0x02183FB8 thumb ov022
 *   UNION_APP_AddEntryTarget 0x02183FA8 thumb ov022
 *   d_02175624 0x02175624 data a1
 */
#include "../include/Obj09364.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void UNION_APP_SetMemberEntry(int, void *, u8, int);
extern void UNION_APP_AddEntryTarget(u8 *p, u8 index);
extern u8 d_02175624[];
void UNION_COMMAND_RecvAppJoinData(int a, int x, int y, u8 *p)
{
    if (((struct Obj09364 *)p)->f3528 == 0) {
        func_02034714((const char *)d_02175624, 0, (const char *)d_02175624);
        return;
    }
    UNION_APP_SetMemberEntry(((struct Obj09364 *)p)->f3528, p, a, y);
    UNION_APP_AddEntryTarget((u8 *)(((struct Obj09364 *)p)->f3528), a);
}
